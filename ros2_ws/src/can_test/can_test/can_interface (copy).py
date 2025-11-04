#!/usr/bin/env python3

import math
from canlib import canlib, Frame
from canlib.canlib import CanError
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16, Int32
from nav_msgs.msg import Odometry
from custom_msgs.msg import WheelRPM

class CANInterface(Node):
    def __init__(self, channel=0, bitrate=canlib.canBITRATE_50K, can_id=1):
        super().__init__('can_interface')

        self.channel_num = channel
        self.can_id = can_id
        self.latest_cmd_rpm = WheelRPM()

        # 상태 변수 초기화
        self.left_rpm = 0
        self.left_encoder = 0
        self.left = 0.0
        self.prev_left = 0.0
        self.x = 0.0
        self.y = 0.0
        self.cmd_received_recently = False

        try:
            self.ch = canlib.openChannel(channel)
            self.ch.setBusOutputControl(canlib.Driver.NORMAL)
            self.ch.setBusParams(bitrate)
            self.ch.busOn()

            self.send_pid_frame(217, [0, 0, 0, 0])  # Reset Motor1 Posi
            self.send_pid_frame(10, [11])           # PID_MONITOR BC on
            self.send_pid_frame(46, [1])            # 위치 정보 엔코더로 받기
            self.send_pid_frame(156, [166, 21])     # PID_ENC_PPR as 5542
        except CanError as e:
            self.get_logger().error(f"❌ CAN 장치 없음 또는 초기화 실패: {e}")
            return

        # ROS pub/sub
        self.subscription = self.create_subscription(WheelRPM, '/cmd_rpm', self.cmd_callback, 10)
        self.rpm_publisher = self.create_publisher(Int16, '/left_rpm', 10)
        self.odom_publisher = self.create_publisher(Odometry, '/odom', 10)
        self.encoder_publisher = self.create_publisher(Int32, '/encoder', 10)

        # 타이머 (CAN이 없으면 callback 내부에서 무시)
        self.timer = self.create_timer(0.01, self.timer_callback)        # 100Hz
        self.safety_timer = self.create_timer(0.1, self.safety_timer_callback)  # 10Hz

    def cmd_callback(self, msg):
        self.latest_cmd_rpm = msg
        self.cmd_received_recently = True

    def timer_callback(self):
        if not self.ch:
            return
        l_rpm = self.latest_cmd_rpm.left_rpm
        r_rpm = self.latest_cmd_rpm.right_rpm
        data = [1, l_rpm & 0xFF, (l_rpm >> 8) & 0xFF, 1, r_rpm & 0xFF, (r_rpm >> 8) & 0xFF, 0]
        self.send_pid_frame(207, data)
        self.receive_loop()

    def safety_timer_callback(self):
        if not self.ch:
            return
        if self.cmd_received_recently:
            self.cmd_received_recently = False
        else:
            self.send_pid_frame(207, [1, 0, 0, 1, 0, 0, 0])  # 정지 명령

    def receive_loop(self):
        if not self.ch:
            return
        while True:
            try:
                frame = self.ch.read(timeout=0)
                pid = frame.data[0]

                if pid != 196:
                    continue

                self.left_rpm = int.from_bytes(frame.data[2:4], byteorder='little', signed=True)
                self.left_encoder = int.from_bytes(frame.data[4:8], byteorder='little', signed=True)

                encoder_msg = Int32()
                encoder_msg.data = self.left_encoder
                self.encoder_publisher.publish(encoder_msg)

                self.publish_left_rpm()
                self.update_odometry()
                break

            except canlib.CanNoMsg:
                break
            except Exception as e:
                self.get_logger().error(f"[RECEIVE ERROR] {e}")
                break

    def publish_left_rpm(self):
        msg = Int16()
        msg.data = self.left_rpm
        self.rpm_publisher.publish(msg)

    def update_odometry(self):
        ppr = 5542
        wheel_diameter = 0.1715
        wheel_circumference = math.pi * wheel_diameter

        self.prev_left = self.left
        self.left = (self.left_encoder / 4) / ppr * wheel_circumference

        delta_left = self.left - self.prev_left
        delta_s = delta_left
        theta = 0

        self.x += delta_s * math.cos(theta)
        self.y += delta_s * math.sin(theta)

        odom_msg = Odometry()
        odom_msg.header.stamp = self.get_clock().now().to_msg()
        odom_msg.header.frame_id = "odom"
        odom_msg.child_frame_id = "base_link"
        odom_msg.pose.pose.position.x = self.x
        odom_msg.pose.pose.position.y = self.y
        odom_msg.pose.pose.position.z = 0.0

        self.odom_publisher.publish(odom_msg)

    def send_pid_frame(self, pid: int, data: list[int]):
        if not self.ch:
            return
        if len(data) > 7:
            raise ValueError("Data must be at most 7 bytes.")
        full_data = [pid] + data + [0] * (8 - len(data) - 1)
        try:
            frame = Frame(id_=self.can_id, data=full_data, flags=canlib.MessageFlag.STD)
            self.ch.write(frame)
        except Exception as e:
            self.get_logger().error(f"[TX ERROR] Failed to send frame: {e}")

    def close(self):
        if not self.ch:
            return
        try:
            self.send_pid_frame(10, [12])  # PID_MONITOR BC off
            self.ch.busOff()
            self.ch.close()
        except Exception as e:
            self.get_logger().error(f"[CAN CLOSE ERROR] {e}")

def main(args=None):
    rclpy.init(args=args)
    node = CANInterface()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Keyboard Interrupt로 종료")
    finally:
        node.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
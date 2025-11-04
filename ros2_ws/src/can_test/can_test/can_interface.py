#!/usr/bin/env python3

import math
import can  # ✅ Kvaser 대신 python-can 사용
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16, Int32
from nav_msgs.msg import Odometry
from custom_msgs.msg import WheelRPM

class CANInterface(Node):
    def __init__(self):
        super().__init__("can_interface")

        # ✅ SocketCAN 초기화
        try:
            self.bus = can.interface.Bus(channel='can0', bustype='socketcan')
            self.get_logger().info("✅ SocketCAN 연결 성공 (can0)")
        except Exception as e:
            self.get_logger().error(f"❌ CAN 초기화 실패: {e}")
            self.bus = None
            return

        self.latest_cmd_rpm = WheelRPM()
        self.left_rpm = 0
        self.left_encoder = 0

        self.x = 0.0
        self.y = 0.0
        self.prev_left = 0.0
        self.left = 0.0

        self.cmd_received_recently = False

        # ✅ ROS Sub / Pub
        self.subscription = self.create_subscription(WheelRPM, '/cmd_rpm', self.cmd_callback, 10)
        self.rpm_publisher = self.create_publisher(Int16, '/left_rpm', 10)
        self.encoder_publisher = self.create_publisher(Int32, '/encoder', 10)
        self.odom_publisher = self.create_publisher(Odometry, '/odom', 10)

        # ✅ Timer 콜백 (100Hz 송신)
        self.timer = self.create_timer(0.01, self.timer_callback)
        self.safety_timer = self.create_timer(0.1, self.safety_timer_callback)

    def cmd_callback(self, msg):
        self.latest_cmd_rpm = msg
        self.cmd_received_recently = True

    def timer_callback(self):
        if not self.bus:
            return

        l_rpm = self.latest_cmd_rpm.left_rpm
        r_rpm = self.latest_cmd_rpm.right_rpm

        data = [1, l_rpm & 0xFF, (l_rpm >> 8) & 0xFF,
                1, r_rpm & 0xFF, (r_rpm >> 8) & 0xFF, 0]

        self.send_pid_frame(207, data)
        self.receive_can()

    def safety_timer_callback(self):
        if not self.bus:
            return
        if not self.cmd_received_recently:
            self.send_pid_frame(207, [1, 0, 0, 1, 0, 0, 0])
        else:
            self.cmd_received_recently = False

    # ✅ Kvaser 방식 → python-can 전송 방식으로 변경
    def send_pid_frame(self, pid, data):
        if not self.bus:
            return
        frame = can.Message(arbitration_id=1,  # 기존 self.can_id 대신 고정
                            data=[pid] + data,
                            is_extended_id=False)
        try:
            self.bus.send(frame)
        except can.CanError:
            self.get_logger().error("[TX ERROR] CAN 메시지 송신 실패")

    # ✅ 수신부 SocketCAN으로 변경
    def receive_can(self):
        if not self.bus:
            return
        try:
            frame = self.bus.recv(timeout=0.001)
            if frame is None:
                return
            data = frame.data
            if data[0] != 196:
                return

            self.left_rpm = int.from_bytes(data[2:4], 'little', signed=True)
            self.left_encoder = int.from_bytes(data[4:8], 'little', signed=True)

            rpm_msg = Int16()
            rpm_msg.data = self.left_rpm
            self.rpm_publisher.publish(rpm_msg)

            enc_msg = Int32()
            enc_msg.data = self.left_encoder
            self.encoder_publisher.publish(enc_msg)

        except Exception as e:
            self.get_logger().error(f"[RX ERROR] {e}")

    def close(self):
        if self.bus:
            self.bus.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = CANInterface()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()

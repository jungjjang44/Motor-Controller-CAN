#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from custom_msgs.msg import WheelRPM
import threading


class RpmPublisher(Node):
    def __init__(self):
        super().__init__('rpm_publisher')
        self.publisher = self.create_publisher(WheelRPM, '/cmd_rpm', 10)
        self.timer = self.create_timer(0.2, self.publish_loop)  # 5Hz
        self.current_left_rpm = None
        self.current_right_rpm = None
        self.get_logger().info('RpmPublisher node started. Enter left and right RPMs.')

    def publish_loop(self):
        if self.current_left_rpm is not None and self.current_right_rpm is not None:
            msg = WheelRPM()
            msg.left_rpm = self.current_left_rpm
            msg.right_rpm = self.current_right_rpm
            self.publisher.publish(msg)
            self.get_logger().info(f'Published RPMs → Left: {msg.left_rpm}, Right: {msg.right_rpm}')

    def update_rpm(self, left_rpm, right_rpm):
        self.current_left_rpm = left_rpm
        self.current_right_rpm = right_rpm
        self.get_logger().info(f'Current RPMs set to → Left: {left_rpm}, Right: {right_rpm}')


def main(args=None):
    rclpy.init(args=args)
    node = RpmPublisher()

    spin_thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
    spin_thread.start()

    try:
        while rclpy.ok():
            try:
                user_input = input("Enter left and right RPM (e.g., 100 -100), or 'q' to quit: ")
                if user_input.strip().lower() == 'q':
                    break
                parts = user_input.strip().split()
                if len(parts) != 2:
                    print("❗ 왼쪽과 오른쪽 rpm을 공백으로 구분해 입력하세요.")
                    continue
                left_rpm = int(parts[0])
                right_rpm = int(parts[1])
                node.update_rpm(left_rpm, right_rpm)
            except ValueError:
                print("❗ 정수로 입력하거나 'q'로 종료하세요.")
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

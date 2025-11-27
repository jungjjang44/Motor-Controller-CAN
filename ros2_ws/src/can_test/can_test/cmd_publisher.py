#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from custom_msgs.msg import WheelRPM
import threading


class RpmPublisher(Node):
    def __init__(self):
        super().__init__('rpm_publisher')
        # 큐 사이즈는 10으로 설정
        self.publisher = self.create_publisher(WheelRPM, '/cmd_rpm', 10)
        self.get_logger().info('RpmPublisher node started. Ready for input.')

    # ✅ 타이머 제거됨: 이제 이 함수는 사용자가 호출할 때만 실행됩니다.
    def publish_once(self, left_rpm, right_rpm):
        msg = WheelRPM()
        msg.left_rpm = int(left_rpm)
        msg.right_rpm = int(right_rpm)
        
        # 메시지 발행 (딱 1번)
        self.publisher.publish(msg)
        self.get_logger().info(f'✅ Sent Command → Left: {msg.left_rpm}, Right: {msg.right_rpm}')


def main(args=None):
    rclpy.init(args=args)
    node = RpmPublisher()

    # ROS 2 통신을 위한 스레드 (백그라운드에서 노드 유지)
    spin_thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
    spin_thread.start()

    print("-------------------------------------------------")
    print("🚗 RPM Command Publisher (Event Triggered)")
    print("-------------------------------------------------")

    try:
        while rclpy.ok():
            try:
                # 사용자 입력 대기
                user_input = input("\nEnter left and right RPM (e.g., '100 -100'), or 'q' to quit: ")
                
                # 종료 조건
                if user_input.strip().lower() == 'q':
                    print("Exiting...")
                    break
                
                parts = user_input.strip().split()
                if len(parts) != 2:
                    print("❗ 잘못된 형식입니다. 공백으로 구분된 두 개의 정수를 입력하세요.")
                    continue
                
                left_rpm = int(parts[0])
                right_rpm = int(parts[1])

                # ✅ 입력받은 즉시 1회 전송
                node.publish_once(left_rpm, right_rpm)

            except ValueError:
                print("❗ 숫자가 아닙니다. 정수를 입력해주세요.")
            except Exception as e:
                print(f"❗ 에러 발생: {e}")

    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        spin_thread.join()


if __name__ == '__main__':
    main()
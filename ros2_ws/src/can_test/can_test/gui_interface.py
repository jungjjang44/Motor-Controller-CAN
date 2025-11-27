#!/usr/bin/env python3

import json
import rclpy
from rclpy.node import Node
from custom_msgs.msg import WheelRPM
import paho.mqtt.client as mqtt

BROKER_IP="0.tcp.jp.ngrok.io" # ngrok tcp tunneling
BROKER_PORT=11278 # ngrok tcp tunneling -> 매번 바뀌는 듯..? 해결 방법 찾기!

MQTT_TOPIC  = "robot/cmd/speed"
RPM_GAIN    = 500.0              # speed 0.1 -> rpm 50 (예: 0.1 * 500 = 50)


class MqttToRpmNode(Node):
    def __init__(self):
        super().__init__("mqtt_to_rpm")
        self.publisher = self.create_publisher(WheelRPM, "/cmd_rpm", 10)
        self.current_speed = 0.0

        self.mqtt_client = mqtt.Client(client_id="jetson-subscriber")
        self.mqtt_client.on_connect = self.on_mqtt_connect
        self.mqtt_client.on_message = self.on_mqtt_message
        self.mqtt_client.connect(BROKER_IP, BROKER_PORT, 60)
        self.mqtt_client.loop_start()

        self.get_logger().info("MQTT→RPM bridge node started")

    # MQTT 콜백들
    def on_mqtt_connect(self, client, userdata, flags, rc):
        self.get_logger().info(f"MQTT connected rc={rc}")
        if rc == 0:
            client.subscribe(MQTT_TOPIC)
            self.get_logger().info(f"Subscribed to {MQTT_TOPIC}")

    def on_mqtt_message(self, client, userdata, msg):
        try:
            payload = msg.payload.decode("utf-8")
            data = json.loads(payload)

            # speed 추출 및 저장
            self.current_speed = float(data.get("speed", 0.0))

            # speed → RPM 변환
            rpm = self.current_speed * RPM_GAIN
            left_rpm = int(-rpm)
            right_rpm = int(rpm)

            # WheelRPM 1회 발행
            ros_msg = WheelRPM()
            ros_msg.left_rpm = left_rpm
            ros_msg.right_rpm = right_rpm
            self.publisher.publish(ros_msg)

            self.get_logger().info(
                f"speed={self.current_speed:.3f} -> "
                f"cmd_rpm L:{left_rpm} R:{right_rpm}"
            )

        except Exception as e:
            self.get_logger().warn(f"MQTT message handling error: {e}")

    def destroy_node(self):
        # 종료 시 MQTT 정리
        try:
            self.mqtt_client.loop_stop()
            self.mqtt_client.disconnect()
        except Exception:
            pass
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = MqttToRpmNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()

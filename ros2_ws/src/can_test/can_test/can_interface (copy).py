#!/usr/bin/env python3

# s
import can
import rclpy
import time
from rclpy.node import Node
from std_msgs.msg import Int32, Float32
from custom_msgs.msg import WheelRPM

class CANInterface(Node):
    def __init__(self):
        super().__init__("can_interface")

        # ==========================================
        # ⚙️ [설정] 환경에 맞게 수정
        # ==========================================
        self.channel = 'can0'       
        self.target_id = 0x100      # 모터 피드백 ID
        self.PPR = 4096             # 분해능
        # ==========================================

        # CAN 연결
        try:
            self.bus = can.Bus(channel=self.channel, interface='socketcan', bitrate=500000)
            self.get_logger().info(f"✅ CAN 연결 성공 ({self.channel})")
        except Exception as e:
            self.get_logger().error(f"❌ CAN 초기화 실패: {e}")
            self.bus = None
            return

        # 이전 명령값 저장용 (중복 전송 방지)
        self.prev_left_cmd = None
        self.prev_right_cmd = None

        # ✅ [Subscriber] 명령이 들어오면 즉시 쏩니다 (Event-Driven)
        self.subscription = self.create_subscription(
            WheelRPM, 
            '/cmd_rpm', 
            self.cmd_callback, 
            10
        )

        # ✅ [Publisher] 모터 상태
        self.rpm_publisher = self.create_publisher(Float32, '/motor/rpm', 10)
        self.encoder_publisher = self.create_publisher(Int32, '/motor/encoder', 10)

        # ✅ [Timer] 수신(RX) 전용 - 100Hz (0.01초)
        # 송신은 여기서 하지 않습니다! 오직 수신만 담당하여 속도를 높입니다.
        self.timer = self.create_timer(0.01, self.rx_timer_callback)

    # =========================================================
    # 📤 [송신부] Callback 방식 (명령이 올 때만 실행)
    # =========================================================
    def cmd_callback(self, msg):
        print("왔다!!")
        if not self.bus:
            return
        print("왔다!!!!")
        # 현재 명령값
        l_rpm = int(msg.left_rpm)
        r_rpm = int(msg.right_rpm)

        # 🚀 최적화: 이전 값과 다를 때만 전송 (Bus 부하 감소)
        # (만약 모터가 Heartbeat가 필요하다면 이 조건문을 빼거나 별도 타이머가 필요함)
        if (l_rpm != self.prev_left_cmd) or (r_rpm != self.prev_right_cmd):
            data = [
                1,                  
                l_rpm & 0xFF,       
                (l_rpm >> 8) & 0xFF, 
                1,                  
                r_rpm & 0xFF,       
                (r_rpm >> 8) & 0xFF, 
                0                   
            ]

            # 즉시 전송
            if l_rpm==0 and r_rpm==0:
                print(f"velocity:0")
                self.send_pid_frame(207, data)
                time.sleep(0.1)
                self.send_pid_frame(0, data)
            else:
                self.send_pid_frame(207, data)
            # self.send_can_message(0xCF, data) # PID 207

            # 상태 업데이트
            self.prev_left_cmd = l_rpm
            self.prev_right_cmd = r_rpm
            
            # 디버깅용 (필요시 주석 해제)
            self.get_logger().info(f"📤 명령 전송: L={l_rpm}, R={r_rpm}")

    def send_can_message(self, arbitration_id, data):
        try:
            msg = can.Message(arbitration_id=arbitration_id, data=data, is_extended_id=False)
            self.bus.send(msg)
        except can.CanError:
            pass # 에러 무시

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

    # =========================================================
    # 📥 [수신부] Timer 방식 (Polling & Flushing)
    # =========================================================
    def rx_timer_callback(self):
        if not self.bus:
            return
        
        # 🚀 While Loop: 버퍼에 쌓인 모든 데이터를 싹 비웁니다 (반응속도 극대화)
        while True:
            try:
                frame = self.bus.recv(timeout=0) # Non-blocking
                if frame is None:
                    break
                
                # 타겟 ID 필터링
                if frame.arbitration_id != self.target_id:
                    continue

                data = frame.data
                if len(data) < 8:
                    continue

                # 데이터 파싱 (앞 4바이트=엔코더, 뒤 3바이트=PPS)
                raw_enc = int.from_bytes(data[0:4], 'little', signed=True)
                raw_pps = int.from_bytes(data[4:7], 'little', signed=True)

                # RPM 변환
                real_rpm = (raw_pps * 60.0) / self.PPR

                # Publish
                msg_rpm = Float32()
                msg_rpm.data = real_rpm
                self.rpm_publisher.publish(msg_rpm)

                msg_enc = Int32()
                msg_enc.data = raw_enc
                self.encoder_publisher.publish(msg_enc)
                # print(f" RPM:{real_rpm} | encoder:{raw_enc}")
            except Exception as e:
                self.get_logger().error(f"RX Error: {e}")
                break

    def destroy_node(self):
        if self.bus:
            self.bus.shutdown()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = CANInterface()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
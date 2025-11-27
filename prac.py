#!/usr/bin/env python3

import can
import time
import struct  # 음수 처리를 위해 추가

# 음수 RPM을 안전하게 바이트로 변환하기 위한 헬퍼 함수
def make_rpm_data(l_rpm, r_rpm):
    # 'h'는 short(2바이트 정수)를 의미하며, 리틀 엔디안(<)으로 처리
    l_bytes = struct.pack('<h', l_rpm)
    r_bytes = struct.pack('<h', r_rpm)
    
    return [
        1,              # Enable L
        l_bytes[0],     # L RPM Low byte
        l_bytes[1],     # L RPM High byte
        1,              # Enable R
        r_bytes[0],     # R RPM Low byte
        r_bytes[1],     # R RPM High byte
        0               # Reserved/Check
    ]

def send_pid_frame(bus, pid, data):
    msg = can.Message(
        arbitration_id=1,          # MD200T 쪽으로 보내는 CAN ID (너가 쓰는 ID 그대로)
        data=[pid] + data,
        is_extended_id=False
    )
    try:
        bus.send(msg)
        print(f"[TX] PID {pid}: {data}")
    except can.CanError as e:
        print(f"TX Error: {e}")

# ===========================
# 🔍 특정 PID 값을 읽어오는 함수
# ===========================
def read_pid(bus, pid, timeout=0.1):
    """
    MD200T에서 특정 PID의 현재 값을 읽어온다.
    - pid: 읽고 싶은 PID 번호 (0~253)
    - timeout: 응답 대기 시간(sec)
    반환:
      - pid <= 100  : 1바이트 정수(int)
      - 101~190     : 2바이트 리틀엔디언 정수(int, unsigned)
      - 191 이상    : 남은 바이트 전체(bytes)
      - 타임아웃    : None
    """
    # 1) 요청 프레임 전송: PID_REQ_PID_DATA (PID 4), D1 = 읽고 싶은 PID
    #    프레임: [4, pid, ...]
    send_pid_frame(bus, 4, [pid])

    # 2) 응답 대기
    end_t = time.time() + timeout
    while time.time() < end_t:
        frame = bus.recv(timeout=0.01)
        if frame is None:
            continue

        data = frame.data
        if not data:
            continue

        # 응답 첫 바이트는 "해당 PID 번호"여야 함
        if data[0] != pid:
            continue

        payload = data[1:]  # 실제 값 부분

        # PID 범위별 데이터 길이에 따라 해석
        if pid <= 100:
            # 1바이트 값
            return payload[0]
        elif pid <= 190:
            # 2바이트 리틀엔디언 (부호 없는 정수로 처리)
            if len(payload) < 2:
                return None
            return int.from_bytes(payload[:2], byteorder="little", signed=False)
        else:
            # 그 이상은 용도마다 다르니 raw bytes로 돌려줌
            return bytes(payload)

    # 타임아웃
    return None


def main():
    channel = 'can0'
    
    print(f"Connecting to {channel}...")
    
    try:
        with can.Bus(channel=channel, interface='socketcan', bitrate=500000) as bus:
            # --- 첫 번째 명령 : 회전 ---
            l_rpm = -100
            r_rpm = 100
            data = make_rpm_data(l_rpm, r_rpm)
            send_pid_frame(bus, 207, data)   # PID_PNT_VEL_CMD

            print("Sleeping for 5 seconds...")
            time.sleep(5.0)

            # # --- 두 번째 명령 : 정지 ---
            # l_rpm = 0
            # r_rpm = 0
            # data = make_rpm_data(l_rpm, r_rpm)
            # send_pid_frame(bus, 207, data)
            # print("Sleeping for 5 seconds...")
            # time.sleep(5.0)

            # # 입력 모드 기본값(ANALOG)으로 세팅 예시 (원하면 유지)
            send_pid_frame(bus, 25, [0])     # PID_INPUT_TYPE = 0 (ANALOG)
            time.sleep(1.0)

            send_pid_frame(bus, 10, [44])     # PID_INPUT_TYPE = 0 (ANALOG)

            # ===========================
            # 🔍 주요 PID 값 읽어보기 예시
            # ===========================
            # 원하는 PID 번호를 여기 리스트에 추가해서 덤프하면 됨
            important_pids = [0, 1, 24, 25, 34, 56, 207]  # 예: VER, STOP_STATUS, INPUT_TYPE, TURN_RATIO

            print("\n--- PID READ TEST ---")
            for p in important_pids:
                val = read_pid(bus, p, timeout=0.2)
                print(f"PID {p} -> {val}")
            print("Done.")

    except OSError as e:
        print(f"OS Error (CAN 장치가 켜져 있나요?): {e}")
    except Exception as e:
        print(f"Unexpected Error: {e}")

if __name__ == "__main__":
    main()

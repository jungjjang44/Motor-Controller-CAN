#!/usr/bin/env python3

import can
import time
import sys

def read_encoder_rpm():
    # ==========================================
    # ✅ 설정 (본인 환경에 맞게 수정)
    # ==========================================
    CHANNEL = 'can0'      # 현재 연결된 인터페이스 (can0 또는 can1)
    BITRATE = 500000      # 500k bps
    TARGET_ID = 0x100     # 모터 피드백 ID (256)
    # ==========================================

    print(f"🚀 모터 데이터 리더기 시작 (Interface: {CHANNEL}, ID: 0x{TARGET_ID:X})")
    print("Ctrl+C를 누르면 종료됩니다.")
    print("-" * 60)
    print(f"{'RAW HEX':^25} | {'Encoder (위치)':^15} | {'RPM (속도)':^10}")
    print("-" * 60)

    try:
        # SocketCAN 연결
        bus = can.Bus(channel=CHANNEL, interface='socketcan', bitrate=BITRATE)
    except Exception as e:
        print(f"❌ 연결 실패: {e}")
        return

    try:
        while True:
            # 1. 데이터 수신 (타임아웃 1초)
            msg = bus.recv(timeout=1.0)
            
            if msg is None:
                # 데이터가 안 들어올 때
                continue

            # 2. ID 필터링 (0x100만 통과)
            if msg.arbitration_id != TARGET_ID:
                continue
            
            data = msg.data
            if data[4]==0x02:
                print("OKOKOKOKOKOK")
            if len(data) < 8:
                continue

            # =========================================================
            # ✅ 데이터 파싱 (분석 결과 적용)
            # =========================================================
            
            # [엔코더]: 앞쪽 4바이트 (Index 0~3)
            # 특징: 바퀴를 돌리면 값이 누적되고 멈추면 유지됨
            encoder_val = int.from_bytes(data[0:4], byteorder='little', signed=True)
            
            # [RPM]: 중간 2바이트 (Index 4~5)
            # 특징: 바퀴를 돌릴 때만 변하고 멈추면 0으로 돌아옴
            rpm_val = int.from_bytes(data[4:7], byteorder='little', signed=True)

            # =========================================================

            # 3. 출력
            hex_str = " ".join([f"{b:02X}" for b in data])
            print(f"{hex_str:25} | {encoder_val:15d} | {rpm_val:10d}")

    except KeyboardInterrupt:
        print("\n🛑 프로그램 종료")
        bus.shutdown()

if __name__ == "__main__":
    read_encoder_rpm()
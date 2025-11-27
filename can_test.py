#!/usr/bin/env python3

import can
import time

def send_can_message_loop():
    bus = can.interface.Bus(channel='can0', bustype='socketcan')

    while True:
        msg = can.Message(
            arbitration_id=0x101,              # 0x101 ID 사용
            data=[0x11, 0x22, 0x33, 0x44],     # 임의의 4바이트 데이터
            is_extended_id=False
        )

        try:
            bus.send(msg)
            print("TX -> ID:0x102  DATA:[11 22 33 44]")
        except can.CanError as e:
            print(e)

        time.sleep(0.1)  # 0.1초 주기 (10Hz) → 원하면 수정 가능

if __name__ == "__main__":
    send_can_message_loop()

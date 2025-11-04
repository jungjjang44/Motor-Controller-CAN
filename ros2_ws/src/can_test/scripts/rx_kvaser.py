#!/usr/bin/env python3
from canlib import canlib
import time

CHANNEL_RX = 1                    # Kvaser #2
BITRATE    = canlib.canBITRATE_50K

def main():
    ch = canlib.openChannel(CHANNEL_RX)
    ch.setBusParams(BITRATE)
    ch.setBusOutputControl(canlib.Driver.NORMAL)  # 두 대만 있을 땐 NORMAL로 ACK 제공
    ch.busOn()
    print(f"[RX] up on ch{CHANNEL_RX} @50k")

    print("[RX] capturing all frames for 10s ...")
    t0 = time.time()
    while time.time() - t0 < 10:
        try:
            frame = ch.read(timeout=200)
            print(f"[RX] ID=0x{frame.id:03X} DLC={len(frame.data)} Data={list(frame.data)}")
        except canlib.CanNoMsg:
            pass

    ch.busOff()
    ch.close()

if __name__ == "__main__":
    main()
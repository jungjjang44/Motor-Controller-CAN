#!/usr/bin/env python3

'''
송신용 코드
'''

from canlib import canlib, Frame
import time

CHANNEL_TX = 0                    # Kvaser #1
BITRATE    = canlib.canBITRATE_50K
TX_ID      = 0x001

def main():
    ch = canlib.openChannel(CHANNEL_TX)
    ch.setBusParams(BITRATE)
    ch.setBusOutputControl(canlib.Driver.NORMAL)
    ch.busOn()
    print(f"[TX] up on ch{CHANNEL_TX} @50k")

    frame = Frame(id_=TX_ID, data=[0x0A, 0x0B, 0, 0, 0, 0, 0, 0], flags=canlib.MessageFlag.STD)
    ch.write(frame)
    print("[TX] MONITOR ON frame sent")


    # 테스트용 - 주기 송신
    for i in range(5):
        data = [0xC0, i, 1, 2, 3, 4, 5, 0]
        ch.write(Frame(id_=TX_ID, data=data))
        print(f"[TX] sent: {data}")
        time.sleep(0.5)

    ch.busOff()
    ch.close()

if __name__ == "__main__":
    main()
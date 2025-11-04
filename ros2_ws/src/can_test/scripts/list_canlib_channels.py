# list_canlib_channels.py
from canlib import canlib,Frame
n = canlib.getNumberOfChannels()
print("num channels:", n)
for ch in range(n):
    cd = canlib.ChannelData(ch)
    print(ch, cd.device_name, cd.channel_name)

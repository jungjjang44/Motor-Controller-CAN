import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/krri/Motor-Controller-CAN/ros2_ws/install/can_test'

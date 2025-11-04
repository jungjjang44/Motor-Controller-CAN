# UTMPoint.msg

# 이 메시지는 GPS 좌표를 UTM 좌표계로 표현합니다.
std_msgs/Header header   # 시간 및 좌표 프레임 정보

float64 easting          # UTM 동향 좌표 (m)
float64 northing         # UTM 북향 좌표 (m)
int32 zone_number        # UTM Zone 번호 (예: 52)
string zone_letter       # UTM Zone 문자 (예: 'S')
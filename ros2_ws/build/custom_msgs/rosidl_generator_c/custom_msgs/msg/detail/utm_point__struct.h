// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/UTMPoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__UTM_POINT__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__UTM_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'zone_letter'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/UTMPoint in the package custom_msgs.
/**
  * UTMPoint.msg
 */
typedef struct custom_msgs__msg__UTMPoint
{
  /// 이 메시지는 GPS 좌표를 UTM 좌표계로 표현합니다.
  /// 시간 및 좌표 프레임 정보
  std_msgs__msg__Header header;
  /// UTM 동향 좌표 (m)
  double easting;
  /// UTM 북향 좌표 (m)
  double northing;
  /// UTM Zone 번호 (예: 52)
  int32_t zone_number;
  /// UTM Zone 문자 (예: 'S')
  rosidl_runtime_c__String zone_letter;
} custom_msgs__msg__UTMPoint;

// Struct for a sequence of custom_msgs__msg__UTMPoint.
typedef struct custom_msgs__msg__UTMPoint__Sequence
{
  custom_msgs__msg__UTMPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__UTMPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__UTM_POINT__STRUCT_H_

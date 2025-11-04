// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/CameraInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/CameraInfo in the package custom_msgs.
typedef struct custom_msgs__msg__CameraInfo
{
  double avg_distance;
  int32_t image_count;
} custom_msgs__msg__CameraInfo;

// Struct for a sequence of custom_msgs__msg__CameraInfo.
typedef struct custom_msgs__msg__CameraInfo__Sequence
{
  custom_msgs__msg__CameraInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__CameraInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/WheelRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/WheelRPM in the package custom_msgs.
/**
  * Message   #
 */
typedef struct custom_msgs__msg__WheelRPM
{
  int16_t left_rpm;
  int16_t right_rpm;
} custom_msgs__msg__WheelRPM;

// Struct for a sequence of custom_msgs__msg__WheelRPM.
typedef struct custom_msgs__msg__WheelRPM__Sequence
{
  custom_msgs__msg__WheelRPM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__WheelRPM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:srv/GetPTZImage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__SRV__DETAIL__GET_PTZ_IMAGE__STRUCT_H_
#define CUSTOM_MSGS__SRV__DETAIL__GET_PTZ_IMAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetPTZImage in the package custom_msgs.
typedef struct custom_msgs__srv__GetPTZImage_Request
{
  uint8_t structure_needs_at_least_one_member;
} custom_msgs__srv__GetPTZImage_Request;

// Struct for a sequence of custom_msgs__srv__GetPTZImage_Request.
typedef struct custom_msgs__srv__GetPTZImage_Request__Sequence
{
  custom_msgs__srv__GetPTZImage_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__srv__GetPTZImage_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in srv/GetPTZImage in the package custom_msgs.
typedef struct custom_msgs__srv__GetPTZImage_Response
{
  sensor_msgs__msg__Image image;
} custom_msgs__srv__GetPTZImage_Response;

// Struct for a sequence of custom_msgs__srv__GetPTZImage_Response.
typedef struct custom_msgs__srv__GetPTZImage_Response__Sequence
{
  custom_msgs__srv__GetPTZImage_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__srv__GetPTZImage_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__SRV__DETAIL__GET_PTZ_IMAGE__STRUCT_H_

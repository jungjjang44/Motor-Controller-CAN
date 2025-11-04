// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:action/MapsDistance.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__ACTION__DETAIL__MAPS_DISTANCE__STRUCT_H_
#define CUSTOM_MSGS__ACTION__DETAIL__MAPS_DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/MapsDistance in the package custom_msgs.
typedef struct custom_msgs__action__MapsDistance_Goal
{
  /// 이동할 거리 (양수: 전진, 음수: 후진/복귀)
  double distance;
  double velocity;
} custom_msgs__action__MapsDistance_Goal;

// Struct for a sequence of custom_msgs__action__MapsDistance_Goal.
typedef struct custom_msgs__action__MapsDistance_Goal__Sequence
{
  custom_msgs__action__MapsDistance_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__MapsDistance_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/MapsDistance in the package custom_msgs.
typedef struct custom_msgs__action__MapsDistance_Result
{
  /// 성공 여부
  bool success;
  rosidl_runtime_c__String message;
  double final_distance;
} custom_msgs__action__MapsDistance_Result;

// Struct for a sequence of custom_msgs__action__MapsDistance_Result.
typedef struct custom_msgs__action__MapsDistance_Result__Sequence
{
  custom_msgs__action__MapsDistance_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__MapsDistance_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/MapsDistance in the package custom_msgs.
typedef struct custom_msgs__action__MapsDistance_Feedback
{
  /// 현재까지 이동한 거리
  double distance_traveled;
} custom_msgs__action__MapsDistance_Feedback;

// Struct for a sequence of custom_msgs__action__MapsDistance_Feedback.
typedef struct custom_msgs__action__MapsDistance_Feedback__Sequence
{
  custom_msgs__action__MapsDistance_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__MapsDistance_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "custom_msgs/action/detail/maps_distance__struct.h"

/// Struct defined in action/MapsDistance in the package custom_msgs.
typedef struct custom_msgs__action__MapsDistance_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_msgs__action__MapsDistance_Goal goal;
} custom_msgs__action__MapsDistance_SendGoal_Request;

// Struct for a sequence of custom_msgs__action__MapsDistance_SendGoal_Request.
typedef struct custom_msgs__action__MapsDistance_SendGoal_Request__Sequence
{
  custom_msgs__action__MapsDistance_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__MapsDistance_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MapsDistance in the package custom_msgs.
typedef struct custom_msgs__action__MapsDistance_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} custom_msgs__action__MapsDistance_SendGoal_Response;

// Struct for a sequence of custom_msgs__action__MapsDistance_SendGoal_Response.
typedef struct custom_msgs__action__MapsDistance_SendGoal_Response__Sequence
{
  custom_msgs__action__MapsDistance_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__MapsDistance_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MapsDistance in the package custom_msgs.
typedef struct custom_msgs__action__MapsDistance_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} custom_msgs__action__MapsDistance_GetResult_Request;

// Struct for a sequence of custom_msgs__action__MapsDistance_GetResult_Request.
typedef struct custom_msgs__action__MapsDistance_GetResult_Request__Sequence
{
  custom_msgs__action__MapsDistance_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__MapsDistance_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_msgs/action/detail/maps_distance__struct.h"

/// Struct defined in action/MapsDistance in the package custom_msgs.
typedef struct custom_msgs__action__MapsDistance_GetResult_Response
{
  int8_t status;
  custom_msgs__action__MapsDistance_Result result;
} custom_msgs__action__MapsDistance_GetResult_Response;

// Struct for a sequence of custom_msgs__action__MapsDistance_GetResult_Response.
typedef struct custom_msgs__action__MapsDistance_GetResult_Response__Sequence
{
  custom_msgs__action__MapsDistance_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__MapsDistance_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "custom_msgs/action/detail/maps_distance__struct.h"

/// Struct defined in action/MapsDistance in the package custom_msgs.
typedef struct custom_msgs__action__MapsDistance_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_msgs__action__MapsDistance_Feedback feedback;
} custom_msgs__action__MapsDistance_FeedbackMessage;

// Struct for a sequence of custom_msgs__action__MapsDistance_FeedbackMessage.
typedef struct custom_msgs__action__MapsDistance_FeedbackMessage__Sequence
{
  custom_msgs__action__MapsDistance_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__MapsDistance_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__ACTION__DETAIL__MAPS_DISTANCE__STRUCT_H_

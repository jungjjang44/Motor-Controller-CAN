// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:action/MapsDistance.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__ACTION__DETAIL__MAPS_DISTANCE__BUILDER_HPP_
#define CUSTOM_MSGS__ACTION__DETAIL__MAPS_DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/action/detail/maps_distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_MapsDistance_Goal_velocity
{
public:
  explicit Init_MapsDistance_Goal_velocity(::custom_msgs::action::MapsDistance_Goal & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::MapsDistance_Goal velocity(::custom_msgs::action::MapsDistance_Goal::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_Goal msg_;
};

class Init_MapsDistance_Goal_distance
{
public:
  Init_MapsDistance_Goal_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapsDistance_Goal_velocity distance(::custom_msgs::action::MapsDistance_Goal::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_MapsDistance_Goal_velocity(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::MapsDistance_Goal>()
{
  return custom_msgs::action::builder::Init_MapsDistance_Goal_distance();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_MapsDistance_Result_final_distance
{
public:
  explicit Init_MapsDistance_Result_final_distance(::custom_msgs::action::MapsDistance_Result & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::MapsDistance_Result final_distance(::custom_msgs::action::MapsDistance_Result::_final_distance_type arg)
  {
    msg_.final_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_Result msg_;
};

class Init_MapsDistance_Result_message
{
public:
  explicit Init_MapsDistance_Result_message(::custom_msgs::action::MapsDistance_Result & msg)
  : msg_(msg)
  {}
  Init_MapsDistance_Result_final_distance message(::custom_msgs::action::MapsDistance_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_MapsDistance_Result_final_distance(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_Result msg_;
};

class Init_MapsDistance_Result_success
{
public:
  Init_MapsDistance_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapsDistance_Result_message success(::custom_msgs::action::MapsDistance_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MapsDistance_Result_message(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::MapsDistance_Result>()
{
  return custom_msgs::action::builder::Init_MapsDistance_Result_success();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_MapsDistance_Feedback_distance_traveled
{
public:
  Init_MapsDistance_Feedback_distance_traveled()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msgs::action::MapsDistance_Feedback distance_traveled(::custom_msgs::action::MapsDistance_Feedback::_distance_traveled_type arg)
  {
    msg_.distance_traveled = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::MapsDistance_Feedback>()
{
  return custom_msgs::action::builder::Init_MapsDistance_Feedback_distance_traveled();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_MapsDistance_SendGoal_Request_goal
{
public:
  explicit Init_MapsDistance_SendGoal_Request_goal(::custom_msgs::action::MapsDistance_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::MapsDistance_SendGoal_Request goal(::custom_msgs::action::MapsDistance_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_SendGoal_Request msg_;
};

class Init_MapsDistance_SendGoal_Request_goal_id
{
public:
  Init_MapsDistance_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapsDistance_SendGoal_Request_goal goal_id(::custom_msgs::action::MapsDistance_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MapsDistance_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::MapsDistance_SendGoal_Request>()
{
  return custom_msgs::action::builder::Init_MapsDistance_SendGoal_Request_goal_id();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_MapsDistance_SendGoal_Response_stamp
{
public:
  explicit Init_MapsDistance_SendGoal_Response_stamp(::custom_msgs::action::MapsDistance_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::MapsDistance_SendGoal_Response stamp(::custom_msgs::action::MapsDistance_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_SendGoal_Response msg_;
};

class Init_MapsDistance_SendGoal_Response_accepted
{
public:
  Init_MapsDistance_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapsDistance_SendGoal_Response_stamp accepted(::custom_msgs::action::MapsDistance_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MapsDistance_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::MapsDistance_SendGoal_Response>()
{
  return custom_msgs::action::builder::Init_MapsDistance_SendGoal_Response_accepted();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_MapsDistance_GetResult_Request_goal_id
{
public:
  Init_MapsDistance_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msgs::action::MapsDistance_GetResult_Request goal_id(::custom_msgs::action::MapsDistance_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::MapsDistance_GetResult_Request>()
{
  return custom_msgs::action::builder::Init_MapsDistance_GetResult_Request_goal_id();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_MapsDistance_GetResult_Response_result
{
public:
  explicit Init_MapsDistance_GetResult_Response_result(::custom_msgs::action::MapsDistance_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::MapsDistance_GetResult_Response result(::custom_msgs::action::MapsDistance_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_GetResult_Response msg_;
};

class Init_MapsDistance_GetResult_Response_status
{
public:
  Init_MapsDistance_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapsDistance_GetResult_Response_result status(::custom_msgs::action::MapsDistance_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MapsDistance_GetResult_Response_result(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::MapsDistance_GetResult_Response>()
{
  return custom_msgs::action::builder::Init_MapsDistance_GetResult_Response_status();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_MapsDistance_FeedbackMessage_feedback
{
public:
  explicit Init_MapsDistance_FeedbackMessage_feedback(::custom_msgs::action::MapsDistance_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::MapsDistance_FeedbackMessage feedback(::custom_msgs::action::MapsDistance_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_FeedbackMessage msg_;
};

class Init_MapsDistance_FeedbackMessage_goal_id
{
public:
  Init_MapsDistance_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapsDistance_FeedbackMessage_feedback goal_id(::custom_msgs::action::MapsDistance_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MapsDistance_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_msgs::action::MapsDistance_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::MapsDistance_FeedbackMessage>()
{
  return custom_msgs::action::builder::Init_MapsDistance_FeedbackMessage_goal_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__ACTION__DETAIL__MAPS_DISTANCE__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/WheelRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/wheel_rpm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_WheelRPM_right_rpm
{
public:
  explicit Init_WheelRPM_right_rpm(::custom_msgs::msg::WheelRPM & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::WheelRPM right_rpm(::custom_msgs::msg::WheelRPM::_right_rpm_type arg)
  {
    msg_.right_rpm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::WheelRPM msg_;
};

class Init_WheelRPM_left_rpm
{
public:
  Init_WheelRPM_left_rpm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WheelRPM_right_rpm left_rpm(::custom_msgs::msg::WheelRPM::_left_rpm_type arg)
  {
    msg_.left_rpm = std::move(arg);
    return Init_WheelRPM_right_rpm(msg_);
  }

private:
  ::custom_msgs::msg::WheelRPM msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::WheelRPM>()
{
  return custom_msgs::msg::builder::Init_WheelRPM_left_rpm();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__BUILDER_HPP_

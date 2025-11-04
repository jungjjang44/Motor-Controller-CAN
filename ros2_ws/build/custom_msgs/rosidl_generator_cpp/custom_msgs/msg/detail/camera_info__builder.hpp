// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/CameraInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/camera_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_CameraInfo_image_count
{
public:
  explicit Init_CameraInfo_image_count(::custom_msgs::msg::CameraInfo & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::CameraInfo image_count(::custom_msgs::msg::CameraInfo::_image_count_type arg)
  {
    msg_.image_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::CameraInfo msg_;
};

class Init_CameraInfo_avg_distance
{
public:
  Init_CameraInfo_avg_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CameraInfo_image_count avg_distance(::custom_msgs::msg::CameraInfo::_avg_distance_type arg)
  {
    msg_.avg_distance = std::move(arg);
    return Init_CameraInfo_image_count(msg_);
  }

private:
  ::custom_msgs::msg::CameraInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::CameraInfo>()
{
  return custom_msgs::msg::builder::Init_CameraInfo_avg_distance();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:srv/GetPTZImage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__SRV__DETAIL__GET_PTZ_IMAGE__BUILDER_HPP_
#define CUSTOM_MSGS__SRV__DETAIL__GET_PTZ_IMAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/srv/detail/get_ptz_image__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::srv::GetPTZImage_Request>()
{
  return ::custom_msgs::srv::GetPTZImage_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPTZImage_Response_image
{
public:
  Init_GetPTZImage_Response_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msgs::srv::GetPTZImage_Response image(::custom_msgs::srv::GetPTZImage_Response::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::srv::GetPTZImage_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::srv::GetPTZImage_Response>()
{
  return custom_msgs::srv::builder::Init_GetPTZImage_Response_image();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__SRV__DETAIL__GET_PTZ_IMAGE__BUILDER_HPP_

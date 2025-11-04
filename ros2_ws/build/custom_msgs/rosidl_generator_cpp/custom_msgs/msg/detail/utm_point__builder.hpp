// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/UTMPoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__UTM_POINT__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__UTM_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/utm_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_UTMPoint_zone_letter
{
public:
  explicit Init_UTMPoint_zone_letter(::custom_msgs::msg::UTMPoint & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::UTMPoint zone_letter(::custom_msgs::msg::UTMPoint::_zone_letter_type arg)
  {
    msg_.zone_letter = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::UTMPoint msg_;
};

class Init_UTMPoint_zone_number
{
public:
  explicit Init_UTMPoint_zone_number(::custom_msgs::msg::UTMPoint & msg)
  : msg_(msg)
  {}
  Init_UTMPoint_zone_letter zone_number(::custom_msgs::msg::UTMPoint::_zone_number_type arg)
  {
    msg_.zone_number = std::move(arg);
    return Init_UTMPoint_zone_letter(msg_);
  }

private:
  ::custom_msgs::msg::UTMPoint msg_;
};

class Init_UTMPoint_northing
{
public:
  explicit Init_UTMPoint_northing(::custom_msgs::msg::UTMPoint & msg)
  : msg_(msg)
  {}
  Init_UTMPoint_zone_number northing(::custom_msgs::msg::UTMPoint::_northing_type arg)
  {
    msg_.northing = std::move(arg);
    return Init_UTMPoint_zone_number(msg_);
  }

private:
  ::custom_msgs::msg::UTMPoint msg_;
};

class Init_UTMPoint_easting
{
public:
  explicit Init_UTMPoint_easting(::custom_msgs::msg::UTMPoint & msg)
  : msg_(msg)
  {}
  Init_UTMPoint_northing easting(::custom_msgs::msg::UTMPoint::_easting_type arg)
  {
    msg_.easting = std::move(arg);
    return Init_UTMPoint_northing(msg_);
  }

private:
  ::custom_msgs::msg::UTMPoint msg_;
};

class Init_UTMPoint_header
{
public:
  Init_UTMPoint_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UTMPoint_easting header(::custom_msgs::msg::UTMPoint::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UTMPoint_easting(msg_);
  }

private:
  ::custom_msgs::msg::UTMPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::UTMPoint>()
{
  return custom_msgs::msg::builder::Init_UTMPoint_header();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__UTM_POINT__BUILDER_HPP_

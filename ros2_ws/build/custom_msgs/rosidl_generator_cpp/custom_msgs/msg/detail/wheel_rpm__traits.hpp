// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/WheelRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/wheel_rpm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const WheelRPM & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_rpm
  {
    out << "left_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.left_rpm, out);
    out << ", ";
  }

  // member: right_rpm
  {
    out << "right_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.right_rpm, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WheelRPM & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.left_rpm, out);
    out << "\n";
  }

  // member: right_rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.right_rpm, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WheelRPM & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::msg::WheelRPM & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::WheelRPM & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::WheelRPM>()
{
  return "custom_msgs::msg::WheelRPM";
}

template<>
inline const char * name<custom_msgs::msg::WheelRPM>()
{
  return "custom_msgs/msg/WheelRPM";
}

template<>
struct has_fixed_size<custom_msgs::msg::WheelRPM>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_msgs::msg::WheelRPM>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_msgs::msg::WheelRPM>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__WHEEL_RPM__TRAITS_HPP_

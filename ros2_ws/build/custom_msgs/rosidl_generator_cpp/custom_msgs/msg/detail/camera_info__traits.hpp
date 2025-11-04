// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/CameraInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/camera_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CameraInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: avg_distance
  {
    out << "avg_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_distance, out);
    out << ", ";
  }

  // member: image_count
  {
    out << "image_count: ";
    rosidl_generator_traits::value_to_yaml(msg.image_count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CameraInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: avg_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avg_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_distance, out);
    out << "\n";
  }

  // member: image_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image_count: ";
    rosidl_generator_traits::value_to_yaml(msg.image_count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CameraInfo & msg, bool use_flow_style = false)
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
  const custom_msgs::msg::CameraInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::CameraInfo & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::CameraInfo>()
{
  return "custom_msgs::msg::CameraInfo";
}

template<>
inline const char * name<custom_msgs::msg::CameraInfo>()
{
  return "custom_msgs/msg/CameraInfo";
}

template<>
struct has_fixed_size<custom_msgs::msg::CameraInfo>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_msgs::msg::CameraInfo>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_msgs::msg::CameraInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__CAMERA_INFO__TRAITS_HPP_

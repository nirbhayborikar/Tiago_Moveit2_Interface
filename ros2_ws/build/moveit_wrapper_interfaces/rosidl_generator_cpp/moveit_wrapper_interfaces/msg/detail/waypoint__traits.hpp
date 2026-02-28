// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_wrapper_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
#define MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_wrapper_interfaces/msg/detail/waypoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Waypoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: named_target
  {
    out << "named_target: ";
    rosidl_generator_traits::value_to_yaml(msg.named_target, out);
    out << ", ";
  }

  // member: linear_movement
  {
    out << "linear_movement: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_movement, out);
    out << ", ";
  }

  // member: linear_eef_step
  {
    out << "linear_eef_step: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_eef_step, out);
    out << ", ";
  }

  // member: linear_jump_thresh
  {
    out << "linear_jump_thresh: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_jump_thresh, out);
    out << ", ";
  }

  // member: linear_disable_collisions
  {
    out << "linear_disable_collisions: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_disable_collisions, out);
    out << ", ";
  }

  // member: path_constraints
  {
    out << "path_constraints: ";
    to_flow_style_yaml(msg.path_constraints, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Waypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: named_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "named_target: ";
    rosidl_generator_traits::value_to_yaml(msg.named_target, out);
    out << "\n";
  }

  // member: linear_movement
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_movement: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_movement, out);
    out << "\n";
  }

  // member: linear_eef_step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_eef_step: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_eef_step, out);
    out << "\n";
  }

  // member: linear_jump_thresh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_jump_thresh: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_jump_thresh, out);
    out << "\n";
  }

  // member: linear_disable_collisions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_disable_collisions: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_disable_collisions, out);
    out << "\n";
  }

  // member: path_constraints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_constraints:\n";
    to_block_style_yaml(msg.path_constraints, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Waypoint & msg, bool use_flow_style = false)
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

}  // namespace moveit_wrapper_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use moveit_wrapper_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const moveit_wrapper_interfaces::msg::Waypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::msg::Waypoint & msg)
{
  return moveit_wrapper_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::msg::Waypoint>()
{
  return "moveit_wrapper_interfaces::msg::Waypoint";
}

template<>
inline const char * name<moveit_wrapper_interfaces::msg::Waypoint>()
{
  return "moveit_wrapper_interfaces/msg/Waypoint";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::msg::Waypoint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::msg::Waypoint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::msg::Waypoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_

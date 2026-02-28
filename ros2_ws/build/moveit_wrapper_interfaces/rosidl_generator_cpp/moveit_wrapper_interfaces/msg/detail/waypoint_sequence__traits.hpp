// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__TRAITS_HPP_
#define MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoints'
#include "moveit_wrapper_interfaces/msg/detail/waypoint__traits.hpp"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const WaypointSequence & msg,
  std::ostream & out)
{
  out << "{";
  // member: sequence_id
  {
    out << "sequence_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence_id, out);
    out << ", ";
  }

  // member: waypoints
  {
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []";
    } else {
      out << "waypoints: [";
      size_t pending_items = msg.waypoints.size();
      for (auto item : msg.waypoints) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: path_constraints
  {
    out << "path_constraints: ";
    to_flow_style_yaml(msg.path_constraints, out);
    out << ", ";
  }

  // member: use_linear_interpolation
  {
    out << "use_linear_interpolation: ";
    rosidl_generator_traits::value_to_yaml(msg.use_linear_interpolation, out);
    out << ", ";
  }

  // member: velocity_scaling
  {
    out << "velocity_scaling: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_scaling, out);
    out << ", ";
  }

  // member: acceleration_scaling
  {
    out << "acceleration_scaling: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration_scaling, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WaypointSequence & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sequence_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sequence_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence_id, out);
    out << "\n";
  }

  // member: waypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []\n";
    } else {
      out << "waypoints:\n";
      for (auto item : msg.waypoints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: path_constraints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_constraints:\n";
    to_block_style_yaml(msg.path_constraints, out, indentation + 2);
  }

  // member: use_linear_interpolation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_linear_interpolation: ";
    rosidl_generator_traits::value_to_yaml(msg.use_linear_interpolation, out);
    out << "\n";
  }

  // member: velocity_scaling
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity_scaling: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_scaling, out);
    out << "\n";
  }

  // member: acceleration_scaling
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration_scaling: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration_scaling, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WaypointSequence & msg, bool use_flow_style = false)
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
  const moveit_wrapper_interfaces::msg::WaypointSequence & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::msg::WaypointSequence & msg)
{
  return moveit_wrapper_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::msg::WaypointSequence>()
{
  return "moveit_wrapper_interfaces::msg::WaypointSequence";
}

template<>
inline const char * name<moveit_wrapper_interfaces::msg::WaypointSequence>()
{
  return "moveit_wrapper_interfaces/msg/WaypointSequence";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::msg::WaypointSequence>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::msg::WaypointSequence>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::msg::WaypointSequence>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__TRAITS_HPP_

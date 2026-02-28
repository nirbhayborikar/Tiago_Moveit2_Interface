// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_wrapper_interfaces:srv/GetNamedTarget.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGET__TRAITS_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_wrapper_interfaces/srv/detail/get_named_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetNamedTarget_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: move_group
  {
    out << "move_group: ";
    rosidl_generator_traits::value_to_yaml(msg.move_group, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetNamedTarget_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: move_group
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_group: ";
    rosidl_generator_traits::value_to_yaml(msg.move_group, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetNamedTarget_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace moveit_wrapper_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use moveit_wrapper_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const moveit_wrapper_interfaces::srv::GetNamedTarget_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::srv::GetNamedTarget_Request & msg)
{
  return moveit_wrapper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::GetNamedTarget_Request>()
{
  return "moveit_wrapper_interfaces::srv::GetNamedTarget_Request";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::GetNamedTarget_Request>()
{
  return "moveit_wrapper_interfaces/srv/GetNamedTarget_Request";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::GetNamedTarget_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::GetNamedTarget_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::srv::GetNamedTarget_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'joint_state'
#include "sensor_msgs/msg/detail/joint_state__traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetNamedTarget_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: joint_state
  {
    out << "joint_state: ";
    to_flow_style_yaml(msg.joint_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetNamedTarget_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: joint_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_state:\n";
    to_block_style_yaml(msg.joint_state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetNamedTarget_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace moveit_wrapper_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use moveit_wrapper_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const moveit_wrapper_interfaces::srv::GetNamedTarget_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::srv::GetNamedTarget_Response & msg)
{
  return moveit_wrapper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::GetNamedTarget_Response>()
{
  return "moveit_wrapper_interfaces::srv::GetNamedTarget_Response";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::GetNamedTarget_Response>()
{
  return "moveit_wrapper_interfaces/srv/GetNamedTarget_Response";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::GetNamedTarget_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::GetNamedTarget_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::srv::GetNamedTarget_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::GetNamedTarget>()
{
  return "moveit_wrapper_interfaces::srv::GetNamedTarget";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::GetNamedTarget>()
{
  return "moveit_wrapper_interfaces/srv/GetNamedTarget";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::GetNamedTarget>
  : std::integral_constant<
    bool,
    has_fixed_size<moveit_wrapper_interfaces::srv::GetNamedTarget_Request>::value &&
    has_fixed_size<moveit_wrapper_interfaces::srv::GetNamedTarget_Response>::value
  >
{
};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::GetNamedTarget>
  : std::integral_constant<
    bool,
    has_bounded_size<moveit_wrapper_interfaces::srv::GetNamedTarget_Request>::value &&
    has_bounded_size<moveit_wrapper_interfaces::srv::GetNamedTarget_Response>::value
  >
{
};

template<>
struct is_service<moveit_wrapper_interfaces::srv::GetNamedTarget>
  : std::true_type
{
};

template<>
struct is_service_request<moveit_wrapper_interfaces::srv::GetNamedTarget_Request>
  : std::true_type
{
};

template<>
struct is_service_response<moveit_wrapper_interfaces::srv::GetNamedTarget_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGET__TRAITS_HPP_

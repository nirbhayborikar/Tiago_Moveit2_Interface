// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_wrapper_interfaces:srv/DettachObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__TRAITS_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_wrapper_interfaces/srv/detail/dettach_obj__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DettachObj_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: object_names
  {
    if (msg.object_names.size() == 0) {
      out << "object_names: []";
    } else {
      out << "object_names: [";
      size_t pending_items = msg.object_names.size();
      for (auto item : msg.object_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
  const DettachObj_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: object_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.object_names.size() == 0) {
      out << "object_names: []\n";
    } else {
      out << "object_names:\n";
      for (auto item : msg.object_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

inline std::string to_yaml(const DettachObj_Request & msg, bool use_flow_style = false)
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
  const moveit_wrapper_interfaces::srv::DettachObj_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::srv::DettachObj_Request & msg)
{
  return moveit_wrapper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::DettachObj_Request>()
{
  return "moveit_wrapper_interfaces::srv::DettachObj_Request";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::DettachObj_Request>()
{
  return "moveit_wrapper_interfaces/srv/DettachObj_Request";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::DettachObj_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::DettachObj_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::srv::DettachObj_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace moveit_wrapper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DettachObj_Response & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DettachObj_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DettachObj_Response & msg, bool use_flow_style = false)
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
  const moveit_wrapper_interfaces::srv::DettachObj_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::srv::DettachObj_Response & msg)
{
  return moveit_wrapper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::DettachObj_Response>()
{
  return "moveit_wrapper_interfaces::srv::DettachObj_Response";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::DettachObj_Response>()
{
  return "moveit_wrapper_interfaces/srv/DettachObj_Response";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::DettachObj_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::DettachObj_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::srv::DettachObj_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::DettachObj>()
{
  return "moveit_wrapper_interfaces::srv::DettachObj";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::DettachObj>()
{
  return "moveit_wrapper_interfaces/srv/DettachObj";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::DettachObj>
  : std::integral_constant<
    bool,
    has_fixed_size<moveit_wrapper_interfaces::srv::DettachObj_Request>::value &&
    has_fixed_size<moveit_wrapper_interfaces::srv::DettachObj_Response>::value
  >
{
};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::DettachObj>
  : std::integral_constant<
    bool,
    has_bounded_size<moveit_wrapper_interfaces::srv::DettachObj_Request>::value &&
    has_bounded_size<moveit_wrapper_interfaces::srv::DettachObj_Response>::value
  >
{
};

template<>
struct is_service<moveit_wrapper_interfaces::srv::DettachObj>
  : std::true_type
{
};

template<>
struct is_service_request<moveit_wrapper_interfaces::srv::DettachObj_Request>
  : std::true_type
{
};

template<>
struct is_service_response<moveit_wrapper_interfaces::srv::DettachObj_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_wrapper_interfaces:srv/GetColObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__TRAITS_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_wrapper_interfaces/srv/detail/get_col_obj__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetColObj_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetColObj_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetColObj_Request & msg, bool use_flow_style = false)
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
  const moveit_wrapper_interfaces::srv::GetColObj_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::srv::GetColObj_Request & msg)
{
  return moveit_wrapper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::GetColObj_Request>()
{
  return "moveit_wrapper_interfaces::srv::GetColObj_Request";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::GetColObj_Request>()
{
  return "moveit_wrapper_interfaces/srv/GetColObj_Request";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::GetColObj_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::GetColObj_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<moveit_wrapper_interfaces::srv::GetColObj_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'objects'
#include "visualization_msgs/msg/detail/marker__traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetColObj_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: objects
  {
    if (msg.objects.size() == 0) {
      out << "objects: []";
    } else {
      out << "objects: [";
      size_t pending_items = msg.objects.size();
      for (auto item : msg.objects) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

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
  const GetColObj_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.objects.size() == 0) {
      out << "objects: []\n";
    } else {
      out << "objects:\n";
      for (auto item : msg.objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

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

inline std::string to_yaml(const GetColObj_Response & msg, bool use_flow_style = false)
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
  const moveit_wrapper_interfaces::srv::GetColObj_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::srv::GetColObj_Response & msg)
{
  return moveit_wrapper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::GetColObj_Response>()
{
  return "moveit_wrapper_interfaces::srv::GetColObj_Response";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::GetColObj_Response>()
{
  return "moveit_wrapper_interfaces/srv/GetColObj_Response";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::GetColObj_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::GetColObj_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::srv::GetColObj_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::GetColObj>()
{
  return "moveit_wrapper_interfaces::srv::GetColObj";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::GetColObj>()
{
  return "moveit_wrapper_interfaces/srv/GetColObj";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::GetColObj>
  : std::integral_constant<
    bool,
    has_fixed_size<moveit_wrapper_interfaces::srv::GetColObj_Request>::value &&
    has_fixed_size<moveit_wrapper_interfaces::srv::GetColObj_Response>::value
  >
{
};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::GetColObj>
  : std::integral_constant<
    bool,
    has_bounded_size<moveit_wrapper_interfaces::srv::GetColObj_Request>::value &&
    has_bounded_size<moveit_wrapper_interfaces::srv::GetColObj_Response>::value
  >
{
};

template<>
struct is_service<moveit_wrapper_interfaces::srv::GetColObj>
  : std::true_type
{
};

template<>
struct is_service_request<moveit_wrapper_interfaces::srv::GetColObj_Request>
  : std::true_type
{
};

template<>
struct is_service_response<moveit_wrapper_interfaces::srv::GetColObj_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__TRAITS_HPP_

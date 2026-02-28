// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_wrapper_interfaces:srv/Plan.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN__TRAITS_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_wrapper_interfaces/srv/detail/plan__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoints'
#include "moveit_wrapper_interfaces/msg/detail/waypoint__traits.hpp"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__traits.hpp"
// Member 'start_state'
#include "moveit_msgs/msg/detail/robot_state__traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Plan_Request & msg,
  std::ostream & out)
{
  out << "{";
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

  // member: send_partial
  {
    out << "send_partial: ";
    rosidl_generator_traits::value_to_yaml(msg.send_partial, out);
    out << ", ";
  }

  // member: use_start_state
  {
    out << "use_start_state: ";
    rosidl_generator_traits::value_to_yaml(msg.use_start_state, out);
    out << ", ";
  }

  // member: start_state
  {
    out << "start_state: ";
    to_flow_style_yaml(msg.start_state, out);
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
  const Plan_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
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

  // member: send_partial
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "send_partial: ";
    rosidl_generator_traits::value_to_yaml(msg.send_partial, out);
    out << "\n";
  }

  // member: use_start_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_start_state: ";
    rosidl_generator_traits::value_to_yaml(msg.use_start_state, out);
    out << "\n";
  }

  // member: start_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_state:\n";
    to_block_style_yaml(msg.start_state, out, indentation + 2);
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

inline std::string to_yaml(const Plan_Request & msg, bool use_flow_style = false)
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
  const moveit_wrapper_interfaces::srv::Plan_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::srv::Plan_Request & msg)
{
  return moveit_wrapper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::Plan_Request>()
{
  return "moveit_wrapper_interfaces::srv::Plan_Request";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::Plan_Request>()
{
  return "moveit_wrapper_interfaces/srv/Plan_Request";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::Plan_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::Plan_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::srv::Plan_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'plans'
#include "moveit_msgs/msg/detail/robot_trajectory__traits.hpp"

namespace moveit_wrapper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Plan_Response & msg,
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

  // member: plans
  {
    if (msg.plans.size() == 0) {
      out << "plans: []";
    } else {
      out << "plans: [";
      size_t pending_items = msg.plans.size();
      for (auto item : msg.plans) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Plan_Response & msg,
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

  // member: plans
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.plans.size() == 0) {
      out << "plans: []\n";
    } else {
      out << "plans:\n";
      for (auto item : msg.plans) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Plan_Response & msg, bool use_flow_style = false)
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
  const moveit_wrapper_interfaces::srv::Plan_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_wrapper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_wrapper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_wrapper_interfaces::srv::Plan_Response & msg)
{
  return moveit_wrapper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::Plan_Response>()
{
  return "moveit_wrapper_interfaces::srv::Plan_Response";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::Plan_Response>()
{
  return "moveit_wrapper_interfaces/srv/Plan_Response";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::Plan_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::Plan_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_wrapper_interfaces::srv::Plan_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<moveit_wrapper_interfaces::srv::Plan>()
{
  return "moveit_wrapper_interfaces::srv::Plan";
}

template<>
inline const char * name<moveit_wrapper_interfaces::srv::Plan>()
{
  return "moveit_wrapper_interfaces/srv/Plan";
}

template<>
struct has_fixed_size<moveit_wrapper_interfaces::srv::Plan>
  : std::integral_constant<
    bool,
    has_fixed_size<moveit_wrapper_interfaces::srv::Plan_Request>::value &&
    has_fixed_size<moveit_wrapper_interfaces::srv::Plan_Response>::value
  >
{
};

template<>
struct has_bounded_size<moveit_wrapper_interfaces::srv::Plan>
  : std::integral_constant<
    bool,
    has_bounded_size<moveit_wrapper_interfaces::srv::Plan_Request>::value &&
    has_bounded_size<moveit_wrapper_interfaces::srv::Plan_Response>::value
  >
{
};

template<>
struct is_service<moveit_wrapper_interfaces::srv::Plan>
  : std::true_type
{
};

template<>
struct is_service_request<moveit_wrapper_interfaces::srv::Plan_Request>
  : std::true_type
{
};

template<>
struct is_service_response<moveit_wrapper_interfaces::srv::Plan_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN__TRAITS_HPP_

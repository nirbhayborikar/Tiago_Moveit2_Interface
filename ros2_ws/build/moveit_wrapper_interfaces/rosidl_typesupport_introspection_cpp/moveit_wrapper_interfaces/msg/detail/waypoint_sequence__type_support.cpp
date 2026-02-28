// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace moveit_wrapper_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void WaypointSequence_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) moveit_wrapper_interfaces::msg::WaypointSequence(_init);
}

void WaypointSequence_fini_function(void * message_memory)
{
  auto typed_message = static_cast<moveit_wrapper_interfaces::msg::WaypointSequence *>(message_memory);
  typed_message->~WaypointSequence();
}

size_t size_function__WaypointSequence__waypoints(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<moveit_wrapper_interfaces::msg::Waypoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__WaypointSequence__waypoints(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<moveit_wrapper_interfaces::msg::Waypoint> *>(untyped_member);
  return &member[index];
}

void * get_function__WaypointSequence__waypoints(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<moveit_wrapper_interfaces::msg::Waypoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__WaypointSequence__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const moveit_wrapper_interfaces::msg::Waypoint *>(
    get_const_function__WaypointSequence__waypoints(untyped_member, index));
  auto & value = *reinterpret_cast<moveit_wrapper_interfaces::msg::Waypoint *>(untyped_value);
  value = item;
}

void assign_function__WaypointSequence__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<moveit_wrapper_interfaces::msg::Waypoint *>(
    get_function__WaypointSequence__waypoints(untyped_member, index));
  const auto & value = *reinterpret_cast<const moveit_wrapper_interfaces::msg::Waypoint *>(untyped_value);
  item = value;
}

void resize_function__WaypointSequence__waypoints(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<moveit_wrapper_interfaces::msg::Waypoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WaypointSequence_message_member_array[6] = {
  {
    "sequence_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::msg::WaypointSequence, sequence_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<moveit_wrapper_interfaces::msg::Waypoint>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::msg::WaypointSequence, waypoints),  // bytes offset in struct
    nullptr,  // default value
    size_function__WaypointSequence__waypoints,  // size() function pointer
    get_const_function__WaypointSequence__waypoints,  // get_const(index) function pointer
    get_function__WaypointSequence__waypoints,  // get(index) function pointer
    fetch_function__WaypointSequence__waypoints,  // fetch(index, &value) function pointer
    assign_function__WaypointSequence__waypoints,  // assign(index, value) function pointer
    resize_function__WaypointSequence__waypoints  // resize(index) function pointer
  },
  {
    "path_constraints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<moveit_msgs::msg::Constraints>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::msg::WaypointSequence, path_constraints),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "use_linear_interpolation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::msg::WaypointSequence, use_linear_interpolation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "velocity_scaling",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::msg::WaypointSequence, velocity_scaling),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "acceleration_scaling",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::msg::WaypointSequence, acceleration_scaling),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WaypointSequence_message_members = {
  "moveit_wrapper_interfaces::msg",  // message namespace
  "WaypointSequence",  // message name
  6,  // number of fields
  sizeof(moveit_wrapper_interfaces::msg::WaypointSequence),
  WaypointSequence_message_member_array,  // message members
  WaypointSequence_init_function,  // function to initialize message memory (memory has to be allocated)
  WaypointSequence_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WaypointSequence_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WaypointSequence_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace moveit_wrapper_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<moveit_wrapper_interfaces::msg::WaypointSequence>()
{
  return &::moveit_wrapper_interfaces::msg::rosidl_typesupport_introspection_cpp::WaypointSequence_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, moveit_wrapper_interfaces, msg, WaypointSequence)() {
  return &::moveit_wrapper_interfaces::msg::rosidl_typesupport_introspection_cpp::WaypointSequence_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

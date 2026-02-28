// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from moveit_wrapper_interfaces:srv/ExecutePlans.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "moveit_wrapper_interfaces/srv/detail/execute_plans__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecutePlans_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) moveit_wrapper_interfaces::srv::ExecutePlans_Request(_init);
}

void ExecutePlans_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<moveit_wrapper_interfaces::srv::ExecutePlans_Request *>(message_memory);
  typed_message->~ExecutePlans_Request();
}

size_t size_function__ExecutePlans_Request__plans(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<moveit_msgs::msg::RobotTrajectory> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecutePlans_Request__plans(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<moveit_msgs::msg::RobotTrajectory> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecutePlans_Request__plans(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<moveit_msgs::msg::RobotTrajectory> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecutePlans_Request__plans(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const moveit_msgs::msg::RobotTrajectory *>(
    get_const_function__ExecutePlans_Request__plans(untyped_member, index));
  auto & value = *reinterpret_cast<moveit_msgs::msg::RobotTrajectory *>(untyped_value);
  value = item;
}

void assign_function__ExecutePlans_Request__plans(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<moveit_msgs::msg::RobotTrajectory *>(
    get_function__ExecutePlans_Request__plans(untyped_member, index));
  const auto & value = *reinterpret_cast<const moveit_msgs::msg::RobotTrajectory *>(untyped_value);
  item = value;
}

void resize_function__ExecutePlans_Request__plans(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<moveit_msgs::msg::RobotTrajectory> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecutePlans_Request_message_member_array[2] = {
  {
    "plans",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<moveit_msgs::msg::RobotTrajectory>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::srv::ExecutePlans_Request, plans),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecutePlans_Request__plans,  // size() function pointer
    get_const_function__ExecutePlans_Request__plans,  // get_const(index) function pointer
    get_function__ExecutePlans_Request__plans,  // get(index) function pointer
    fetch_function__ExecutePlans_Request__plans,  // fetch(index, &value) function pointer
    assign_function__ExecutePlans_Request__plans,  // assign(index, value) function pointer
    resize_function__ExecutePlans_Request__plans  // resize(index) function pointer
  },
  {
    "move_group",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::srv::ExecutePlans_Request, move_group),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecutePlans_Request_message_members = {
  "moveit_wrapper_interfaces::srv",  // message namespace
  "ExecutePlans_Request",  // message name
  2,  // number of fields
  sizeof(moveit_wrapper_interfaces::srv::ExecutePlans_Request),
  ExecutePlans_Request_message_member_array,  // message members
  ExecutePlans_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecutePlans_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecutePlans_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecutePlans_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace moveit_wrapper_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<moveit_wrapper_interfaces::srv::ExecutePlans_Request>()
{
  return &::moveit_wrapper_interfaces::srv::rosidl_typesupport_introspection_cpp::ExecutePlans_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, moveit_wrapper_interfaces, srv, ExecutePlans_Request)() {
  return &::moveit_wrapper_interfaces::srv::rosidl_typesupport_introspection_cpp::ExecutePlans_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "moveit_wrapper_interfaces/srv/detail/execute_plans__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecutePlans_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) moveit_wrapper_interfaces::srv::ExecutePlans_Response(_init);
}

void ExecutePlans_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<moveit_wrapper_interfaces::srv::ExecutePlans_Response *>(message_memory);
  typed_message->~ExecutePlans_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecutePlans_Response_message_member_array[2] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::srv::ExecutePlans_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces::srv::ExecutePlans_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecutePlans_Response_message_members = {
  "moveit_wrapper_interfaces::srv",  // message namespace
  "ExecutePlans_Response",  // message name
  2,  // number of fields
  sizeof(moveit_wrapper_interfaces::srv::ExecutePlans_Response),
  ExecutePlans_Response_message_member_array,  // message members
  ExecutePlans_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecutePlans_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecutePlans_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecutePlans_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace moveit_wrapper_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<moveit_wrapper_interfaces::srv::ExecutePlans_Response>()
{
  return &::moveit_wrapper_interfaces::srv::rosidl_typesupport_introspection_cpp::ExecutePlans_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, moveit_wrapper_interfaces, srv, ExecutePlans_Response)() {
  return &::moveit_wrapper_interfaces::srv::rosidl_typesupport_introspection_cpp::ExecutePlans_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "moveit_wrapper_interfaces/srv/detail/execute_plans__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ExecutePlans_service_members = {
  "moveit_wrapper_interfaces::srv",  // service namespace
  "ExecutePlans",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<moveit_wrapper_interfaces::srv::ExecutePlans>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t ExecutePlans_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecutePlans_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace moveit_wrapper_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<moveit_wrapper_interfaces::srv::ExecutePlans>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::moveit_wrapper_interfaces::srv::rosidl_typesupport_introspection_cpp::ExecutePlans_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::moveit_wrapper_interfaces::srv::ExecutePlans_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::moveit_wrapper_interfaces::srv::ExecutePlans_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, moveit_wrapper_interfaces, srv, ExecutePlans)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<moveit_wrapper_interfaces::srv::ExecutePlans>();
}

#ifdef __cplusplus
}
#endif

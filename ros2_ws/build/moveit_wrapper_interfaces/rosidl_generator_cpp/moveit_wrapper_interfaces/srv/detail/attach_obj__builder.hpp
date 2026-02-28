// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:srv/AttachObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ATTACH_OBJ__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ATTACH_OBJ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/srv/detail/attach_obj__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_AttachObj_Request_move_group
{
public:
  explicit Init_AttachObj_Request_move_group(::moveit_wrapper_interfaces::srv::AttachObj_Request & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::AttachObj_Request move_group(::moveit_wrapper_interfaces::srv::AttachObj_Request::_move_group_type arg)
  {
    msg_.move_group = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::AttachObj_Request msg_;
};

class Init_AttachObj_Request_object_names
{
public:
  Init_AttachObj_Request_object_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AttachObj_Request_move_group object_names(::moveit_wrapper_interfaces::srv::AttachObj_Request::_object_names_type arg)
  {
    msg_.object_names = std::move(arg);
    return Init_AttachObj_Request_move_group(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::AttachObj_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::AttachObj_Request>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_AttachObj_Request_object_names();
}

}  // namespace moveit_wrapper_interfaces


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_AttachObj_Response_message
{
public:
  explicit Init_AttachObj_Response_message(::moveit_wrapper_interfaces::srv::AttachObj_Response & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::AttachObj_Response message(::moveit_wrapper_interfaces::srv::AttachObj_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::AttachObj_Response msg_;
};

class Init_AttachObj_Response_success
{
public:
  Init_AttachObj_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AttachObj_Response_message success(::moveit_wrapper_interfaces::srv::AttachObj_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_AttachObj_Response_message(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::AttachObj_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::AttachObj_Response>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_AttachObj_Response_success();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ATTACH_OBJ__BUILDER_HPP_

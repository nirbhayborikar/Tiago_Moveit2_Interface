// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:srv/GotoNamedTarget.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GOTO_NAMED_TARGET__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GOTO_NAMED_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/srv/detail/goto_named_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_GotoNamedTarget_Request_move_group
{
public:
  explicit Init_GotoNamedTarget_Request_move_group(::moveit_wrapper_interfaces::srv::GotoNamedTarget_Request & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::GotoNamedTarget_Request move_group(::moveit_wrapper_interfaces::srv::GotoNamedTarget_Request::_move_group_type arg)
  {
    msg_.move_group = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::GotoNamedTarget_Request msg_;
};

class Init_GotoNamedTarget_Request_name
{
public:
  Init_GotoNamedTarget_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoNamedTarget_Request_move_group name(::moveit_wrapper_interfaces::srv::GotoNamedTarget_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_GotoNamedTarget_Request_move_group(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::GotoNamedTarget_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::GotoNamedTarget_Request>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_GotoNamedTarget_Request_name();
}

}  // namespace moveit_wrapper_interfaces


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_GotoNamedTarget_Response_message
{
public:
  explicit Init_GotoNamedTarget_Response_message(::moveit_wrapper_interfaces::srv::GotoNamedTarget_Response & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::GotoNamedTarget_Response message(::moveit_wrapper_interfaces::srv::GotoNamedTarget_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::GotoNamedTarget_Response msg_;
};

class Init_GotoNamedTarget_Response_success
{
public:
  Init_GotoNamedTarget_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoNamedTarget_Response_message success(::moveit_wrapper_interfaces::srv::GotoNamedTarget_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GotoNamedTarget_Response_message(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::GotoNamedTarget_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::GotoNamedTarget_Response>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_GotoNamedTarget_Response_success();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GOTO_NAMED_TARGET__BUILDER_HPP_

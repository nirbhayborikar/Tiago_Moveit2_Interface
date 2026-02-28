// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:srv/GetNamedTargets.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGETS__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGETS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/srv/detail/get_named_targets__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetNamedTargets_Request_move_group
{
public:
  Init_GetNamedTargets_Request_move_group()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::moveit_wrapper_interfaces::srv::GetNamedTargets_Request move_group(::moveit_wrapper_interfaces::srv::GetNamedTargets_Request::_move_group_type arg)
  {
    msg_.move_group = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::GetNamedTargets_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::GetNamedTargets_Request>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_GetNamedTargets_Request_move_group();
}

}  // namespace moveit_wrapper_interfaces


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetNamedTargets_Response_message
{
public:
  explicit Init_GetNamedTargets_Response_message(::moveit_wrapper_interfaces::srv::GetNamedTargets_Response & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::GetNamedTargets_Response message(::moveit_wrapper_interfaces::srv::GetNamedTargets_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::GetNamedTargets_Response msg_;
};

class Init_GetNamedTargets_Response_success
{
public:
  explicit Init_GetNamedTargets_Response_success(::moveit_wrapper_interfaces::srv::GetNamedTargets_Response & msg)
  : msg_(msg)
  {}
  Init_GetNamedTargets_Response_message success(::moveit_wrapper_interfaces::srv::GetNamedTargets_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetNamedTargets_Response_message(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::GetNamedTargets_Response msg_;
};

class Init_GetNamedTargets_Response_names
{
public:
  Init_GetNamedTargets_Response_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetNamedTargets_Response_success names(::moveit_wrapper_interfaces::srv::GetNamedTargets_Response::_names_type arg)
  {
    msg_.names = std::move(arg);
    return Init_GetNamedTargets_Response_success(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::GetNamedTargets_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::GetNamedTargets_Response>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_GetNamedTargets_Response_names();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGETS__BUILDER_HPP_

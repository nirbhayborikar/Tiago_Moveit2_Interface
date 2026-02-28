// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:srv/MoveTorso.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__MOVE_TORSO__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__MOVE_TORSO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/srv/detail/move_torso__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveTorso_Request_move_group
{
public:
  explicit Init_MoveTorso_Request_move_group(::moveit_wrapper_interfaces::srv::MoveTorso_Request & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::MoveTorso_Request move_group(::moveit_wrapper_interfaces::srv::MoveTorso_Request::_move_group_type arg)
  {
    msg_.move_group = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::MoveTorso_Request msg_;
};

class Init_MoveTorso_Request_relative
{
public:
  explicit Init_MoveTorso_Request_relative(::moveit_wrapper_interfaces::srv::MoveTorso_Request & msg)
  : msg_(msg)
  {}
  Init_MoveTorso_Request_move_group relative(::moveit_wrapper_interfaces::srv::MoveTorso_Request::_relative_type arg)
  {
    msg_.relative = std::move(arg);
    return Init_MoveTorso_Request_move_group(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::MoveTorso_Request msg_;
};

class Init_MoveTorso_Request_joint_value
{
public:
  Init_MoveTorso_Request_joint_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTorso_Request_relative joint_value(::moveit_wrapper_interfaces::srv::MoveTorso_Request::_joint_value_type arg)
  {
    msg_.joint_value = std::move(arg);
    return Init_MoveTorso_Request_relative(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::MoveTorso_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::MoveTorso_Request>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_MoveTorso_Request_joint_value();
}

}  // namespace moveit_wrapper_interfaces


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveTorso_Response_message
{
public:
  explicit Init_MoveTorso_Response_message(::moveit_wrapper_interfaces::srv::MoveTorso_Response & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::MoveTorso_Response message(::moveit_wrapper_interfaces::srv::MoveTorso_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::MoveTorso_Response msg_;
};

class Init_MoveTorso_Response_success
{
public:
  Init_MoveTorso_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTorso_Response_message success(::moveit_wrapper_interfaces::srv::MoveTorso_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveTorso_Response_message(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::MoveTorso_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::MoveTorso_Response>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_MoveTorso_Response_success();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__MOVE_TORSO__BUILDER_HPP_

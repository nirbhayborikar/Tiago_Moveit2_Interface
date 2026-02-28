// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:srv/DettachObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/srv/detail/dettach_obj__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_DettachObj_Request_move_group
{
public:
  explicit Init_DettachObj_Request_move_group(::moveit_wrapper_interfaces::srv::DettachObj_Request & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::DettachObj_Request move_group(::moveit_wrapper_interfaces::srv::DettachObj_Request::_move_group_type arg)
  {
    msg_.move_group = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::DettachObj_Request msg_;
};

class Init_DettachObj_Request_object_names
{
public:
  Init_DettachObj_Request_object_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DettachObj_Request_move_group object_names(::moveit_wrapper_interfaces::srv::DettachObj_Request::_object_names_type arg)
  {
    msg_.object_names = std::move(arg);
    return Init_DettachObj_Request_move_group(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::DettachObj_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::DettachObj_Request>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_DettachObj_Request_object_names();
}

}  // namespace moveit_wrapper_interfaces


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_DettachObj_Response_message
{
public:
  explicit Init_DettachObj_Response_message(::moveit_wrapper_interfaces::srv::DettachObj_Response & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::DettachObj_Response message(::moveit_wrapper_interfaces::srv::DettachObj_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::DettachObj_Response msg_;
};

class Init_DettachObj_Response_success
{
public:
  Init_DettachObj_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DettachObj_Response_message success(::moveit_wrapper_interfaces::srv::DettachObj_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DettachObj_Response_message(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::DettachObj_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::DettachObj_Response>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_DettachObj_Response_success();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:srv/AddColObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ADD_COL_OBJ__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ADD_COL_OBJ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/srv/detail/add_col_obj__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddColObj_Request_objects
{
public:
  Init_AddColObj_Request_objects()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::moveit_wrapper_interfaces::srv::AddColObj_Request objects(::moveit_wrapper_interfaces::srv::AddColObj_Request::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::AddColObj_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::AddColObj_Request>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_AddColObj_Request_objects();
}

}  // namespace moveit_wrapper_interfaces


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddColObj_Response_message
{
public:
  explicit Init_AddColObj_Response_message(::moveit_wrapper_interfaces::srv::AddColObj_Response & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::AddColObj_Response message(::moveit_wrapper_interfaces::srv::AddColObj_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::AddColObj_Response msg_;
};

class Init_AddColObj_Response_success
{
public:
  Init_AddColObj_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddColObj_Response_message success(::moveit_wrapper_interfaces::srv::AddColObj_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_AddColObj_Response_message(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::AddColObj_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::AddColObj_Response>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_AddColObj_Response_success();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ADD_COL_OBJ__BUILDER_HPP_

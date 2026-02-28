// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:srv/Plan.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/srv/detail/plan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_Plan_Request_move_group
{
public:
  explicit Init_Plan_Request_move_group(::moveit_wrapper_interfaces::srv::Plan_Request & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::Plan_Request move_group(::moveit_wrapper_interfaces::srv::Plan_Request::_move_group_type arg)
  {
    msg_.move_group = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Request msg_;
};

class Init_Plan_Request_start_state
{
public:
  explicit Init_Plan_Request_start_state(::moveit_wrapper_interfaces::srv::Plan_Request & msg)
  : msg_(msg)
  {}
  Init_Plan_Request_move_group start_state(::moveit_wrapper_interfaces::srv::Plan_Request::_start_state_type arg)
  {
    msg_.start_state = std::move(arg);
    return Init_Plan_Request_move_group(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Request msg_;
};

class Init_Plan_Request_use_start_state
{
public:
  explicit Init_Plan_Request_use_start_state(::moveit_wrapper_interfaces::srv::Plan_Request & msg)
  : msg_(msg)
  {}
  Init_Plan_Request_start_state use_start_state(::moveit_wrapper_interfaces::srv::Plan_Request::_use_start_state_type arg)
  {
    msg_.use_start_state = std::move(arg);
    return Init_Plan_Request_start_state(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Request msg_;
};

class Init_Plan_Request_send_partial
{
public:
  explicit Init_Plan_Request_send_partial(::moveit_wrapper_interfaces::srv::Plan_Request & msg)
  : msg_(msg)
  {}
  Init_Plan_Request_use_start_state send_partial(::moveit_wrapper_interfaces::srv::Plan_Request::_send_partial_type arg)
  {
    msg_.send_partial = std::move(arg);
    return Init_Plan_Request_use_start_state(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Request msg_;
};

class Init_Plan_Request_path_constraints
{
public:
  explicit Init_Plan_Request_path_constraints(::moveit_wrapper_interfaces::srv::Plan_Request & msg)
  : msg_(msg)
  {}
  Init_Plan_Request_send_partial path_constraints(::moveit_wrapper_interfaces::srv::Plan_Request::_path_constraints_type arg)
  {
    msg_.path_constraints = std::move(arg);
    return Init_Plan_Request_send_partial(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Request msg_;
};

class Init_Plan_Request_waypoints
{
public:
  Init_Plan_Request_waypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Plan_Request_path_constraints waypoints(::moveit_wrapper_interfaces::srv::Plan_Request::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return Init_Plan_Request_path_constraints(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::Plan_Request>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_Plan_Request_waypoints();
}

}  // namespace moveit_wrapper_interfaces


namespace moveit_wrapper_interfaces
{

namespace srv
{

namespace builder
{

class Init_Plan_Response_plans
{
public:
  explicit Init_Plan_Response_plans(::moveit_wrapper_interfaces::srv::Plan_Response & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::srv::Plan_Response plans(::moveit_wrapper_interfaces::srv::Plan_Response::_plans_type arg)
  {
    msg_.plans = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Response msg_;
};

class Init_Plan_Response_message
{
public:
  explicit Init_Plan_Response_message(::moveit_wrapper_interfaces::srv::Plan_Response & msg)
  : msg_(msg)
  {}
  Init_Plan_Response_plans message(::moveit_wrapper_interfaces::srv::Plan_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_Plan_Response_plans(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Response msg_;
};

class Init_Plan_Response_success
{
public:
  Init_Plan_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Plan_Response_message success(::moveit_wrapper_interfaces::srv::Plan_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Plan_Response_message(msg_);
  }

private:
  ::moveit_wrapper_interfaces::srv::Plan_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::srv::Plan_Response>()
{
  return moveit_wrapper_interfaces::srv::builder::Init_Plan_Response_success();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/msg/detail/waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace msg
{

namespace builder
{

class Init_Waypoint_path_constraints
{
public:
  explicit Init_Waypoint_path_constraints(::moveit_wrapper_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::msg::Waypoint path_constraints(::moveit_wrapper_interfaces::msg::Waypoint::_path_constraints_type arg)
  {
    msg_.path_constraints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_linear_disable_collisions
{
public:
  explicit Init_Waypoint_linear_disable_collisions(::moveit_wrapper_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_path_constraints linear_disable_collisions(::moveit_wrapper_interfaces::msg::Waypoint::_linear_disable_collisions_type arg)
  {
    msg_.linear_disable_collisions = std::move(arg);
    return Init_Waypoint_path_constraints(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_linear_jump_thresh
{
public:
  explicit Init_Waypoint_linear_jump_thresh(::moveit_wrapper_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_linear_disable_collisions linear_jump_thresh(::moveit_wrapper_interfaces::msg::Waypoint::_linear_jump_thresh_type arg)
  {
    msg_.linear_jump_thresh = std::move(arg);
    return Init_Waypoint_linear_disable_collisions(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_linear_eef_step
{
public:
  explicit Init_Waypoint_linear_eef_step(::moveit_wrapper_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_linear_jump_thresh linear_eef_step(::moveit_wrapper_interfaces::msg::Waypoint::_linear_eef_step_type arg)
  {
    msg_.linear_eef_step = std::move(arg);
    return Init_Waypoint_linear_jump_thresh(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_linear_movement
{
public:
  explicit Init_Waypoint_linear_movement(::moveit_wrapper_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_linear_eef_step linear_movement(::moveit_wrapper_interfaces::msg::Waypoint::_linear_movement_type arg)
  {
    msg_.linear_movement = std::move(arg);
    return Init_Waypoint_linear_eef_step(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_named_target
{
public:
  explicit Init_Waypoint_named_target(::moveit_wrapper_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_linear_movement named_target(::moveit_wrapper_interfaces::msg::Waypoint::_named_target_type arg)
  {
    msg_.named_target = std::move(arg);
    return Init_Waypoint_linear_movement(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_pose
{
public:
  Init_Waypoint_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Waypoint_named_target pose(::moveit_wrapper_interfaces::msg::Waypoint::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Waypoint_named_target(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::Waypoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::msg::Waypoint>()
{
  return moveit_wrapper_interfaces::msg::builder::Init_Waypoint_pose();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_

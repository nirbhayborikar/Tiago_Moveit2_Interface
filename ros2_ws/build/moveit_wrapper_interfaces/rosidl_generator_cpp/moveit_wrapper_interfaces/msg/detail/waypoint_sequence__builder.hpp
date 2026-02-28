// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__BUILDER_HPP_
#define MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_wrapper_interfaces
{

namespace msg
{

namespace builder
{

class Init_WaypointSequence_acceleration_scaling
{
public:
  explicit Init_WaypointSequence_acceleration_scaling(::moveit_wrapper_interfaces::msg::WaypointSequence & msg)
  : msg_(msg)
  {}
  ::moveit_wrapper_interfaces::msg::WaypointSequence acceleration_scaling(::moveit_wrapper_interfaces::msg::WaypointSequence::_acceleration_scaling_type arg)
  {
    msg_.acceleration_scaling = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::WaypointSequence msg_;
};

class Init_WaypointSequence_velocity_scaling
{
public:
  explicit Init_WaypointSequence_velocity_scaling(::moveit_wrapper_interfaces::msg::WaypointSequence & msg)
  : msg_(msg)
  {}
  Init_WaypointSequence_acceleration_scaling velocity_scaling(::moveit_wrapper_interfaces::msg::WaypointSequence::_velocity_scaling_type arg)
  {
    msg_.velocity_scaling = std::move(arg);
    return Init_WaypointSequence_acceleration_scaling(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::WaypointSequence msg_;
};

class Init_WaypointSequence_use_linear_interpolation
{
public:
  explicit Init_WaypointSequence_use_linear_interpolation(::moveit_wrapper_interfaces::msg::WaypointSequence & msg)
  : msg_(msg)
  {}
  Init_WaypointSequence_velocity_scaling use_linear_interpolation(::moveit_wrapper_interfaces::msg::WaypointSequence::_use_linear_interpolation_type arg)
  {
    msg_.use_linear_interpolation = std::move(arg);
    return Init_WaypointSequence_velocity_scaling(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::WaypointSequence msg_;
};

class Init_WaypointSequence_path_constraints
{
public:
  explicit Init_WaypointSequence_path_constraints(::moveit_wrapper_interfaces::msg::WaypointSequence & msg)
  : msg_(msg)
  {}
  Init_WaypointSequence_use_linear_interpolation path_constraints(::moveit_wrapper_interfaces::msg::WaypointSequence::_path_constraints_type arg)
  {
    msg_.path_constraints = std::move(arg);
    return Init_WaypointSequence_use_linear_interpolation(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::WaypointSequence msg_;
};

class Init_WaypointSequence_waypoints
{
public:
  explicit Init_WaypointSequence_waypoints(::moveit_wrapper_interfaces::msg::WaypointSequence & msg)
  : msg_(msg)
  {}
  Init_WaypointSequence_path_constraints waypoints(::moveit_wrapper_interfaces::msg::WaypointSequence::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return Init_WaypointSequence_path_constraints(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::WaypointSequence msg_;
};

class Init_WaypointSequence_sequence_id
{
public:
  Init_WaypointSequence_sequence_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WaypointSequence_waypoints sequence_id(::moveit_wrapper_interfaces::msg::WaypointSequence::_sequence_id_type arg)
  {
    msg_.sequence_id = std::move(arg);
    return Init_WaypointSequence_waypoints(msg_);
  }

private:
  ::moveit_wrapper_interfaces::msg::WaypointSequence msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_wrapper_interfaces::msg::WaypointSequence>()
{
  return moveit_wrapper_interfaces::msg::builder::Init_WaypointSequence_sequence_id();
}

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__BUILDER_HPP_

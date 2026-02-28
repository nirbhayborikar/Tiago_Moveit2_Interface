// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/DriveToWallT.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/drive_to_wall_t__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_DriveToWallT_min_distance
{
public:
  explicit Init_DriveToWallT_min_distance(::custom_interfaces::msg::DriveToWallT & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::DriveToWallT min_distance(::custom_interfaces::msg::DriveToWallT::_min_distance_type arg)
  {
    msg_.min_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::DriveToWallT msg_;
};

class Init_DriveToWallT_linear_x
{
public:
  Init_DriveToWallT_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallT_min_distance linear_x(::custom_interfaces::msg::DriveToWallT::_linear_x_type arg)
  {
    msg_.linear_x = std::move(arg);
    return Init_DriveToWallT_min_distance(msg_);
  }

private:
  ::custom_interfaces::msg::DriveToWallT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::DriveToWallT>()
{
  return custom_interfaces::msg::builder::Init_DriveToWallT_linear_x();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/DriveToWallS.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__DRIVE_TO_WALL_S__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__DRIVE_TO_WALL_S__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/drive_to_wall_s__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_DriveToWallS_Request_min_distance
{
public:
  explicit Init_DriveToWallS_Request_min_distance(::custom_interfaces::srv::DriveToWallS_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::DriveToWallS_Request min_distance(::custom_interfaces::srv::DriveToWallS_Request::_min_distance_type arg)
  {
    msg_.min_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::DriveToWallS_Request msg_;
};

class Init_DriveToWallS_Request_linear_x
{
public:
  Init_DriveToWallS_Request_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallS_Request_min_distance linear_x(::custom_interfaces::srv::DriveToWallS_Request::_linear_x_type arg)
  {
    msg_.linear_x = std::move(arg);
    return Init_DriveToWallS_Request_min_distance(msg_);
  }

private:
  ::custom_interfaces::srv::DriveToWallS_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::DriveToWallS_Request>()
{
  return custom_interfaces::srv::builder::Init_DriveToWallS_Request_linear_x();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_DriveToWallS_Response_success
{
public:
  explicit Init_DriveToWallS_Response_success(::custom_interfaces::srv::DriveToWallS_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::DriveToWallS_Response success(::custom_interfaces::srv::DriveToWallS_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::DriveToWallS_Response msg_;
};

class Init_DriveToWallS_Response_message
{
public:
  Init_DriveToWallS_Response_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallS_Response_success message(::custom_interfaces::srv::DriveToWallS_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_DriveToWallS_Response_success(msg_);
  }

private:
  ::custom_interfaces::srv::DriveToWallS_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::DriveToWallS_Response>()
{
  return custom_interfaces::srv::builder::Init_DriveToWallS_Response_message();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__DRIVE_TO_WALL_S__BUILDER_HPP_

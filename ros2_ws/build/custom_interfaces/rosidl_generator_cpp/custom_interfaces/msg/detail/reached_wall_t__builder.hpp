// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/ReachedWallT.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__REACHED_WALL_T__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__REACHED_WALL_T__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/reached_wall_t__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_ReachedWallT_success
{
public:
  explicit Init_ReachedWallT_success(::custom_interfaces::msg::ReachedWallT & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::ReachedWallT success(::custom_interfaces::msg::ReachedWallT::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::ReachedWallT msg_;
};

class Init_ReachedWallT_message
{
public:
  Init_ReachedWallT_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReachedWallT_success message(::custom_interfaces::msg::ReachedWallT::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ReachedWallT_success(msg_);
  }

private:
  ::custom_interfaces::msg::ReachedWallT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::ReachedWallT>()
{
  return custom_interfaces::msg::builder::Init_ReachedWallT_message();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__REACHED_WALL_T__BUILDER_HPP_

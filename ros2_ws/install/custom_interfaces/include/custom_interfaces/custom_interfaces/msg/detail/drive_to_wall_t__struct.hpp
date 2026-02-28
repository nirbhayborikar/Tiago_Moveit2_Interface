// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/DriveToWallT.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__DriveToWallT __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__DriveToWallT __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DriveToWallT_
{
  using Type = DriveToWallT_<ContainerAllocator>;

  explicit DriveToWallT_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->min_distance = 0.0;
    }
  }

  explicit DriveToWallT_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->min_distance = 0.0;
    }
  }

  // field types and members
  using _linear_x_type =
    double;
  _linear_x_type linear_x;
  using _min_distance_type =
    double;
  _min_distance_type min_distance;

  // setters for named parameter idiom
  Type & set__linear_x(
    const double & _arg)
  {
    this->linear_x = _arg;
    return *this;
  }
  Type & set__min_distance(
    const double & _arg)
  {
    this->min_distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::DriveToWallT_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::DriveToWallT_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::DriveToWallT_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::DriveToWallT_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::DriveToWallT_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::DriveToWallT_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::DriveToWallT_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::DriveToWallT_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::DriveToWallT_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::DriveToWallT_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__DriveToWallT
    std::shared_ptr<custom_interfaces::msg::DriveToWallT_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__DriveToWallT
    std::shared_ptr<custom_interfaces::msg::DriveToWallT_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DriveToWallT_ & other) const
  {
    if (this->linear_x != other.linear_x) {
      return false;
    }
    if (this->min_distance != other.min_distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const DriveToWallT_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DriveToWallT_

// alias to use template instance with default allocator
using DriveToWallT =
  custom_interfaces::msg::DriveToWallT_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/DriveToWallS.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__DRIVE_TO_WALL_S__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__DRIVE_TO_WALL_S__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__DriveToWallS_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__DriveToWallS_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DriveToWallS_Request_
{
  using Type = DriveToWallS_Request_<ContainerAllocator>;

  explicit DriveToWallS_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->min_distance = 0.0;
    }
  }

  explicit DriveToWallS_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__DriveToWallS_Request
    std::shared_ptr<custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__DriveToWallS_Request
    std::shared_ptr<custom_interfaces::srv::DriveToWallS_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DriveToWallS_Request_ & other) const
  {
    if (this->linear_x != other.linear_x) {
      return false;
    }
    if (this->min_distance != other.min_distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const DriveToWallS_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DriveToWallS_Request_

// alias to use template instance with default allocator
using DriveToWallS_Request =
  custom_interfaces::srv::DriveToWallS_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__DriveToWallS_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__DriveToWallS_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DriveToWallS_Response_
{
  using Type = DriveToWallS_Response_<ContainerAllocator>;

  explicit DriveToWallS_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->success = false;
    }
  }

  explicit DriveToWallS_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->success = false;
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__DriveToWallS_Response
    std::shared_ptr<custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__DriveToWallS_Response
    std::shared_ptr<custom_interfaces::srv::DriveToWallS_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DriveToWallS_Response_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const DriveToWallS_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DriveToWallS_Response_

// alias to use template instance with default allocator
using DriveToWallS_Response =
  custom_interfaces::srv::DriveToWallS_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct DriveToWallS
{
  using Request = custom_interfaces::srv::DriveToWallS_Request;
  using Response = custom_interfaces::srv::DriveToWallS_Response;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__DRIVE_TO_WALL_S__STRUCT_HPP_

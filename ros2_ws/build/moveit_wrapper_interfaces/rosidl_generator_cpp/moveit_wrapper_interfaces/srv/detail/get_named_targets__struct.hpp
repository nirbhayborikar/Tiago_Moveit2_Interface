// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_wrapper_interfaces:srv/GetNamedTargets.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGETS__STRUCT_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGETS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__moveit_wrapper_interfaces__srv__GetNamedTargets_Request __attribute__((deprecated))
#else
# define DEPRECATED__moveit_wrapper_interfaces__srv__GetNamedTargets_Request __declspec(deprecated)
#endif

namespace moveit_wrapper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetNamedTargets_Request_
{
  using Type = GetNamedTargets_Request_<ContainerAllocator>;

  explicit GetNamedTargets_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_group = "";
    }
  }

  explicit GetNamedTargets_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : move_group(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_group = "";
    }
  }

  // field types and members
  using _move_group_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _move_group_type move_group;

  // setters for named parameter idiom
  Type & set__move_group(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->move_group = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__GetNamedTargets_Request
    std::shared_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__GetNamedTargets_Request
    std::shared_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetNamedTargets_Request_ & other) const
  {
    if (this->move_group != other.move_group) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetNamedTargets_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetNamedTargets_Request_

// alias to use template instance with default allocator
using GetNamedTargets_Request =
  moveit_wrapper_interfaces::srv::GetNamedTargets_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace moveit_wrapper_interfaces


#ifndef _WIN32
# define DEPRECATED__moveit_wrapper_interfaces__srv__GetNamedTargets_Response __attribute__((deprecated))
#else
# define DEPRECATED__moveit_wrapper_interfaces__srv__GetNamedTargets_Response __declspec(deprecated)
#endif

namespace moveit_wrapper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetNamedTargets_Response_
{
  using Type = GetNamedTargets_Response_<ContainerAllocator>;

  explicit GetNamedTargets_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit GetNamedTargets_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _names_type names;
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->names = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__GetNamedTargets_Response
    std::shared_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__GetNamedTargets_Response
    std::shared_ptr<moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetNamedTargets_Response_ & other) const
  {
    if (this->names != other.names) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetNamedTargets_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetNamedTargets_Response_

// alias to use template instance with default allocator
using GetNamedTargets_Response =
  moveit_wrapper_interfaces::srv::GetNamedTargets_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace moveit_wrapper_interfaces

namespace moveit_wrapper_interfaces
{

namespace srv
{

struct GetNamedTargets
{
  using Request = moveit_wrapper_interfaces::srv::GetNamedTargets_Request;
  using Response = moveit_wrapper_interfaces::srv::GetNamedTargets_Response;
};

}  // namespace srv

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGETS__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_wrapper_interfaces:srv/AttachObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ATTACH_OBJ__STRUCT_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ATTACH_OBJ__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__moveit_wrapper_interfaces__srv__AttachObj_Request __attribute__((deprecated))
#else
# define DEPRECATED__moveit_wrapper_interfaces__srv__AttachObj_Request __declspec(deprecated)
#endif

namespace moveit_wrapper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AttachObj_Request_
{
  using Type = AttachObj_Request_<ContainerAllocator>;

  explicit AttachObj_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_group = "";
    }
  }

  explicit AttachObj_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : move_group(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_group = "";
    }
  }

  // field types and members
  using _object_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _object_names_type object_names;
  using _move_group_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _move_group_type move_group;

  // setters for named parameter idiom
  Type & set__object_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->object_names = _arg;
    return *this;
  }
  Type & set__move_group(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->move_group = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__AttachObj_Request
    std::shared_ptr<moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__AttachObj_Request
    std::shared_ptr<moveit_wrapper_interfaces::srv::AttachObj_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AttachObj_Request_ & other) const
  {
    if (this->object_names != other.object_names) {
      return false;
    }
    if (this->move_group != other.move_group) {
      return false;
    }
    return true;
  }
  bool operator!=(const AttachObj_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AttachObj_Request_

// alias to use template instance with default allocator
using AttachObj_Request =
  moveit_wrapper_interfaces::srv::AttachObj_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace moveit_wrapper_interfaces


#ifndef _WIN32
# define DEPRECATED__moveit_wrapper_interfaces__srv__AttachObj_Response __attribute__((deprecated))
#else
# define DEPRECATED__moveit_wrapper_interfaces__srv__AttachObj_Response __declspec(deprecated)
#endif

namespace moveit_wrapper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AttachObj_Response_
{
  using Type = AttachObj_Response_<ContainerAllocator>;

  explicit AttachObj_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit AttachObj_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
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
    moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__AttachObj_Response
    std::shared_ptr<moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__AttachObj_Response
    std::shared_ptr<moveit_wrapper_interfaces::srv::AttachObj_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AttachObj_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const AttachObj_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AttachObj_Response_

// alias to use template instance with default allocator
using AttachObj_Response =
  moveit_wrapper_interfaces::srv::AttachObj_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace moveit_wrapper_interfaces

namespace moveit_wrapper_interfaces
{

namespace srv
{

struct AttachObj
{
  using Request = moveit_wrapper_interfaces::srv::AttachObj_Request;
  using Response = moveit_wrapper_interfaces::srv::AttachObj_Response;
};

}  // namespace srv

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__ATTACH_OBJ__STRUCT_HPP_

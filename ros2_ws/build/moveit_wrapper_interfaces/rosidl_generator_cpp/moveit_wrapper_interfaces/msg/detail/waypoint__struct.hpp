// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_wrapper_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_
#define MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_wrapper_interfaces__msg__Waypoint __attribute__((deprecated))
#else
# define DEPRECATED__moveit_wrapper_interfaces__msg__Waypoint __declspec(deprecated)
#endif

namespace moveit_wrapper_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Waypoint_
{
  using Type = Waypoint_<ContainerAllocator>;

  explicit Waypoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    path_constraints(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->named_target = "";
      this->linear_movement = false;
      this->linear_eef_step = 0.0f;
      this->linear_jump_thresh = 0.0f;
      this->linear_disable_collisions = false;
    }
  }

  explicit Waypoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init),
    named_target(_alloc),
    path_constraints(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->named_target = "";
      this->linear_movement = false;
      this->linear_eef_step = 0.0f;
      this->linear_jump_thresh = 0.0f;
      this->linear_disable_collisions = false;
    }
  }

  // field types and members
  using _pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_type pose;
  using _named_target_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _named_target_type named_target;
  using _linear_movement_type =
    bool;
  _linear_movement_type linear_movement;
  using _linear_eef_step_type =
    float;
  _linear_eef_step_type linear_eef_step;
  using _linear_jump_thresh_type =
    float;
  _linear_jump_thresh_type linear_jump_thresh;
  using _linear_disable_collisions_type =
    bool;
  _linear_disable_collisions_type linear_disable_collisions;
  using _path_constraints_type =
    moveit_msgs::msg::Constraints_<ContainerAllocator>;
  _path_constraints_type path_constraints;

  // setters for named parameter idiom
  Type & set__pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__named_target(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->named_target = _arg;
    return *this;
  }
  Type & set__linear_movement(
    const bool & _arg)
  {
    this->linear_movement = _arg;
    return *this;
  }
  Type & set__linear_eef_step(
    const float & _arg)
  {
    this->linear_eef_step = _arg;
    return *this;
  }
  Type & set__linear_jump_thresh(
    const float & _arg)
  {
    this->linear_jump_thresh = _arg;
    return *this;
  }
  Type & set__linear_disable_collisions(
    const bool & _arg)
  {
    this->linear_disable_collisions = _arg;
    return *this;
  }
  Type & set__path_constraints(
    const moveit_msgs::msg::Constraints_<ContainerAllocator> & _arg)
  {
    this->path_constraints = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_wrapper_interfaces__msg__Waypoint
    std::shared_ptr<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_wrapper_interfaces__msg__Waypoint
    std::shared_ptr<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Waypoint_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->named_target != other.named_target) {
      return false;
    }
    if (this->linear_movement != other.linear_movement) {
      return false;
    }
    if (this->linear_eef_step != other.linear_eef_step) {
      return false;
    }
    if (this->linear_jump_thresh != other.linear_jump_thresh) {
      return false;
    }
    if (this->linear_disable_collisions != other.linear_disable_collisions) {
      return false;
    }
    if (this->path_constraints != other.path_constraints) {
      return false;
    }
    return true;
  }
  bool operator!=(const Waypoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Waypoint_

// alias to use template instance with default allocator
using Waypoint =
  moveit_wrapper_interfaces::msg::Waypoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_

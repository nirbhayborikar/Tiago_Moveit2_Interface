// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__STRUCT_HPP_
#define MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'waypoints'
#include "moveit_wrapper_interfaces/msg/detail/waypoint__struct.hpp"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_wrapper_interfaces__msg__WaypointSequence __attribute__((deprecated))
#else
# define DEPRECATED__moveit_wrapper_interfaces__msg__WaypointSequence __declspec(deprecated)
#endif

namespace moveit_wrapper_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WaypointSequence_
{
  using Type = WaypointSequence_<ContainerAllocator>;

  explicit WaypointSequence_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path_constraints(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sequence_id = "";
      this->use_linear_interpolation = false;
      this->velocity_scaling = 0.0;
      this->acceleration_scaling = 0.0;
    }
  }

  explicit WaypointSequence_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sequence_id(_alloc),
    path_constraints(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sequence_id = "";
      this->use_linear_interpolation = false;
      this->velocity_scaling = 0.0;
      this->acceleration_scaling = 0.0;
    }
  }

  // field types and members
  using _sequence_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sequence_id_type sequence_id;
  using _waypoints_type =
    std::vector<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>>>;
  _waypoints_type waypoints;
  using _path_constraints_type =
    moveit_msgs::msg::Constraints_<ContainerAllocator>;
  _path_constraints_type path_constraints;
  using _use_linear_interpolation_type =
    bool;
  _use_linear_interpolation_type use_linear_interpolation;
  using _velocity_scaling_type =
    double;
  _velocity_scaling_type velocity_scaling;
  using _acceleration_scaling_type =
    double;
  _acceleration_scaling_type acceleration_scaling;

  // setters for named parameter idiom
  Type & set__sequence_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sequence_id = _arg;
    return *this;
  }
  Type & set__waypoints(
    const std::vector<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<moveit_wrapper_interfaces::msg::Waypoint_<ContainerAllocator>>> & _arg)
  {
    this->waypoints = _arg;
    return *this;
  }
  Type & set__path_constraints(
    const moveit_msgs::msg::Constraints_<ContainerAllocator> & _arg)
  {
    this->path_constraints = _arg;
    return *this;
  }
  Type & set__use_linear_interpolation(
    const bool & _arg)
  {
    this->use_linear_interpolation = _arg;
    return *this;
  }
  Type & set__velocity_scaling(
    const double & _arg)
  {
    this->velocity_scaling = _arg;
    return *this;
  }
  Type & set__acceleration_scaling(
    const double & _arg)
  {
    this->acceleration_scaling = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_wrapper_interfaces__msg__WaypointSequence
    std::shared_ptr<moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_wrapper_interfaces__msg__WaypointSequence
    std::shared_ptr<moveit_wrapper_interfaces::msg::WaypointSequence_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WaypointSequence_ & other) const
  {
    if (this->sequence_id != other.sequence_id) {
      return false;
    }
    if (this->waypoints != other.waypoints) {
      return false;
    }
    if (this->path_constraints != other.path_constraints) {
      return false;
    }
    if (this->use_linear_interpolation != other.use_linear_interpolation) {
      return false;
    }
    if (this->velocity_scaling != other.velocity_scaling) {
      return false;
    }
    if (this->acceleration_scaling != other.acceleration_scaling) {
      return false;
    }
    return true;
  }
  bool operator!=(const WaypointSequence_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WaypointSequence_

// alias to use template instance with default allocator
using WaypointSequence =
  moveit_wrapper_interfaces::msg::WaypointSequence_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_wrapper_interfaces:srv/PlanJoints.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN_JOINTS__STRUCT_HPP_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN_JOINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'joint_states'
#include "sensor_msgs/msg/detail/joint_state__struct.hpp"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__struct.hpp"
// Member 'start_state'
#include "moveit_msgs/msg/detail/robot_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_wrapper_interfaces__srv__PlanJoints_Request __attribute__((deprecated))
#else
# define DEPRECATED__moveit_wrapper_interfaces__srv__PlanJoints_Request __declspec(deprecated)
#endif

namespace moveit_wrapper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PlanJoints_Request_
{
  using Type = PlanJoints_Request_<ContainerAllocator>;

  explicit PlanJoints_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path_constraints(_init),
    start_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_partial = false;
      this->use_start_state = false;
      this->move_group = "";
    }
  }

  explicit PlanJoints_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path_constraints(_alloc, _init),
    start_state(_alloc, _init),
    move_group(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_partial = false;
      this->use_start_state = false;
      this->move_group = "";
    }
  }

  // field types and members
  using _joint_states_type =
    std::vector<sensor_msgs::msg::JointState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::JointState_<ContainerAllocator>>>;
  _joint_states_type joint_states;
  using _path_constraints_type =
    moveit_msgs::msg::Constraints_<ContainerAllocator>;
  _path_constraints_type path_constraints;
  using _send_partial_type =
    bool;
  _send_partial_type send_partial;
  using _use_start_state_type =
    bool;
  _use_start_state_type use_start_state;
  using _start_state_type =
    moveit_msgs::msg::RobotState_<ContainerAllocator>;
  _start_state_type start_state;
  using _move_group_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _move_group_type move_group;

  // setters for named parameter idiom
  Type & set__joint_states(
    const std::vector<sensor_msgs::msg::JointState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::JointState_<ContainerAllocator>>> & _arg)
  {
    this->joint_states = _arg;
    return *this;
  }
  Type & set__path_constraints(
    const moveit_msgs::msg::Constraints_<ContainerAllocator> & _arg)
  {
    this->path_constraints = _arg;
    return *this;
  }
  Type & set__send_partial(
    const bool & _arg)
  {
    this->send_partial = _arg;
    return *this;
  }
  Type & set__use_start_state(
    const bool & _arg)
  {
    this->use_start_state = _arg;
    return *this;
  }
  Type & set__start_state(
    const moveit_msgs::msg::RobotState_<ContainerAllocator> & _arg)
  {
    this->start_state = _arg;
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
    moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__PlanJoints_Request
    std::shared_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__PlanJoints_Request
    std::shared_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanJoints_Request_ & other) const
  {
    if (this->joint_states != other.joint_states) {
      return false;
    }
    if (this->path_constraints != other.path_constraints) {
      return false;
    }
    if (this->send_partial != other.send_partial) {
      return false;
    }
    if (this->use_start_state != other.use_start_state) {
      return false;
    }
    if (this->start_state != other.start_state) {
      return false;
    }
    if (this->move_group != other.move_group) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanJoints_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanJoints_Request_

// alias to use template instance with default allocator
using PlanJoints_Request =
  moveit_wrapper_interfaces::srv::PlanJoints_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace moveit_wrapper_interfaces


// Include directives for member types
// Member 'plans'
#include "moveit_msgs/msg/detail/robot_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_wrapper_interfaces__srv__PlanJoints_Response __attribute__((deprecated))
#else
# define DEPRECATED__moveit_wrapper_interfaces__srv__PlanJoints_Response __declspec(deprecated)
#endif

namespace moveit_wrapper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PlanJoints_Response_
{
  using Type = PlanJoints_Response_<ContainerAllocator>;

  explicit PlanJoints_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit PlanJoints_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
  using _plans_type =
    std::vector<moveit_msgs::msg::RobotTrajectory_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<moveit_msgs::msg::RobotTrajectory_<ContainerAllocator>>>;
  _plans_type plans;

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
  Type & set__plans(
    const std::vector<moveit_msgs::msg::RobotTrajectory_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<moveit_msgs::msg::RobotTrajectory_<ContainerAllocator>>> & _arg)
  {
    this->plans = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__PlanJoints_Response
    std::shared_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_wrapper_interfaces__srv__PlanJoints_Response
    std::shared_ptr<moveit_wrapper_interfaces::srv::PlanJoints_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanJoints_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->plans != other.plans) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanJoints_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanJoints_Response_

// alias to use template instance with default allocator
using PlanJoints_Response =
  moveit_wrapper_interfaces::srv::PlanJoints_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace moveit_wrapper_interfaces

namespace moveit_wrapper_interfaces
{

namespace srv
{

struct PlanJoints
{
  using Request = moveit_wrapper_interfaces::srv::PlanJoints_Request;
  using Response = moveit_wrapper_interfaces::srv::PlanJoints_Response;
};

}  // namespace srv

}  // namespace moveit_wrapper_interfaces

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN_JOINTS__STRUCT_HPP_

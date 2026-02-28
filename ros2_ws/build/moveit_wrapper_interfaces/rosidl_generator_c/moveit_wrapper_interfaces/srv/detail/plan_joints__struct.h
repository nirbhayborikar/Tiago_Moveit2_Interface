// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_wrapper_interfaces:srv/PlanJoints.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN_JOINTS__STRUCT_H_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN_JOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_states'
#include "sensor_msgs/msg/detail/joint_state__struct.h"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__struct.h"
// Member 'start_state'
#include "moveit_msgs/msg/detail/robot_state__struct.h"
// Member 'move_group'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/PlanJoints in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__srv__PlanJoints_Request
{
  sensor_msgs__msg__JointState__Sequence joint_states;
  /// list of global constraints for this movement, each waypoint can have additional constraints
  moveit_msgs__msg__Constraints path_constraints;
  /// If set to true and there is an error while planing, the response contain the plan until the error
  bool send_partial;
  /// if true start_state will be used as the starting state
  bool use_start_state;
  moveit_msgs__msg__RobotState start_state;
  rosidl_runtime_c__String move_group;
} moveit_wrapper_interfaces__srv__PlanJoints_Request;

// Struct for a sequence of moveit_wrapper_interfaces__srv__PlanJoints_Request.
typedef struct moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence
{
  moveit_wrapper_interfaces__srv__PlanJoints_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'plans'
#include "moveit_msgs/msg/detail/robot_trajectory__struct.h"

/// Struct defined in srv/PlanJoints in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__srv__PlanJoints_Response
{
  bool success;
  rosidl_runtime_c__String message;
  /// list of plans, each plan describes the trajectory between two waypoints
  moveit_msgs__msg__RobotTrajectory__Sequence plans;
} moveit_wrapper_interfaces__srv__PlanJoints_Response;

// Struct for a sequence of moveit_wrapper_interfaces__srv__PlanJoints_Response.
typedef struct moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence
{
  moveit_wrapper_interfaces__srv__PlanJoints_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__PLAN_JOINTS__STRUCT_H_

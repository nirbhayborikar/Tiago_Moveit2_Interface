// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_wrapper_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_
#define MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'named_target'
#include "rosidl_runtime_c/string.h"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__struct.h"

/// Struct defined in msg/Waypoint in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__msg__Waypoint
{
  /// pose of waypoint, used when named_target is empty
  geometry_msgs__msg__PoseStamped pose;
  /// robot states available as targets, both either remembered states or default states from srdf.
  rosidl_runtime_c__String named_target;
  ///  Linear movement
  /// true to move the arm on a straigt line to the pose
  bool linear_movement;
  /// step size in to generate linear movement (default 0.01)
  float linear_eef_step;
  /// The jump_threshold specifies the maximum distance in configuration space between consecutive points in the resulting path.
  float linear_jump_thresh;
  /// Just don't set it to true if you don't know what you are doing :)
  bool linear_disable_collisions;
  /// list of constraints for this movement
  moveit_msgs__msg__Constraints path_constraints;
} moveit_wrapper_interfaces__msg__Waypoint;

// Struct for a sequence of moveit_wrapper_interfaces__msg__Waypoint.
typedef struct moveit_wrapper_interfaces__msg__Waypoint__Sequence
{
  moveit_wrapper_interfaces__msg__Waypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__msg__Waypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_

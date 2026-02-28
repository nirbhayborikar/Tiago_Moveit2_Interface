// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__STRUCT_H_
#define MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sequence_id'
#include "rosidl_runtime_c/string.h"
// Member 'waypoints'
#include "moveit_wrapper_interfaces/msg/detail/waypoint__struct.h"
// Member 'path_constraints'
#include "moveit_msgs/msg/detail/constraints__struct.h"

/// Struct defined in msg/WaypointSequence in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__msg__WaypointSequence
{
  /// Identifier for this sequence
  rosidl_runtime_c__String sequence_id;
  /// Waypoints for this trajectory
  moveit_wrapper_interfaces__msg__Waypoint__Sequence waypoints;
  /// Constraints specific to this sequence
  moveit_msgs__msg__Constraints path_constraints;
  /// Use linear interpolation between waypoints
  bool use_linear_interpolation;
  /// Velocity scaling for this sequence (0.0 = use default)
  double velocity_scaling;
  /// Acceleration scaling for this sequence (0.0 = use default)
  double acceleration_scaling;
} moveit_wrapper_interfaces__msg__WaypointSequence;

// Struct for a sequence of moveit_wrapper_interfaces__msg__WaypointSequence.
typedef struct moveit_wrapper_interfaces__msg__WaypointSequence__Sequence
{
  moveit_wrapper_interfaces__msg__WaypointSequence * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__msg__WaypointSequence__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_WRAPPER_INTERFACES__MSG__DETAIL__WAYPOINT_SEQUENCE__STRUCT_H_

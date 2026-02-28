// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_wrapper_interfaces:srv/GetNamedTarget.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGET__STRUCT_H_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'move_group'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetNamedTarget in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__srv__GetNamedTarget_Request
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String move_group;
} moveit_wrapper_interfaces__srv__GetNamedTarget_Request;

// Struct for a sequence of moveit_wrapper_interfaces__srv__GetNamedTarget_Request.
typedef struct moveit_wrapper_interfaces__srv__GetNamedTarget_Request__Sequence
{
  moveit_wrapper_interfaces__srv__GetNamedTarget_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__srv__GetNamedTarget_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'joint_state'
#include "sensor_msgs/msg/detail/joint_state__struct.h"

/// Struct defined in srv/GetNamedTarget in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__srv__GetNamedTarget_Response
{
  bool success;
  rosidl_runtime_c__String message;
  sensor_msgs__msg__JointState joint_state;
} moveit_wrapper_interfaces__srv__GetNamedTarget_Response;

// Struct for a sequence of moveit_wrapper_interfaces__srv__GetNamedTarget_Response.
typedef struct moveit_wrapper_interfaces__srv__GetNamedTarget_Response__Sequence
{
  moveit_wrapper_interfaces__srv__GetNamedTarget_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__srv__GetNamedTarget_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_NAMED_TARGET__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_wrapper_interfaces:srv/GetColObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__STRUCT_H_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetColObj in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__srv__GetColObj_Request
{
  uint8_t structure_needs_at_least_one_member;
} moveit_wrapper_interfaces__srv__GetColObj_Request;

// Struct for a sequence of moveit_wrapper_interfaces__srv__GetColObj_Request.
typedef struct moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence
{
  moveit_wrapper_interfaces__srv__GetColObj_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'objects'
#include "visualization_msgs/msg/detail/marker__struct.h"
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetColObj in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__srv__GetColObj_Response
{
  visualization_msgs__msg__Marker__Sequence objects;
  bool success;
  rosidl_runtime_c__String message;
} moveit_wrapper_interfaces__srv__GetColObj_Response;

// Struct for a sequence of moveit_wrapper_interfaces__srv__GetColObj_Response.
typedef struct moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence
{
  moveit_wrapper_interfaces__srv__GetColObj_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__STRUCT_H_

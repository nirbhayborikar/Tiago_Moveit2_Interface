// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_wrapper_interfaces:srv/DettachObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__STRUCT_H_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'object_names'
// Member 'move_group'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DettachObj in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__srv__DettachObj_Request
{
  rosidl_runtime_c__String__Sequence object_names;
  rosidl_runtime_c__String move_group;
} moveit_wrapper_interfaces__srv__DettachObj_Request;

// Struct for a sequence of moveit_wrapper_interfaces__srv__DettachObj_Request.
typedef struct moveit_wrapper_interfaces__srv__DettachObj_Request__Sequence
{
  moveit_wrapper_interfaces__srv__DettachObj_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__srv__DettachObj_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DettachObj in the package moveit_wrapper_interfaces.
typedef struct moveit_wrapper_interfaces__srv__DettachObj_Response
{
  bool success;
  rosidl_runtime_c__String message;
} moveit_wrapper_interfaces__srv__DettachObj_Response;

// Struct for a sequence of moveit_wrapper_interfaces__srv__DettachObj_Response.
typedef struct moveit_wrapper_interfaces__srv__DettachObj_Response__Sequence
{
  moveit_wrapper_interfaces__srv__DettachObj_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_wrapper_interfaces__srv__DettachObj_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__DETTACH_OBJ__STRUCT_H_

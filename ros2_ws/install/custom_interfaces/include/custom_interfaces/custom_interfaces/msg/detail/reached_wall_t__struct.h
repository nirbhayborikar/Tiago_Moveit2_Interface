// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/ReachedWallT.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__REACHED_WALL_T__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__REACHED_WALL_T__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ReachedWallT in the package custom_interfaces.
typedef struct custom_interfaces__msg__ReachedWallT
{
  rosidl_runtime_c__String message;
  bool success;
} custom_interfaces__msg__ReachedWallT;

// Struct for a sequence of custom_interfaces__msg__ReachedWallT.
typedef struct custom_interfaces__msg__ReachedWallT__Sequence
{
  custom_interfaces__msg__ReachedWallT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__ReachedWallT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__REACHED_WALL_T__STRUCT_H_

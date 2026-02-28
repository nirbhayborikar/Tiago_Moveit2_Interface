// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/DriveToWallT.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/DriveToWallT in the package custom_interfaces.
typedef struct custom_interfaces__msg__DriveToWallT
{
  double linear_x;
  double min_distance;
} custom_interfaces__msg__DriveToWallT;

// Struct for a sequence of custom_interfaces__msg__DriveToWallT.
typedef struct custom_interfaces__msg__DriveToWallT__Sequence
{
  custom_interfaces__msg__DriveToWallT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__DriveToWallT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DRIVE_TO_WALL_T__STRUCT_H_

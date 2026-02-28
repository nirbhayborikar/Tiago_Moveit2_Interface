// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from moveit_wrapper_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice
#include "moveit_wrapper_interfaces/msg/detail/waypoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `named_target`
#include "rosidl_runtime_c/string_functions.h"
// Member `path_constraints`
#include "moveit_msgs/msg/detail/constraints__functions.h"

bool
moveit_wrapper_interfaces__msg__Waypoint__init(moveit_wrapper_interfaces__msg__Waypoint * msg)
{
  if (!msg) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose)) {
    moveit_wrapper_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  // named_target
  if (!rosidl_runtime_c__String__init(&msg->named_target)) {
    moveit_wrapper_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  // linear_movement
  // linear_eef_step
  // linear_jump_thresh
  // linear_disable_collisions
  // path_constraints
  if (!moveit_msgs__msg__Constraints__init(&msg->path_constraints)) {
    moveit_wrapper_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  return true;
}

void
moveit_wrapper_interfaces__msg__Waypoint__fini(moveit_wrapper_interfaces__msg__Waypoint * msg)
{
  if (!msg) {
    return;
  }
  // pose
  geometry_msgs__msg__PoseStamped__fini(&msg->pose);
  // named_target
  rosidl_runtime_c__String__fini(&msg->named_target);
  // linear_movement
  // linear_eef_step
  // linear_jump_thresh
  // linear_disable_collisions
  // path_constraints
  moveit_msgs__msg__Constraints__fini(&msg->path_constraints);
}

bool
moveit_wrapper_interfaces__msg__Waypoint__are_equal(const moveit_wrapper_interfaces__msg__Waypoint * lhs, const moveit_wrapper_interfaces__msg__Waypoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // named_target
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->named_target), &(rhs->named_target)))
  {
    return false;
  }
  // linear_movement
  if (lhs->linear_movement != rhs->linear_movement) {
    return false;
  }
  // linear_eef_step
  if (lhs->linear_eef_step != rhs->linear_eef_step) {
    return false;
  }
  // linear_jump_thresh
  if (lhs->linear_jump_thresh != rhs->linear_jump_thresh) {
    return false;
  }
  // linear_disable_collisions
  if (lhs->linear_disable_collisions != rhs->linear_disable_collisions) {
    return false;
  }
  // path_constraints
  if (!moveit_msgs__msg__Constraints__are_equal(
      &(lhs->path_constraints), &(rhs->path_constraints)))
  {
    return false;
  }
  return true;
}

bool
moveit_wrapper_interfaces__msg__Waypoint__copy(
  const moveit_wrapper_interfaces__msg__Waypoint * input,
  moveit_wrapper_interfaces__msg__Waypoint * output)
{
  if (!input || !output) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // named_target
  if (!rosidl_runtime_c__String__copy(
      &(input->named_target), &(output->named_target)))
  {
    return false;
  }
  // linear_movement
  output->linear_movement = input->linear_movement;
  // linear_eef_step
  output->linear_eef_step = input->linear_eef_step;
  // linear_jump_thresh
  output->linear_jump_thresh = input->linear_jump_thresh;
  // linear_disable_collisions
  output->linear_disable_collisions = input->linear_disable_collisions;
  // path_constraints
  if (!moveit_msgs__msg__Constraints__copy(
      &(input->path_constraints), &(output->path_constraints)))
  {
    return false;
  }
  return true;
}

moveit_wrapper_interfaces__msg__Waypoint *
moveit_wrapper_interfaces__msg__Waypoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__msg__Waypoint * msg = (moveit_wrapper_interfaces__msg__Waypoint *)allocator.allocate(sizeof(moveit_wrapper_interfaces__msg__Waypoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_wrapper_interfaces__msg__Waypoint));
  bool success = moveit_wrapper_interfaces__msg__Waypoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_wrapper_interfaces__msg__Waypoint__destroy(moveit_wrapper_interfaces__msg__Waypoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_wrapper_interfaces__msg__Waypoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_wrapper_interfaces__msg__Waypoint__Sequence__init(moveit_wrapper_interfaces__msg__Waypoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__msg__Waypoint * data = NULL;

  if (size) {
    data = (moveit_wrapper_interfaces__msg__Waypoint *)allocator.zero_allocate(size, sizeof(moveit_wrapper_interfaces__msg__Waypoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_wrapper_interfaces__msg__Waypoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_wrapper_interfaces__msg__Waypoint__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
moveit_wrapper_interfaces__msg__Waypoint__Sequence__fini(moveit_wrapper_interfaces__msg__Waypoint__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      moveit_wrapper_interfaces__msg__Waypoint__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

moveit_wrapper_interfaces__msg__Waypoint__Sequence *
moveit_wrapper_interfaces__msg__Waypoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__msg__Waypoint__Sequence * array = (moveit_wrapper_interfaces__msg__Waypoint__Sequence *)allocator.allocate(sizeof(moveit_wrapper_interfaces__msg__Waypoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_wrapper_interfaces__msg__Waypoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_wrapper_interfaces__msg__Waypoint__Sequence__destroy(moveit_wrapper_interfaces__msg__Waypoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_wrapper_interfaces__msg__Waypoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_wrapper_interfaces__msg__Waypoint__Sequence__are_equal(const moveit_wrapper_interfaces__msg__Waypoint__Sequence * lhs, const moveit_wrapper_interfaces__msg__Waypoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_wrapper_interfaces__msg__Waypoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_wrapper_interfaces__msg__Waypoint__Sequence__copy(
  const moveit_wrapper_interfaces__msg__Waypoint__Sequence * input,
  moveit_wrapper_interfaces__msg__Waypoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_wrapper_interfaces__msg__Waypoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_wrapper_interfaces__msg__Waypoint * data =
      (moveit_wrapper_interfaces__msg__Waypoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_wrapper_interfaces__msg__Waypoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_wrapper_interfaces__msg__Waypoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_wrapper_interfaces__msg__Waypoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

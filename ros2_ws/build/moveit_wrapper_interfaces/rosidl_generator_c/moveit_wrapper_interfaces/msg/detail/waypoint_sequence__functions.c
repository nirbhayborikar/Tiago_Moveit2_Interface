// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sequence_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `waypoints`
#include "moveit_wrapper_interfaces/msg/detail/waypoint__functions.h"
// Member `path_constraints`
#include "moveit_msgs/msg/detail/constraints__functions.h"

bool
moveit_wrapper_interfaces__msg__WaypointSequence__init(moveit_wrapper_interfaces__msg__WaypointSequence * msg)
{
  if (!msg) {
    return false;
  }
  // sequence_id
  if (!rosidl_runtime_c__String__init(&msg->sequence_id)) {
    moveit_wrapper_interfaces__msg__WaypointSequence__fini(msg);
    return false;
  }
  // waypoints
  if (!moveit_wrapper_interfaces__msg__Waypoint__Sequence__init(&msg->waypoints, 0)) {
    moveit_wrapper_interfaces__msg__WaypointSequence__fini(msg);
    return false;
  }
  // path_constraints
  if (!moveit_msgs__msg__Constraints__init(&msg->path_constraints)) {
    moveit_wrapper_interfaces__msg__WaypointSequence__fini(msg);
    return false;
  }
  // use_linear_interpolation
  // velocity_scaling
  // acceleration_scaling
  return true;
}

void
moveit_wrapper_interfaces__msg__WaypointSequence__fini(moveit_wrapper_interfaces__msg__WaypointSequence * msg)
{
  if (!msg) {
    return;
  }
  // sequence_id
  rosidl_runtime_c__String__fini(&msg->sequence_id);
  // waypoints
  moveit_wrapper_interfaces__msg__Waypoint__Sequence__fini(&msg->waypoints);
  // path_constraints
  moveit_msgs__msg__Constraints__fini(&msg->path_constraints);
  // use_linear_interpolation
  // velocity_scaling
  // acceleration_scaling
}

bool
moveit_wrapper_interfaces__msg__WaypointSequence__are_equal(const moveit_wrapper_interfaces__msg__WaypointSequence * lhs, const moveit_wrapper_interfaces__msg__WaypointSequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sequence_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sequence_id), &(rhs->sequence_id)))
  {
    return false;
  }
  // waypoints
  if (!moveit_wrapper_interfaces__msg__Waypoint__Sequence__are_equal(
      &(lhs->waypoints), &(rhs->waypoints)))
  {
    return false;
  }
  // path_constraints
  if (!moveit_msgs__msg__Constraints__are_equal(
      &(lhs->path_constraints), &(rhs->path_constraints)))
  {
    return false;
  }
  // use_linear_interpolation
  if (lhs->use_linear_interpolation != rhs->use_linear_interpolation) {
    return false;
  }
  // velocity_scaling
  if (lhs->velocity_scaling != rhs->velocity_scaling) {
    return false;
  }
  // acceleration_scaling
  if (lhs->acceleration_scaling != rhs->acceleration_scaling) {
    return false;
  }
  return true;
}

bool
moveit_wrapper_interfaces__msg__WaypointSequence__copy(
  const moveit_wrapper_interfaces__msg__WaypointSequence * input,
  moveit_wrapper_interfaces__msg__WaypointSequence * output)
{
  if (!input || !output) {
    return false;
  }
  // sequence_id
  if (!rosidl_runtime_c__String__copy(
      &(input->sequence_id), &(output->sequence_id)))
  {
    return false;
  }
  // waypoints
  if (!moveit_wrapper_interfaces__msg__Waypoint__Sequence__copy(
      &(input->waypoints), &(output->waypoints)))
  {
    return false;
  }
  // path_constraints
  if (!moveit_msgs__msg__Constraints__copy(
      &(input->path_constraints), &(output->path_constraints)))
  {
    return false;
  }
  // use_linear_interpolation
  output->use_linear_interpolation = input->use_linear_interpolation;
  // velocity_scaling
  output->velocity_scaling = input->velocity_scaling;
  // acceleration_scaling
  output->acceleration_scaling = input->acceleration_scaling;
  return true;
}

moveit_wrapper_interfaces__msg__WaypointSequence *
moveit_wrapper_interfaces__msg__WaypointSequence__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__msg__WaypointSequence * msg = (moveit_wrapper_interfaces__msg__WaypointSequence *)allocator.allocate(sizeof(moveit_wrapper_interfaces__msg__WaypointSequence), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_wrapper_interfaces__msg__WaypointSequence));
  bool success = moveit_wrapper_interfaces__msg__WaypointSequence__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_wrapper_interfaces__msg__WaypointSequence__destroy(moveit_wrapper_interfaces__msg__WaypointSequence * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_wrapper_interfaces__msg__WaypointSequence__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_wrapper_interfaces__msg__WaypointSequence__Sequence__init(moveit_wrapper_interfaces__msg__WaypointSequence__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__msg__WaypointSequence * data = NULL;

  if (size) {
    data = (moveit_wrapper_interfaces__msg__WaypointSequence *)allocator.zero_allocate(size, sizeof(moveit_wrapper_interfaces__msg__WaypointSequence), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_wrapper_interfaces__msg__WaypointSequence__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_wrapper_interfaces__msg__WaypointSequence__fini(&data[i - 1]);
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
moveit_wrapper_interfaces__msg__WaypointSequence__Sequence__fini(moveit_wrapper_interfaces__msg__WaypointSequence__Sequence * array)
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
      moveit_wrapper_interfaces__msg__WaypointSequence__fini(&array->data[i]);
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

moveit_wrapper_interfaces__msg__WaypointSequence__Sequence *
moveit_wrapper_interfaces__msg__WaypointSequence__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__msg__WaypointSequence__Sequence * array = (moveit_wrapper_interfaces__msg__WaypointSequence__Sequence *)allocator.allocate(sizeof(moveit_wrapper_interfaces__msg__WaypointSequence__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_wrapper_interfaces__msg__WaypointSequence__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_wrapper_interfaces__msg__WaypointSequence__Sequence__destroy(moveit_wrapper_interfaces__msg__WaypointSequence__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_wrapper_interfaces__msg__WaypointSequence__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_wrapper_interfaces__msg__WaypointSequence__Sequence__are_equal(const moveit_wrapper_interfaces__msg__WaypointSequence__Sequence * lhs, const moveit_wrapper_interfaces__msg__WaypointSequence__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_wrapper_interfaces__msg__WaypointSequence__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_wrapper_interfaces__msg__WaypointSequence__Sequence__copy(
  const moveit_wrapper_interfaces__msg__WaypointSequence__Sequence * input,
  moveit_wrapper_interfaces__msg__WaypointSequence__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_wrapper_interfaces__msg__WaypointSequence);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_wrapper_interfaces__msg__WaypointSequence * data =
      (moveit_wrapper_interfaces__msg__WaypointSequence *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_wrapper_interfaces__msg__WaypointSequence__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_wrapper_interfaces__msg__WaypointSequence__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_wrapper_interfaces__msg__WaypointSequence__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from moveit_wrapper_interfaces:srv/PlanJoints.idl
// generated code does not contain a copyright notice
#include "moveit_wrapper_interfaces/srv/detail/plan_joints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `joint_states`
#include "sensor_msgs/msg/detail/joint_state__functions.h"
// Member `path_constraints`
#include "moveit_msgs/msg/detail/constraints__functions.h"
// Member `start_state`
#include "moveit_msgs/msg/detail/robot_state__functions.h"
// Member `move_group`
#include "rosidl_runtime_c/string_functions.h"

bool
moveit_wrapper_interfaces__srv__PlanJoints_Request__init(moveit_wrapper_interfaces__srv__PlanJoints_Request * msg)
{
  if (!msg) {
    return false;
  }
  // joint_states
  if (!sensor_msgs__msg__JointState__Sequence__init(&msg->joint_states, 0)) {
    moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(msg);
    return false;
  }
  // path_constraints
  if (!moveit_msgs__msg__Constraints__init(&msg->path_constraints)) {
    moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(msg);
    return false;
  }
  // send_partial
  // use_start_state
  // start_state
  if (!moveit_msgs__msg__RobotState__init(&msg->start_state)) {
    moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(msg);
    return false;
  }
  // move_group
  if (!rosidl_runtime_c__String__init(&msg->move_group)) {
    moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(msg);
    return false;
  }
  return true;
}

void
moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(moveit_wrapper_interfaces__srv__PlanJoints_Request * msg)
{
  if (!msg) {
    return;
  }
  // joint_states
  sensor_msgs__msg__JointState__Sequence__fini(&msg->joint_states);
  // path_constraints
  moveit_msgs__msg__Constraints__fini(&msg->path_constraints);
  // send_partial
  // use_start_state
  // start_state
  moveit_msgs__msg__RobotState__fini(&msg->start_state);
  // move_group
  rosidl_runtime_c__String__fini(&msg->move_group);
}

bool
moveit_wrapper_interfaces__srv__PlanJoints_Request__are_equal(const moveit_wrapper_interfaces__srv__PlanJoints_Request * lhs, const moveit_wrapper_interfaces__srv__PlanJoints_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint_states
  if (!sensor_msgs__msg__JointState__Sequence__are_equal(
      &(lhs->joint_states), &(rhs->joint_states)))
  {
    return false;
  }
  // path_constraints
  if (!moveit_msgs__msg__Constraints__are_equal(
      &(lhs->path_constraints), &(rhs->path_constraints)))
  {
    return false;
  }
  // send_partial
  if (lhs->send_partial != rhs->send_partial) {
    return false;
  }
  // use_start_state
  if (lhs->use_start_state != rhs->use_start_state) {
    return false;
  }
  // start_state
  if (!moveit_msgs__msg__RobotState__are_equal(
      &(lhs->start_state), &(rhs->start_state)))
  {
    return false;
  }
  // move_group
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->move_group), &(rhs->move_group)))
  {
    return false;
  }
  return true;
}

bool
moveit_wrapper_interfaces__srv__PlanJoints_Request__copy(
  const moveit_wrapper_interfaces__srv__PlanJoints_Request * input,
  moveit_wrapper_interfaces__srv__PlanJoints_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // joint_states
  if (!sensor_msgs__msg__JointState__Sequence__copy(
      &(input->joint_states), &(output->joint_states)))
  {
    return false;
  }
  // path_constraints
  if (!moveit_msgs__msg__Constraints__copy(
      &(input->path_constraints), &(output->path_constraints)))
  {
    return false;
  }
  // send_partial
  output->send_partial = input->send_partial;
  // use_start_state
  output->use_start_state = input->use_start_state;
  // start_state
  if (!moveit_msgs__msg__RobotState__copy(
      &(input->start_state), &(output->start_state)))
  {
    return false;
  }
  // move_group
  if (!rosidl_runtime_c__String__copy(
      &(input->move_group), &(output->move_group)))
  {
    return false;
  }
  return true;
}

moveit_wrapper_interfaces__srv__PlanJoints_Request *
moveit_wrapper_interfaces__srv__PlanJoints_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__PlanJoints_Request * msg = (moveit_wrapper_interfaces__srv__PlanJoints_Request *)allocator.allocate(sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Request));
  bool success = moveit_wrapper_interfaces__srv__PlanJoints_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_wrapper_interfaces__srv__PlanJoints_Request__destroy(moveit_wrapper_interfaces__srv__PlanJoints_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence__init(moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__PlanJoints_Request * data = NULL;

  if (size) {
    data = (moveit_wrapper_interfaces__srv__PlanJoints_Request *)allocator.zero_allocate(size, sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_wrapper_interfaces__srv__PlanJoints_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(&data[i - 1]);
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
moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence__fini(moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence * array)
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
      moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(&array->data[i]);
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

moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence *
moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence * array = (moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence *)allocator.allocate(sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence__destroy(moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence__are_equal(const moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence * lhs, const moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_wrapper_interfaces__srv__PlanJoints_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence__copy(
  const moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence * input,
  moveit_wrapper_interfaces__srv__PlanJoints_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_wrapper_interfaces__srv__PlanJoints_Request * data =
      (moveit_wrapper_interfaces__srv__PlanJoints_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_wrapper_interfaces__srv__PlanJoints_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_wrapper_interfaces__srv__PlanJoints_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `plans`
#include "moveit_msgs/msg/detail/robot_trajectory__functions.h"

bool
moveit_wrapper_interfaces__srv__PlanJoints_Response__init(moveit_wrapper_interfaces__srv__PlanJoints_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    moveit_wrapper_interfaces__srv__PlanJoints_Response__fini(msg);
    return false;
  }
  // plans
  if (!moveit_msgs__msg__RobotTrajectory__Sequence__init(&msg->plans, 0)) {
    moveit_wrapper_interfaces__srv__PlanJoints_Response__fini(msg);
    return false;
  }
  return true;
}

void
moveit_wrapper_interfaces__srv__PlanJoints_Response__fini(moveit_wrapper_interfaces__srv__PlanJoints_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // plans
  moveit_msgs__msg__RobotTrajectory__Sequence__fini(&msg->plans);
}

bool
moveit_wrapper_interfaces__srv__PlanJoints_Response__are_equal(const moveit_wrapper_interfaces__srv__PlanJoints_Response * lhs, const moveit_wrapper_interfaces__srv__PlanJoints_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // plans
  if (!moveit_msgs__msg__RobotTrajectory__Sequence__are_equal(
      &(lhs->plans), &(rhs->plans)))
  {
    return false;
  }
  return true;
}

bool
moveit_wrapper_interfaces__srv__PlanJoints_Response__copy(
  const moveit_wrapper_interfaces__srv__PlanJoints_Response * input,
  moveit_wrapper_interfaces__srv__PlanJoints_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // plans
  if (!moveit_msgs__msg__RobotTrajectory__Sequence__copy(
      &(input->plans), &(output->plans)))
  {
    return false;
  }
  return true;
}

moveit_wrapper_interfaces__srv__PlanJoints_Response *
moveit_wrapper_interfaces__srv__PlanJoints_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__PlanJoints_Response * msg = (moveit_wrapper_interfaces__srv__PlanJoints_Response *)allocator.allocate(sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Response));
  bool success = moveit_wrapper_interfaces__srv__PlanJoints_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_wrapper_interfaces__srv__PlanJoints_Response__destroy(moveit_wrapper_interfaces__srv__PlanJoints_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_wrapper_interfaces__srv__PlanJoints_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence__init(moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__PlanJoints_Response * data = NULL;

  if (size) {
    data = (moveit_wrapper_interfaces__srv__PlanJoints_Response *)allocator.zero_allocate(size, sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_wrapper_interfaces__srv__PlanJoints_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_wrapper_interfaces__srv__PlanJoints_Response__fini(&data[i - 1]);
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
moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence__fini(moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence * array)
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
      moveit_wrapper_interfaces__srv__PlanJoints_Response__fini(&array->data[i]);
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

moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence *
moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence * array = (moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence *)allocator.allocate(sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence__destroy(moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence__are_equal(const moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence * lhs, const moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_wrapper_interfaces__srv__PlanJoints_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence__copy(
  const moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence * input,
  moveit_wrapper_interfaces__srv__PlanJoints_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_wrapper_interfaces__srv__PlanJoints_Response * data =
      (moveit_wrapper_interfaces__srv__PlanJoints_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_wrapper_interfaces__srv__PlanJoints_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_wrapper_interfaces__srv__PlanJoints_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_wrapper_interfaces__srv__PlanJoints_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

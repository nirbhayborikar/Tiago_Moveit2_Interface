// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from moveit_wrapper_interfaces:srv/GotoNamedTarget.idl
// generated code does not contain a copyright notice
#include "moveit_wrapper_interfaces/srv/detail/goto_named_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
// Member `move_group`
#include "rosidl_runtime_c/string_functions.h"

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__init(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__fini(msg);
    return false;
  }
  // move_group
  if (!rosidl_runtime_c__String__init(&msg->move_group)) {
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__fini(msg);
    return false;
  }
  return true;
}

void
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__fini(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // move_group
  rosidl_runtime_c__String__fini(&msg->move_group);
}

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__are_equal(const moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * lhs, const moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
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
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__copy(
  const moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * input,
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
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

moveit_wrapper_interfaces__srv__GotoNamedTarget_Request *
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * msg = (moveit_wrapper_interfaces__srv__GotoNamedTarget_Request *)allocator.allocate(sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request));
  bool success = moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__destroy(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence__init(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * data = NULL;

  if (size) {
    data = (moveit_wrapper_interfaces__srv__GotoNamedTarget_Request *)allocator.zero_allocate(size, sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__fini(&data[i - 1]);
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
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence__fini(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence * array)
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
      moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__fini(&array->data[i]);
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

moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence *
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence * array = (moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence *)allocator.allocate(sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence__destroy(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence__are_equal(const moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence * lhs, const moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence__copy(
  const moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence * input,
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Request * data =
      (moveit_wrapper_interfaces__srv__GotoNamedTarget_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_wrapper_interfaces__srv__GotoNamedTarget_Request__copy(
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

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__init(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__fini(msg);
    return false;
  }
  return true;
}

void
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__fini(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__are_equal(const moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * lhs, const moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * rhs)
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
  return true;
}

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__copy(
  const moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * input,
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * output)
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
  return true;
}

moveit_wrapper_interfaces__srv__GotoNamedTarget_Response *
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * msg = (moveit_wrapper_interfaces__srv__GotoNamedTarget_Response *)allocator.allocate(sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response));
  bool success = moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__destroy(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence__init(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * data = NULL;

  if (size) {
    data = (moveit_wrapper_interfaces__srv__GotoNamedTarget_Response *)allocator.zero_allocate(size, sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__fini(&data[i - 1]);
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
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence__fini(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence * array)
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
      moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__fini(&array->data[i]);
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

moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence *
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence * array = (moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence *)allocator.allocate(sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence__destroy(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence__are_equal(const moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence * lhs, const moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence__copy(
  const moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence * input,
  moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_wrapper_interfaces__srv__GotoNamedTarget_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_wrapper_interfaces__srv__GotoNamedTarget_Response * data =
      (moveit_wrapper_interfaces__srv__GotoNamedTarget_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_wrapper_interfaces__srv__GotoNamedTarget_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

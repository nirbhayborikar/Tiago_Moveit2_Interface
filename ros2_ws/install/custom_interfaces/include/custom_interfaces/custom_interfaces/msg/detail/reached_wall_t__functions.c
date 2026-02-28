// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/ReachedWallT.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/reached_wall_t__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_interfaces__msg__ReachedWallT__init(custom_interfaces__msg__ReachedWallT * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    custom_interfaces__msg__ReachedWallT__fini(msg);
    return false;
  }
  // success
  return true;
}

void
custom_interfaces__msg__ReachedWallT__fini(custom_interfaces__msg__ReachedWallT * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // success
}

bool
custom_interfaces__msg__ReachedWallT__are_equal(const custom_interfaces__msg__ReachedWallT * lhs, const custom_interfaces__msg__ReachedWallT * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__ReachedWallT__copy(
  const custom_interfaces__msg__ReachedWallT * input,
  custom_interfaces__msg__ReachedWallT * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

custom_interfaces__msg__ReachedWallT *
custom_interfaces__msg__ReachedWallT__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__ReachedWallT * msg = (custom_interfaces__msg__ReachedWallT *)allocator.allocate(sizeof(custom_interfaces__msg__ReachedWallT), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__ReachedWallT));
  bool success = custom_interfaces__msg__ReachedWallT__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__ReachedWallT__destroy(custom_interfaces__msg__ReachedWallT * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__ReachedWallT__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__ReachedWallT__Sequence__init(custom_interfaces__msg__ReachedWallT__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__ReachedWallT * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__ReachedWallT *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__ReachedWallT), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__ReachedWallT__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__ReachedWallT__fini(&data[i - 1]);
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
custom_interfaces__msg__ReachedWallT__Sequence__fini(custom_interfaces__msg__ReachedWallT__Sequence * array)
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
      custom_interfaces__msg__ReachedWallT__fini(&array->data[i]);
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

custom_interfaces__msg__ReachedWallT__Sequence *
custom_interfaces__msg__ReachedWallT__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__ReachedWallT__Sequence * array = (custom_interfaces__msg__ReachedWallT__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__ReachedWallT__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__ReachedWallT__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__ReachedWallT__Sequence__destroy(custom_interfaces__msg__ReachedWallT__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__ReachedWallT__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__ReachedWallT__Sequence__are_equal(const custom_interfaces__msg__ReachedWallT__Sequence * lhs, const custom_interfaces__msg__ReachedWallT__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__ReachedWallT__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__ReachedWallT__Sequence__copy(
  const custom_interfaces__msg__ReachedWallT__Sequence * input,
  custom_interfaces__msg__ReachedWallT__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__ReachedWallT);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__ReachedWallT * data =
      (custom_interfaces__msg__ReachedWallT *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__ReachedWallT__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__ReachedWallT__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__ReachedWallT__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

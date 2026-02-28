// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__rosidl_typesupport_introspection_c.h"
#include "moveit_wrapper_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__functions.h"
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__struct.h"


// Include directives for member types
// Member `sequence_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `waypoints`
#include "moveit_wrapper_interfaces/msg/waypoint.h"
// Member `waypoints`
#include "moveit_wrapper_interfaces/msg/detail/waypoint__rosidl_typesupport_introspection_c.h"
// Member `path_constraints`
#include "moveit_msgs/msg/constraints.h"
// Member `path_constraints`
#include "moveit_msgs/msg/detail/constraints__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  moveit_wrapper_interfaces__msg__WaypointSequence__init(message_memory);
}

void moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_fini_function(void * message_memory)
{
  moveit_wrapper_interfaces__msg__WaypointSequence__fini(message_memory);
}

size_t moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__size_function__WaypointSequence__waypoints(
  const void * untyped_member)
{
  const moveit_wrapper_interfaces__msg__Waypoint__Sequence * member =
    (const moveit_wrapper_interfaces__msg__Waypoint__Sequence *)(untyped_member);
  return member->size;
}

const void * moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__get_const_function__WaypointSequence__waypoints(
  const void * untyped_member, size_t index)
{
  const moveit_wrapper_interfaces__msg__Waypoint__Sequence * member =
    (const moveit_wrapper_interfaces__msg__Waypoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__get_function__WaypointSequence__waypoints(
  void * untyped_member, size_t index)
{
  moveit_wrapper_interfaces__msg__Waypoint__Sequence * member =
    (moveit_wrapper_interfaces__msg__Waypoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__fetch_function__WaypointSequence__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const moveit_wrapper_interfaces__msg__Waypoint * item =
    ((const moveit_wrapper_interfaces__msg__Waypoint *)
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__get_const_function__WaypointSequence__waypoints(untyped_member, index));
  moveit_wrapper_interfaces__msg__Waypoint * value =
    (moveit_wrapper_interfaces__msg__Waypoint *)(untyped_value);
  *value = *item;
}

void moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__assign_function__WaypointSequence__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  moveit_wrapper_interfaces__msg__Waypoint * item =
    ((moveit_wrapper_interfaces__msg__Waypoint *)
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__get_function__WaypointSequence__waypoints(untyped_member, index));
  const moveit_wrapper_interfaces__msg__Waypoint * value =
    (const moveit_wrapper_interfaces__msg__Waypoint *)(untyped_value);
  *item = *value;
}

bool moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__resize_function__WaypointSequence__waypoints(
  void * untyped_member, size_t size)
{
  moveit_wrapper_interfaces__msg__Waypoint__Sequence * member =
    (moveit_wrapper_interfaces__msg__Waypoint__Sequence *)(untyped_member);
  moveit_wrapper_interfaces__msg__Waypoint__Sequence__fini(member);
  return moveit_wrapper_interfaces__msg__Waypoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_member_array[6] = {
  {
    "sequence_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__msg__WaypointSequence, sequence_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__msg__WaypointSequence, waypoints),  // bytes offset in struct
    NULL,  // default value
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__size_function__WaypointSequence__waypoints,  // size() function pointer
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__get_const_function__WaypointSequence__waypoints,  // get_const(index) function pointer
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__get_function__WaypointSequence__waypoints,  // get(index) function pointer
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__fetch_function__WaypointSequence__waypoints,  // fetch(index, &value) function pointer
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__assign_function__WaypointSequence__waypoints,  // assign(index, value) function pointer
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__resize_function__WaypointSequence__waypoints  // resize(index) function pointer
  },
  {
    "path_constraints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__msg__WaypointSequence, path_constraints),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "use_linear_interpolation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__msg__WaypointSequence, use_linear_interpolation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity_scaling",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__msg__WaypointSequence, velocity_scaling),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceleration_scaling",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__msg__WaypointSequence, acceleration_scaling),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_members = {
  "moveit_wrapper_interfaces__msg",  // message namespace
  "WaypointSequence",  // message name
  6,  // number of fields
  sizeof(moveit_wrapper_interfaces__msg__WaypointSequence),
  moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_member_array,  // message members
  moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_init_function,  // function to initialize message memory (memory has to be allocated)
  moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_type_support_handle = {
  0,
  &moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, msg, WaypointSequence)() {
  moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, msg, Waypoint)();
  moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_msgs, msg, Constraints)();
  if (!moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_type_support_handle.typesupport_identifier) {
    moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &moveit_wrapper_interfaces__msg__WaypointSequence__rosidl_typesupport_introspection_c__WaypointSequence_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

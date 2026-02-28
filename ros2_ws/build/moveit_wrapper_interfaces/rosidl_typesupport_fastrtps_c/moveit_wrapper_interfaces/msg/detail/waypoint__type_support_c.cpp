// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from moveit_wrapper_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice
#include "moveit_wrapper_interfaces/msg/detail/waypoint__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "moveit_wrapper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "moveit_wrapper_interfaces/msg/detail/waypoint__struct.h"
#include "moveit_wrapper_interfaces/msg/detail/waypoint__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/pose_stamped__functions.h"  // pose
#include "moveit_msgs/msg/detail/constraints__functions.h"  // path_constraints
#include "rosidl_runtime_c/string.h"  // named_target
#include "rosidl_runtime_c/string_functions.h"  // named_target

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t get_serialized_size_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t max_serialized_size_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PoseStamped)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t get_serialized_size_moveit_msgs__msg__Constraints(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t max_serialized_size_moveit_msgs__msg__Constraints(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_msgs, msg, Constraints)();


using _Waypoint__ros_msg_type = moveit_wrapper_interfaces__msg__Waypoint;

static bool _Waypoint__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Waypoint__ros_msg_type * ros_message = static_cast<const _Waypoint__ros_msg_type *>(untyped_ros_message);
  // Field name: pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PoseStamped
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->pose, cdr))
    {
      return false;
    }
  }

  // Field name: named_target
  {
    const rosidl_runtime_c__String * str = &ros_message->named_target;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: linear_movement
  {
    cdr << (ros_message->linear_movement ? true : false);
  }

  // Field name: linear_eef_step
  {
    cdr << ros_message->linear_eef_step;
  }

  // Field name: linear_jump_thresh
  {
    cdr << ros_message->linear_jump_thresh;
  }

  // Field name: linear_disable_collisions
  {
    cdr << (ros_message->linear_disable_collisions ? true : false);
  }

  // Field name: path_constraints
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, moveit_msgs, msg, Constraints
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->path_constraints, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Waypoint__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Waypoint__ros_msg_type * ros_message = static_cast<_Waypoint__ros_msg_type *>(untyped_ros_message);
  // Field name: pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PoseStamped
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->pose))
    {
      return false;
    }
  }

  // Field name: named_target
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->named_target.data) {
      rosidl_runtime_c__String__init(&ros_message->named_target);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->named_target,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'named_target'\n");
      return false;
    }
  }

  // Field name: linear_movement
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->linear_movement = tmp ? true : false;
  }

  // Field name: linear_eef_step
  {
    cdr >> ros_message->linear_eef_step;
  }

  // Field name: linear_jump_thresh
  {
    cdr >> ros_message->linear_jump_thresh;
  }

  // Field name: linear_disable_collisions
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->linear_disable_collisions = tmp ? true : false;
  }

  // Field name: path_constraints
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, moveit_msgs, msg, Constraints
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->path_constraints))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_wrapper_interfaces
size_t get_serialized_size_moveit_wrapper_interfaces__msg__Waypoint(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Waypoint__ros_msg_type * ros_message = static_cast<const _Waypoint__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pose

  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->pose), current_alignment);
  // field.name named_target
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->named_target.size + 1);
  // field.name linear_movement
  {
    size_t item_size = sizeof(ros_message->linear_movement);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name linear_eef_step
  {
    size_t item_size = sizeof(ros_message->linear_eef_step);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name linear_jump_thresh
  {
    size_t item_size = sizeof(ros_message->linear_jump_thresh);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name linear_disable_collisions
  {
    size_t item_size = sizeof(ros_message->linear_disable_collisions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name path_constraints

  current_alignment += get_serialized_size_moveit_msgs__msg__Constraints(
    &(ros_message->path_constraints), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Waypoint__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_moveit_wrapper_interfaces__msg__Waypoint(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_wrapper_interfaces
size_t max_serialized_size_moveit_wrapper_interfaces__msg__Waypoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: pose
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: named_target
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: linear_movement
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: linear_eef_step
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: linear_jump_thresh
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: linear_disable_collisions
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: path_constraints
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_moveit_msgs__msg__Constraints(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = moveit_wrapper_interfaces__msg__Waypoint;
    is_plain =
      (
      offsetof(DataType, path_constraints) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Waypoint__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_moveit_wrapper_interfaces__msg__Waypoint(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Waypoint = {
  "moveit_wrapper_interfaces::msg",
  "Waypoint",
  _Waypoint__cdr_serialize,
  _Waypoint__cdr_deserialize,
  _Waypoint__get_serialized_size,
  _Waypoint__max_serialized_size
};

static rosidl_message_type_support_t _Waypoint__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Waypoint,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, msg, Waypoint)() {
  return &_Waypoint__type_support;
}

#if defined(__cplusplus)
}
#endif

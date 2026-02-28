// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "moveit_wrapper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__struct.h"
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__functions.h"
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

#include "moveit_msgs/msg/detail/constraints__functions.h"  // path_constraints
#include "moveit_wrapper_interfaces/msg/detail/waypoint__functions.h"  // waypoints
#include "rosidl_runtime_c/string.h"  // sequence_id
#include "rosidl_runtime_c/string_functions.h"  // sequence_id

// forward declare type support functions
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
size_t get_serialized_size_moveit_wrapper_interfaces__msg__Waypoint(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_moveit_wrapper_interfaces__msg__Waypoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, msg, Waypoint)();


using _WaypointSequence__ros_msg_type = moveit_wrapper_interfaces__msg__WaypointSequence;

static bool _WaypointSequence__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _WaypointSequence__ros_msg_type * ros_message = static_cast<const _WaypointSequence__ros_msg_type *>(untyped_ros_message);
  // Field name: sequence_id
  {
    const rosidl_runtime_c__String * str = &ros_message->sequence_id;
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

  // Field name: waypoints
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, msg, Waypoint
      )()->data);
    size_t size = ros_message->waypoints.size;
    auto array_ptr = ros_message->waypoints.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
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

  // Field name: use_linear_interpolation
  {
    cdr << (ros_message->use_linear_interpolation ? true : false);
  }

  // Field name: velocity_scaling
  {
    cdr << ros_message->velocity_scaling;
  }

  // Field name: acceleration_scaling
  {
    cdr << ros_message->acceleration_scaling;
  }

  return true;
}

static bool _WaypointSequence__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _WaypointSequence__ros_msg_type * ros_message = static_cast<_WaypointSequence__ros_msg_type *>(untyped_ros_message);
  // Field name: sequence_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->sequence_id.data) {
      rosidl_runtime_c__String__init(&ros_message->sequence_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->sequence_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'sequence_id'\n");
      return false;
    }
  }

  // Field name: waypoints
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, msg, Waypoint
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->waypoints.data) {
      moveit_wrapper_interfaces__msg__Waypoint__Sequence__fini(&ros_message->waypoints);
    }
    if (!moveit_wrapper_interfaces__msg__Waypoint__Sequence__init(&ros_message->waypoints, size)) {
      fprintf(stderr, "failed to create array for field 'waypoints'");
      return false;
    }
    auto array_ptr = ros_message->waypoints.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
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

  // Field name: use_linear_interpolation
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->use_linear_interpolation = tmp ? true : false;
  }

  // Field name: velocity_scaling
  {
    cdr >> ros_message->velocity_scaling;
  }

  // Field name: acceleration_scaling
  {
    cdr >> ros_message->acceleration_scaling;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_wrapper_interfaces
size_t get_serialized_size_moveit_wrapper_interfaces__msg__WaypointSequence(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WaypointSequence__ros_msg_type * ros_message = static_cast<const _WaypointSequence__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name sequence_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sequence_id.size + 1);
  // field.name waypoints
  {
    size_t array_size = ros_message->waypoints.size;
    auto array_ptr = ros_message->waypoints.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_moveit_wrapper_interfaces__msg__Waypoint(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name path_constraints

  current_alignment += get_serialized_size_moveit_msgs__msg__Constraints(
    &(ros_message->path_constraints), current_alignment);
  // field.name use_linear_interpolation
  {
    size_t item_size = sizeof(ros_message->use_linear_interpolation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name velocity_scaling
  {
    size_t item_size = sizeof(ros_message->velocity_scaling);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acceleration_scaling
  {
    size_t item_size = sizeof(ros_message->acceleration_scaling);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _WaypointSequence__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_moveit_wrapper_interfaces__msg__WaypointSequence(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_wrapper_interfaces
size_t max_serialized_size_moveit_wrapper_interfaces__msg__WaypointSequence(
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

  // member: sequence_id
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
  // member: waypoints
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_moveit_wrapper_interfaces__msg__Waypoint(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
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
  // member: use_linear_interpolation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: velocity_scaling
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: acceleration_scaling
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = moveit_wrapper_interfaces__msg__WaypointSequence;
    is_plain =
      (
      offsetof(DataType, acceleration_scaling) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _WaypointSequence__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_moveit_wrapper_interfaces__msg__WaypointSequence(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_WaypointSequence = {
  "moveit_wrapper_interfaces::msg",
  "WaypointSequence",
  _WaypointSequence__cdr_serialize,
  _WaypointSequence__cdr_deserialize,
  _WaypointSequence__get_serialized_size,
  _WaypointSequence__max_serialized_size
};

static rosidl_message_type_support_t _WaypointSequence__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_WaypointSequence,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, msg, WaypointSequence)() {
  return &_WaypointSequence__type_support;
}

#if defined(__cplusplus)
}
#endif

// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from moveit_wrapper_interfaces:srv/PlanJoints.idl
// generated code does not contain a copyright notice
#include "moveit_wrapper_interfaces/srv/detail/plan_joints__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "moveit_wrapper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "moveit_wrapper_interfaces/srv/detail/plan_joints__struct.h"
#include "moveit_wrapper_interfaces/srv/detail/plan_joints__functions.h"
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
#include "moveit_msgs/msg/detail/robot_state__functions.h"  // start_state
#include "rosidl_runtime_c/string.h"  // move_group
#include "rosidl_runtime_c/string_functions.h"  // move_group
#include "sensor_msgs/msg/detail/joint_state__functions.h"  // joint_states

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
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t get_serialized_size_moveit_msgs__msg__RobotState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t max_serialized_size_moveit_msgs__msg__RobotState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_msgs, msg, RobotState)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t get_serialized_size_sensor_msgs__msg__JointState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t max_serialized_size_sensor_msgs__msg__JointState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, JointState)();


using _PlanJoints_Request__ros_msg_type = moveit_wrapper_interfaces__srv__PlanJoints_Request;

static bool _PlanJoints_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PlanJoints_Request__ros_msg_type * ros_message = static_cast<const _PlanJoints_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: joint_states
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, JointState
      )()->data);
    size_t size = ros_message->joint_states.size;
    auto array_ptr = ros_message->joint_states.data;
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

  // Field name: send_partial
  {
    cdr << (ros_message->send_partial ? true : false);
  }

  // Field name: use_start_state
  {
    cdr << (ros_message->use_start_state ? true : false);
  }

  // Field name: start_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, moveit_msgs, msg, RobotState
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->start_state, cdr))
    {
      return false;
    }
  }

  // Field name: move_group
  {
    const rosidl_runtime_c__String * str = &ros_message->move_group;
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

  return true;
}

static bool _PlanJoints_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PlanJoints_Request__ros_msg_type * ros_message = static_cast<_PlanJoints_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: joint_states
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, JointState
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

    if (ros_message->joint_states.data) {
      sensor_msgs__msg__JointState__Sequence__fini(&ros_message->joint_states);
    }
    if (!sensor_msgs__msg__JointState__Sequence__init(&ros_message->joint_states, size)) {
      fprintf(stderr, "failed to create array for field 'joint_states'");
      return false;
    }
    auto array_ptr = ros_message->joint_states.data;
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

  // Field name: send_partial
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->send_partial = tmp ? true : false;
  }

  // Field name: use_start_state
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->use_start_state = tmp ? true : false;
  }

  // Field name: start_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, moveit_msgs, msg, RobotState
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->start_state))
    {
      return false;
    }
  }

  // Field name: move_group
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->move_group.data) {
      rosidl_runtime_c__String__init(&ros_message->move_group);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->move_group,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'move_group'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_wrapper_interfaces
size_t get_serialized_size_moveit_wrapper_interfaces__srv__PlanJoints_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PlanJoints_Request__ros_msg_type * ros_message = static_cast<const _PlanJoints_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name joint_states
  {
    size_t array_size = ros_message->joint_states.size;
    auto array_ptr = ros_message->joint_states.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_sensor_msgs__msg__JointState(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name path_constraints

  current_alignment += get_serialized_size_moveit_msgs__msg__Constraints(
    &(ros_message->path_constraints), current_alignment);
  // field.name send_partial
  {
    size_t item_size = sizeof(ros_message->send_partial);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name use_start_state
  {
    size_t item_size = sizeof(ros_message->use_start_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name start_state

  current_alignment += get_serialized_size_moveit_msgs__msg__RobotState(
    &(ros_message->start_state), current_alignment);
  // field.name move_group
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->move_group.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _PlanJoints_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_moveit_wrapper_interfaces__srv__PlanJoints_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_wrapper_interfaces
size_t max_serialized_size_moveit_wrapper_interfaces__srv__PlanJoints_Request(
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

  // member: joint_states
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
        max_serialized_size_sensor_msgs__msg__JointState(
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
  // member: send_partial
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: use_start_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: start_state
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_moveit_msgs__msg__RobotState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: move_group
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = moveit_wrapper_interfaces__srv__PlanJoints_Request;
    is_plain =
      (
      offsetof(DataType, move_group) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PlanJoints_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_moveit_wrapper_interfaces__srv__PlanJoints_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PlanJoints_Request = {
  "moveit_wrapper_interfaces::srv",
  "PlanJoints_Request",
  _PlanJoints_Request__cdr_serialize,
  _PlanJoints_Request__cdr_deserialize,
  _PlanJoints_Request__get_serialized_size,
  _PlanJoints_Request__max_serialized_size
};

static rosidl_message_type_support_t _PlanJoints_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PlanJoints_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, srv, PlanJoints_Request)() {
  return &_PlanJoints_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "moveit_wrapper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "moveit_wrapper_interfaces/srv/detail/plan_joints__struct.h"
// already included above
// #include "moveit_wrapper_interfaces/srv/detail/plan_joints__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "moveit_msgs/msg/detail/robot_trajectory__functions.h"  // plans
// already included above
// #include "rosidl_runtime_c/string.h"  // message
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // message

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t get_serialized_size_moveit_msgs__msg__RobotTrajectory(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
size_t max_serialized_size_moveit_msgs__msg__RobotTrajectory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_msgs, msg, RobotTrajectory)();


using _PlanJoints_Response__ros_msg_type = moveit_wrapper_interfaces__srv__PlanJoints_Response;

static bool _PlanJoints_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PlanJoints_Response__ros_msg_type * ros_message = static_cast<const _PlanJoints_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: message
  {
    const rosidl_runtime_c__String * str = &ros_message->message;
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

  // Field name: plans
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, moveit_msgs, msg, RobotTrajectory
      )()->data);
    size_t size = ros_message->plans.size;
    auto array_ptr = ros_message->plans.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _PlanJoints_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PlanJoints_Response__ros_msg_type * ros_message = static_cast<_PlanJoints_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: message
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->message.data) {
      rosidl_runtime_c__String__init(&ros_message->message);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->message,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'message'\n");
      return false;
    }
  }

  // Field name: plans
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, moveit_msgs, msg, RobotTrajectory
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

    if (ros_message->plans.data) {
      moveit_msgs__msg__RobotTrajectory__Sequence__fini(&ros_message->plans);
    }
    if (!moveit_msgs__msg__RobotTrajectory__Sequence__init(&ros_message->plans, size)) {
      fprintf(stderr, "failed to create array for field 'plans'");
      return false;
    }
    auto array_ptr = ros_message->plans.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_wrapper_interfaces
size_t get_serialized_size_moveit_wrapper_interfaces__srv__PlanJoints_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PlanJoints_Response__ros_msg_type * ros_message = static_cast<const _PlanJoints_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->message.size + 1);
  // field.name plans
  {
    size_t array_size = ros_message->plans.size;
    auto array_ptr = ros_message->plans.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_moveit_msgs__msg__RobotTrajectory(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PlanJoints_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_moveit_wrapper_interfaces__srv__PlanJoints_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_wrapper_interfaces
size_t max_serialized_size_moveit_wrapper_interfaces__srv__PlanJoints_Response(
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

  // member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: message
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
  // member: plans
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
        max_serialized_size_moveit_msgs__msg__RobotTrajectory(
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
    using DataType = moveit_wrapper_interfaces__srv__PlanJoints_Response;
    is_plain =
      (
      offsetof(DataType, plans) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PlanJoints_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_moveit_wrapper_interfaces__srv__PlanJoints_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PlanJoints_Response = {
  "moveit_wrapper_interfaces::srv",
  "PlanJoints_Response",
  _PlanJoints_Response__cdr_serialize,
  _PlanJoints_Response__cdr_deserialize,
  _PlanJoints_Response__get_serialized_size,
  _PlanJoints_Response__max_serialized_size
};

static rosidl_message_type_support_t _PlanJoints_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PlanJoints_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, srv, PlanJoints_Response)() {
  return &_PlanJoints_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "moveit_wrapper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "moveit_wrapper_interfaces/srv/plan_joints.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t PlanJoints__callbacks = {
  "moveit_wrapper_interfaces::srv",
  "PlanJoints",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, srv, PlanJoints_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, srv, PlanJoints_Response)(),
};

static rosidl_service_type_support_t PlanJoints__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &PlanJoints__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_wrapper_interfaces, srv, PlanJoints)() {
  return &PlanJoints__handle;
}

#if defined(__cplusplus)
}
#endif

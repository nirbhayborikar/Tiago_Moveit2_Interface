// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from moveit_wrapper_interfaces:srv/PlanJoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "moveit_wrapper_interfaces/srv/detail/plan_joints__rosidl_typesupport_introspection_c.h"
#include "moveit_wrapper_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "moveit_wrapper_interfaces/srv/detail/plan_joints__functions.h"
#include "moveit_wrapper_interfaces/srv/detail/plan_joints__struct.h"


// Include directives for member types
// Member `joint_states`
#include "sensor_msgs/msg/joint_state.h"
// Member `joint_states`
#include "sensor_msgs/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"
// Member `path_constraints`
#include "moveit_msgs/msg/constraints.h"
// Member `path_constraints`
#include "moveit_msgs/msg/detail/constraints__rosidl_typesupport_introspection_c.h"
// Member `start_state`
#include "moveit_msgs/msg/robot_state.h"
// Member `start_state`
#include "moveit_msgs/msg/detail/robot_state__rosidl_typesupport_introspection_c.h"
// Member `move_group`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  moveit_wrapper_interfaces__srv__PlanJoints_Request__init(message_memory);
}

void moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_fini_function(void * message_memory)
{
  moveit_wrapper_interfaces__srv__PlanJoints_Request__fini(message_memory);
}

size_t moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__size_function__PlanJoints_Request__joint_states(
  const void * untyped_member)
{
  const sensor_msgs__msg__JointState__Sequence * member =
    (const sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return member->size;
}

const void * moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__get_const_function__PlanJoints_Request__joint_states(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__JointState__Sequence * member =
    (const sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__get_function__PlanJoints_Request__joint_states(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__JointState__Sequence * member =
    (sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return &member->data[index];
}

void moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__fetch_function__PlanJoints_Request__joint_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__JointState * item =
    ((const sensor_msgs__msg__JointState *)
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__get_const_function__PlanJoints_Request__joint_states(untyped_member, index));
  sensor_msgs__msg__JointState * value =
    (sensor_msgs__msg__JointState *)(untyped_value);
  *value = *item;
}

void moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__assign_function__PlanJoints_Request__joint_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__JointState * item =
    ((sensor_msgs__msg__JointState *)
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__get_function__PlanJoints_Request__joint_states(untyped_member, index));
  const sensor_msgs__msg__JointState * value =
    (const sensor_msgs__msg__JointState *)(untyped_value);
  *item = *value;
}

bool moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__resize_function__PlanJoints_Request__joint_states(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__JointState__Sequence * member =
    (sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  sensor_msgs__msg__JointState__Sequence__fini(member);
  return sensor_msgs__msg__JointState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_member_array[6] = {
  {
    "joint_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Request, joint_states),  // bytes offset in struct
    NULL,  // default value
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__size_function__PlanJoints_Request__joint_states,  // size() function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__get_const_function__PlanJoints_Request__joint_states,  // get_const(index) function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__get_function__PlanJoints_Request__joint_states,  // get(index) function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__fetch_function__PlanJoints_Request__joint_states,  // fetch(index, &value) function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__assign_function__PlanJoints_Request__joint_states,  // assign(index, value) function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__resize_function__PlanJoints_Request__joint_states  // resize(index) function pointer
  },
  {
    "path_constraints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Request, path_constraints),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "send_partial",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Request, send_partial),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "use_start_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Request, use_start_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Request, start_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "move_group",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Request, move_group),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_members = {
  "moveit_wrapper_interfaces__srv",  // message namespace
  "PlanJoints_Request",  // message name
  6,  // number of fields
  sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Request),
  moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_member_array,  // message members
  moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_type_support_handle = {
  0,
  &moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, srv, PlanJoints_Request)() {
  moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, JointState)();
  moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_msgs, msg, Constraints)();
  moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_msgs, msg, RobotState)();
  if (!moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_type_support_handle.typesupport_identifier) {
    moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &moveit_wrapper_interfaces__srv__PlanJoints_Request__rosidl_typesupport_introspection_c__PlanJoints_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "moveit_wrapper_interfaces/srv/detail/plan_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "moveit_wrapper_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "moveit_wrapper_interfaces/srv/detail/plan_joints__functions.h"
// already included above
// #include "moveit_wrapper_interfaces/srv/detail/plan_joints__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `plans`
#include "moveit_msgs/msg/robot_trajectory.h"
// Member `plans`
#include "moveit_msgs/msg/detail/robot_trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  moveit_wrapper_interfaces__srv__PlanJoints_Response__init(message_memory);
}

void moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_fini_function(void * message_memory)
{
  moveit_wrapper_interfaces__srv__PlanJoints_Response__fini(message_memory);
}

size_t moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__size_function__PlanJoints_Response__plans(
  const void * untyped_member)
{
  const moveit_msgs__msg__RobotTrajectory__Sequence * member =
    (const moveit_msgs__msg__RobotTrajectory__Sequence *)(untyped_member);
  return member->size;
}

const void * moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__get_const_function__PlanJoints_Response__plans(
  const void * untyped_member, size_t index)
{
  const moveit_msgs__msg__RobotTrajectory__Sequence * member =
    (const moveit_msgs__msg__RobotTrajectory__Sequence *)(untyped_member);
  return &member->data[index];
}

void * moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__get_function__PlanJoints_Response__plans(
  void * untyped_member, size_t index)
{
  moveit_msgs__msg__RobotTrajectory__Sequence * member =
    (moveit_msgs__msg__RobotTrajectory__Sequence *)(untyped_member);
  return &member->data[index];
}

void moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__fetch_function__PlanJoints_Response__plans(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const moveit_msgs__msg__RobotTrajectory * item =
    ((const moveit_msgs__msg__RobotTrajectory *)
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__get_const_function__PlanJoints_Response__plans(untyped_member, index));
  moveit_msgs__msg__RobotTrajectory * value =
    (moveit_msgs__msg__RobotTrajectory *)(untyped_value);
  *value = *item;
}

void moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__assign_function__PlanJoints_Response__plans(
  void * untyped_member, size_t index, const void * untyped_value)
{
  moveit_msgs__msg__RobotTrajectory * item =
    ((moveit_msgs__msg__RobotTrajectory *)
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__get_function__PlanJoints_Response__plans(untyped_member, index));
  const moveit_msgs__msg__RobotTrajectory * value =
    (const moveit_msgs__msg__RobotTrajectory *)(untyped_value);
  *item = *value;
}

bool moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__resize_function__PlanJoints_Response__plans(
  void * untyped_member, size_t size)
{
  moveit_msgs__msg__RobotTrajectory__Sequence * member =
    (moveit_msgs__msg__RobotTrajectory__Sequence *)(untyped_member);
  moveit_msgs__msg__RobotTrajectory__Sequence__fini(member);
  return moveit_msgs__msg__RobotTrajectory__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_member_array[3] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "plans",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_wrapper_interfaces__srv__PlanJoints_Response, plans),  // bytes offset in struct
    NULL,  // default value
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__size_function__PlanJoints_Response__plans,  // size() function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__get_const_function__PlanJoints_Response__plans,  // get_const(index) function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__get_function__PlanJoints_Response__plans,  // get(index) function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__fetch_function__PlanJoints_Response__plans,  // fetch(index, &value) function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__assign_function__PlanJoints_Response__plans,  // assign(index, value) function pointer
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__resize_function__PlanJoints_Response__plans  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_members = {
  "moveit_wrapper_interfaces__srv",  // message namespace
  "PlanJoints_Response",  // message name
  3,  // number of fields
  sizeof(moveit_wrapper_interfaces__srv__PlanJoints_Response),
  moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_member_array,  // message members
  moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_type_support_handle = {
  0,
  &moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, srv, PlanJoints_Response)() {
  moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_msgs, msg, RobotTrajectory)();
  if (!moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_type_support_handle.typesupport_identifier) {
    moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &moveit_wrapper_interfaces__srv__PlanJoints_Response__rosidl_typesupport_introspection_c__PlanJoints_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "moveit_wrapper_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "moveit_wrapper_interfaces/srv/detail/plan_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_service_members = {
  "moveit_wrapper_interfaces__srv",  // service namespace
  "PlanJoints",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_Request_message_type_support_handle,
  NULL  // response message
  // moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_Response_message_type_support_handle
};

static rosidl_service_type_support_t moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_service_type_support_handle = {
  0,
  &moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, srv, PlanJoints_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, srv, PlanJoints_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_wrapper_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, srv, PlanJoints)() {
  if (!moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_service_type_support_handle.typesupport_identifier) {
    moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, srv, PlanJoints_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_wrapper_interfaces, srv, PlanJoints_Response)()->data;
  }

  return &moveit_wrapper_interfaces__srv__detail__plan_joints__rosidl_typesupport_introspection_c__PlanJoints_service_type_support_handle;
}

// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
// generated code does not contain a copyright notice
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__rosidl_typesupport_fastrtps_cpp.hpp"
#include "moveit_wrapper_interfaces/msg/detail/waypoint_sequence__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace moveit_wrapper_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const moveit_wrapper_interfaces::msg::Waypoint &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  moveit_wrapper_interfaces::msg::Waypoint &);
size_t get_serialized_size(
  const moveit_wrapper_interfaces::msg::Waypoint &,
  size_t current_alignment);
size_t
max_serialized_size_Waypoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace moveit_wrapper_interfaces

namespace moveit_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const moveit_msgs::msg::Constraints &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  moveit_msgs::msg::Constraints &);
size_t get_serialized_size(
  const moveit_msgs::msg::Constraints &,
  size_t current_alignment);
size_t
max_serialized_size_Constraints(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace moveit_msgs


namespace moveit_wrapper_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_moveit_wrapper_interfaces
cdr_serialize(
  const moveit_wrapper_interfaces::msg::WaypointSequence & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: sequence_id
  cdr << ros_message.sequence_id;
  // Member: waypoints
  {
    size_t size = ros_message.waypoints.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      moveit_wrapper_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.waypoints[i],
        cdr);
    }
  }
  // Member: path_constraints
  moveit_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.path_constraints,
    cdr);
  // Member: use_linear_interpolation
  cdr << (ros_message.use_linear_interpolation ? true : false);
  // Member: velocity_scaling
  cdr << ros_message.velocity_scaling;
  // Member: acceleration_scaling
  cdr << ros_message.acceleration_scaling;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_moveit_wrapper_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  moveit_wrapper_interfaces::msg::WaypointSequence & ros_message)
{
  // Member: sequence_id
  cdr >> ros_message.sequence_id;

  // Member: waypoints
  {
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

    ros_message.waypoints.resize(size);
    for (size_t i = 0; i < size; i++) {
      moveit_wrapper_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.waypoints[i]);
    }
  }

  // Member: path_constraints
  moveit_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.path_constraints);

  // Member: use_linear_interpolation
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.use_linear_interpolation = tmp ? true : false;
  }

  // Member: velocity_scaling
  cdr >> ros_message.velocity_scaling;

  // Member: acceleration_scaling
  cdr >> ros_message.acceleration_scaling;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_moveit_wrapper_interfaces
get_serialized_size(
  const moveit_wrapper_interfaces::msg::WaypointSequence & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: sequence_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.sequence_id.size() + 1);
  // Member: waypoints
  {
    size_t array_size = ros_message.waypoints.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        moveit_wrapper_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.waypoints[index], current_alignment);
    }
  }
  // Member: path_constraints

  current_alignment +=
    moveit_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.path_constraints, current_alignment);
  // Member: use_linear_interpolation
  {
    size_t item_size = sizeof(ros_message.use_linear_interpolation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: velocity_scaling
  {
    size_t item_size = sizeof(ros_message.velocity_scaling);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acceleration_scaling
  {
    size_t item_size = sizeof(ros_message.acceleration_scaling);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_moveit_wrapper_interfaces
max_serialized_size_WaypointSequence(
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


  // Member: sequence_id
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

  // Member: waypoints
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
      size_t inner_size =
        moveit_wrapper_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Waypoint(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: path_constraints
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        moveit_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Constraints(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: use_linear_interpolation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: velocity_scaling
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: acceleration_scaling
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
    using DataType = moveit_wrapper_interfaces::msg::WaypointSequence;
    is_plain =
      (
      offsetof(DataType, acceleration_scaling) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _WaypointSequence__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const moveit_wrapper_interfaces::msg::WaypointSequence *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _WaypointSequence__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<moveit_wrapper_interfaces::msg::WaypointSequence *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _WaypointSequence__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const moveit_wrapper_interfaces::msg::WaypointSequence *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _WaypointSequence__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_WaypointSequence(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _WaypointSequence__callbacks = {
  "moveit_wrapper_interfaces::msg",
  "WaypointSequence",
  _WaypointSequence__cdr_serialize,
  _WaypointSequence__cdr_deserialize,
  _WaypointSequence__get_serialized_size,
  _WaypointSequence__max_serialized_size
};

static rosidl_message_type_support_t _WaypointSequence__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_WaypointSequence__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace moveit_wrapper_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_moveit_wrapper_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<moveit_wrapper_interfaces::msg::WaypointSequence>()
{
  return &moveit_wrapper_interfaces::msg::typesupport_fastrtps_cpp::_WaypointSequence__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, moveit_wrapper_interfaces, msg, WaypointSequence)() {
  return &moveit_wrapper_interfaces::msg::typesupport_fastrtps_cpp::_WaypointSequence__handle;
}

#ifdef __cplusplus
}
#endif

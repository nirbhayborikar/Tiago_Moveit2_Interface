// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:action/DriveToWallA.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__ACTION__DETAIL__DRIVE_TO_WALL_A__BUILDER_HPP_
#define CUSTOM_INTERFACES__ACTION__DETAIL__DRIVE_TO_WALL_A__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/action/detail/drive_to_wall_a__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DriveToWallA_Goal_min_distance
{
public:
  explicit Init_DriveToWallA_Goal_min_distance(::custom_interfaces::action::DriveToWallA_Goal & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DriveToWallA_Goal min_distance(::custom_interfaces::action::DriveToWallA_Goal::_min_distance_type arg)
  {
    msg_.min_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_Goal msg_;
};

class Init_DriveToWallA_Goal_linear_x
{
public:
  Init_DriveToWallA_Goal_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallA_Goal_min_distance linear_x(::custom_interfaces::action::DriveToWallA_Goal::_linear_x_type arg)
  {
    msg_.linear_x = std::move(arg);
    return Init_DriveToWallA_Goal_min_distance(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DriveToWallA_Goal>()
{
  return custom_interfaces::action::builder::Init_DriveToWallA_Goal_linear_x();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DriveToWallA_Result_success
{
public:
  explicit Init_DriveToWallA_Result_success(::custom_interfaces::action::DriveToWallA_Result & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DriveToWallA_Result success(::custom_interfaces::action::DriveToWallA_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_Result msg_;
};

class Init_DriveToWallA_Result_message
{
public:
  Init_DriveToWallA_Result_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallA_Result_success message(::custom_interfaces::action::DriveToWallA_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_DriveToWallA_Result_success(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DriveToWallA_Result>()
{
  return custom_interfaces::action::builder::Init_DriveToWallA_Result_message();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DriveToWallA_Feedback_current_distance
{
public:
  Init_DriveToWallA_Feedback_current_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::DriveToWallA_Feedback current_distance(::custom_interfaces::action::DriveToWallA_Feedback::_current_distance_type arg)
  {
    msg_.current_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DriveToWallA_Feedback>()
{
  return custom_interfaces::action::builder::Init_DriveToWallA_Feedback_current_distance();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DriveToWallA_SendGoal_Request_goal
{
public:
  explicit Init_DriveToWallA_SendGoal_Request_goal(::custom_interfaces::action::DriveToWallA_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DriveToWallA_SendGoal_Request goal(::custom_interfaces::action::DriveToWallA_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_SendGoal_Request msg_;
};

class Init_DriveToWallA_SendGoal_Request_goal_id
{
public:
  Init_DriveToWallA_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallA_SendGoal_Request_goal goal_id(::custom_interfaces::action::DriveToWallA_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DriveToWallA_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DriveToWallA_SendGoal_Request>()
{
  return custom_interfaces::action::builder::Init_DriveToWallA_SendGoal_Request_goal_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DriveToWallA_SendGoal_Response_stamp
{
public:
  explicit Init_DriveToWallA_SendGoal_Response_stamp(::custom_interfaces::action::DriveToWallA_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DriveToWallA_SendGoal_Response stamp(::custom_interfaces::action::DriveToWallA_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_SendGoal_Response msg_;
};

class Init_DriveToWallA_SendGoal_Response_accepted
{
public:
  Init_DriveToWallA_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallA_SendGoal_Response_stamp accepted(::custom_interfaces::action::DriveToWallA_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_DriveToWallA_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DriveToWallA_SendGoal_Response>()
{
  return custom_interfaces::action::builder::Init_DriveToWallA_SendGoal_Response_accepted();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DriveToWallA_GetResult_Request_goal_id
{
public:
  Init_DriveToWallA_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::DriveToWallA_GetResult_Request goal_id(::custom_interfaces::action::DriveToWallA_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DriveToWallA_GetResult_Request>()
{
  return custom_interfaces::action::builder::Init_DriveToWallA_GetResult_Request_goal_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DriveToWallA_GetResult_Response_result
{
public:
  explicit Init_DriveToWallA_GetResult_Response_result(::custom_interfaces::action::DriveToWallA_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DriveToWallA_GetResult_Response result(::custom_interfaces::action::DriveToWallA_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_GetResult_Response msg_;
};

class Init_DriveToWallA_GetResult_Response_status
{
public:
  Init_DriveToWallA_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallA_GetResult_Response_result status(::custom_interfaces::action::DriveToWallA_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_DriveToWallA_GetResult_Response_result(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DriveToWallA_GetResult_Response>()
{
  return custom_interfaces::action::builder::Init_DriveToWallA_GetResult_Response_status();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DriveToWallA_FeedbackMessage_feedback
{
public:
  explicit Init_DriveToWallA_FeedbackMessage_feedback(::custom_interfaces::action::DriveToWallA_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DriveToWallA_FeedbackMessage feedback(::custom_interfaces::action::DriveToWallA_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_FeedbackMessage msg_;
};

class Init_DriveToWallA_FeedbackMessage_goal_id
{
public:
  Init_DriveToWallA_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveToWallA_FeedbackMessage_feedback goal_id(::custom_interfaces::action::DriveToWallA_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DriveToWallA_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_interfaces::action::DriveToWallA_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DriveToWallA_FeedbackMessage>()
{
  return custom_interfaces::action::builder::Init_DriveToWallA_FeedbackMessage_goal_id();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__ACTION__DETAIL__DRIVE_TO_WALL_A__BUILDER_HPP_

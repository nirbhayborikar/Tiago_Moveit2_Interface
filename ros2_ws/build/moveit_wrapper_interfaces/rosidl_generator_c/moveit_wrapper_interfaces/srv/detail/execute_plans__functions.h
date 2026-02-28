// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from moveit_wrapper_interfaces:srv/ExecutePlans.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__EXECUTE_PLANS__FUNCTIONS_H_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__EXECUTE_PLANS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "moveit_wrapper_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "moveit_wrapper_interfaces/srv/detail/execute_plans__struct.h"

/// Initialize srv/ExecutePlans message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * moveit_wrapper_interfaces__srv__ExecutePlans_Request
 * )) before or use
 * moveit_wrapper_interfaces__srv__ExecutePlans_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Request__init(moveit_wrapper_interfaces__srv__ExecutePlans_Request * msg);

/// Finalize srv/ExecutePlans message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__ExecutePlans_Request__fini(moveit_wrapper_interfaces__srv__ExecutePlans_Request * msg);

/// Create srv/ExecutePlans message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
moveit_wrapper_interfaces__srv__ExecutePlans_Request *
moveit_wrapper_interfaces__srv__ExecutePlans_Request__create();

/// Destroy srv/ExecutePlans message.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__ExecutePlans_Request__destroy(moveit_wrapper_interfaces__srv__ExecutePlans_Request * msg);

/// Check for srv/ExecutePlans message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Request__are_equal(const moveit_wrapper_interfaces__srv__ExecutePlans_Request * lhs, const moveit_wrapper_interfaces__srv__ExecutePlans_Request * rhs);

/// Copy a srv/ExecutePlans message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Request__copy(
  const moveit_wrapper_interfaces__srv__ExecutePlans_Request * input,
  moveit_wrapper_interfaces__srv__ExecutePlans_Request * output);

/// Initialize array of srv/ExecutePlans messages.
/**
 * It allocates the memory for the number of elements and calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence__init(moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence * array, size_t size);

/// Finalize array of srv/ExecutePlans messages.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence__fini(moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence * array);

/// Create array of srv/ExecutePlans messages.
/**
 * It allocates the memory for the array and calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence *
moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence__create(size_t size);

/// Destroy array of srv/ExecutePlans messages.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence__destroy(moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence * array);

/// Check for srv/ExecutePlans message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence__are_equal(const moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence * lhs, const moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence * rhs);

/// Copy an array of srv/ExecutePlans messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence__copy(
  const moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence * input,
  moveit_wrapper_interfaces__srv__ExecutePlans_Request__Sequence * output);

/// Initialize srv/ExecutePlans message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * moveit_wrapper_interfaces__srv__ExecutePlans_Response
 * )) before or use
 * moveit_wrapper_interfaces__srv__ExecutePlans_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Response__init(moveit_wrapper_interfaces__srv__ExecutePlans_Response * msg);

/// Finalize srv/ExecutePlans message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__ExecutePlans_Response__fini(moveit_wrapper_interfaces__srv__ExecutePlans_Response * msg);

/// Create srv/ExecutePlans message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
moveit_wrapper_interfaces__srv__ExecutePlans_Response *
moveit_wrapper_interfaces__srv__ExecutePlans_Response__create();

/// Destroy srv/ExecutePlans message.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__ExecutePlans_Response__destroy(moveit_wrapper_interfaces__srv__ExecutePlans_Response * msg);

/// Check for srv/ExecutePlans message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Response__are_equal(const moveit_wrapper_interfaces__srv__ExecutePlans_Response * lhs, const moveit_wrapper_interfaces__srv__ExecutePlans_Response * rhs);

/// Copy a srv/ExecutePlans message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Response__copy(
  const moveit_wrapper_interfaces__srv__ExecutePlans_Response * input,
  moveit_wrapper_interfaces__srv__ExecutePlans_Response * output);

/// Initialize array of srv/ExecutePlans messages.
/**
 * It allocates the memory for the number of elements and calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence__init(moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence * array, size_t size);

/// Finalize array of srv/ExecutePlans messages.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence__fini(moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence * array);

/// Create array of srv/ExecutePlans messages.
/**
 * It allocates the memory for the array and calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence *
moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence__create(size_t size);

/// Destroy array of srv/ExecutePlans messages.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence__destroy(moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence * array);

/// Check for srv/ExecutePlans message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence__are_equal(const moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence * lhs, const moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence * rhs);

/// Copy an array of srv/ExecutePlans messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence__copy(
  const moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence * input,
  moveit_wrapper_interfaces__srv__ExecutePlans_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__EXECUTE_PLANS__FUNCTIONS_H_

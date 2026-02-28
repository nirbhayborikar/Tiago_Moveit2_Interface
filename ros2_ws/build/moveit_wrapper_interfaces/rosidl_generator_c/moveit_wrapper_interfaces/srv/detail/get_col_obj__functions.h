// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from moveit_wrapper_interfaces:srv/GetColObj.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__FUNCTIONS_H_
#define MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "moveit_wrapper_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "moveit_wrapper_interfaces/srv/detail/get_col_obj__struct.h"

/// Initialize srv/GetColObj message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * moveit_wrapper_interfaces__srv__GetColObj_Request
 * )) before or use
 * moveit_wrapper_interfaces__srv__GetColObj_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__GetColObj_Request__init(moveit_wrapper_interfaces__srv__GetColObj_Request * msg);

/// Finalize srv/GetColObj message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__GetColObj_Request__fini(moveit_wrapper_interfaces__srv__GetColObj_Request * msg);

/// Create srv/GetColObj message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * moveit_wrapper_interfaces__srv__GetColObj_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
moveit_wrapper_interfaces__srv__GetColObj_Request *
moveit_wrapper_interfaces__srv__GetColObj_Request__create();

/// Destroy srv/GetColObj message.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__GetColObj_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__GetColObj_Request__destroy(moveit_wrapper_interfaces__srv__GetColObj_Request * msg);

/// Check for srv/GetColObj message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__GetColObj_Request__are_equal(const moveit_wrapper_interfaces__srv__GetColObj_Request * lhs, const moveit_wrapper_interfaces__srv__GetColObj_Request * rhs);

/// Copy a srv/GetColObj message.
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
moveit_wrapper_interfaces__srv__GetColObj_Request__copy(
  const moveit_wrapper_interfaces__srv__GetColObj_Request * input,
  moveit_wrapper_interfaces__srv__GetColObj_Request * output);

/// Initialize array of srv/GetColObj messages.
/**
 * It allocates the memory for the number of elements and calls
 * moveit_wrapper_interfaces__srv__GetColObj_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence__init(moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence * array, size_t size);

/// Finalize array of srv/GetColObj messages.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__GetColObj_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence__fini(moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence * array);

/// Create array of srv/GetColObj messages.
/**
 * It allocates the memory for the array and calls
 * moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence *
moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence__create(size_t size);

/// Destroy array of srv/GetColObj messages.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence__destroy(moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence * array);

/// Check for srv/GetColObj message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence__are_equal(const moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence * lhs, const moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence * rhs);

/// Copy an array of srv/GetColObj messages.
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
moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence__copy(
  const moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence * input,
  moveit_wrapper_interfaces__srv__GetColObj_Request__Sequence * output);

/// Initialize srv/GetColObj message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * moveit_wrapper_interfaces__srv__GetColObj_Response
 * )) before or use
 * moveit_wrapper_interfaces__srv__GetColObj_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__GetColObj_Response__init(moveit_wrapper_interfaces__srv__GetColObj_Response * msg);

/// Finalize srv/GetColObj message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__GetColObj_Response__fini(moveit_wrapper_interfaces__srv__GetColObj_Response * msg);

/// Create srv/GetColObj message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * moveit_wrapper_interfaces__srv__GetColObj_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
moveit_wrapper_interfaces__srv__GetColObj_Response *
moveit_wrapper_interfaces__srv__GetColObj_Response__create();

/// Destroy srv/GetColObj message.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__GetColObj_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__GetColObj_Response__destroy(moveit_wrapper_interfaces__srv__GetColObj_Response * msg);

/// Check for srv/GetColObj message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__GetColObj_Response__are_equal(const moveit_wrapper_interfaces__srv__GetColObj_Response * lhs, const moveit_wrapper_interfaces__srv__GetColObj_Response * rhs);

/// Copy a srv/GetColObj message.
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
moveit_wrapper_interfaces__srv__GetColObj_Response__copy(
  const moveit_wrapper_interfaces__srv__GetColObj_Response * input,
  moveit_wrapper_interfaces__srv__GetColObj_Response * output);

/// Initialize array of srv/GetColObj messages.
/**
 * It allocates the memory for the number of elements and calls
 * moveit_wrapper_interfaces__srv__GetColObj_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence__init(moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence * array, size_t size);

/// Finalize array of srv/GetColObj messages.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__GetColObj_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence__fini(moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence * array);

/// Create array of srv/GetColObj messages.
/**
 * It allocates the memory for the array and calls
 * moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence *
moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence__create(size_t size);

/// Destroy array of srv/GetColObj messages.
/**
 * It calls
 * moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
void
moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence__destroy(moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence * array);

/// Check for srv/GetColObj message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_wrapper_interfaces
bool
moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence__are_equal(const moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence * lhs, const moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence * rhs);

/// Copy an array of srv/GetColObj messages.
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
moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence__copy(
  const moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence * input,
  moveit_wrapper_interfaces__srv__GetColObj_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_WRAPPER_INTERFACES__SRV__DETAIL__GET_COL_OBJ__FUNCTIONS_H_

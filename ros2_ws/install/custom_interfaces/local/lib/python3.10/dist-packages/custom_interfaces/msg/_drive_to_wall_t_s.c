// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_interfaces:msg/DriveToWallT.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_interfaces/msg/detail/drive_to_wall_t__struct.h"
#include "custom_interfaces/msg/detail/drive_to_wall_t__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_interfaces__msg__drive_to_wall_t__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_interfaces.msg._drive_to_wall_t.DriveToWallT", full_classname_dest, 51) == 0);
  }
  custom_interfaces__msg__DriveToWallT * ros_message = _ros_message;
  {  // linear_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "linear_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->linear_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // min_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_distance = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_interfaces__msg__drive_to_wall_t__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DriveToWallT */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_interfaces.msg._drive_to_wall_t");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DriveToWallT");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_interfaces__msg__DriveToWallT * ros_message = (custom_interfaces__msg__DriveToWallT *)raw_ros_message;
  {  // linear_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->linear_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "linear_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

# generated from rosidl_generator_py/resource/_idl.py.em
# with input from moveit_wrapper_interfaces:msg/WaypointSequence.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_WaypointSequence(type):
    """Metaclass of message 'WaypointSequence'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('moveit_wrapper_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'moveit_wrapper_interfaces.msg.WaypointSequence')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__waypoint_sequence
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__waypoint_sequence
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__waypoint_sequence
            cls._TYPE_SUPPORT = module.type_support_msg__msg__waypoint_sequence
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__waypoint_sequence

            from moveit_msgs.msg import Constraints
            if Constraints.__class__._TYPE_SUPPORT is None:
                Constraints.__class__.__import_type_support__()

            from moveit_wrapper_interfaces.msg import Waypoint
            if Waypoint.__class__._TYPE_SUPPORT is None:
                Waypoint.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class WaypointSequence(metaclass=Metaclass_WaypointSequence):
    """Message class 'WaypointSequence'."""

    __slots__ = [
        '_sequence_id',
        '_waypoints',
        '_path_constraints',
        '_use_linear_interpolation',
        '_velocity_scaling',
        '_acceleration_scaling',
    ]

    _fields_and_field_types = {
        'sequence_id': 'string',
        'waypoints': 'sequence<moveit_wrapper_interfaces/Waypoint>',
        'path_constraints': 'moveit_msgs/Constraints',
        'use_linear_interpolation': 'boolean',
        'velocity_scaling': 'double',
        'acceleration_scaling': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['moveit_wrapper_interfaces', 'msg'], 'Waypoint')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['moveit_msgs', 'msg'], 'Constraints'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.sequence_id = kwargs.get('sequence_id', str())
        self.waypoints = kwargs.get('waypoints', [])
        from moveit_msgs.msg import Constraints
        self.path_constraints = kwargs.get('path_constraints', Constraints())
        self.use_linear_interpolation = kwargs.get('use_linear_interpolation', bool())
        self.velocity_scaling = kwargs.get('velocity_scaling', float())
        self.acceleration_scaling = kwargs.get('acceleration_scaling', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.sequence_id != other.sequence_id:
            return False
        if self.waypoints != other.waypoints:
            return False
        if self.path_constraints != other.path_constraints:
            return False
        if self.use_linear_interpolation != other.use_linear_interpolation:
            return False
        if self.velocity_scaling != other.velocity_scaling:
            return False
        if self.acceleration_scaling != other.acceleration_scaling:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sequence_id(self):
        """Message field 'sequence_id'."""
        return self._sequence_id

    @sequence_id.setter
    def sequence_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sequence_id' field must be of type 'str'"
        self._sequence_id = value

    @builtins.property
    def waypoints(self):
        """Message field 'waypoints'."""
        return self._waypoints

    @waypoints.setter
    def waypoints(self, value):
        if __debug__:
            from moveit_wrapper_interfaces.msg import Waypoint
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Waypoint) for v in value) and
                 True), \
                "The 'waypoints' field must be a set or sequence and each value of type 'Waypoint'"
        self._waypoints = value

    @builtins.property
    def path_constraints(self):
        """Message field 'path_constraints'."""
        return self._path_constraints

    @path_constraints.setter
    def path_constraints(self, value):
        if __debug__:
            from moveit_msgs.msg import Constraints
            assert \
                isinstance(value, Constraints), \
                "The 'path_constraints' field must be a sub message of type 'Constraints'"
        self._path_constraints = value

    @builtins.property
    def use_linear_interpolation(self):
        """Message field 'use_linear_interpolation'."""
        return self._use_linear_interpolation

    @use_linear_interpolation.setter
    def use_linear_interpolation(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'use_linear_interpolation' field must be of type 'bool'"
        self._use_linear_interpolation = value

    @builtins.property
    def velocity_scaling(self):
        """Message field 'velocity_scaling'."""
        return self._velocity_scaling

    @velocity_scaling.setter
    def velocity_scaling(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'velocity_scaling' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'velocity_scaling' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._velocity_scaling = value

    @builtins.property
    def acceleration_scaling(self):
        """Message field 'acceleration_scaling'."""
        return self._acceleration_scaling

    @acceleration_scaling.setter
    def acceleration_scaling(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'acceleration_scaling' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'acceleration_scaling' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._acceleration_scaling = value

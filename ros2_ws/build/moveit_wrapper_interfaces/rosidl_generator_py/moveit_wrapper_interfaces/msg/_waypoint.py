# generated from rosidl_generator_py/resource/_idl.py.em
# with input from moveit_wrapper_interfaces:msg/Waypoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Waypoint(type):
    """Metaclass of message 'Waypoint'."""

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
                'moveit_wrapper_interfaces.msg.Waypoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__waypoint
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__waypoint
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__waypoint
            cls._TYPE_SUPPORT = module.type_support_msg__msg__waypoint
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__waypoint

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

            from moveit_msgs.msg import Constraints
            if Constraints.__class__._TYPE_SUPPORT is None:
                Constraints.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Waypoint(metaclass=Metaclass_Waypoint):
    """Message class 'Waypoint'."""

    __slots__ = [
        '_pose',
        '_named_target',
        '_linear_movement',
        '_linear_eef_step',
        '_linear_jump_thresh',
        '_linear_disable_collisions',
        '_path_constraints',
    ]

    _fields_and_field_types = {
        'pose': 'geometry_msgs/PoseStamped',
        'named_target': 'string',
        'linear_movement': 'boolean',
        'linear_eef_step': 'float',
        'linear_jump_thresh': 'float',
        'linear_disable_collisions': 'boolean',
        'path_constraints': 'moveit_msgs/Constraints',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['moveit_msgs', 'msg'], 'Constraints'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import PoseStamped
        self.pose = kwargs.get('pose', PoseStamped())
        self.named_target = kwargs.get('named_target', str())
        self.linear_movement = kwargs.get('linear_movement', bool())
        self.linear_eef_step = kwargs.get('linear_eef_step', float())
        self.linear_jump_thresh = kwargs.get('linear_jump_thresh', float())
        self.linear_disable_collisions = kwargs.get('linear_disable_collisions', bool())
        from moveit_msgs.msg import Constraints
        self.path_constraints = kwargs.get('path_constraints', Constraints())

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
        if self.pose != other.pose:
            return False
        if self.named_target != other.named_target:
            return False
        if self.linear_movement != other.linear_movement:
            return False
        if self.linear_eef_step != other.linear_eef_step:
            return False
        if self.linear_jump_thresh != other.linear_jump_thresh:
            return False
        if self.linear_disable_collisions != other.linear_disable_collisions:
            return False
        if self.path_constraints != other.path_constraints:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'pose' field must be a sub message of type 'PoseStamped'"
        self._pose = value

    @builtins.property
    def named_target(self):
        """Message field 'named_target'."""
        return self._named_target

    @named_target.setter
    def named_target(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'named_target' field must be of type 'str'"
        self._named_target = value

    @builtins.property
    def linear_movement(self):
        """Message field 'linear_movement'."""
        return self._linear_movement

    @linear_movement.setter
    def linear_movement(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'linear_movement' field must be of type 'bool'"
        self._linear_movement = value

    @builtins.property
    def linear_eef_step(self):
        """Message field 'linear_eef_step'."""
        return self._linear_eef_step

    @linear_eef_step.setter
    def linear_eef_step(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'linear_eef_step' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'linear_eef_step' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._linear_eef_step = value

    @builtins.property
    def linear_jump_thresh(self):
        """Message field 'linear_jump_thresh'."""
        return self._linear_jump_thresh

    @linear_jump_thresh.setter
    def linear_jump_thresh(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'linear_jump_thresh' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'linear_jump_thresh' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._linear_jump_thresh = value

    @builtins.property
    def linear_disable_collisions(self):
        """Message field 'linear_disable_collisions'."""
        return self._linear_disable_collisions

    @linear_disable_collisions.setter
    def linear_disable_collisions(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'linear_disable_collisions' field must be of type 'bool'"
        self._linear_disable_collisions = value

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

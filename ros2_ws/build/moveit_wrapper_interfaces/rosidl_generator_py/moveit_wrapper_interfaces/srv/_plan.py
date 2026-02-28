# generated from rosidl_generator_py/resource/_idl.py.em
# with input from moveit_wrapper_interfaces:srv/Plan.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Plan_Request(type):
    """Metaclass of message 'Plan_Request'."""

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
                'moveit_wrapper_interfaces.srv.Plan_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__plan__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__plan__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__plan__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__plan__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__plan__request

            from moveit_msgs.msg import Constraints
            if Constraints.__class__._TYPE_SUPPORT is None:
                Constraints.__class__.__import_type_support__()

            from moveit_msgs.msg import RobotState
            if RobotState.__class__._TYPE_SUPPORT is None:
                RobotState.__class__.__import_type_support__()

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


class Plan_Request(metaclass=Metaclass_Plan_Request):
    """Message class 'Plan_Request'."""

    __slots__ = [
        '_waypoints',
        '_path_constraints',
        '_send_partial',
        '_use_start_state',
        '_start_state',
        '_move_group',
    ]

    _fields_and_field_types = {
        'waypoints': 'sequence<moveit_wrapper_interfaces/Waypoint>',
        'path_constraints': 'moveit_msgs/Constraints',
        'send_partial': 'boolean',
        'use_start_state': 'boolean',
        'start_state': 'moveit_msgs/RobotState',
        'move_group': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['moveit_wrapper_interfaces', 'msg'], 'Waypoint')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['moveit_msgs', 'msg'], 'Constraints'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['moveit_msgs', 'msg'], 'RobotState'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.waypoints = kwargs.get('waypoints', [])
        from moveit_msgs.msg import Constraints
        self.path_constraints = kwargs.get('path_constraints', Constraints())
        self.send_partial = kwargs.get('send_partial', bool())
        self.use_start_state = kwargs.get('use_start_state', bool())
        from moveit_msgs.msg import RobotState
        self.start_state = kwargs.get('start_state', RobotState())
        self.move_group = kwargs.get('move_group', str())

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
        if self.waypoints != other.waypoints:
            return False
        if self.path_constraints != other.path_constraints:
            return False
        if self.send_partial != other.send_partial:
            return False
        if self.use_start_state != other.use_start_state:
            return False
        if self.start_state != other.start_state:
            return False
        if self.move_group != other.move_group:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def send_partial(self):
        """Message field 'send_partial'."""
        return self._send_partial

    @send_partial.setter
    def send_partial(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'send_partial' field must be of type 'bool'"
        self._send_partial = value

    @builtins.property
    def use_start_state(self):
        """Message field 'use_start_state'."""
        return self._use_start_state

    @use_start_state.setter
    def use_start_state(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'use_start_state' field must be of type 'bool'"
        self._use_start_state = value

    @builtins.property
    def start_state(self):
        """Message field 'start_state'."""
        return self._start_state

    @start_state.setter
    def start_state(self, value):
        if __debug__:
            from moveit_msgs.msg import RobotState
            assert \
                isinstance(value, RobotState), \
                "The 'start_state' field must be a sub message of type 'RobotState'"
        self._start_state = value

    @builtins.property
    def move_group(self):
        """Message field 'move_group'."""
        return self._move_group

    @move_group.setter
    def move_group(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'move_group' field must be of type 'str'"
        self._move_group = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Plan_Response(type):
    """Metaclass of message 'Plan_Response'."""

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
                'moveit_wrapper_interfaces.srv.Plan_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__plan__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__plan__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__plan__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__plan__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__plan__response

            from moveit_msgs.msg import RobotTrajectory
            if RobotTrajectory.__class__._TYPE_SUPPORT is None:
                RobotTrajectory.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Plan_Response(metaclass=Metaclass_Plan_Response):
    """Message class 'Plan_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_plans',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'plans': 'sequence<moveit_msgs/RobotTrajectory>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['moveit_msgs', 'msg'], 'RobotTrajectory')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        self.plans = kwargs.get('plans', [])

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
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        if self.plans != other.plans:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def plans(self):
        """Message field 'plans'."""
        return self._plans

    @plans.setter
    def plans(self, value):
        if __debug__:
            from moveit_msgs.msg import RobotTrajectory
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
                 all(isinstance(v, RobotTrajectory) for v in value) and
                 True), \
                "The 'plans' field must be a set or sequence and each value of type 'RobotTrajectory'"
        self._plans = value


class Metaclass_Plan(type):
    """Metaclass of service 'Plan'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('moveit_wrapper_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'moveit_wrapper_interfaces.srv.Plan')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__plan

            from moveit_wrapper_interfaces.srv import _plan
            if _plan.Metaclass_Plan_Request._TYPE_SUPPORT is None:
                _plan.Metaclass_Plan_Request.__import_type_support__()
            if _plan.Metaclass_Plan_Response._TYPE_SUPPORT is None:
                _plan.Metaclass_Plan_Response.__import_type_support__()


class Plan(metaclass=Metaclass_Plan):
    from moveit_wrapper_interfaces.srv._plan import Plan_Request as Request
    from moveit_wrapper_interfaces.srv._plan import Plan_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')

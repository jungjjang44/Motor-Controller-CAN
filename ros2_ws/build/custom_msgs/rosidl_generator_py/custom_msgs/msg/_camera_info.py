# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/CameraInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CameraInfo(type):
    """Metaclass of message 'CameraInfo'."""

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
            module = import_type_support('custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msgs.msg.CameraInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__camera_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__camera_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__camera_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__camera_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__camera_info

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CameraInfo(metaclass=Metaclass_CameraInfo):
    """Message class 'CameraInfo'."""

    __slots__ = [
        '_avg_distance',
        '_image_count',
    ]

    _fields_and_field_types = {
        'avg_distance': 'double',
        'image_count': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.avg_distance = kwargs.get('avg_distance', float())
        self.image_count = kwargs.get('image_count', int())

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
        if self.avg_distance != other.avg_distance:
            return False
        if self.image_count != other.image_count:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def avg_distance(self):
        """Message field 'avg_distance'."""
        return self._avg_distance

    @avg_distance.setter
    def avg_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'avg_distance' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'avg_distance' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._avg_distance = value

    @builtins.property
    def image_count(self):
        """Message field 'image_count'."""
        return self._image_count

    @image_count.setter
    def image_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'image_count' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'image_count' field must be an integer in [-2147483648, 2147483647]"
        self._image_count = value

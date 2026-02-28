from setuptools import find_packages
from setuptools import setup

setup(
    name='moveit_wrapper_interfaces',
    version='1.1.2',
    packages=find_packages(
        include=('moveit_wrapper_interfaces', 'moveit_wrapper_interfaces.*')),
)

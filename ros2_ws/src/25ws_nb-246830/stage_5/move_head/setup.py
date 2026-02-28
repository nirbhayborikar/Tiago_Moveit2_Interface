from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'move_head'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Add the action files to the share directory
        (os.path.join('share', package_name, 'action'), 
         glob('action/*.action')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='Move TIAGo head using action server',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'move_head = move_head.move_head:main',
            'move_head_action_server = move_head.move_head_action_server:main',
            
        ],
    },
)
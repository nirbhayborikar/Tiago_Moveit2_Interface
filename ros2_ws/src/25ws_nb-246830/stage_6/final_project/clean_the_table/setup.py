from setuptools import find_packages, setup

package_name = 'clean_the_table'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'drive_to_table = clean_the_table.drive_to_table:main',
            'scene_analysis = clean_the_table.scene_analysis:main',
            'pick_and_carry = clean_the_table.pick_and_carry:main',
            'drive_and_place = clean_the_table.drive_and_place:main',
            'clean_the_table_all = clean_the_table.clean_the_table_all:main',
        ],
    },
)

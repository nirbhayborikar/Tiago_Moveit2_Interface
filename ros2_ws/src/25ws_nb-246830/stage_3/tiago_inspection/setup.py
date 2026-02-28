from setuptools import find_packages, setup

package_name = 'tiago_inspection'

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
    maintainer='Nirbhay',
    maintainer_email='nb-246830@rwu.de',
    description='robocup inspection',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'start_inspection = tiago_inspection.start_inspection:main'
        ],
    },
)

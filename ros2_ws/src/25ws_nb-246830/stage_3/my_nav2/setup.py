from setuptools import setup

package_name = 'my_nav2'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),  # Explicitly install package.xml
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Nirbhay',
    maintainer_email='nb-246830@rwu.de',
    description='A simple package to publish navigation goals',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'my_node = my_nav2.my_node:main',
        ],
    },
)


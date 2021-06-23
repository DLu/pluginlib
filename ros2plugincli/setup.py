from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2plugincli',
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    install_requires=['ros2cli'],
    zip_safe=True,
    maintainer='David V. Lu!!',
    maintainer_email='davidvlu@gmail.com',
    description=' The ROS 2 command line extension for pluginlib.',
    license='BSD',
    tests_require=['pytest'],
    entry_points={
        'ros2cli.command': [
            'plugin = ros2plugincli.command.plugin:PluginCommand',
        ],
        'ros2plugincli.verb': [
            'world = ros2plugincli.verb.list:ListVerb',
        ],
    }
)

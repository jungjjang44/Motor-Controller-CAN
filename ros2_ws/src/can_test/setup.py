from setuptools import find_packages, setup

package_name = 'can_test'

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
    maintainer='krri',
    maintainer_email='jungjjang44@g.skku.edu',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'can_interface = can_test.can_interface:main',
            'cmd_publisher = can_test.cmd_publisher:main',
            'gui_interface = can_test.gui_interface:main',
        ],
    },
)

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
  return LaunchDescription([
    Node(
      package='turtlesim',
      node_executable='turtlesim_node',
      name='turtlesim_node',
      output='screen'
    ),
    Node(
      package='const_circle',
      node_executable='pubsub_circle',
      name='pubsub_circle',
      output='screen'
    ),
])

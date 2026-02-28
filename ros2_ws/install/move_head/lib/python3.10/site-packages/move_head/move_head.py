#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from sensor_msgs.msg import JointState
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration
import math
import time


class MoveHead(Node):
    def __init__(self):
        super().__init__('move_head')
        
        # Subscriber to joint states
        self.joint_state_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_callback,
            10
        )
        
        # Action client for head controller
        self.trajectory_client = ActionClient(
            self,
            FollowJointTrajectory,
            '/head_controller/follow_joint_trajectory'
        )
        
        # Current head positions
        self.head_1_pos = 0.0  # Pan (left-right)
        self.head_2_pos = 0.0  # Tilt (up-down)
        self.joint_names = ['head_1_joint', 'head_2_joint']
        
        # Joint limits for TIAGo head
        self.joint_limits = {
            'head_1_joint': {'min': -1.5, 'max': 1.5},  # ±1.5 rad pan
            'head_2_joint': {'min': -0.9, 'max': 0.9}   # ±0.9 rad tilt
        }
        
        # Connect to action server
        self.connect_to_server()
        
    def connect_to_server(self):
        """Connect to the head controller action server."""
        self.get_logger().info('Waiting for head controller action server...')
        
        if self.trajectory_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().info('✅ Connected to head controller!')
            # Test movement after connection
            self.create_timer(2.0, self.test_movement)
        else:
            self.get_logger().error('❌ Could not connect to head controller!')
        
    def joint_state_callback(self, msg):
        """Update current head joint positions."""
        try:
            # Get current positions
            for i, name in enumerate(msg.name):
                if name == 'head_1_joint':
                    self.head_1_pos = msg.position[i]
                elif name == 'head_2_joint':
                    self.head_2_pos = msg.position[i]
            
            # Log once
            if not hasattr(self, 'positions_logged'):
                self.get_logger().info(f'Current head position: pan={self.head_1_pos:.3f}, tilt={self.head_2_pos:.3f}')
                self.positions_logged = True
            
        except Exception as e:
            self.get_logger().warn(f'Error reading joint states: {e}')
            
    def test_movement(self):
        """Test head movement."""
        self.get_logger().info('Testing head movement...')
        
        # Move to look left and down
        success = self.move_head_absolute(pan=0.5, tilt=0.3)
        
        if success:
            self.get_logger().info('✅ Test movement successful!')
            
            # After 3 seconds, move back to center
            self.create_timer(3.0, lambda: self.move_head_absolute(pan=0.0, tilt=0.0))
        else:
            self.get_logger().error('❌ Test movement failed!')
            
    def move_head_absolute(self, pan=0.0, tilt=0.0, duration=2.0):
        """
        Move head to absolute position.
        
        Args:
            pan: head_1_joint position (radians, positive = left)
            tilt: head_2_joint position (radians, positive = down)
            duration: movement duration in seconds
            
        Returns:
            bool: True if movement successful
        """
        # Apply joint limits
        pan = max(min(pan, self.joint_limits['head_1_joint']['max']), 
                 self.joint_limits['head_1_joint']['min'])
        tilt = max(min(tilt, self.joint_limits['head_2_joint']['max']), 
                  self.joint_limits['head_2_joint']['min'])
        
        self.get_logger().info(f'Moving head to: pan={pan:.3f}, tilt={tilt:.3f}')
        
        # Create trajectory point
        point = JointTrajectoryPoint()
        point.positions = [float(pan), float(tilt)]
        point.time_from_start = Duration(sec=int(duration), nanosec=0)
        
        # Create trajectory
        trajectory = JointTrajectory()
        trajectory.joint_names = self.joint_names
        trajectory.points = [point]
        
        # Create goal
        goal_msg = FollowJointTrajectory.Goal()
        goal_msg.trajectory = trajectory
        
        # Send goal
        future = self.trajectory_client.send_goal_async(goal_msg)
        
        # Wait for goal to be accepted
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        
        if future.result() is None:
            self.get_logger().error('Failed to send goal: timeout')
            return False
            
        goal_handle = future.result()
        
        if not goal_handle.accepted:
            self.get_logger().error('Goal rejected by action server')
            return False
            
        self.get_logger().info('Goal accepted, executing...')
        
        # Wait for result
        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=duration + 5.0)
        
        if result_future.result() is None:
            self.get_logger().error('Failed to get result: timeout')
            return False
            
        result = result_future.result().result
        
        if result.error_code == 0:  # SUCCESSFUL
            self.get_logger().info(f'✅ Movement completed successfully!')
            return True
        else:
            self.get_logger().error(f'❌ Movement failed with error: {result.error_string}')
            return False
    
    def move_head_relative(self, pan_increment=0.0, tilt_increment=0.0, duration=2.0):
        """
        Move head relative to current position.
        
        Args:
            pan_increment: head_1_joint increment (radians)
            tilt_increment: head_2_joint increment (radians)
            duration: movement duration in seconds
        """
        new_pan = self.head_1_pos + pan_increment
        new_tilt = self.head_2_pos + tilt_increment
        
        return self.move_head_absolute(new_pan, new_tilt, duration)


def main(args=None):
    rclpy.init(args=args)
    node = MoveHead()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
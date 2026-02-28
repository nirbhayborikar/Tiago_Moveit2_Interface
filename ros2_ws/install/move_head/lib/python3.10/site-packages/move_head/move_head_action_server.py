#!/usr/bin/env python3
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
from move_head.action import MoveHead
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration


class MoveHeadActionServer(Node):
    def __init__(self):
        super().__init__('move_head_action_server')
        
        # Create our custom action server
        self._action_server = ActionServer(
            self,
            MoveHead,
            'move_head_action',
            self.execute_callback,
            callback_group=ReentrantCallbackGroup()
        )
        
        # Client for TIAGo's head controller
        self.head_client = ActionClient(
            self,
            FollowJointTrajectory,
            '/head_controller/follow_joint_trajectory'
        )
        
        self.get_logger().info('MoveHead Action Server started!')
        self.get_logger().info('Connecting to head controller...')
        
        # Try to connect to head controller
        if self.head_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().info('✅ Connected to head controller!')
        else:
            self.get_logger().error('❌ Could not connect to head controller!')
        
    def execute_callback(self, goal_handle):
        """Execute the move head action."""
        self.get_logger().info('Executing move head action...')
        
        # Get goal
        goal = goal_handle.request
        pan = goal.pan_angle
        tilt = goal.tilt_angle
        
        self.get_logger().info(f'Moving head to: pan={pan:.3f}, tilt={tilt:.3f}')
        
        # Create result
        result = MoveHead.Result()
        
        # Publish initial feedback
        feedback_msg = MoveHead.Feedback()
        feedback_msg.current_pan = 0.0
        feedback_msg.current_tilt = 0.0
        goal_handle.publish_feedback(feedback_msg)
        
        try:
            # Move head using trajectory action
            success = self.move_head_trajectory(pan, tilt)
            
            if success:
                result.success = True
                result.message = f"Successfully moved head to pan={pan:.3f}, tilt={tilt:.3f}"
                goal_handle.succeed()
                self.get_logger().info('✅ Action succeeded!')
            else:
                result.success = False
                result.message = "Failed to move head"
                goal_handle.abort()
                self.get_logger().error('❌ Action failed!')
                
        except Exception as e:
            result.success = False
            result.message = f"Error: {str(e)}"
            goal_handle.abort()
            self.get_logger().error(f'Action error: {e}')
            
        return result
    
    def move_head_trajectory(self, pan, tilt, duration=2.0):
        """Move head using FollowJointTrajectory action."""
        if not self.head_client.server_is_ready():
            self.get_logger().error('Head controller not ready!')
            return False
        
        # Create trajectory point
        point = JointTrajectoryPoint()
        point.positions = [float(pan), float(tilt)]
        point.time_from_start = Duration(sec=int(duration), nanosec=0)
        
        # Create trajectory
        trajectory = JointTrajectory()
        trajectory.joint_names = ['head_1_joint', 'head_2_joint']
        trajectory.points = [point]
        
        # Create goal
        goal_msg = FollowJointTrajectory.Goal()
        goal_msg.trajectory = trajectory
        
        # Send goal
        future = self.head_client.send_goal_async(goal_msg)
        
        # Wait for goal to be accepted
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        
        if future.result() is None:
            self.get_logger().error('Failed to send goal: timeout')
            return False
            
        goal_handle = future.result()
        
        if not goal_handle.accepted:
            self.get_logger().error('Goal rejected by head controller')
            return False
            
        self.get_logger().info('Goal accepted by head controller')
        
        # Wait for result
        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=duration + 5.0)
        
        if result_future.result() is None:
            self.get_logger().error('Failed to get result: timeout')
            return False
            
        result = result_future.result().result
        
        if result.error_code == 0:  # SUCCESSFUL
            return True
        else:
            self.get_logger().error(f'Head controller error: {result.error_string}')
            return False


def main(args=None):
    rclpy.init(args=args)
    node = MoveHeadActionServer()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
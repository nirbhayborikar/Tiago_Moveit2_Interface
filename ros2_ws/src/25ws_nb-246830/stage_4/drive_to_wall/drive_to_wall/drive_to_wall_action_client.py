import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from custom_interfaces.action import DriveToWallA
import sys
import time

class DriveToWallActionClient(Node):
    def __init__(self):
        super().__init__('drive_to_wall_action_client')
        
        # Create action client
        self._action_client = ActionClient(self, DriveToWallA, 'drive_to_wall_action')
        
        # Timer to send goal after node is initialized
        self.timer = self.create_timer(1.0, self.send_goal)

    def send_goal(self):
        self.timer.cancel()  # Only run once
        
        # Wait for action server
        self.get_logger().info('Waiting for action server...')
        self._action_client.wait_for_server()
        
        # Create goal
        goal_msg = DriveToWallA.Goal()
        
        # Set parameters from command line or defaults
        if len(sys.argv) >= 3:
            goal_msg.linear_x = float(sys.argv[1])
            goal_msg.min_distance = float(sys.argv[2])
        else:
            # Default values
            goal_msg.linear_x = 0.2
            goal_msg.min_distance = 0.5
        
        self.get_logger().info(f'Sending goal: speed={goal_msg.linear_x}, distance={goal_msg.min_distance}')
        
        # Send goal asynchronously
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        """Handle response when goal is accepted/rejected."""
        goal_handle = future.result()
        
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return
        
        self.get_logger().info('Goal accepted :)')
        
        # Start a timer to cancel the goal after 3 seconds (for testing cancellation)
        self.cancel_timer = self.create_timer(3.0, self.cancel_goal)
        
        # Get result
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def cancel_goal(self):
        """Cancel the goal (for testing)."""
        self.cancel_timer.cancel()
        self.get_logger().info('Cancelling goal...')
        
        # Create a future for cancellation
        if hasattr(self, '_goal_handle'):
            future = self._goal_handle.cancel_goal_async()
            future.add_done_callback(self.cancel_done_callback)

    def cancel_done_callback(self, future):
        """Handle completion of cancellation."""
        cancel_response = future.result()
        
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info('Goal successfully cancelled')
        else:
            self.get_logger().info('Goal failed to cancel')

    def feedback_callback(self, feedback_msg):
        """Handle feedback from action server."""
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Received feedback: Current distance = {feedback.current_distance:.2f}m')

    def get_result_callback(self, future):
        """Handle result from action server."""
        result = future.result().result
        self.get_logger().info(f'Action Result: {result.message}')
        self.get_logger().info(f'Success: {result.success}')
        
        # Shutdown after receiving result
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = DriveToWallActionClient()
    rclpy.spin(node)
    node.destroy_node()

if __name__ == '__main__':
    main()
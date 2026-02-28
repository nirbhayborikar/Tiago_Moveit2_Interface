import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import random

class GoalPublisher(Node):
    def __init__(self):
        super().__init__('goal_pub')
        self.publisher_ = self.create_publisher(PoseStamped, '/goal_pose', 10)
        self.timer = self.create_timer(5.0, self.publish_goal)  # Publish a goal every 5 seconds

    def publish_goal(self):
        goal = PoseStamped()
        goal.header.frame_id = 'map'
        goal.header.stamp = self.get_clock().now().to_msg()
        
        # Generate random goal coordinates
        goal.pose.position.x = random.uniform(-2.0, 2.0)
        goal.pose.position.y = random.uniform(-2.0, 2.0)
        goal.pose.orientation.w = 1.0  # Default orientation
         
        self.publisher_.publish(goal)
        self.get_logger().info(f'Publishing goal: x={goal.pose.position.x}, y={goal.pose.position.y}')

def main(args=None):
    rclpy.init(args=args)
    node = GoalPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

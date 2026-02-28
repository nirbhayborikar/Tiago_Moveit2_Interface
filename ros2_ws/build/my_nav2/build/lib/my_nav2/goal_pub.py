import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from random import uniform

class GoalPublisher(Node):
    def __init__(self):
        super().__init__('goal_pub')
        self.get_logger().info('goal_pose Node has started')
        self.publisher_ = self.create_publisher(PoseStamped, '/goal_pose', 10)
        self.timer = self.create_timer(2.0, self.publish_goal)  # Publish a goal every 2 seconds

    def publish_goal(self):
        goal = PoseStamped()
        goal.header.frame_id = 'map'
        goal.header.stamp = self.get_clock().now().to_msg()
        
        # Generate random goal coordinates
        goal.pose.position.x = uniform(-5.0,5.0)
        goal.pose.position.y = uniform(-5.0,5.0)
        goal.pose.orientation.w = 1.0  # Default orientation
         
        self.publisher_.publish(goal)
        self.get_logger().info(f'Publishing goal: x={goal.pose.position.x}, y={goal.pose.position.y}')

def main(args=None):
    rclpy.init(args=args)
    print("Node is running")  # Debug line
    goal_pub = GoalPublisher()
    rclpy.spin(goal_pub)
    goal_pub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

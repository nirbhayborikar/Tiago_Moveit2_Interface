import rclpy
from rclpy.node import Node
from custom_interfaces.msg import DriveToWallT, ReachedWallT

class DriveToWallClient(Node):
    def __init__(self):
        super().__init__('drive_to_wall_topic_client')
        
        self.goal_pub = self.create_publisher(DriveToWallT, '/drive_to_wall_goal', 10)
        self.reached_sub = self.create_subscription(ReachedWallT, '/reached_wall', self.reached_callback, 10)
        
        # Timer to trigger the publish once
        self.timer = self.create_timer(1.0, self.send_goal)

    def send_goal(self):
        self.timer.cancel() # Only run once
        msg = DriveToWallT()
        msg.linear_x = 0.2        # Changed from msg.speed
        msg.min_distance = 0.5    # Changed from msg.distance
        self.get_logger().info('Publishing drive command to robot...')
        self.goal_pub.publish(msg)

    def reached_callback(self, msg):
        self.get_logger().info(f'RESPONSE RECEIVED: "{msg.message}" | Success: {msg.success}')

def main(args=None):
    rclpy.init(args=args)
    node = DriveToWallClient()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
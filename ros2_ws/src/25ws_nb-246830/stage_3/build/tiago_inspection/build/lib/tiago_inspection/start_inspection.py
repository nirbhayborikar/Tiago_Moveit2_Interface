import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped, PoseStamped
from sensor_msgs.msg import LaserScan
from gazebo_msgs.srv import DeleteEntity


class StartInspection(Node):
    def __init__(self):
        super().__init__('start_inspection')

        # Publisher for initial pose
        self.pose_pub = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)

        # Publisher for goal pose
        self.goal_pub = self.create_publisher(PoseStamped, '/goal_pose', 10)

        # Subscriber for /initialpose (observe 2D Pose Estimate changes)
        self.create_subscription(PoseWithCovarianceStamped, '/initialpose', self.initialpose_callback, 10)

        # Subscriber for /scan (check for obstacles)
        self.scan_sub = self.create_subscription(LaserScan, '/scan', self.scan_callback, 10)

        # Client for /delete_entity service
        self.delete_client = self.create_client(DeleteEntity, '/delete_entity')
        while not self.delete_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for /delete_entity service...')

        # State variables
        self.obstacle_detected = True
        self.door_deleted = False

        # Initialize the robot’s position
        self.publish_initial_pose()

    def publish_initial_pose(self):
        """Publish the initial pose of the robot."""
        msg = PoseWithCovarianceStamped()
        msg.header.frame_id = "map"
        msg.pose.pose.position.x = 0.5  # Example position
        msg.pose.pose.position.y = 1.0
        msg.pose.pose.orientation.z = 0.0
        msg.pose.pose.orientation.w = 1.0
        self.pose_pub.publish(msg)
        self.get_logger().info("Published initial pose to /initialpose")

    def initialpose_callback(self, msg):
        """Callback for observing /initialpose topic."""
        self.get_logger().info(f"Received initial pose: Position({msg.pose.pose.position.x}, {msg.pose.pose.position.y})")

    def scan_callback(self, msg):
        """Callback for /scan to check for obstacles."""
        # Check front-most region of the scan
        front_distance = min(msg.ranges[:10] + msg.ranges[-10:])  # Combine front-left and front-right ranges
        if front_distance > 1.0:  # No obstacle within 1 meter
            if self.obstacle_detected:  # Only log and act if state has changed
                self.obstacle_detected = False
                self.get_logger().info("Obstacle is gone! Attempting to delete the door.")
                self.delete_door()
        else:
            self.obstacle_detected = True

    def delete_door(self):
        """Call the /delete_entity service to remove the door."""
        if self.door_deleted:
            return  # Avoid multiple attempts to delete the door

        request = DeleteEntity.Request()
        request.name = "door"  # Name of the entity to delete
        future = self.delete_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.get_logger().info("Successfully deleted the door.")
            self.door_deleted = True
            self.navigate_to_inspection()
        else:
            self.get_logger().error("Failed to delete the door.")

    def navigate_to_inspection(self):
        """Publish a goal pose to navigate to the inspection point."""
        goal_msg = PoseStamped()
        goal_msg.header.frame_id = "map"
        goal_msg.pose.position.x = 3.0  # Example inspection point coordinates
        goal_msg.pose.position.y = 1.5
        goal_msg.pose.orientation.z = 0.0
        goal_msg.pose.orientation.w = 1.0
        self.goal_pub.publish(goal_msg)
        self.get_logger().info("Published goal pose to navigate to the inspection point")


def main(args=None):
    rclpy.init(args=args)
    node = StartInspection()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()

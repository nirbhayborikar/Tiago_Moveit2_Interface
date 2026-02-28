import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from custom_interfaces.msg import DriveToWallT, ReachedWallT
import math

class DriveToWallSubscriber(Node):
    def __init__(self):
        super().__init__('drive_to_wall_topic')
        
        # Publishers
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.reached_pub = self.create_publisher(ReachedWallT, '/reached_wall', 10)
        
        # Subscribers
        self.goal_sub = self.create_subscription(DriveToWallT, '/drive_to_wall_goal', self.goal_callback, 10)
        self.scan_sub = self.create_subscription(LaserScan, '/scan', self.scan_callback, 10)
        
        self.target_speed = 0.0
        self.target_dist = 0.0
        self.is_active = False

    def goal_callback(self, msg):
        self.target_speed = msg.linear_x
        self.target_dist = msg.min_distance
        self.is_active = True
        self.get_logger().info(f'Goal received: Speed {self.target_speed}, Distance {self.target_dist}')

    def scan_callback(self, msg):
        if not self.is_active:
            return

        # Get laser scan parameters
        angle_min = msg.angle_min  # Usually -π (-180°)
        angle_max = msg.angle_max  # Usually π (180°)
        angle_increment = msg.angle_increment
        ranges = msg.ranges
        
        # Calculate indices for 270° to 360° (which is -90° to 0° in radians)
        # Convert degrees to radians: 270° = -π/2, 360° = 0
        target_min_angle = -math.pi / 2  # -90° = 270°
        target_max_angle = 0.0           # 0° = 360°
        
        # Calculate start and end indices
        start_idx = int((target_min_angle - angle_min) / angle_increment)
        end_idx = int((target_max_angle - angle_min) / angle_increment)
        
        # Ensure indices are within bounds
        start_idx = max(0, min(start_idx, len(ranges)-1))
        end_idx = max(0, min(end_idx, len(ranges)-1))
        
        if start_idx > end_idx:
            start_idx, end_idx = end_idx, start_idx
        
        # Extract ranges for the desired sector
        sector_ranges = ranges[start_idx:end_idx+1]
        
        if not sector_ranges:
            self.get_logger().warn('No ranges in selected sector!')
            return
        
        # Find valid distances (filter out inf and NaN)
        valid_ranges = []
        for dist in sector_ranges:
            if msg.range_min <= dist <= msg.range_max:
                valid_ranges.append(dist)
        
        if not valid_ranges:
            self.get_logger().warn('No valid ranges in selected sector!')
            return
        
        # Get the middle distance from the sector (closest to 315° or -45°)
        mid_idx = len(sector_ranges) // 2
        current_dist = sector_ranges[mid_idx]
        
        # Alternatively, get minimum distance in the sector (for wall following)
        # current_dist = min(valid_ranges)
        
        self.get_logger().info(f'Sector (270°-360°): indices {start_idx}-{end_idx}')
        self.get_logger().info(f'Current distance: {current_dist:.2f}m, Target: {self.target_dist:.2f}m')
        
        cmd = Twist()
        if current_dist > self.target_dist:
            cmd.linear.x = self.target_speed
            self.get_logger().info(f'Moving forward at {self.target_speed} m/s')
        else:
            # STOP the robot
            cmd.linear.x = 0.0
            cmd.angular.z = 0.0
            self.is_active = False
            
            # Publish completion message
            reached_msg = ReachedWallT()
            reached_msg.message = "reached wall"
            reached_msg.success = True
            self.reached_pub.publish(reached_msg)
            self.get_logger().info('Wall reached! Stopping and notifying client.')

        self.cmd_vel_pub.publish(cmd)

def main(args=None):
    rclpy.init(args=args)
    node = DriveToWallSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
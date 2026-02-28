import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from custom_interfaces.srv import DriveToWallS
import math

class DriveToWallService(Node):
    def __init__(self):
        super().__init__('drive_to_wall_service')
        
        # Create service
        self.srv = self.create_service(
            DriveToWallS, 
            'drive_to_wall_service', 
            self.service_callback,
            callback_group=ReentrantCallbackGroup()  # Allows multiple callbacks
        )
        
        # Publishers and Subscribers
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.scan_sub = self.create_subscription(LaserScan, '/scan', self.scan_callback, 10)
        
        # Service state variables
        self.target_speed = 0.0
        self.target_dist = 0.0
        self.is_active = False
        self.service_request = None
        self.service_response = None

    def service_callback(self, request, response):
        self.get_logger().info(f'Service called: linear_x={request.linear_x}, min_distance={request.min_distance}')
        
        # Store request parameters
        self.target_speed = request.linear_x
        self.target_dist = request.min_distance
        self.is_active = True
        self.service_request = request
        self.service_response = response
        
        # Return immediately - the scan callback will handle the actual work
        # and set the response when done
        return response

    def scan_callback(self, msg):
        if not self.is_active or self.service_response is None:
            return

        # Get laser scan parameters
        angle_min = msg.angle_min
        angle_increment = msg.angle_increment
        ranges = msg.ranges
        
        # Find indices for 270° to 360° (-90° to 0°)
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
        
        # Get the middle distance from the sector
        mid_idx = len(sector_ranges) // 2
        current_dist = sector_ranges[mid_idx]
        
        # Filter invalid distances
        if not (msg.range_min <= current_dist <= msg.range_max):
            self.get_logger().warn(f'Invalid distance reading: {current_dist}')
            return
        
        self.get_logger().info(f'Current distance: {current_dist:.2f}m, Target: {self.target_dist:.2f}m')
        
        cmd = Twist()
        if current_dist > self.target_dist:
            cmd.linear.x = self.target_speed
            self.get_logger().info(f'Moving forward at {self.target_speed} m/s')
        else:
            # STOP the robot
            cmd.linear.x = 0.0
            self.is_active = False
            
            # Set service response
            self.service_response.message = "Successfully reached the wall"
            self.service_response.success = True
            
            self.get_logger().info('Wall reached! Service completed.')
            
            # Reset for next call
            self.service_response = None

        self.cmd_vel_pub.publish(cmd)

def main(args=None):
    rclpy.init(args=args)
    node = DriveToWallService()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
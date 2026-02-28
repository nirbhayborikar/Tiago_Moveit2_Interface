import rclpy
from rclpy.node import Node

from sensor_msgs.msg import LaserScan

class StartInspection(Node):
    def __init__(self):
        super().__init__('start_inspection')  # Node name
        self.get_logger().info('check_laser_scan_data')

        self.check_ranges =None # store laser values
        # Create a subscriber for laser scan data
        self.laser_scan_sub = self.create_subscription(
            LaserScan,
            '/scan_raw',  # Replace with the actual topic name
            self.laser_scan_callback,
            10
        )

        # Initialize variables
        
        self.movement_complete = False
        self.min_distance_threshold = 0.5  # Minimum distance to consider the door open
   
        self.door_open_detected = False  # Flag to track if the door is detected as open

    

    def laser_scan_callback(self, msg):
        # Check for open space in front of the robot (example)
        self.check_ranges = msg.ranges
        min_distance = min(self.check_ranges[270:361])
        if min_distance > 1.5:  # Adjust this threshold as needed
            self.door_is_open = True 
            self.get_logger().info("Opened_door.........................")
            #self.get_logger().info("Door detected open, preparing to move robot.")
            self.get_logger().info(f"laser_scan_0 to 89: {self.check_ranges[0:90]}")
            self.get_logger().info(f"laser_scan_90 to 179: {self.check_ranges[90:180]}")
            self.get_logger().info(f"laser_scan_180 to 269: {self.check_ranges[180:270]}")
            self.get_logger().info(f"laser_scan_270 to 359: {self.check_ranges[270:361]}")
        else:
            self.get_logger().info(f"laser_scan_0 to 89: {self.check_ranges[0:90]}")
            self.get_logger().info(f"laser_scan_90 to 179: {self.check_ranges[90:180]}")
            self.get_logger().info(f"laser_scan_180 to 269: {self.check_ranges[180:270]}")
            self.get_logger().info(f"laser_scan_270 to 359: {self.check_ranges[270:361]}")
         
            self.get_logger().info("not_opened_door.")

        


def main(args=None):
    rclpy.init(args=args)
    print("Node is running")  # Debug line
    start_inspection = StartInspection()
    rclpy.spin(start_inspection)
    start_inspection.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


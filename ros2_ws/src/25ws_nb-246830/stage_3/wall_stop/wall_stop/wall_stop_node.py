#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist


class WallStopNode(Node):
    def __init__(self):
        super().__init__('wall_stop_node')
        self.get_logger().info('Wall Stop Node has started')

        # Publisher for controlling the robot's velocity
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        # Subscriber for the laser scanner (updated to /scan_raw)
        self.laser_sub = self.create_subscription(LaserScan, '/scan_raw', self.laser_callback, 10)

        # Threshold distance to the wall
        self.stop_distance = 0.98  # meters

    def laser_callback(self, msg):
        # Get the minimum distance to an obstacle from the laser scan data
        min_distance = min(msg.ranges)

        if min_distance < self.stop_distance:
            self.get_logger().info(f"Obstacle detected at {min_distance:.2f} meters. Turning left.")
            #print min dist
            # Stop the robot if too close to a wall
            self.stop_robot()
            self.move_left()# take left 
            
        else:
            # Continue moving forward
            self.move_forward()

    def move_forward(self):
        twist = Twist()
        twist.linear.x = 0.5  # Forward speed
        twist.angular.z = 0.0 # No rotation
        self.cmd_vel_pub.publish(twist)

    def stop_robot(self):
        twist = Twist()
        twist.linear.x = 0.0  # Stop linear motion
        twist.angular.z = 0.0  # No rotation
        self.cmd_vel_pub.publish(twist)
    
    def move_left(self):

        twist = Twist()
        twist.linear.x = 0.0  # Stop linear motion
        twist.angular.z = 1.0  # left rotation
        
        self.cmd_vel_pub.publish(twist)
        self.create_timer(1.0, self.move_forward)  # Continue forward after the turn

def main(args=None):
    rclpy.init(args=args)
    wall_stop_node = WallStopNode()
    print("Node is running")  # Debug line
    rclpy.spin(wall_stop_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

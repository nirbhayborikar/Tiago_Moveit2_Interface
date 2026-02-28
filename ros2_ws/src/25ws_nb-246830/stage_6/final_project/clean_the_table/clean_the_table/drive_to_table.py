# Driving to pick table, after door is opened.

import rclpy # ros client library for python
from rclpy.node import Node #importing node, it give acess to class node

from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped, Twist
# .msg is a directory contain definition, posestamped it represent robot, point , a 3d point in space, and other definition
from nav2_msgs.action import NavigateToPose # Importing the 'Action definition' for moving the robot to a specific goal
from rclpy.action import ActionClient # Import the client that sends goals to an Action Server
from sensor_msgs.msg import LaserScan # Import the message type for LiDAR/Laser data
from nav2_msgs.msg import SpeedLimit  # Import the message type used to restrict robot velocity

class StartInspection(Node):
    def __init__(self):
        super().__init__('start_inspection')  # Node name
        self.get_logger().info('start_inspection Node has started')

        # Create initial position publisher
        self.pose_publisher = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)
        
        # Create an Action Client specifically for 'NavigateToPose' on the 'navigate_to_pose' server topic []
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        # Goal publisher
        self.goal_publisher_ = self.create_publisher(PoseStamped, '/goal_pose', 10)
        
        # publish move message
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)


        # 1. Add the Speed Limit Publisher
        self.speed_limit_pub = self.create_publisher(SpeedLimit, '/speed_limit', 10)

        
        
        # Wait for the action server[]
        while not self._action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info('waiting for action server')       
        self.check_ranges = None
        # Create a subscriber for laser scan data
        self.laser_scan_sub = self.create_subscription(
            LaserScan,
            '/scan_raw',  # Replace with the actual topic name
            self.laser_scan_callback,
            10
        )

        # Initialize variables
        self.door_is_open = False
        self.initial_pose_published = False
        self.movement_complete = False
        self.min_distance_threshold = 0.5  # Minimum distance to consider the door open
        self.goal_published = False  # Flag to track if the goal has been published
        self.door_open_detected = False  # Flag to track if the door is detected as open

        # Publish initial pose once on node startup
        self.publish_initial_pose()
    

    def laser_scan_callback(self, msg):
        # Check for open space in front of the robot (example)
        
        self.check_ranges = msg.ranges
        min_distance = min(self.check_ranges[270:361])
        if min_distance > 1.5:  # Adjust this threshold as needed
            self.door_is_open = True 
            self.get_logger().info("Open_door.:)....")
            self.get_logger().info(f"laser_scan_270 to 359: {self.check_ranges[270:361]}")
            self.publish_goal() # publish goal
        else:
            self.get_logger().info("not_opened_door.")
            self.get_logger().info(f"laser_scan_270 to 359: {self.check_ranges[270:361]}")

        
    def set_max_speed(self):
        """Tells Nav2 to use 100% of the robot's configured max speed."""
        msg = SpeedLimit()
        msg.percentage = True      # We are using percentage mode
        msg.speed_limit = 100.0    # 100% of the limits in your params file
        self.speed_limit_pub.publish(msg)
        self.get_logger().info("Nav2 Speed Limit set to 100%. Rushing to goal!")

    def publish_initial_pose(self):
        if not self.initial_pose_published:
            msg = PoseWithCovarianceStamped()

            msg.header.frame_id = 'map'
            msg.header.stamp = self.get_clock().now().to_msg()

            # Initial position
            # Header
            msg.header.frame_id = 'map'
            msg.header.stamp = self.get_clock().now().to_msg()
            

            # Position (YOUR EXACT COORDINATES)
            msg.pose.pose.position.x = -2.6948771476745605
            msg.pose.pose.position.y = 3.9419679641723633
            msg.pose.pose.position.z = 0.0
            
            # Orientation (YOUR EXACT ORIENTATION)
            msg.pose.pose.orientation.x = 0.0
            msg.pose.pose.orientation.y = 0.0
            msg.pose.pose.orientation.z = 0.09089543432953555
            msg.pose.pose.orientation.w = 0.9958604420389662
            
            # Covariance matrix
            msg.pose.covariance = [
                0.25, 0.0, 0.0, 0.0, 0.0, 0.0,
                0.0, 0.25, 0.0, 0.0, 0.0, 0.0,
                0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891909122467
            ]
            # Publish initial pose
            self.pose_publisher.publish(msg)
            self.get_logger().info(f"Published initial pose: x={msg.pose.pose.position.x}, y={msg.pose.pose.position.y}")
            self.initial_pose_published = True  # Mark initial pose as published

    def publish_goal(self):
        if not self.goal_published:
            goal = PoseStamped()
            goal.header.frame_id = 'map'
            goal.header.stamp = self.get_clock().now().to_msg()

            # Goal position coordinates
            goal.pose.position.x = 0.2965392773707665 # Target position (x)
            goal.pose.position.y =  5.863092763400552 # Target position (y)
            goal.pose.position.z = 0.0
            goal.pose.orientation.z = 0.0037829493783980307
            goal.pose.orientation.w = 0.9999928446214005


            # Publish the goal
            self.goal_publisher_.publish(goal)
            self.get_logger().info(f'Published goal: x={goal.pose.position.x}, y={goal.pose.position.y}')

            # Create a goal for the navigation action
            goal_msg = NavigateToPose.Goal()
            goal_msg.pose = goal



            # Send the goal to the navigation action server
            self._send_goal_future = self._action_client.send_goal_async(goal_msg)

            # Wait for the result
            self._send_goal_future.add_done_callback(self._goal_response_callback)
            

            self.goal_published = True  # Set the flag to True after publishing the goal
            self.create_timer(10.0, self.complete_movement) 

    # control speed
    def control_speed(self):
        msg = Twist()
        self.get_logger().info("Moving in x speed with 0.4m/s")
        msg.linear.x = 6.0
        msg.angular.z = 0.0

    def complete_movement(self):
        self.movement_complete = True
        self.get_logger().info("Movement complete. Shutting down node.")
        self.destroy_node()        
    
    def _goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal was rejected!')
            return

        self.get_logger().info('Goal was accepted.')

        # 2. Trigger the speed boost as soon as the goal starts
        self.set_max_speed()

        # Request the result of the navigation goal asynchronously (non-blocking) from the goal handle
        self._get_result_future = goal_handle.get_result_async()

        #Assign a "callback" function to trigger automatically once the navigation task is finished
        self._get_result_future.add_done_callback(self._result_callback)

    # The Result Callback: Checking Success or Failure
  
    def _result_callback(self, future):
        try:
            # Extract the actual result object from the completed 'future'
            result = future.result().result
            
            # Check if the result object contains the specific 'navigation_status' field
            if hasattr(result, 'navigation_status'): 
                # If the status matches the 'SUCCEEDED' constant, log a success message
                if result.navigation_status == NavigateToPose.Result.SUCCEEDED:
                    self.get_logger().info('Goal succeeded!')
                # If it's anything else (Aborted, Canceled), log the failure status
                else:
                    self.get_logger().info(f'Goal failed with status: {result.navigation_status}')
            else:
                # Alert the user if the result message structure isn't what we expected
                self.get_logger().warn("No 'navigation_status' attribute found in result.")
                
        except AttributeError:
            # Handle cases where the 'future' might be empty or formatted incorrectly
            self.get_logger().error("Error accessing result attributes.")



def main(args=None):
    rclpy.init(args=args)
    print("Node is running")  # Debug line
    start_inspection = StartInspection()
    rclpy.spin(start_inspection)
    start_inspection.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
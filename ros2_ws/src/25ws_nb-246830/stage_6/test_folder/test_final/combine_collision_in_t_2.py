# synchronising


import rclpy # final code work at 54 sec
import time 
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped, Twist
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from sensor_msgs.msg import LaserScan
from nav2_msgs.msg import SpeedLimit  # <--- New Import
import math 

# collision object
from visualization_msgs.msg import Marker # visualization a ROS package,  msg is a submodule where message definitions are stored, marker a message type (reperesent visula object)

# Library for using tf2
from tf2_ros import TransformException # tf2_ros, a library from ROS for handling coordinate frame transformation, while TransformException is an error type (when lookup fail: frame not exist)
from tf2_ros.buffer import Buffer # buffer, a container to store transforms, here importing 'Buffer' class
from tf2_ros.transform_listener import TransformListener # TransformListener, a component that listens transforms from /tf topics, and send to buffer.
from moveit_wrapper_interfaces.srv import (AddColObj, ExecutePlans, Plan, AttachObj, GetAttachedObjs, RemoveColObj, DettachObj) #
import time # access time 

# for a PoseStamped object
from geometry_msgs.msg import PoseStamped # .msg is a directory contain definition, posestamped it represent robot, point , a 3d point in space
from moveit_wrapper_interfaces.msg import Waypoint # waypoint equence of position

# for planning 
from moveit_msgs.msg import Constraints, RobotState

# adding playmotion
from play_motion2_msgs.action import PlayMotion2
# Instead of calculating a path every time,
#  play_motion2 stores specific joint configurations (motions) in a configuration file.
#  When calling a motion like "open", "close", or "home", the package retrieves a list of joint positions and sends them directly to the controller.
# partially close 
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint



class StartInspection(Node):
    def __init__(self):
        super().__init__('start_inspection')  # Node name
        self.get_logger().info('start_inspection Node has started')

        # Create initial position publisher
        self.pose_publisher = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)
        
        # Action client for navigation
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        # Goal publisher
        self.goal_publisher_ = self.create_publisher(PoseStamped, '/goal_pose', 10)
        
        # publish move message
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)

        # check pose reached or not 

        self.current_pose = None
        self.pose_subscriber = self.create_subscription(PoseWithCovarianceStamped,'/amcl_pose',self.pose_callback,10)

    
        # 1. Add the Speed Limit Publisher
        self.speed_limit_pub = self.create_publisher(SpeedLimit, '/speed_limit', 10)

        # Wait for the action server
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


        # if reached goal
        self.first_reached = False
        # Publish initial pose once on node startup
        self.publish_initial_pose()

        # navigation check 
        self.current_velocity = None
        self.velocity_subscriber = self.create_subscription(
            Twist,
            '/cmd_vel',  # or '/nav_vel' depending on your setup
            self.velocity_callback,
            10
        )
        

        # navigation 



        # Add goal 2 tracking
        self.second_goal_reached = False

    # LEFT SIDE     
        # # Goal 2 coordinates (place table)
        # self.GOAL2_X = 1.5741179954636981
        # self.GOAL2_Y = 4.912653505829689
        # self.GOAL2_Z = 0.0
        # self.GOAL2_ORI_Z = -0.19530498864376572
        # self.GOAL2_ORI_W = 0.9807425561332895

    # Table front
        # self.GOAL2_X = 1.251873222468747
        # self.GOAL2_Y = 4.583467138377046
        # self.GOAL2_Z = 0.0


        # self.GOAL2_ORI_Z = 0.14741090113024635
        # self.GOAL2_ORI_W =  0.9890753390050572


# # table front little back 

        # self.GOAL2_X = 1.2020
        # self.GOAL2_Y = 4.590279115860679
        # self.GOAL2_Z = 0.0
        # self.GOAL2_ORI_Z = 0.20104190797444843
        # self.GOAL2_ORI_W =  0.9795826413519144

# table more back 


        self.GOAL2_X = 1.3525344141489204
        self.GOAL2_Y =   4.865876153895031
        self.GOAL2_Z = 0.0

        self.GOAL2_ORI_Z = -0.0254971623464817
        self.GOAL2_ORI_W = 0.9996748945093485




#best till now
# goal 2 table
# 1.15
        # self.GOAL2_X = 1.3708202151650375
        # self.GOAL2_Y =  4.48227501923998
        # self.GOAL2_Z = 0.0

        # self.GOAL2_ORI_Z = 0.27575799687726343

        # self.GOAL2_ORI_W = 0.961227094477803



        # collision object


        # sending marker to ROS by creating publisher, to topic 'visulaization_marker'
        self.publisher = self.create_publisher(Marker, 'visualization_marker', 10)

       
        # initiailze tag pose , so when not found program should not crash

        # Tx means april tag from table 1, for the movemnt TC variable will be taken 

        self.pos_Tx = self.pos_Ty = self.pos_Tz = 0.0

        # for table 1, collsion object publishing
        self.pos_TCx = self.pos_TCy = self.pos_TCz = 0.0

        # adiing rotation for table pick 
        self.rot_Tx = self.rot_Ty = self.rot_Tz = self.rot_Tw = 0.0
        # save rotation value 
        self.rot_TCx = self.rot_TCy = self.rot_TCz = self.rot_TCw = 0.0


        # 01x means april tag from obj 1, for the movemnt or collsion object 01C. 

        self.pos_01x = self.pos_01y = self.pos_01z = 0.0

        # for obj1 collision.

        self.pos_01Cx = self.pos_01Cy = self.pos_01Cz = 0.0

        # object 1
        self.rot_01x = self.rot_01y = self.rot_01z = self.rot_01w = 0.0
        # save rotation 
        self.rot_01Cx = self.rot_01Cy = self.rot_01Cz = self.rot_01Cw = 0.0



        # 02x means april tag from obj 2, for the movemnt or collsion object 02C. 

        self.pos_02x = self.pos_02y = self.pos_02z = 0.0

        # for obj2 collision.
        
        self.pos_02Cx = self.pos_02Cy = self.pos_02Cz = 0.0
        

        # object 2
        self.rot_02x = self.rot_02y = self.rot_02z = self.rot_02w = 0.0
        # save rotation 
        self.rot_02Cx = self.rot_02Cy = self.rot_02Cz = self.rot_02Cw = 0.0

        # 03x means april tag from obj 3, for the movemnt or collsion object 03C. 

        self.pos_03x = self.pos_03y = self.pos_03z = 0.0

        # for obj3 collision.
        
        self.pos_03Cx = self.pos_03Cy = self.pos_03Cz = 0.0

        # object 3
        self.rot_03x = self.rot_03y = self.rot_03z = self.rot_03w = 0.0
        # save rotation 
        self.rot_03Cx = self.rot_03Cy = self.rot_03Cz = self.rot_03Cw = 0.0

        # TP means april tag from table, where object need to be place , for the movemnt or collsion object TPC. 

        self.pos_TPx = self.pos_TPy = self.pos_TPz = 0.0

        # for obj2 collision.
        
        self.pos_TPCx = self.pos_TPCy = self.pos_TPCz = 0.0

        # table place rotation
        self.rot_TPx = self.rot_TPy = self.rot_TPz = self.rot_TPw = 0.0
        # save rotation 
        self.rot_TPCx = self.rot_TPCy = self.rot_TPCz = self.rot_TPCw = 0.0

        # ---------- CONSTANT TAG IDS ----------
        self.TABLE_PICK_ID  = 11
        self.TABLE_PLACE_ID = 10


        # ---------- SLOT MANAGEMENT ----------
        self.object_slots = {}      # tag_id → slot (1,2,3)
        self.max_objects = 3


        # ---------- LATCHED POSES ----------
        # bascially save pose when it available, so when something come in front of vision and we don't have real-time pose we can use this.
        self.latched_pose = {}      # tag_id -> (x, y, z)


        self.timer = self.create_timer(0.5, self.get_tag_pose) # calling function
 

        #setup listener  in __init__ method , so the node starts hearing the coordinate frames.

        self.tf_buffer = Buffer() # Buffer is a class constructor it has a data structure for the buffer.
        self.tf_listener = TransformListener(self.tf_buffer, self) # this subscribe to tf statics / transform topics.

        # add collision object
        self.add_col_client = self.create_client(AddColObj, "/moveit_wrapper/add_collision_object")

        # Planning-scene & attach/detach   
        self.plan_client = self.create_client(Plan, "/moveit_wrapper/plan")
        self.execute_client = self.create_client(ExecutePlans, "/moveit_wrapper/execute_plans")
        # attach object client
        self.attach_col_client = self.create_client(AttachObj, "/moveit_wrapper/attach_object")
        #self.get_attached_client = self.create_client(GetAttachedObjs, "/moveit_wrapper/get_attached_objects")



        # Marker publisher for move_marker1
        self.pub = self.create_publisher(Marker, 'move_markers', 10)


        # create the action client
        self.gripper_client = ActionClient(self, PlayMotion2, 'play_motion2')


        #self.send_gripper_command("open")

        # publisher for gripper partial close
        self.gripper_pub = self.create_publisher(JointTrajectory, '/gripper_controller/joint_trajectory', 10)
        
        # open gripper
        self.send_gripper_command("open")

        # Flag to control when to latch poses
        self.robot_is_stopped = False
        self.poses_latched = False
        
       # remove, detach , and convert detach to visualization marker 
       
        # Remove collision object
        self.remove_col_client = self.create_client(
            RemoveColObj, "/moveit_wrapper/remove_collision_object"
        ) 

        # detach collision object       
        self.detach_col_client = self.create_client(
            DettachObj, "/moveit_wrapper/detach_object"
        )

        # attach collision object to visualization marker
        self.get_attached_client = self.create_client(
            GetAttachedObjs, "/moveit_wrapper/get_attached_objects"
        )       
        
        
        
        
        # wait for services
        self.wait_for_services()




    
    def pose_callback(self, msg):
        self.current_pose = msg.pose.pose

    # Before move manually, you need to calculate the distance between where you are and where you want to be.
    # Use the Euclidean distance formula.

    def get_distance_to_goal(self, goal_x, goal_y):
        if self.current_pose is None:
            return float('inf') # Return a huge number if we don't know position yet
        
        return math.sqrt(
            (goal_x - self.current_pose.position.x)**2 + 
            (goal_y - self.current_pose.position.y)**2
        )
    
    # Logic for Manual Movement
    # If the distance is too high, you will send a Twist message to move the robot slightly.
    
    # def perform_correction(self):
    #     self.get_logger().info("Starting manual correction...")
    #     move_msg = Twist()
        
    #     # 1. Linear X movement (Slow nudge)
    #     move_msg.linear.x = 0.1  # 0.1 meters per second
    #     move_msg.angular.z = 0.2 # Slight rotation
        
    #     # 2. Publish and wait briefly
    #     self.publisher_.publish(move_msg)
    #     time.sleep(2.0) # Move for 2 seconds
        
    #     # 3. Stop
    #     move_msg.linear.x = 0.0
    #     move_msg.angular.z = 0.0
    #     self.publisher_.publish(move_msg)
    #     self.get_logger().info("Correction finished.")


    def laser_scan_callback(self, msg):
        # Check for open space in front of the robot (example)
        # STEP 1: The Guard Clause
        # 1. STOP if we are already moving to the goal
        if self.goal_published:
            return
        
        self.check_ranges = msg.ranges

        if not self.check_ranges:
            return

    # Indices 270 to 360 are usually the front-left quadrant
        scan_slice = msg.ranges[270:361]

        # 3. Filter out bad sensor readings (inf and nan)
        valid_ranges = [r for r in scan_slice if math.isfinite(r)]

        if not valid_ranges:
            # If no valid points, assume blocked for safety
            return    

        # 4. Find the closest object in that slice
        min_distance = min(valid_ranges)


        #min_distance = min(self.check_ranges[270:361])
        if min_distance > 1.5:  # Adjust this threshold as needed
            self.door_is_open = True 
            self.get_logger().info("Open_door.:)....")
            #self.get_logger().info(f"laser_scan_270 to 359: {self.check_ranges[270:361]}") # commented
            #self.get_logger().info("Door detected open, preparing to move robot.")
            self.publish_goal() # Move robot linearly for 10 seconds
        else:
            self.get_logger().info("Waiting for door to open...", once=True)
            #self.get_logger().info(f"laser_scan_270 to 359: {self.check_ranges[270:361]}") # commented

        
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

        if self.goal_published:
            return # Double safety
    
        self.goal_published = True # Set it IMMEDIATELY

        #if not self.goal_published:
        goal = PoseStamped()
        goal.header.frame_id = 'map'
        goal.header.stamp = self.get_clock().now().to_msg()
        # Goal position coordinates
        goal.pose.position.x = 0.2965392773707665 # Target position (x)
        goal.pose.position.y =  5.863092763400552 # 5.4614 Target position (y)
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


    # control speed
    def control_speed(self):
        msg = Twist()
        self.get_logger().info("Moving in x speed with 0.4m/s")
        msg.linear.x = 2.0
        msg.angular.z = 0.0

    def complete_movement(self):
        self.movement_complete = True
        self.get_logger().info("Movement complete")
        #self.destroy_node()        
    
    def _goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal was rejected!')
            return

        self.get_logger().info('Goal was accepted.')

        self.control_speed()
        # 2. Trigger the speed boost as soon as the goal starts
        self.set_max_speed()

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self._result_callback)




    def _result_callback(self, future):
        try:
            result = future.result()
            status = result.status

            self.get_logger().info(f"Navigation finished with status code: {status}")

            # ===== TARGET POSITION =====
            target_x = 0.2965392773707665
            target_y = 5.863092763400552
            target_z = 0.0

            if self.current_pose is None:
                self.get_logger().warn("Current pose not available!")
                return

            # ===== CURRENT POSITION =====
            current_x = self.current_pose.position.x
            current_y = self.current_pose.position.y
            current_z = self.current_pose.position.z

            # ===== ERROR CALCULATION =====
            dx = target_x - current_x
            dy = target_y - current_y
            dz = target_z - current_z

            total_error = math.sqrt(dx**2 + dy**2 + dz**2)

            tolerance = 0.40  # Your custom tolerance (25cm) #0.25

            self.get_logger().info(
                f"\n"
                f"===== FINAL POSITION CHECK =====\n"
                f"Target:   ({target_x:.3f}, {target_y:.3f}, {target_z:.3f})\n"
                f"Current:  ({current_x:.3f}, {current_y:.3f}, {current_z:.3f})\n"
                f"ΔX: {dx:.3f} m\n"
                f"ΔY: {dy:.3f} m\n"
                f"ΔZ: {dz:.3f} m\n"
                f"Total Error: {total_error:.3f} m\n"
                f"Tolerance: {tolerance:.3f} m\n"
                f"================================"
            )

            # ✅ Your OWN decision (ignore Nav2 status)
            if total_error <= tolerance:
                self.get_logger().info("Reached goal within custom tolerance ✅")
                self.first_reached = True
                
            else:
                self.get_logger().warn("Not within tolerance ❌ Performing correction...")
                #self.perform_correction()

        except Exception as e:
            self.get_logger().error(f"Error in result callback: {e}")



# navigation check function 
    def velocity_callback(self, msg):
        """Track robot velocity"""
        self.current_velocity = msg

    def is_robot_stopped(self, linear_threshold=0.01, angular_threshold=0.01):
        """
        Check if robot has stopped moving
        
        Args:
            linear_threshold: Max linear velocity to consider stopped (m/s)
            angular_threshold: Max angular velocity to consider stopped (rad/s)
        
        Returns:
            bool: True if robot is stopped
        """
        if self.current_velocity is None:
            return False
        
        linear_vel = abs(self.current_velocity.linear.x)
        angular_vel = abs(self.current_velocity.angular.z)
        
        is_stopped = (linear_vel < linear_threshold and 
                     angular_vel < angular_threshold)
        
        if is_stopped and not self.robot_is_stopped:
            self.get_logger().info("🛑 Robot has STOPPED - latching poses now!")
            self.robot_is_stopped = True
        
        return is_stopped



    # goal 2  to table place
    def navigate_to_goal2(self):
        """Navigate to the place table (goal 2)"""
        self.get_logger().info("=" * 50)
        self.get_logger().info("NAVIGATING TO PLACE TABLE (GOAL 2)")
        self.get_logger().info("=" * 50)
        

        # reset robot moving 
        self.robot_is_stopped = False

        self.get_logger().info(" Reset robot_is_stopped flag - robot moving to Goal 2")

        # Create goal message
        goal = PoseStamped()
        goal.header.frame_id = 'map'
        goal.header.stamp = self.get_clock().now().to_msg()
        
        # Goal 2 position
        goal.pose.position.x = self.GOAL2_X
        goal.pose.position.y = self.GOAL2_Y
        goal.pose.position.z = self.GOAL2_Z
        
        # Goal 2 orientation
        goal.pose.orientation.z = self.GOAL2_ORI_Z
        goal.pose.orientation.w = self.GOAL2_ORI_W
        
        # Publish the goal
        self.goal_publisher_.publish(goal)
        self.get_logger().info(f'Published Goal 2: x={goal.pose.position.x:.3f}, y={goal.pose.position.y:.3f}')
        
        # Create navigation action goal
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = goal
        
        # Send the goal
        self._send_goal_future = self._action_client.send_goal_async(goal_msg)
        self._send_goal_future.add_done_callback(self._goal2_response_callback)
        
        return True

    def _goal2_response_callback(self, future):
        """Handle Goal 2 acceptance"""
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('Goal 2 was rejected!')
            return

        self.get_logger().info('Goal 2 was accepted! Moving to place table...')
        
        # Set speed
        self.set_max_speed()
        
        # Wait for result
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self._goal2_result_callback)

    def _goal2_result_callback(self, future):
        """Handle Goal 2 completion"""
        try:
            result = future.result()
            status = result.status
            
            self.get_logger().info(f"Goal 2 navigation finished with status: {status}")
            
            if self.current_pose is None:
                self.get_logger().warn("Current pose not available!")
                return
            
            # Calculate error
            dx = self.GOAL2_X - self.current_pose.position.x
            dy = self.GOAL2_Y - self.current_pose.position.y
            error = math.sqrt(dx**2 + dy**2)
            
            tolerance = 0.40
            
            self.get_logger().info(
                f"\n"
                f"===== GOAL 2 POSITION CHECK =====\n"
                f"Target:   ({self.GOAL2_X:.3f}, {self.GOAL2_Y:.3f})\n"
                f"Current:  ({self.current_pose.position.x:.3f}, {self.current_pose.position.y:.3f})\n"
                f"Error: {error:.3f} m\n"
                f"Tolerance: {tolerance:.3f} m\n"
                f"================================"
            )
            
            if error <= tolerance:
                self.get_logger().info("✅ Reached Goal 2 (Place Table)!")
                self.second_goal_reached = True

                self.get_logger().info("robot stop!")
              

                self.get_logger().info("add collision object")
                self.add_table_2_collision_object()
                #self.place_object()
                #self.get_logger().info("add collision object"add_table_2_collision_object)

            else:
                self.get_logger().warn(f"❌ Not within tolerance (error: {error:.3f}m)")
                
        except Exception as e:
            self.get_logger().error(f"Error in Goal 2 result callback: {e}")











# collision object function


    def test_collision_object(self):

        self.get_logger().info("stop robot first..")
        # robot movement 
        # ✅ Check if robot is moving
        if not self.is_robot_stopped():
            self.get_logger().warn("Robot is moving! Stopping before adding markers...")
            #self.stop_robot()
            
            # # Wait for robot to actually stop
            # timeout = 0.03
            # start_time = time.time()
            # while not self.is_robot_stopped() and (time.time() - start_time) < timeout:
            #     #time.sleep(0.1)
            #     rclpy.spin_once(self, timeout_sec=0.01)
            
            # if not self.is_robot_stopped():
            #     self.get_logger().error("Failed to stop robot within timeout!")
            #     return False
        
        self.get_logger().info("✅ Robot confirmed stopped. Creating markers...")
        









        self.get_logger().info("sending Marker...")

        

        # call method to ad collision objects
        
        # collision objects
        self.collision_objects()
        # all markers for position
        self.move_markers()

        # arm move
        self.pick_object()



    def collision_objects(self):


       # collision 
        self.get_logger().info("Adding collision objects..")
       
        # 1. marker a object is created for the table 
        
        col_marker_table_1 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker
        col_marker_table_1.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker_table_1.header.stamp = self.get_clock().now().to_msg()
        col_marker_table_1.ns = "table_1" # 'ns: Namespace' it allows you to group markers together 
        col_marker_table_1.id = 1
        col_marker_table_1.type = Marker.CYLINDER # tells the shape of marker
        col_marker_table_1.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)
        # position
        col_marker_table_1.pose.position.x = self.pos_TCx + 0.243 # 0.185
        col_marker_table_1.pose.position.y = self.pos_TCy - 5*0.0162  # " - " following axis going right side
        col_marker_table_1.pose.position.z = self.pos_TCz - 0.052 #0.030 # 0.048
        #orientation- 
        #col_marker_table_1.pose.orientation.w = 1.0

               
        col_marker_table_1.pose.orientation.x = self.rot_TCx
        col_marker_table_1.pose.orientation.y = self.rot_TCy
        col_marker_table_1.pose.orientation.z = self.rot_TCz # 0.075
        col_marker_table_1.pose.orientation.w = self.rot_TCw # 0.075

        # Size  or say scale 
        col_marker_table_1.scale.x = 0.5 #Marker diameter (m)
        col_marker_table_1.scale.y = 0.5 # diameter (m)
        col_marker_table_1.scale.z = 0.1 # height (m)
        # Giving Marker a color
        col_marker_table_1.color.g = 1.0  
        col_marker_table_1.color.a = 1.0 # 1.0 = Opaque

        # MARKER 2, for the object 1

        col_marker_obj_1 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker
    
        col_marker_obj_1.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker_obj_1.header.stamp = self.get_clock().now().to_msg()
        col_marker_obj_1.ns = "obj_1" # 'ns: Namespace' it allows you to group markers together 
        col_marker_obj_1.id = 2
        col_marker_obj_1.type = Marker.CUBE# tells the shape of marker
        col_marker_obj_1.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)
        
        e = 0.068
        # position
        col_marker_obj_1.pose.position.x = self.pos_01Cx + e #  " + ", going opposite to axis, forward #0.75
        col_marker_obj_1.pose.position.y = self.pos_01Cy - 0.0125
        col_marker_obj_1.pose.position.z = self.pos_01Cz + 0.090 # 0.075
        #orientation- 
        col_marker_obj_1.pose.orientation.x = self.rot_01Cx
        col_marker_obj_1.pose.orientation.y = self.rot_01Cy
        col_marker_obj_1.pose.orientation.z = self.rot_01Cz 
        col_marker_obj_1.pose.orientation.w = self.rot_01Cw 
        
        # Size  or say scale real object : width, depth, height 0.04, 0.06, 0.15
        col_marker_obj_1.scale.x = 0.06 #Marker diameter (m) 0.06
        col_marker_obj_1.scale.y = 0.03 # diameter (m) 0.04
        col_marker_obj_1.scale.z = 0.15 # height (m)
        # Giving Marker a color
        col_marker_obj_1.color.g = 1.0
        col_marker_obj_1.color.a = 1.0 # 1.0 = Opaque


        # MARKER 3 , SECOND OBJECT obj_2

      
        col_marker_obj_2 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker
        col_marker_obj_2.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker_obj_2.header.stamp = self.get_clock().now().to_msg()
        col_marker_obj_2.ns = "obj_2" # 'ns: Namespace' it allows you to group markers together 
        col_marker_obj_2.id = 3
        col_marker_obj_2.type = Marker.CUBE# tells the shape of marker
        col_marker_obj_2.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)
        # position
        col_marker_obj_2.pose.position.x = self.pos_02Cx + e
        col_marker_obj_2.pose.position.y = self.pos_02Cy - 0.0125
        col_marker_obj_2.pose.position.z = self.pos_02Cz + 0.090
        #orientation- 
        #col_marker_obj_2.pose.orientation.w = 1.0


         #orientation- 
        col_marker_obj_2.pose.orientation.x = self.rot_02Cx
        col_marker_obj_2.pose.orientation.y = self.rot_02Cy
        col_marker_obj_2.pose.orientation.z = self.rot_02Cz 
        col_marker_obj_2.pose.orientation.w = self.rot_02Cw 

        # Size  or say scale real object : width, depth, height 0.04, 0.06, 0.15
        col_marker_obj_2.scale.x = 0.06 #Marker dlistiameter (m) 0.06
        col_marker_obj_2.scale.y = 0.03 # diameter (m) 0.04
        col_marker_obj_2.scale.z = 0.15 # height (m)
        # Giving Marker a color
        col_marker_obj_2.color.g = 1.0
        col_marker_obj_2.color.a = 1.0 # 1.0 = Opaque
        # MARKER 4 , obj_3
        
        col_marker_obj_3 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker

        col_marker_obj_3.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker_obj_3.header.stamp = self.get_clock().now().to_msg()
        col_marker_obj_3.ns = "obj_3" # 'ns: Namespace' it allows you to group markers together 
        col_marker_obj_3.id = 4
        col_marker_obj_3.type = Marker.CUBE# tells the shape of marker
        col_marker_obj_3.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)
        # position
        col_marker_obj_3.pose.position.x = self.pos_03Cx + e
        col_marker_obj_3.pose.position.y = self.pos_03Cy - 0.0125
        col_marker_obj_3.pose.position.z = self.pos_03Cz + 0.090
        #orientation- 
        #col_marker_obj_3.pose.orientation.w = 1.0


        col_marker_obj_3.pose.orientation.x = self.rot_03Cx
        col_marker_obj_3.pose.orientation.y = self.rot_03Cy
        col_marker_obj_3.pose.orientation.z = self.rot_03Cz 
        col_marker_obj_3.pose.orientation.w = self.rot_03Cw 


        # Size  or say scale real object : width, depth, height 0.04, 0.06, 0.15
        col_marker_obj_3.scale.x = 0.06 #Marker diameter (m) 0.06
        col_marker_obj_3.scale.y = 0.03 # diameter (m) 0.04
        col_marker_obj_3.scale.z = 0.15 # height (m)
        # Giving Marker a colorlist
        col_marker_obj_3.color.g = 1.0
        col_marker_obj_3.color.a = 1.0 # 1.0 = Opaque
        
        #MARKER 5, table_2 , placing table
        


        markers = [col_marker_table_1, col_marker_obj_1, col_marker_obj_2, col_marker_obj_3]
        

        self.add_coll_objects_from_markers(markers)
        



    def move_markers(self):
        # Creating Pregrasp and grasp position  
        

        self.pregrasp_obj_1_wp = Waypoint() # issue 29, created pregrasp object 

        #WayPoint(). A MoveIt-specific wrapper that contains a pose and possibly extra metadata (speed, constraints, etc.).
        pregrasp_obj_1_pose = PoseStamped()
        pregrasp_obj_1_pose.header.frame_id = "base_link"
        
        pregrasp_obj_1_pose.header.stamp = self.get_clock().now().to_msg() # Telling the transform tree: "This position is calculated based on the robot's current state right now.
        
        # Adjusting X (distance to robot). 
        
        # If robot is at X=0, subtracting 0.20m from object X makes it closer.
        c = 0.15 # tolerance
        b = 0.02
        a = 0.10
        pregrasp_obj_1_pose.pose.position.x = self.pos_01Cx - c
        pregrasp_obj_1_pose.pose.position.y = self.pos_01Cy
        pregrasp_obj_1_pose.pose.position.z = self.pos_01Cz + a # Lift slightly to avoid dragging
        

        pregrasp_obj_1_pose.pose.orientation.w = 1.0 # 
        self.pregrasp_obj_1_wp.pose = pregrasp_obj_1_pose


        # 2 Grasp Waypoint (5cm closer to robot)
        self.grasp_obj_1_wp = Waypoint()
        grasp_obj_1_pose = PoseStamped()
        grasp_obj_1_pose.header.frame_id = "base_link"
        grasp_obj_1_pose.header.stamp = self.get_clock().now().to_msg()
        
        grasp_obj_1_pose.pose.position.x = self.pos_01Cx - b
        grasp_obj_1_pose.pose.position.y = self.pos_01Cy 
        grasp_obj_1_pose.pose.position.z = self.pos_01Cz + a
        
        grasp_obj_1_pose.pose.orientation.w = 1.0
        self.grasp_obj_1_wp.pose = grasp_obj_1_pose
        
        


        # lift waypoint 
        # 3. Lift Waypoint 
        self.lift_obj_1_wp = Waypoint()
        lift_obj_1_pose = PoseStamped()
        lift_obj_1_pose.header.frame_id = "base_link"
        lift_obj_1_pose.pose.position.x = self.pos_01Cx - b
        lift_obj_1_pose.pose.position.y = self.pos_01Cy
        lift_obj_1_pose.pose.position.z = self.pos_01Cz + 3*a
        lift_obj_1_pose.pose.orientation.w = 1.0
        self.lift_obj_1_wp.pose = lift_obj_1_pose


        # holdback 1, for object 1
        self.holdback_obj_1_wp = Waypoint()
        holdback_obj_1_pose = PoseStamped()
        holdback_obj_1_pose.header.frame_id = "base_link"
        holdback_obj_1_pose.pose.position.x = self.pos_01Cx - c
        holdback_obj_1_pose.pose.position.y = self.pos_01Cy
        holdback_obj_1_pose.pose.position.z = self.pos_01Cz + 3*0.10 # 
        holdback_obj_1_pose.pose.orientation.w = 1.0
        self.holdback_obj_1_wp.pose = holdback_obj_1_pose



     

        #  Pregrasp 1 , for object 1
        move_marker_pre_1 = Marker()
        move_marker_pre_1.header.frame_id = "base_link"
        move_marker_pre_1.header.stamp = self.get_clock().now().to_msg()
        move_marker_pre_1 .ns = "pregrasp_1"
        move_marker_pre_1.id = 10 # Unique ID
        move_marker_pre_1.type = Marker.ARROW
        move_marker_pre_1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker_pre_1.pose = pregrasp_obj_1_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker_pre_1.scale.x = 0.3  # Length of arrow
        move_marker_pre_1.scale.y = 0.02 # Arrow head width
        move_marker_pre_1.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker_pre_1.color.r = 1.0 # Red for all obj1 
        move_marker_pre_1.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        self.pub.publish(move_marker_pre_1)
    

        # ###############grasp 1, for object 1#################


        move_marker_grasp_1 = Marker()
        move_marker_grasp_1.header.frame_id = "base_link"
        move_marker_grasp_1.header.stamp = self.get_clock().now().to_msg()
        move_marker_grasp_1 .ns = "grasp_1"
        move_marker_grasp_1.id = 11 # Unique ID
        move_marker_grasp_1.type = Marker.ARROW
        move_marker_grasp_1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker_grasp_1.pose = grasp_obj_1_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker_grasp_1.scale.x = 0.3  # Length of arrow
        move_marker_grasp_1.scale.y = 0.02 # Arrow head width
        move_marker_grasp_1.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker_grasp_1.color.r = 1.0 # Red for all obj1 
        move_marker_grasp_1.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        self.pub.publish(move_marker_grasp_1)

        ######## lift 1, object 1###########

        move_marker_lift_1 = Marker()
        move_marker_lift_1.header.frame_id = "base_link"
        move_marker_lift_1.header.stamp = self.get_clock().now().to_msg()
        move_marker_lift_1 .ns = "lift_1"
        move_marker_lift_1.id = 12 # Unique ID
        move_marker_lift_1.type = Marker.ARROW
        move_marker_lift_1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker_lift_1.pose = lift_obj_1_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker_lift_1.scale.x = 0.3  # Length of arrow
        move_marker_lift_1.scale.y = 0.02 # Arrow head width
        move_marker_lift_1.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker_lift_1.color.r = 1.0 # Red for all obj1 
        move_marker_lift_1.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        self.pub.publish(move_marker_lift_1)

        ###########  holdback 1, for object 1 ##########


        move_marker_holdback_1 = Marker()
        move_marker_holdback_1.header.frame_id = "base_link"
        move_marker_holdback_1.header.stamp = self.get_clock().now().to_msg()
        move_marker_holdback_1 .ns = "holdback_1"
        move_marker_holdback_1.id = 13 # Unique ID
        move_marker_holdback_1.type = Marker.ARROW
        move_marker_holdback_1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker_holdback_1.pose = holdback_obj_1_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker_holdback_1.scale.x = 0.3  # Length of arrow
        move_marker_holdback_1.scale.y = 0.02 # Arrow head width
        move_marker_holdback_1.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker_holdback_1.color.r = 1.0 # Red for all obj1 
        move_marker_holdback_1.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        self.pub.publish(move_marker_holdback_1)





###############################OBJECT 2 #############################################

        # --- Object 2: Pre-grasp ---
        self.pregrasp_obj_2_wp = Waypoint()
        pregrasp_obj_2_pose = PoseStamped()
        pregrasp_obj_2_pose.header.frame_id = "base_link"
        pregrasp_obj_2_pose.header.stamp = self.get_clock().now().to_msg()
        pregrasp_obj_2_pose.pose.position.x = self.pos_02Cx - 0.20 
        pregrasp_obj_2_pose.pose.position.y = self.pos_02Cy
        pregrasp_obj_2_pose.pose.position.z = self.pos_02Cz + 0.10
        pregrasp_obj_2_pose.pose.orientation.w = 1.0
        self.pregrasp_obj_2_wp.pose = pregrasp_obj_2_pose

        # --- Object 2: Grasp ---
        grasp_obj_2_wp = Waypoint()
        grasp_obj_2_pose = PoseStamped()
        grasp_obj_2_pose.header.frame_id = "base_link"
        grasp_obj_2_pose.pose.position.x = self.pos_02Cx - 0.02
        grasp_obj_2_pose.pose.position.y = self.pos_02Cy
        grasp_obj_2_pose.pose.position.z = self.pos_02Cz + 0.10
        grasp_obj_2_pose.pose.orientation.w = 1.0
        grasp_obj_2_wp.pose = grasp_obj_2_pose

        # --- Object 2: Lift ---
        lift_obj_2_wp = Waypoint()
        lift_obj_2_pose = PoseStamped()
        lift_obj_2_pose.header.frame_id = "base_link"
        lift_obj_2_pose.pose.position.x = self.pos_02Cx - 0.02
        lift_obj_2_pose.pose.position.y = self.pos_02Cy
        lift_obj_2_pose.pose.position.z = self.pos_02Cz + 0.30
        lift_obj_2_pose.pose.orientation.w = 1.0
        lift_obj_2_wp.pose = lift_obj_2_pose

        # --- Object 2: Holdback ---
        holdback_obj_2_wp = Waypoint()
        holdback_obj_2_pose = PoseStamped()
        holdback_obj_2_pose.header.frame_id = "base_link"
        holdback_obj_2_pose.pose.position.x = self.pos_02Cx - 0.20
        holdback_obj_2_pose.pose.position.y = self.pos_02Cy
        holdback_obj_2_pose.pose.position.z = self.pos_02Cz + 0.30
        holdback_obj_2_pose.pose.orientation.w = 1.0
        holdback_obj_2_wp.pose = holdback_obj_2_pose


        ###object 2 marker #######

        #  Pregrasp 2, for object 2 #################
        move_marker_pre_2 = Marker()
        move_marker_pre_2.header.frame_id = "base_link"
        move_marker_pre_2.header.stamp = self.get_clock().now().to_msg()
        move_marker_pre_2.ns = "pregrasp_2"
        move_marker_pre_2.id = 20 # Unique ID for Obj 2 Pre-grasp
        move_marker_pre_2.type = Marker.ARROW
        move_marker_pre_2.action = Marker.ADD

        # Use Object 2 pregrasp pose
        move_marker_pre_2.pose = pregrasp_obj_2_pose.pose

        # Set scale for the arrow
        move_marker_pre_2.scale.x = 0.3  
        move_marker_pre_2.scale.y = 0.02 
        move_marker_pre_2.scale.z = 0.02 

        # Set color (Green)
        move_marker_pre_2.color.g = 1.0 
        move_marker_pre_2.color.a = 1.0 

        # Publish
        self.pub.publish(move_marker_pre_2)


        # GRASP 2, for object 2 

        move_marker_grasp_2 = Marker()
        move_marker_grasp_2.header.frame_id = "base_link"
        move_marker_grasp_2.header.stamp = self.get_clock().now().to_msg()
        move_marker_grasp_2.ns = "grasp_2"
        move_marker_grasp_2.id = 21 # Unique ID for Obj 3
        move_marker_grasp_2.type = Marker.ARROW
        move_marker_grasp_2.action = Marker.ADD
        move_marker_grasp_2.pose = grasp_obj_2_pose.pose # Uses pos_03Cx variables
        move_marker_grasp_2.scale.x, move_marker_grasp_2.scale.y, move_marker_grasp_2.scale.z = 0.3, 0.02, 0.02
        move_marker_grasp_2.color.g, move_marker_grasp_2.color.a = 1.0, 1.0 # Blue
        self.pub.publish(move_marker_grasp_2)

        ######## LIFT 2, object 2 ###########
        move_marker_lift_2 = Marker()
        move_marker_lift_2.header.frame_id = "base_link"
        move_marker_lift_2.header.stamp = self.get_clock().now().to_msg()
        move_marker_lift_2.ns = "lift_2"
        move_marker_lift_2.id = 22
        move_marker_lift_2.type = Marker.ARROW
        move_marker_lift_2.action = Marker.ADD
        move_marker_lift_2.pose = lift_obj_2_pose.pose
        move_marker_lift_2.scale.x, move_marker_lift_2.scale.y, move_marker_lift_2.scale.z = 0.3, 0.02, 0.02
        move_marker_lift_2.color.g, move_marker_lift_2.color.a = 1.0, 1.0
        self.pub.publish(move_marker_lift_2)

        ########### HOLDBACK 2, for object 2 ##########
        move_marker_holdback_2 = Marker()
        move_marker_holdback_2.header.frame_id = "base_link"
        move_marker_holdback_2.header.stamp = self.get_clock().now().to_msg()
        move_marker_holdback_2.ns = "holdback_2"
        move_marker_holdback_2.id = 23
        move_marker_holdback_2.type = Marker.ARROW
        move_marker_holdback_2.action = Marker.ADD
        move_marker_holdback_2.pose = holdback_obj_2_pose.pose
        move_marker_holdback_2.scale.x, move_marker_holdback_2.scale.y, move_marker_holdback_2.scale.z = 0.3, 0.02, 0.02
        move_marker_holdback_2.color.g, move_marker_holdback_2.color.a = 1.0, 1.0
        self.pub.publish(move_marker_holdback_2)




######################### OBJECT 3 ###############################

        # --- Object 3: Pre-grasp ---
        pregrasp_obj_3_wp = Waypoint()
        pregrasp_obj_3_pose = PoseStamped()
        pregrasp_obj_3_pose.header.frame_id = "base_link"
        pregrasp_obj_3_pose.header.stamp = self.get_clock().now().to_msg()
        pregrasp_obj_3_pose.pose.position.x = self.pos_03Cx - 0.25
        pregrasp_obj_3_pose.pose.position.y = self.pos_03Cy 
        pregrasp_obj_3_pose.pose.position.z = self.pos_03Cz + 0.10
        pregrasp_obj_3_pose.pose.orientation.w = 1.0
        pregrasp_obj_3_wp.pose = pregrasp_obj_3_pose

        # --- Object 3: Grasp ---
        grasp_obj_3_wp = Waypoint()
        grasp_obj_3_pose = PoseStamped()
        grasp_obj_3_pose.header.frame_id = "base_link"
        grasp_obj_3_pose.pose.position.x = self.pos_03Cx - 0.03
        grasp_obj_3_pose.pose.position.y = self.pos_03Cy
        grasp_obj_3_pose.pose.position.z = self.pos_03Cz + 0.10
        grasp_obj_3_pose.pose.orientation.w = 1.0
        grasp_obj_3_wp.pose = grasp_obj_3_pose

        # --- Object 3: Lift ---
        lift_obj_3_wp = Waypoint()
        lift_obj_3_pose = PoseStamped()
        lift_obj_3_pose.header.frame_id = "base_link"
        lift_obj_3_pose.pose.position.x = self.pos_03Cx 
        lift_obj_3_pose.pose.position.y = self.pos_03Cy
        lift_obj_3_pose.pose.position.z = self.pos_03Cz + 0.30
        lift_obj_3_pose.pose.orientation.w = 1.0
        lift_obj_3_wp.pose = lift_obj_3_pose

        # --- Object 3: Holdback ---
        holdback_obj_3_wp = Waypoint()
        holdback_obj_3_pose = PoseStamped()
        holdback_obj_3_pose.header.frame_id = "base_link"
        holdback_obj_3_pose.pose.position.x = self.pos_03Cx - 0.15
        holdback_obj_3_pose.pose.position.y = self.pos_03Cy
        holdback_obj_3_pose.pose.position.z = self.pos_03Cz + 0.30
        holdback_obj_3_pose.pose.orientation.w = 1.0
        holdback_obj_3_wp.pose = holdback_obj_3_pose



      ############### object 3 marker ################
        
        # Pregrasp 3, for object 3 

        move_marker_pre_3 = Marker()
        move_marker_pre_3.header.frame_id = "base_link"
        move_marker_pre_3.header.stamp = self.get_clock().now().to_msg()
        move_marker_pre_3.ns = "pregrasp_3"
        move_marker_pre_3.id = 30 # Unique ID for Obj 3 Pre-grasp
        move_marker_pre_3.type = Marker.ARROW
        move_marker_pre_3.action = Marker.ADD

        # Use Object 3 pregrasp pose
        move_marker_pre_3.pose = pregrasp_obj_3_pose.pose

        # Set scale for the arrow
        move_marker_pre_3.scale.x = 0.3  
        move_marker_pre_3.scale.y = 0.02 
        move_marker_pre_3.scale.z = 0.02 

        # Set color (Blue)
        move_marker_pre_3.color.b = 1.0 
        move_marker_pre_3.color.a = 1.0 

        # Publish
        self.pub.publish(move_marker_pre_3)





        # GRASP 3, for object 3 

        move_marker_grasp_3 = Marker()
        move_marker_grasp_3.header.frame_id = "base_link"
        move_marker_grasp_3.header.stamp = self.get_clock().now().to_msg()
        move_marker_grasp_3.ns = "grasp_3"
        move_marker_grasp_3.id = 31 # Unique ID for Obj 3
        move_marker_grasp_3.type = Marker.ARROW
        move_marker_grasp_3.action = Marker.ADD
        move_marker_grasp_3.pose = grasp_obj_3_pose.pose # Uses pos_03Cx variables
        move_marker_grasp_3.scale.x, move_marker_grasp_3.scale.y, move_marker_grasp_3.scale.z = 0.3, 0.02, 0.02
        move_marker_grasp_3.color.b, move_marker_grasp_3.color.a = 1.0, 1.0 # Blue
        self.pub.publish(move_marker_grasp_3)

        ######## LIFT 3, object 3 ###########
        move_marker_lift_3 = Marker()
        move_marker_lift_3.header.frame_id = "base_link"
        move_marker_lift_3.header.stamp = self.get_clock().now().to_msg()
        move_marker_lift_3.ns = "lift_3"
        move_marker_lift_3.id = 32
        move_marker_lift_3.type = Marker.ARROW
        move_marker_lift_3.action = Marker.ADD
        move_marker_lift_3.pose = lift_obj_3_pose.pose
        move_marker_lift_3.scale.x, move_marker_lift_3.scale.y, move_marker_lift_3.scale.z = 0.3, 0.02, 0.02
        move_marker_lift_3.color.b, move_marker_lift_3.color.a = 1.0, 1.0
        self.pub.publish(move_marker_lift_3)

        ########### HOLDBACK 3, for object 3 ##########
        move_marker_holdback_3 = Marker()
        move_marker_holdback_3.header.frame_id = "base_link"
        move_marker_holdback_3.header.stamp = self.get_clock().now().to_msg()
        move_marker_holdback_3.ns = "holdback_3"
        move_marker_holdback_3.id = 33
        move_marker_holdback_3.type = Marker.ARROW
        move_marker_holdback_3.action = Marker.ADD
        move_marker_holdback_3.pose = holdback_obj_3_pose.pose
        move_marker_holdback_3.scale.x, move_marker_holdback_3.scale.y, move_marker_holdback_3.scale.z = 0.3, 0.02, 0.02
        move_marker_holdback_3.color.b, move_marker_holdback_3.color.a = 1.0, 1.0
        self.pub.publish(move_marker_holdback_3)


    # DELETE VISUALIZATION MARKERS

    def delete_visualization_markers(self):
        """Delete all visualization markers from RViz"""
        self.get_logger().info("Deleting visualization markers...")
        
        # List of all marker namespaces to delete
        marker_namespaces = [
            "pregrasp_1", "grasp_1", "lift_1", "holdback_1",
            "pregrasp_2", "grasp_2", "lift_2", "holdback_2",
            "pregrasp_3", "grasp_3", "lift_3", "holdback_3"
        ]
        
        for ns in marker_namespaces:
            delete_marker = Marker()
            delete_marker.header.frame_id = "base_link"
            delete_marker.header.stamp = self.get_clock().now().to_msg()
            delete_marker.ns = ns
            delete_marker.action = Marker.DELETEALL  # Delete all markers in this namespace
            
            self.pub.publish(delete_marker)
        
        self.get_logger().info(f"✅ Deleted {len(marker_namespaces)} marker namespaces")














    # def pick_object(self):
        
    #     if self.second_goal_reached == False:

    #         self.get_logger().info("Planning to Pre-grasp...")

    #         MAX_RETRIES = 10
    #         # again open gripper if not done 
            
    #         self.send_gripper_command("open")

    #         pregrasp_1_success = False
    #         grasp_1_success = False
    #         lift_1_success = False
    #         holdback_1_success = False

    #         for attempt in range(1, MAX_RETRIES + 1):
    #             self.get_logger().info(f"\n🎯 PREGRASP Attempt {attempt}/{MAX_RETRIES}")
            
    #             plan_pregrasp = self.call_planning_service([self.pregrasp_obj_1_wp])

    #             if plan_pregrasp and plan_pregrasp.success:
    #                 self.call_execution_service(plan_pregrasp.plans)
    #                 self.get_logger().info("pregrap reached...")
    #                 pregrasp_1_success = True
    #                 #self.send_gripper_command("open") # if not done
                    
    #                 #  Plan and move from Pre-grasp to Grasp
    #                 for attempt in range(1, MAX_RETRIES + 1):
    #                     self.get_logger().info(f"\n🎯 GRASP Attempt {attempt}/{MAX_RETRIES}")
    #                     self.get_logger().info("Moving to Grasp position...")
    #                     plan_grasp = self.call_planning_service([self.grasp_obj_1_wp])

    #                     #checking done or not 
    #                     if plan_grasp and plan_grasp.success:

    #                         self.call_execution_service(plan_grasp.plans)

    #                         self.get_logger().info("Grasp position reached...")
    #                         grasp_1_success = True

    #                         gripper_active = False
    #                         # then close partially gripper if grasp reached
    #                         if gripper_active is not True:
    #                             self.get_logger().info("Closing gripper and attaching object...")
    #                             self.send_partial_gripper_command()
    #                             self.attach_objects(["obj_1"])
    #                             self.get_logger().error("OBJECT_IS_ATTACHED")

    #                             for attempt in range(1, MAX_RETRIES + 1): 
    #                                 self.get_logger().info(f"\n🎯 lift_1 Attempt {attempt}/{MAX_RETRIES}")
                                    
    #                                 plan_lift = self.call_planning_service([self.lift_obj_1_wp])


    #                                 #checking done or not 
    #                                 if plan_lift and plan_lift.success:
    #                                     self.call_execution_service(plan_lift.plans)
    #                                     self.get_logger().info("lift position reached...")
    #                                     lift_1_success = True


    #                                         # hold and take back (safe position)




    #                                     for attempt in range(1, MAX_RETRIES + 1):
    #                                         self.get_logger().info(f"\n🎯 holdback_1 Attempt {attempt}/{MAX_RETRIES}")
    #                                         self.get_logger().info("move to safe position...")
    #                                         plan_holdback = self.call_planning_service([self.holdback_obj_1_wp])

    #                                         if plan_holdback and plan_holdback.success:
    #                                             self.call_execution_service(plan_holdback.plans)
    #                                             self.get_logger().info("holdback reached ...")

    #                                             holdback_1_success = True
                                                
    #                                             self.get_logger().info(".....................................")
    #                                             self.get_logger().info(".....................................")
    #                                             self.get_logger().info(".....................................")
    #                                             self.get_logger().info(".......PLANNING SUCCESSFUL...1.......")
    #                                             self.get_logger().info(".....................................")
    #                                             self.get_logger().info(".....................................")
    #                                             self.get_logger().info(".....................................")

                                            
    #                                             # remove collision objects:
    #                                             self.get_logger().info("Removing collision objects...")
    #                                             self.remove_collision_obj(["table_1"])
    #                                             self.remove_collision_obj(["obj_2"])
    #                                             self.remove_collision_obj(["obj_3"])

    #                                             # remove visualization markers 
                        
    #                                             self.delete_visualization_markers()

    #                                             # NEW: Navigate to Goal 2

    #                                             self.get_logger().info("Starting navigation to place table...")
    #                                             self.navigate_to_goal2()
    #                                             return True
                                                
                                    
    #                                         else:
    #                                             self.get_logger().error(".....................................")
    #                                             self.get_logger().error(".....................................")
    #                                             self.get_logger().error(".....................................")           
    #                                             self.get_logger().error("............holdback not reached....1.")
    #                                             self.get_logger().error(".....................................")
    #                                             self.get_logger().error(".....................................")   

    #                                     if not holdback_1_success:
    #                                         self.get_logger().error(f"❌ HOLDBACK_1 FAILED after {MAX_RETRIES} attempts! Aborting.")
    #                                         return False



    #                                 else:

    #                                     self.get_logger().error("..............................")
    #                                     self.get_logger().error(".....................................")
    #                                     self.get_logger().error(".....................................")
    #                                     self.get_logger().error(".......lift position not reached....1.......")
    #                                     self.get_logger().error(".....................................")
    #                                     self.get_logger().error(".....................................")
    #                                     self.get_logger().error(".....................................")
                                
                                
    #                             if not lift_1_success:
    #                                 self.get_logger().error(f"❌ LIFT_1 FAILED after {MAX_RETRIES} attempts! Aborting.")
    #                                 return False






    #                 # check reached or not 
                    

    #                     else:
    #                         self.get_logger().error("..............................")
    #                         self.get_logger().error(".....................................")
    #                         self.get_logger().error(".....................................")
    #                         self.get_logger().error(".......Grasp position not reached....1.......")
    #                         self.get_logger().error(".....................................")
    #                         self.get_logger().error(".....................................")
    #                         self.get_logger().error(".....................................")
                    
    #                 if not grasp_1_success:
    #                     self.get_logger().error(f"❌ GRASP_1 FAILED after {MAX_RETRIES} attempts! Aborting.")
    #                     return False




    #             else:
                
    #                 self.get_logger().error(".....................................")
    #                 self.get_logger().error(".....................................")
    #                 self.get_logger().error(".......pregrap NOT reached....1.......")
    #                 self.get_logger().error(".....................................")
    #                 self.get_logger().error(".....................................")
    #                 self.get_logger().error(".....................................")
                
                
    #         if not pregrasp_1_success:
    #             self.get_logger().error(f"❌ PREGRASP_1 FAILED after {MAX_RETRIES} attempts! Aborting.")
    #             return False


    def pick_object(self):
        """Execute pick sequence at Goal 1"""
        
        self.get_logger().info("=" * 80)
        self.get_logger().info("STARTING PICK SEQUENCE")
        self.get_logger().info("=" * 80)
        
        MAX_RETRIES = 10
        self.send_gripper_command("open")

        # ==========================================
        # PHASE 1: PREGRASP
        # ==========================================
        pregrasp_success = False
        
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"🎯 PREGRASP Attempt {attempt}/{MAX_RETRIES}")
            plan_pregrasp = self.call_planning_service([self.pregrasp_obj_1_wp])
            
            if plan_pregrasp and plan_pregrasp.success:
                self.call_execution_service(plan_pregrasp.plans)
                self.get_logger().info("✅ Pregrasp reached!")
                pregrasp_success = True
                break  # ← Exit THIS loop
            else:
                time.sleep(0.5)
        
        if not pregrasp_success:
            self.get_logger().error("❌ PREGRASP FAILED!")
            return False  # ← Exit ENTIRE function

        # ==========================================
        # PHASE 2: GRASP
        # ==========================================
        grasp_success = False
        
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"🎯 GRASP Attempt {attempt}/{MAX_RETRIES}")
            plan_grasp = self.call_planning_service([self.grasp_obj_1_wp])
            
            if plan_grasp and plan_grasp.success:
                self.call_execution_service(plan_grasp.plans)
                self.send_partial_gripper_command()
                self.attach_objects(["obj_1"])
                self.get_logger().info("✅ Grasp reached and object attached!")
                grasp_success = True
                break
            else:
                time.sleep(0.5)
        
        if not grasp_success:
            self.get_logger().error("❌ GRASP FAILED!")
            return False

        # ==========================================
        # PHASE 3: LIFT
        # ==========================================
        lift_success = False
        
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"🎯 LIFT Attempt {attempt}/{MAX_RETRIES}")
            plan_lift = self.call_planning_service([self.lift_obj_1_wp])
            
            if plan_lift and plan_lift.success:
                self.call_execution_service(plan_lift.plans)
                self.get_logger().info("✅ Lift reached!")
                lift_success = True
                break
            else:
                time.sleep(0.5)
        
        if not lift_success:
            self.get_logger().error("❌ LIFT FAILED!")
            return False

        # ==========================================
        # PHASE 4: HOLDBACK
        # ==========================================
        holdback_success = False
        
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"🎯 HOLDBACK Attempt {attempt}/{MAX_RETRIES}")
            plan_holdback = self.call_planning_service([self.holdback_obj_1_wp])
            
            if plan_holdback and plan_holdback.success:
                self.call_execution_service(plan_holdback.plans)
                self.get_logger().info("✅ Holdback reached!")
                holdback_success = True
                break  # ← Exit holdback loop
            else:
                time.sleep(0.5)
        
        if not holdback_success:
            self.get_logger().error("❌ HOLDBACK FAILED!")
            return False

        # ==========================================
        # ALL PHASES COMPLETE - CLEANUP AND NAVIGATE
        # ==========================================
        self.get_logger().info("=" * 80)
        self.get_logger().info("✅✅✅ PICK SEQUENCE COMPLETE! ✅✅✅")
        self.get_logger().info("=" * 80)
        
        # Remove collision objects
        self.get_logger().info("Removing collision objects from Goal 1...")
        self.remove_collision_obj(["table_1", "obj_2", "obj_3"])
        
        # Remove visualization markers
        self.delete_visualization_markers()
        
        # Start navigation to Goal 2
        self.get_logger().info("Starting navigation to Goal 2...")
        self.navigate_to_goal2()
        
        # ✅✅✅ CRITICAL: RETURN TRUE IMMEDIATELY! ✅✅✅
        # This exits the function so no more Goal 1 waypoints are used!
        return True


    def get_tag_pose(self):
        
        # # If already latched, don't update anymore
        # if self.poses_latched:
        #     return True
        
        # Only latch poses when robot is completely stopped
        if not self.is_robot_stopped():
            return False
        
        # Tables + unknown object IDs
        
        
        tag_ids = [self.TABLE_PICK_ID, self.TABLE_PLACE_ID] + list(range(1, self.max_objects+1))


        any_found = False
        self.get_logger().info(f"Checking tags: {tag_ids}")  # <-- debug log

        for tag_id in tag_ids:
            self.update_tag_pose(tag_id)
            any_found =True
        
        self.get_logger().info("No tags found in this cycle.")
        return any_found # tag found then true


    def update_tag_pose(self, tag_id):
        target_frame = f"tag36h11:{tag_id}"
        source_frame = "base_link"

        try:
            trans = self.tf_buffer.lookup_transform(source_frame, target_frame, rclpy.time.Time())
            px = trans.transform.translation.x
            py = trans.transform.translation.y
            pz = trans.transform.translation.z



            #   SAVE ORIENTATION
            qx = trans.transform.rotation.x
            qy = trans.transform.rotation.y
            qz = trans.transform.rotation.z
            qw = trans.transform.rotation.w


            if not self.robot_is_stopped:
            # Robot is moving - don't latch these poses!
                self.get_logger().info(
                    f"Tag {tag_id} detected but robot is moving - skipping latch",
                    throttle_duration_sec=2.0  # Only log every 2 seconds
                )
                return False

            # --- PICK TABLE ---
            if tag_id == self.TABLE_PICK_ID:
                self.pos_Tx, self.pos_Ty, self.pos_Tz = px, py, pz   # live TF
                self.pos_TCx, self.pos_TCy, self.pos_TCz = px, py, pz # **latched**
                 #  Save orientation too
                self.rot_Tx, self.rot_Ty, self.rot_Tz, self.rot_Tw = qx, qy, qz, qw

                self.rot_TCx, self.rot_TCy, self.rot_TCz, self.rot_TCw = qx, qy, qz, qw # LATCH 

            # --- PLACE TABLE ---
            elif tag_id == self.TABLE_PLACE_ID:
                self.pos_TPx, self.pos_TPy, self.pos_TPz = px, py, pz
                self.pos_TPCx, self.pos_TPCy, self.pos_TPCz = px, py, pz # **latched**
                # ROTATION 
                self.rot_TPx, self.rot_TPy, self.rot_TPz, self.rot_TPw = qx, qy, qz, qw

                self.rot_TPCx, self.rot_TPCy, self.rot_TPCz, self.rot_TPCw = qx, qy, qz, qw # LATCH 

                self.get_logger().info("place table pose orientation found")
                self.get_logger().info(f"Tag {tag_id} found at pose ({px:.2f}, {py:.2f}, {pz:.2f})")
                self.get_logger().info(f"Tag {tag_id} found at orientation({qx:.2f}, {qy:.2f}, {qz:.2f},{qw:.2f})")



            # --- OBJECTS ---
            else:
                self.update_object_pose(tag_id, px, py, pz, qx, qy, qz, qw)              # live TF
             #self.update_object_cached_pose(tag_id, px, py, pz)       # **latched**
            
            # print values 
            #self.get_logger().info(f"Tag {tag_id} found at pose ({px:.2f}, {py:.2f}, {pz:.2f})")
            #self.get_logger().info(f"Tag {tag_id} found at orientation({qx:.2f}, {qy:.2f}, {qz:.2f},{qw:.2f})")
            return True

        except TransformException:
            #self.get_logger().info(f"Tag {tag_id} not found")
            
            if tag_id in self.latched_pose:
                px, py, pz , qx, qy, qz, qw = self.latched_pose[tag_id] # unpacking all
                self.update_object_pose(tag_id, px, py, pz, qx, qy, qz, qw)
            return False


#### ASSIGNING SLOT IF IDS CHANGED 
    def assign_slot(self, tag_id):
        """
        Assigns a tag to a free object slot (1,2,3)
        """
        if tag_id in self.object_slots:
            return self.object_slots[tag_id]

        if len(self.object_slots) >= self.max_objects:
            return None  # ignore extra objects

        slot = len(self.object_slots) + 1
        self.object_slots[tag_id] = slot
        return slot


# UPDATE OBJECT POSE ONCE , AVAILABLE

    def update_object_pose(self, tag_id, px, py, pz, qx, qy, qz, qw):
        slot = self.assign_slot(tag_id)
        if slot is None:
            return
        
            # Update latched pose
        self.latched_pose[tag_id] = (px, py, pz, qx, qy, qz, qw)

        if slot == 1 :
            self.pos_01x, self.pos_01y, self.pos_01z = px, py, pz
            self.pos_01Cx, self.pos_01Cy, self.pos_01Cz = px, py, pz

            # object 1
            self.rot_01x, self.rot_01y, self.rot_01z, self.rot_01w = qx, qy, qz, qw
            # save rotation 
            self.rot_01Cx, self.rot_01Cy, self.rot_01Cz, self.rot_01Cw = qx, qy, qz, qw
        elif slot == 2:
            self.pos_02x, self.pos_02y, self.pos_02z = px, py, pz
            self.pos_02Cx, self.pos_02Cy, self.pos_02Cz = px, py, pz


            # object 2
            self.rot_02x, self.rot_02y, self.rot_02z, self.rot_02w = qx, qy, qz, qw
            # save rotation 
            self.rot_02Cx, self.rot_02Cy, self.rot_02Cz, self.rot_02Cw = qx, qy, qz, qw




        elif slot == 3:
            self.pos_03x, self.pos_03y, self.pos_03z = px, py, pz
            self.pos_03Cx, self.pos_03Cy, self.pos_03Cz = px, py, pz

            # object 3
            self.rot_03x, self.rot_03y, self.rot_03z, self.rot_02w = qx, qy, qz, qw
            # save rotation 
            self.rot_03Cx, self.rot_03Cy, self.rot_03Cz, self.rot_03Cw = qx, qy, qz, qw


    #marker to collision object
    def add_coll_objects_from_markers(self, markers):
        """Transform given markers to collision objects. Returns True on success."""

        try:
            req = AddColObj.Request() #Creates a request message for the AddColObj service, and .Request() builds an empty request object
            req.objects = markers # Assigns our input 'markers' to the request field objects, objects exists in the service definition
            fut = self.add_col_client.call_async(req)# Sends the 'service request' without blocking, and Returns a Future object (fut). The service is now executing in the background
            if not self._wait_future(fut, 25.0):# calls a helper method _wait_future, wait for 15 sec for the service to respond, it Returns: True->response_arrived, False->timeout
                self.get_logger().error("AddColObj timeout.")# if nnot respnd in time, logs an error
                return False, []# returns failure , and exit from function

            resp = fut.result() # Extracts the actual response message from the future.(future object , fut) 
            #At this point, the service has completed

            #Check the failure in response
            if hasattr(resp, "success") and resp.success is False: # hasattr(resp, "success"), it checks whether the service has a field "success"
                # resp.success is False, means service called , response returned succesfully but the, operation doesnt work (accidientally service set to success = False, in its response)
                self.get_logger().error(
                    f"AddColObj failed: {getattr(resp, 'message', '')}"
                )
                return False, []

            self.get_logger().info(
                f"Added {len(markers)} collision markers to the planning scene."
            ) # this log success with number of markers
        except Exception as e: # this for any Python exception that happens inside the try block.(Service client not initialized → AttributeError, Invalid message type → TypeError, ROS 2 communication error → RuntimeError)
            self.get_logger().error(f"AddColObj failed: {e}")
            return False, []
        




    # -------------------------------
    # Service waiting
    # -------------------------------
    # The below function check all the services availability that is required for the operation
    # it pause execution until the service is not available


    def wait_for_services(self):
        """Wait for all required services to be available."""
        self.get_logger().info("Waiting for services...")

        # below creating list of tuples, each tuples has service_client_object: self.add_co_client
        services = [
            (self.plan_client, "/moveit_wrapper/plan"),
            (self.execute_client, "/moveit_wrapper/execute_plans"),
            (self.add_col_client, "/moveit_wrapper/add_collision_object"),
            (self.remove_col_client, "/moveit_wrapper/remove_collision_object"),
            (self.attach_col_client, "/moveit_wrapper/attach_object"),
            (self.detach_col_client, "/moveit_wrapper/detach_object"),
            (self.get_attached_client, "/moveit_wrapper/get_attached_objects"),
        ]
         
        # with the list, it allows the code to wait for multiple services in a loop.

        for client, service_name in services:
            
            #client.wait_for_service(timeout_sec=1.0), if service is not available return Fale
            # While not False-> While True-->go inside loop and again wait for client
            while not client.wait_for_service(timeout_sec=1.0):
                self.get_logger().info(
                    f"Service {service_name} not available, waiting..."
                ) 
            # once while False: the loop exist

        self.get_logger().info("All services are available!")

        
    # -------------------------------
    # Utility helpers
    # -------------------------------

    # Wait for a ROS2 future to complete, with a timeout. means waiting for response to receive. return fut.
    def _wait_future(self, future, timeout_sec: float) -> bool: # -> bool, this means it will return True or False
        start = time.time() # Records the current time in seconds.
        while rclpy.ok() and not future.done():
            # While checks 1. (ROS 2 is shut down (rclpy.ok() becomes False), or
            #2. The Future has finished (future.done() becomes True))

            rclpy.spin_once(self, timeout_sec=0.1)
            if time.time() - start > timeout_sec:
                return False
        return future.done() #If the while loop ends without timeout, the Future must be done.Returns True
            #This tells the caller that the Future completed successfully within the timeout.


# trajectory execution services

    def call_execution_service(self, plans):
        """Call the trajectory execution service."""
        self.get_logger().info("Calling trajectory execution service...")

        request = ExecutePlans.Request() # .Request creating a empty object.
        request.plans = plans #plans -> joint trajectory, passing to request object

        request.move_group = "arm_torso" # this tells move_group which robot joint to move

        try:
            future = self.execute_client.call_async(request) # request send, waiting to get it done 
            if not self._wait_future(future, 180.0): # if execution take more than 30 sec it aborts # 30 to 60 
                self.get_logger().error("Execution service call timed out!")
                return None

            response = future.result() # rest handling
            if response.success: # response.success == True -> robot moved
                self.get_logger().info("Trajectory execution successful!")
                self.get_logger().info(f"Message: {response.message}") # response.message -->debug info from the controller.
                return response
            else:
                self.get_logger().error(
                    f"Trajectory execution failed: {response.message}"
                )
                return None

        except Exception as e:
            self.get_logger().error(f"Service call failed: {str(e)}")
            return None
        

    #This is the motion planning request.
    def call_planning_service(self, waypoints, description=""):
        """Call the motion planning service."""
        if description:
            self.get_logger().info(
                f"Calling motion planning service for {description}..."
            )
        else:
            self.get_logger().info("Calling motion planning service...")

        request = Plan.Request()# making a request with empty .Request, which create emty object.
        request.waypoints = waypoints # target pose 
        request.path_constraints = Constraints() # path constraint no constraint free motion
        request.send_partial = True # Accept partial plans
        request.use_start_state = False # Use current robot state
        request.start_state = RobotState() # Empty . as current state is used
        request.move_group = "arm_torso" # move_group -> which joints to plan for

        self.get_logger().info(f"Planning for {len(waypoints)} waypoints:")
        # the below for loop print Frame, and xyz position. Helpful for debugging frame mismatches.
        for i, wp in enumerate(waypoints):
            self.get_logger().info(
                f"  Waypoint {i+1} frame: {wp.pose.header.frame_id} "
                f"pos: [{wp.pose.pose.position.x:.3f}, {wp.pose.pose.position.y:.3f}, {wp.pose.pose.position.z:.3f}]"
            )

        try:
            future = self.plan_client.call_async(request) # calling planning service 
            if not self._wait_future(future, 180.0): # wait for 15 sec           
                self.get_logger().error("Planning service call timed out!")
                return None

            response = future.result()
            if response.success:
                self.get_logger().info(
                    f"Planning successful! Generated {len(response.plans)} trajectory segments"
                )
                self.get_logger().info(f"Message: {response.message}")
                return response
            else:
                self.get_logger().error(f"Planning failed: {response.message}")
                return None

        except Exception as e:
            self.get_logger().error(f"Service call failed: {str(e)}")
            return None



   # close partialy left, with this we can control how much gripper should close
    def send_partial_gripper_command(self, target_gap = 0.0250):
        """
        Closes only the left finger while the right finger remains at a fixed position.
        left_target: The closing position for the left finger.
        right_stay: The current 'open' position for the right finger (from your logs).
        """
        self.get_logger().info(f"Sending partial gripper command: {target_gap}")
        
        msg = JointTrajectory()
        # Both joints are included to move symmetrically
        msg.joint_names = ['gripper_left_finger_joint', 'gripper_right_finger_joint']
        
        point = JointTrajectoryPoint()
        # Both fingers move to the same target value
        point.positions = [target_gap, target_gap]
        point.time_from_start.sec = 1 
        
        msg.points.append(point)
        self.gripper_pub.publish(msg)
  
        return True
    
    # gripper using play_motion2 just full open and close of gripper

    def send_gripper_command(self, motion_name):
        """
        Sends a command to the play_motion2 action server.
        motion_name should be 'open' or 'close'.
        """
        self.get_logger().info(f"Sending gripper command: {motion_name}")
        
        # Wait for the action server to be available
        if not self.gripper_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("Gripper action server not available!")
            return False

        goal_msg = PlayMotion2.Goal()
        goal_msg.motion_name = motion_name # This becomes "open" or "close"
        goal_msg.skip_planning = False # Let it plan the finger movement

        # Send the goal
        send_goal_future = self.gripper_client.send_goal_async(goal_msg) # this command send the goal_msg to  ROS 2 network. 
        #The play_motion2 package then takes over, bypassing MoveIt's trajectory planner to move the gripper fingers directly.
        
        # Wait for the goal to be accepted
        if not self._wait_future(send_goal_future, 10.0):
            self.get_logger().error("Gripper goal request timed out!")
            return False

        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Gripper goal rejected!")
            return False

        # Wait for the result of the motion
        result_future = goal_handle.get_result_async()
        if not self._wait_future(result_future, 10.0):
            self.get_logger().error("Gripper motion execution timed out!")
            return False

        self.get_logger().info(f"Gripper {motion_name} complete.")
        return True



# attach object

    #attach
    def attach_objects(self, names) -> bool:
        """Attach by object names. Returns True on success."""
        if not names:
            self.get_logger().warn("attach_objects called with empty list.")
            return True
        try:
            req = AttachObj.Request()
            req.move_group = "arm_torso"
            req.object_names = names
            fut = self.attach_col_client.call_async(req)
            if not self._wait_future(fut, 25.0):
                self.get_logger().error("AttachObj timeout.")
                return False
            resp = fut.result()
            if hasattr(resp, "success") and resp.success is False:
                self.get_logger().error(
                    f"AttachObj failed: {getattr(resp, 'message', '')}"
                )
                return False
            self.get_logger().info(f"Attached objects: {names}")
            return True
        except Exception as e:
            self.get_logger().error(f"AttachObj failed: {e}")
            return False
        
    # detach 
    
    
    def detach_objects(self, names) -> bool:
        """Detach by object names. Returns True on success."""
        if not names:
            self.get_logger().warn("detach_objects called with empty list.")
            return True
        try:
            req = DettachObj.Request()
            req.move_group = "arm_torso"
            req.object_names = names
            fut = self.detach_col_client.call_async(req)
            if not self._wait_future(fut, 15.0):
                self.get_logger().error("DettachObj timeout.")
                return False
            resp = fut.result()
            if hasattr(resp, "success") and resp.success is False:
                self.get_logger().error(
                    f"DettachObj failed: {getattr(resp, 'message', '')}"
                )
                return False
            self.get_logger().info(f"Detached objects: {names}")
            return True
        except Exception as e:
            self.get_logger().error(f"DettachObj failed: {e}")
            return False

    # -------------------------------
    # Planning scene helpers (all return bool)
    # -------------------------------

    def attach_obj_to_marker(self) -> bool:
        """
        Detach all attached objects, then remove all world objects (empty list = all).
        Returns True on success; False on any failure.
        """
        self.get_logger().info("Clearing planning scene (detach all, remove all)...")

        # Get attached (converting attach collision objects to visualization marker)
        try:
            get_req = GetAttachedObjs.Request()
            get_future = self.get_attached_client.call_async(get_req)
            if not self._wait_future(get_future, 10.0):
                self.get_logger().error("GetAttachedObjs timeout.")
                return False

            attached = list(getattr(get_future.result(), "objs", []))
        except Exception as e:
            self.get_logger().error(f"GetAttachedObjs failed: {e}")
            return False


    # Remove all world objects
    def remove_collision_obj(self, object_names) -> bool:
        
        # custom update for object remove
        if object_names is None:
            object_names = []
        
        try:
            rreq = RemoveColObj.Request()
            rreq.object_names = object_names  # empty = remove all
            r_fut = self.remove_col_client.call_async(rreq)
            if not self._wait_future(r_fut, 15.0):
                self.get_logger().error("RemoveColObj timeout.")
                return False
            rresp = r_fut.result()
            if hasattr(rresp, "success") and rresp.success is False:
                self.get_logger().error(
                    f"RemoveColObj failed: {getattr(rresp, 'message', '')}"
                )
                return False
            
            # Log success
            if object_names:
                self.get_logger().info(f"✅ Removed {len(object_names)} collision objects: {object_names}")
            else:
                self.get_logger().info("✅ Removed ALL collision objects from planning scene")
            
            return True
            
            
        except Exception as e:
            self.get_logger().error(f"RemoveColObj failed: {e}")
            return False

    def table_2_collision_object(self):


        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ entered the table 2 function")
        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ ---------------------------")

        self.collision_done = False    

        if self.second_goal_reached == True:
            self.add_table_2_collision_object()
            #self.place_object()
            if self.collision_done:
                self.marker_table_2()
        return True




    def marker_table_2(self):
        # Creating Pregrasp and grasp position  
        

        pregrasp_obj_1_wp = Waypoint() # issue 29, created pregrasp object 

        #WayPoint(). A MoveIt-specific wrapper that contains a pose and possibly extra metadata (speed, constraints, etc.).
        pregrasp_obj_1_pose = PoseStamped()
        pregrasp_obj_1_pose.header.frame_id = "base_link"
        
        pregrasp_obj_1_pose.header.stamp = self.get_clock().now().to_msg() # Telling the transform tree: "This position is calculated based on the robot's current state right now.
        
        # Adjusting X (distance to robot). 
        # If robot is at X=0, subtracting 0.20m from object X makes it closer.
        pregrasp_obj_1_pose.pose.position.x = self.pos_TPCx - 0.20 
        pregrasp_obj_1_pose.pose.position.y = self.pos_TPCy
        pregrasp_obj_1_pose.pose.position.z = self.pos_TPCz + 0.10 # Lift slightly to avoid dragging
        

        pregrasp_obj_1_pose.pose.orientation.w = 1.0 # 
        pregrasp_obj_1_wp.pose = pregrasp_obj_1_pose


        # 2 Grasp Waypoint (5cm closer to robot)
        grasp_obj_1_wp = Waypoint()
        grasp_obj_1_pose = PoseStamped()
        grasp_obj_1_pose.header.frame_id = "base_link"
        grasp_obj_1_pose.header.stamp = self.get_clock().now().to_msg()
        
        grasp_obj_1_pose.pose.position.x = self.pos_TPCx - 0.02
        grasp_obj_1_pose.pose.position.y = self.pos_TPCy 
        grasp_obj_1_pose.pose.position.z = self.pos_TPCz + 0.10
        
        grasp_obj_1_pose.pose.orientation.w = 1.0
        grasp_obj_1_wp.pose = grasp_obj_1_pose
        
        


        # lift waypoint 
        # 3. Lift Waypoint 
        lift_obj_1_wp = Waypoint()
        lift_obj_1_pose = PoseStamped()
        lift_obj_1_pose.header.frame_id = "base_link"
        lift_obj_1_pose.pose.position.x = self.pos_TPCx - 0.02
        lift_obj_1_pose.pose.position.y = self.pos_TPCy
        lift_obj_1_pose.pose.position.z = self.pos_TPCz + 3*0.10 
        lift_obj_1_pose.pose.orientation.w = 1.0
        lift_obj_1_wp.pose = lift_obj_1_pose



######## lift 1, object 1###########

        move_marker_lift_1 = Marker()
        move_marker_lift_1.header.frame_id = "base_link"
        move_marker_lift_1.header.stamp = self.get_clock().now().to_msg()
        move_marker_lift_1 .ns = "lift_1_P"
        move_marker_lift_1.id = 40 # Unique ID
        move_marker_lift_1.type = Marker.ARROW
        move_marker_lift_1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker_lift_1.pose = lift_obj_1_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker_lift_1.scale.x = 0.3  # Length of arrow
        move_marker_lift_1.scale.y = 0.02 # Arrow head width
        move_marker_lift_1.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker_lift_1.color.r = 1.0 # Red for all obj1 
        move_marker_lift_1.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        self.pub.publish(move_marker_lift_1)


  

        # ###############grasp 1, for object 1#################


        move_marker_grasp_1 = Marker()
        move_marker_grasp_1.header.frame_id = "base_link"
        move_marker_grasp_1.header.stamp = self.get_clock().now().to_msg()
        move_marker_grasp_1 .ns = "grasp_1_P"
        move_marker_grasp_1.id = 41 # Unique ID
        move_marker_grasp_1.type = Marker.ARROW
        move_marker_grasp_1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker_grasp_1.pose = grasp_obj_1_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker_grasp_1.scale.x = 0.3  # Length of arrow
        move_marker_grasp_1.scale.y = 0.02 # Arrow head width
        move_marker_grasp_1.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker_grasp_1.color.r = 1.0 # Red for all obj1 
        move_marker_grasp_1.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        self.pub.publish(move_marker_grasp_1)






        #  Pregrasp 1 , for object 1
        move_marker_pre_1 = Marker()
        move_marker_pre_1.header.frame_id = "base_link"
        move_marker_pre_1.header.stamp = self.get_clock().now().to_msg()
        move_marker_pre_1 .ns = "pregrasp_1_P"
        move_marker_pre_1.id = 42 # Unique ID
        move_marker_pre_1.type = Marker.ARROW
        move_marker_pre_1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker_pre_1.pose = pregrasp_obj_1_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker_pre_1.scale.x = 0.3  # Length of arrow
        move_marker_pre_1.scale.y = 0.02 # Arrow head width
        move_marker_pre_1.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker_pre_1.color.r = 1.0 # Red for all obj1 
        move_marker_pre_1.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        self.pub.publish(move_marker_pre_1)

        self.get_logger().info("✅MARKER 2 function")
        self.get_logger().info("✅MARKER2 function")
        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ ---------------------------")

        return True


  
    def add_table_2_collision_object(self):
        """Add only Table 2 collision object at place location"""
        self.get_logger().info("Creating Table 2 collision object...")



        self.get_logger().info("✅ add t2 n")
        self.get_logger().info("✅  the table 2 function")

        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅ ---------------------------")
        self.get_logger().info("✅  the table 2 OBJECT ADDED function")
        self.get_logger().info("✅  the table 2 OBJECT ADDED function")
        self.get_logger().info("✅  the table 2 OBJECT ADDED function")


        

        
        # Check if we have Table Place tag detected
        if self.pos_TPCx == 0.0 and self.pos_TPCy == 0.0:
            self.get_logger().error("❌ Table Place tag (ID 10) not detected!")
            return False
        
        col_marker_table_2 = Marker()
        col_marker_table_2.header.frame_id = 'base_link'
        col_marker_table_2.header.stamp = self.get_clock().now().to_msg()
        col_marker_table_2.ns = "table_2"
        col_marker_table_2.id = 5
        col_marker_table_2.type = Marker.CUBE
        col_marker_table_2.action = Marker.ADD
        
        # Position (based on Table Place AprilTag)
        col_marker_table_2.pose.position.x = self.pos_TPCx + 0.11
        col_marker_table_2.pose.position.y = self.pos_TPCy - 0.03
        col_marker_table_2.pose.position.z = self.pos_TPCz - 0.21
        
        # Orientation
        col_marker_table_2.pose.orientation.x = 0 #self.rot_TPCx
        col_marker_table_2.pose.orientation.y = 0 #self.rot_TPCy
        col_marker_table_2.pose.orientation.z = 0 #self.rot_TPCz
        col_marker_table_2.pose.orientation.w = 1.0 #self.rot_TPCw
        
        # Size
        col_marker_table_2.scale.x = 0.40
        col_marker_table_2.scale.y = 0.40
        col_marker_table_2.scale.z = 0.40
        
        # Color
        col_marker_table_2.color.g = 1.0
        col_marker_table_2.color.a = 1.0
        
        # Add to planning scene
        success = self.add_coll_objects_from_markers([col_marker_table_2])
        
        if success:
            self.get_logger().info("✅ Table 2 collision object added!")
            self.collision_done = True
            #self.place_object()
        else:
            self.get_logger().error("❌ Failed to add Table 2 collision object!")
        
        return success






    def place_object(self):
        """Place object on Table 2"""
        self.get_logger().info("=" * 80)
        self.get_logger().info("STARTING PLACE SEQUENCE")
        self.get_logger().info("=" * 80)
        
        MAX_RETRIES = 10
        
        # ==========================================
        # PHASE 0: Move arm to safe transport position
        # ==========================================
        self.get_logger().info("Moving to transport position...")
        
        transport_wp = Waypoint()
        transport_pose = PoseStamped()
        transport_pose.header.frame_id = "base_link"
        transport_pose.header.stamp = self.get_clock().now().to_msg()
        
        # Safe position - arm pulled back and up
        transport_pose.pose.position.x = 0.5  # Pulled back from robot
        transport_pose.pose.position.y = 0.5
        transport_pose.pose.position.z = 0.8   # High up
        transport_pose.pose.orientation.w = 1.0
        
        transport_wp.pose = transport_pose
        
        transport_success = False
        
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"🎯 TRANSPORT Attempt {attempt}/{MAX_RETRIES}")
            
        
            plan_transport = self.call_planning_service([transport_wp])
            
            if plan_transport and plan_transport.success:
                self.call_execution_service(plan_transport.plans)
                self.get_logger().info("✅ Transport position reached!")
                transport_success = True
                break
            else:
                self.get_logger().warn(f"❌ Transport attempt {attempt} FAILED")
                time.sleep(0.5)
        
        if not transport_success:
            self.get_logger().error(f"❌ TRANSPORT FAILED after {MAX_RETRIES} attempts!")
            return False
      
        return True






























def main():
    rclpy.init()
    node = StartInspection()
    
    try:
        node.get_logger().info("Starting inspection sequence...")
        
        # ==========================================
        # PHASE 1: Wait for door to open and navigate
        # ==========================================
        node.get_logger().info("Waiting for door to open...")
        
        while rclpy.ok() and not node.goal_published:
            rclpy.spin_once(node, timeout_sec=0.1)
        
        node.get_logger().info("Navigation goal sent!")
        
        # ==========================================
        # PHASE 2: Monitor position until goal reached
        # ==========================================
        target_x = 0.2965392773707665
        target_y = 5.863092763400552
        tolerance = 0.40
        
        check_interval = 0.1  # Check every 0.5 seconds
        last_check_time = time.time()
        
        node.get_logger().info("Monitoring robot position...")
        
        while rclpy.ok() and not node.first_reached:
            # Spin to process callbacks (update current_pose)
            rclpy.spin_once(node, timeout_sec=0.1)
            
            current_time = time.time()
            
            # Check position every 0.5 seconds
            if current_time - last_check_time >= check_interval:
                last_check_time = current_time
                
                if node.current_pose is not None:
                    # Calculate distance to goal
                    dx = target_x - node.current_pose.position.x
                    dy = target_y - node.current_pose.position.y
                    error = math.sqrt(dx**2 + dy**2)
                    
                    node.get_logger().info(
                        f"Position check: error = {error:.3f}m "
                        f"(tolerance: {tolerance}m)"
                    )
                    
                    # Check if within tolerance
                    if error <= tolerance:
                        node.get_logger().info("✅ GOAL REACHED!")
                        node.first_reached = True
                        break
                else:
                    node.get_logger().warn("Waiting for pose update...")
        
        if not node.first_reached:
            node.get_logger().error("Navigation interrupted or failed")
            
        
        # ==========================================
        # PHASE 3: Wait for AprilTags
        # ==========================================
        node.get_logger().info("Goal reached! Searching for AprilTags...")
        
        tag_found = False

        while rclpy.ok() and not tag_found:
            rclpy.spin_once(node, timeout_sec=0.01)
            
            # Update tag poses
            transform = node.get_tag_pose()
            
            # Check if critical tags are detected
            if transform is not None and (node.pos_TCx != 0.0 and 
                node.pos_03Cx != 0.0 and 
                node.pos_02Cx != 0.0 and 
                node.pos_01Cx != 0.0):
                
                tag_found = True
                node.get_logger().info("✅ All required AprilTags found!")

        if tag_found:
            node.get_logger().info("Starting pick-and-place operations...")
            
            if node.second_goal_reached is  True:
                node.test_collision_object()
            
            # Keep spinning for ongoing operations
            #rclpy.spin(node)

   
        # ==================== PHASE 5: Monitor Goal 2 Navigation ====================
        node.get_logger().info("Monitoring navigation to Goal 2...")
        
        last_check_time = time.time()
        
        while rclpy.ok() and not node.second_goal_reached:
            rclpy.spin_once(node, timeout_sec=0.1)
            
            current_time = time.time()
            
            if current_time - last_check_time >= check_interval:
                last_check_time = current_time
                
                if node.current_pose is not None:
                    dx = node.GOAL2_X - node.current_pose.position.x
                    dy = node.GOAL2_Y - node.current_pose.position.y
                    error = math.sqrt(dx**2 + dy**2)
                    
                    node.get_logger().info(f"Goal 2 error = {error:.3f}m (tolerance: {tolerance}m)")
                    
                    if error <= tolerance:
                        node.get_logger().info("✅ GOAL 2 REACHED!")
                        node.second_goal_reached = True
                        break
        
        if not node.second_goal_reached:
            node.get_logger().error("Navigation to Goal 2 failed")
            


        
        # ==========================================
        # PHASE 3: Wait for AprilTagsadd_table_2_collision_object
        # ==========================================
        node.get_logger().info("Goal reached! Searching for AprilTags for table 2..")
        node.get_logger().info("Goal reached! Searching for AprilTags for table 2..")






        tag_found_2 = False

        while rclpy.ok() and not tag_found_2:
            rclpy.spin_once(node, timeout_sec=0.1)
            
            # Update tag poses
            transform = node.get_tag_pose()
            
            # Check if critical tags are detected
            if transform is not None and (node.pos_TPCx != 0.0):
                
                tag_found_2 = True
                node.get_logger().info("✅ All required AprilTags found!")

        if tag_found_2:
            node.get_logger().info("Starting adding collision ...")
            #node.table_2_collision_object()
            
            # Keep spinning for ongoing operations
        
        
        rclpy.spin(node)





        
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down...")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

import rclpy # 
import time 
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped, Twist
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient

from nav2_msgs.msg import SpeedLimit  # <--- use max speed 
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


        self.initial_pose_published = False
        self.movement_complete = False
        
        self.goal_published = False  # Flag to track if the goal has been published
        

        # if reached goal
        self.first_reached = False
        # Publish initial pose once on node startup


        # Marker publisher for move_marker1
        self.pub = self.create_publisher(Marker, 'move_markers', 10)

        

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

        # position , where the table place pose possible (FInal Position)

        self.GOAL2_X = 1.3525344141489204
        self.GOAL2_Y =   4.865876153895031
        self.GOAL2_Z = 0.0
        self.GOAL2_ORI_Z = -0.0254971623464817 
        self.GOAL2_ORI_W = 0.9996748945093485 

        # high value so check will not pass. This value later will be use as difference in current and target orientation in z and w
        self.rz = self.rw = 1.0

        # sending marker to ROS by creating publisher, to topic 'visulaization_marker'
        self.publisher = self.create_publisher(Marker, 'visualization_marker', 10)


        # TP means april tag from table, where object need to be place , for the movemnt or collsion object TPC. 

        self.pos_TPx = self.pos_TPy = self.pos_TPz = 0.0

        # for obj table 2 collision.
        
        self.pos_TPCx = self.pos_TPCy = self.pos_TPCz = 0.0

        # table place rotation
        self.rot_TPx = self.rot_TPy = self.rot_TPz = self.rot_TPw = 0.0
        # save rotation 
        self.rot_TPCx = self.rot_TPCy = self.rot_TPCz = self.rot_TPCw = 0.0

        # ---------- CONSTANT TAG IDS ----------

        self.TABLE_PLACE_ID = 10


        # ---------- LATCHED POSES ----------
        # bascially save pose when it available, so when something come in front of vision and we don't have real-time pose we can use this.
        self.latched_pose = {}      # tag_id -> (x, y, z)


        self.timer = self.create_timer(0.1, self.get_tag_pose) # calling function
 

        #setuped the listener  in __init__ method , so the node starts hearing the coordinate frames.

        self.tf_buffer = Buffer() # Buffer is a class constructor it has a data structure for the buffer.
        self.tf_listener = TransformListener(self.tf_buffer, self) # this subscribe to tf statics / transform topics.

         # add collision object
        self.add_col_client = self.create_client(AddColObj, "/moveit_wrapper/add_collision_object")

        # Planning-scene & attach/detach   
        self.plan_client = self.create_client(Plan, "/moveit_wrapper/plan")
        self.execute_client = self.create_client(ExecutePlans, "/moveit_wrapper/execute_plans")
        # attach object client
        self.attach_col_client = self.create_client(AttachObj, "/moveit_wrapper/attach_object")

        # create the action client
        self.gripper_client = ActionClient(self, PlayMotion2, 'play_motion2')


        # publisher for gripper partial close, this topic control how much need to close the gripper
        self.gripper_pub = self.create_publisher(JointTrajectory, '/gripper_controller/joint_trajectory', 10)

        # Flag to control when to latch poses, I save pose everytime, as sometime robot view get obstruct and apriltag pose lost
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
        
        self.get_logger().info("Publishing initial pose!")
        self.publish_initial_pose()
        
        # wait for services

        self.wait_for_services()




    # this function use /amcl_pose and determine current pose of robot
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
    

   # The function below drive the robot to its maximum speed, which is already in Nav2 preset, we try to use the maximum speed from that configuration     
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
            msg.pose.pose.position.x = 0.2965392773707665 
            msg.pose.pose.position.y = 5.863092763400552 
            msg.pose.pose.position.z = 0.0
            
            # Orientation (YOUR EXACT ORIENTATION)
            msg.pose.pose.orientation.x = 0.0
            msg.pose.pose.orientation.y = 0.0
            msg.pose.pose.orientation.z = 0.0037829493783980307
            msg.pose.pose.orientation.w = 0.9999928446214005

            # Publish initial pose
            self.pose_publisher.publish(msg)
            self.get_logger().info(f"Published initial pose: x={msg.pose.pose.position.x}, y={msg.pose.pose.position.y}")
            self.initial_pose_published = True  # Mark initial pose as published
            
            self.publish_goal()


            self.get_logger().info("Removing collision objects from Goal 1...")

            self.remove_collision_obj(["table_1", "obj_2", "obj_3"])
            self.delete_visualization_markers()


    def publish_goal(self):





        if self.goal_published:
            return # Double safety
    
        self.goal_published = True # Set it IMMEDIATELY

        #if not self.goal_published:
        goal = PoseStamped()
        goal.header.frame_id = 'map'
        goal.header.stamp = self.get_clock().now().to_msg()
        # Goal position coordinates
        goal.pose.position.x = 0.4727249727945442 # Target position (x)
        goal.pose.position.y = 4.481985477209297 # 5.4614 Target position (y)
        goal.pose.position.z = 0.0
        goal.pose.orientation.z = 0.186616765327272
        goal.pose.orientation.w = 0.9824327879803207


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

        self.get_logger().info("goal 1..")
        self.get_logger().info("goal 1..")
        self.get_logger().info("goal 1..")
        self.get_logger().info("goal 1..")
        self.get_logger().info("goal 1..")
        self.get_logger().info("goal 1..")
        self.get_logger().info("goal 1..")


        
        self.goal_published = True  # Set the flag to True after publishing the goal

        


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
            target_x = 0.4727249727945442
            target_y = 4.481985477209297
            target_z = 0.0

            target_rz = 0.186616765327272
            target_rw = 0.9824327879803207

            if self.current_pose is None:
                self.get_logger().warn("Current pose not available!")
                return

            # ===== CURRENT POSITION =====
            current_x = self.current_pose.position.x
            current_y = self.current_pose.position.y
            current_z = self.current_pose.position.z
            current_rz = self.current_pose.orientation.z
            current_rw = self.current_pose.orientation.w

            # ===== ERROR CALCULATION =====
            dx = target_x - current_x
            dy = target_y - current_y
            dz = target_z - current_z


            # error in rotation
            rz = target_rz - current_rz
            rw = target_rw - current_rw
            


            total_error = math.sqrt(dx**2 + dy**2 + dz**2)

            tolerance = 0.30  # Your custom tolerance (25cm) #0.25

            # printing log : Error in distance, tolerance, current and target pose.

            self.get_logger().info(
                f"\n"
                f"===== FINAL POSITION CHECK =====\n"
                f"Target:   ({target_x:.3f}, {target_y:.3f}, {target_z:.3f})\n"
                f"Current:  ({current_x:.3f}, {current_y:.3f}, {current_z:.3f})\n"
                f"current_rotation:  ({current_rz:.5f}, {current_rw:.5f})\n"
                 f"target_rotation:  ({target_rz:.5f}, {target_rw:.5f})\n"
                f"ΔX: {dx:.3f} m\n"
                f"ΔY: {dy:.3f} m\n"
                f"ΔZ: {dz:.3f} m\n"
                f"Δrz: {rz:.5f} m\n"
                f"Δrw: {rw:.5f} m\n"
                f"Total Error: {total_error:.3f} m\n"
                f"Tolerance: {tolerance:.3f} m\n"
                f"================================"
            )

            
            if total_error <= tolerance :
                self.get_logger().info("Reached goal within custom tolerance ✅")
                self.first_reached = True        
                
            else:
                self.get_logger().warn("Not within tolerance ❌ Performing correction...")


        except Exception as e:
            self.get_logger().error(f"Error in result callback: {e}")



# navigation check function 
    # This function check velocity of robot
    def velocity_callback(self, msg):
        """Track robot velocity"""
        self.current_velocity = msg  # updating velocity


    # goal 2  to table place
    def navigate_to_goal2(self):
        """Navigate to the place table (goal 2)"""
        self.get_logger().info("=" * 50)
        self.get_logger().info("NAVIGATING TO PLACE TABLE (GOAL 2)")
        self.get_logger().info("=" * 50)


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

            self.rz = abs(self.GOAL2_ORI_Z - self.current_pose.orientation.z) # taking absolute value
            self.rw = abs(self.GOAL2_ORI_W - self.current_pose.orientation.w) # taking absolute value


            error = math.sqrt(dx**2 + dy**2)
            
            tolerance = 0.40
            
           # Printing Logs: tolerance, current and target pose for position and orientation
            self.get_logger().info(
                f"\n"
                f"===== GOAL 2 POSITION CHECK =====\n"
                f"Target:   ({self.GOAL2_X:.3f}, {self.GOAL2_Y:.3f})\n"
                f"Current:  ({self.current_pose.position.x:.3f}, {self.current_pose.position.y:.3f})\n"
                f"Error: {error:.3f} m\n"
                f"Tolerance: {tolerance:.3f} m\n"
                f"Target_rotation:   ({self.GOAL2_ORI_Z:.3f}, {self.GOAL2_ORI_W:.3f})\n"
                f"Current_rotation:  ({self.current_pose.orientation.z:.3f}, {self.current_pose.orientation.w:.3f})\n"
                f"Error_rotation:    ({self.rz:.3f}, {self.rw:.3f}) m\n"
                f"================================"
            )
  
            
            if error <= tolerance :
                self.get_logger().info("Reached Goal 2 (Place Table)!")
                self.get_logger().info("robot stop!")  
                
            else:
                self.get_logger().warn(f" Not within tolerance (error: {error:.3f}m)")
                
        except Exception as e:
            self.get_logger().error(f"Error in Goal 2 result callback: {e}")



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




    def get_tag_pose(self):
        
        
        # Only latch poses when robot is completely stopped
        if not self.second_goal_reached and self.rz >0.26 and self.rw >0.026:
            return False
        
        # Tables + unknown object IDs
        
        tag_ids = [self.TABLE_PLACE_ID]

        any_found = False
        self.get_logger().info(f"Checking tags: {tag_ids}")  # <-- debug log

        for tag_id in tag_ids:
            self.update_tag_pose(tag_id) # this function save apriltag position
            any_found =True
        
        self.get_logger().info("No tags found in this cycle.")
        return any_found # tag found then true


    def update_tag_pose(self, tag_id):
        target_frame = f"tag36h11_{tag_id}"
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


            if not self.second_goal_reached and self.rz >0.26 and self.rw >0.026:
            # Robot is moving - don't latch these poses!
                self.get_logger().info(
                    f"Tag {tag_id} detected but robot is moving - skipping latch",
                    throttle_duration_sec=2.0  # Only log  2 seconds
                )
                return False

            # --- PICK TABLE ---
            if tag_id == self.TABLE_PLACE_ID:
                self.pos_TPx, self.pos_TPy, self.pos_TPz = px, py, pz   # live TF
                self.pos_TPCx, self.pos_TPCy, self.pos_TPCz = px, py, pz # **latched**
                 #  Save orientation too
                self.rot_TPx, self.rot_TPy, self.rot_TPz, self.rot_TPw = qx, qy, qz, qw

                self.rot_TPCx, self.rot_TPCy, self.rot_TPCz, self.rot_TPCw = qx, qy, qz, qw # LATCH 

                self.get_logger().info(f"{self.pos_TPCx:4f}, {self.pos_TPCy:4f},{self.pos_TPCz:4f}")

            else:
                self.get_logger().info("pose is not update.")
            return True

        except TransformException:
            self.get_logger().info(f"Tag {tag_id} not found")
          
            return False



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
    
    # gripper using play_motion2 just full open and close of gripper, it close full and open to full capacity

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


    def attach_obj_to_marker(self, object_names) -> bool:
        """
        Detach all attached objects, then remove all world objects (empty list = all).
        Returns True on success; False on any failure.
        """
        self.get_logger().warn("turning collision to marker  called.")
        self.get_logger().info("Clearing planning scene (detach all, remove all)...")


         # custom update for object remove
        if object_names is None:
            object_names = []
        

        # Get attached
        try:
            get_req = GetAttachedObjs.Request()
            get_future = self.get_attached_client.call_async(get_req)
            if not self._wait_future(get_future, 10.0):
                self.get_logger().error("GetAttachedObjs timeout.")
                self.dettach_done = True
                return False


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




    def test_collision_object(self):

        self.get_logger().info("sending Marker...")
        self.get_logger().info("collision Marker...")
        self.get_logger().info("move Marker...")
        self.get_logger().info("execute...")


        # call method to ad collision objects
        
        # collision objects  and self.rz<=0.25 and self.rw<=0.025
        if self.second_goal_reached:
            

            self.collision_objects()
            # all markers for position
            self.move_markers()
            self.place_object()
        else:
            self.get_logger().info("robot stopped functions..")


    def collision_objects(self):
        self.get_logger().info("Adding collision objects..")
        
        #MARKER 5, table_2 , placing table
        

        col_marker_table_2 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker

        col_marker_table_2.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker_table_2.header.stamp = self.get_clock().now().to_msg()
        col_marker_table_2.ns = "table_2" # 'ns: Namespace' it allows you to group markers together 
        col_marker_table_2.id = 8
        col_marker_table_2.type = Marker.CUBE# tells the shape of marker
        col_marker_table_2.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)
        # position
        col_marker_table_2.pose.position.x = self.pos_TPCx + 0.11
        col_marker_table_2.pose.position.y = self.pos_TPCy - 0.03
        col_marker_table_2.pose.position.z = self.pos_TPCz - 0.21
        #orientation- 
        col_marker_table_2.pose.orientation.w = 1.0
        # Size  or say scale real object : width, depth, height 0.04, 0.06, 0.15
        col_marker_table_2.scale.x = 0.36 #Marker diameter (m) 0.06
        col_marker_table_2.scale.y = 0.50 # diameter (m) 0.04
        col_marker_table_2.scale.z = 0.40 + 0.002 # heighlistt (m)
        # Giving Marker a color
        col_marker_table_2.color.g = 1.0
        col_marker_table_2.color.a = 1.0 # 1.0 = Opaque
        #create a list
        markers = [col_marker_table_2]
        

        self.add_coll_objects_from_markers(markers)
        

        self.get_logger().info(",.........................................................")  # <-- debug log
        self.get_logger().info(",.........................................................")
        self.get_logger().info(",.........................................................")
        self.get_logger().info("......COLLISION OBJECTS ADDED IN ENVIRONMENT..............")
        self.get_logger().info("......COLLISION OBJECTS ADDED IN ENVIRONMENT............")
        self.get_logger().info("......COLLISION OBJECTS ADDED IN ENVIRONMENT............")
        self.get_logger().info(",.........................................................")
        self.get_logger().info(",.........................................................")


    def move_markers(self):
        # Creating safezone and grasp position  

        # order 
        # lift -> grasp -> safezone  (opposite to pick object)

        # lift waypoint 
        # 1. Lift Waypoint 
        self.lift_obj_1_wp = Waypoint()
        lift_obj_1_pose = PoseStamped()
        lift_obj_1_pose.header.frame_id = "base_link"
        lift_obj_1_pose.pose.position.x = self.pos_TPCx - 0.02
        lift_obj_1_pose.pose.position.y = self.pos_TPCy + 0.15 - 0.04
        lift_obj_1_pose.pose.position.z = self.pos_TPCz + 3*0.10 
        lift_obj_1_pose.pose.orientation.w = 1.0
        self.lift_obj_1_wp.pose = lift_obj_1_pose





        # 2 Grasp Waypoint (5cm closer to robot)
        self.grasp_obj_1_wp = Waypoint()
        grasp_obj_1_pose = PoseStamped()
        grasp_obj_1_pose.header.frame_id = "base_link"
        grasp_obj_1_pose.header.stamp = self.get_clock().now().to_msg()
        
        grasp_obj_1_pose.pose.position.x = self.pos_TPCx - 0.02
        grasp_obj_1_pose.pose.position.y = self.pos_TPCy + 0.15 - 0.04
        grasp_obj_1_pose.pose.position.z = self.pos_TPCz + 0.10
        
        grasp_obj_1_pose.pose.orientation.w = 1.0
        self.grasp_obj_1_wp.pose = grasp_obj_1_pose
        
        
        # 3 safezone
        self.safezone_obj_1_wp = Waypoint() # using Waypoint to create sequence of operation 

        #WayPoint(). A MoveIt-specific wrapper that contains a pose and possibly extra metadata (speed, constraints, etc.).
        safezone_obj_1_pose = PoseStamped()
        safezone_obj_1_pose.header.frame_id = "base_link"
        
        safezone_obj_1_pose.header.stamp = self.get_clock().now().to_msg() # Telling the transform tree: "This position is calculated based on the robot's current state right now.
        
        # this is hardcoded it lead the robot to move safe zone 
        safezone_obj_1_pose.pose.position.x = 0.5 #
        safezone_obj_1_pose.pose.position.y = 0.5 #
        safezone_obj_1_pose.pose.position.z = 0.8 #
        

        safezone_obj_1_pose.pose.orientation.w = 1.0 # 
        self.safezone_obj_1_wp.pose = safezone_obj_1_pose






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






        #  safezone 1 , for object 1
        move_marker_pre_1 = Marker()
        move_marker_pre_1.header.frame_id = "base_link"
        move_marker_pre_1.header.stamp = self.get_clock().now().to_msg()
        move_marker_pre_1 .ns = "safezone_1_P"
        move_marker_pre_1.id = 42 # Unique ID
        move_marker_pre_1.type = Marker.ARROW
        move_marker_pre_1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker_pre_1.pose = safezone_obj_1_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker_pre_1.scale.x = 0.3  # Length of arrow
        move_marker_pre_1.scale.y = 0.02 # Arrow head width
        move_marker_pre_1.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker_pre_1.color.r = 1.0 # Red for all obj1 
        move_marker_pre_1.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        self.pub.publish(move_marker_pre_1)
 



        self.get_logger().info(",.........................................................")  # <-- debug log
        self.get_logger().info(",.........................................................")
        self.get_logger().info(",.........................................................")
        self.get_logger().info("............MARKER PUBLISHING SUCCESSFUL................")
        self.get_logger().info("............MARKER PUBLISHING SUCCESSFUL................")
        self.get_logger().info("............MARKER PUBLISHING SUCCESSFUL................")
        self.get_logger().info(",.........................................................")
        self.get_logger().info(",.........................................................")



    def place_object(self):
        """Place object on Table 2"""
        self.get_logger().info("=" * 80)
        self.get_logger().info("STARTING PLACE SEQUENCE")
        self.get_logger().info("=" * 80)
        
        MAX_RETRIES = 10
        


   # lift 

        # ==========================================
        # PHASE 3: LIFT
        # ==========================================
        lift_success = False
        
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"LIFT Attempt {attempt}/{MAX_RETRIES}")
            plan_lift = self.call_planning_service([self.lift_obj_1_wp])
            
            if plan_lift and plan_lift.success:
                self.call_execution_service(plan_lift.plans)
                self.get_logger().info("Lift reached!")
                lift_success = True
                break
            else:
                self.get_logger().error("LIFT FAILED!")
        
        if not lift_success:
            self.get_logger().error(" LIFT FAILED!")
            return False






   # grasp

        # ==========================================
        # PHASE 2: GRASP
        # ==========================================
        grasp_success = False
        
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"GRASP Attempt {attempt}/{MAX_RETRIES}")
            plan_grasp = self.call_planning_service([self.grasp_obj_1_wp])
            
            if plan_grasp and plan_grasp.success:
                self.call_execution_service(plan_grasp.plans)
            
                self.get_logger().info("Grasp reached")
                grasp_success = True
                

                self.dettach_done = False

                # grt attach obj
                self. detach_objects(["obj_1"])

                

                self.attach_obj_to_marker(["obj_1"])

                # open
                self.opened = False
                self.send_gripper_command("open")
                break

            else:
                self.get_logger().error("....GRASP FAILED!")
        
        if not grasp_success:
            self.get_logger().error("GRASP FAILED!")
            return False

      
        
        

        # ==========================================
        # PHASE 1: safezone
        # ==========================================
        # if self.opened == True:
        #     safezone_success = False
            
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"safezone Attempt {attempt}/{MAX_RETRIES}")
            plan_safezone = self.call_planning_service([self.safezone_obj_1_wp])
            
            if plan_safezone and plan_safezone.success:
                self.call_execution_service(plan_safezone.plans)
                self.get_logger().info("safezone reached!")
                safezone_success = True
                break
                
            else:
                self.get_logger().error(".....safezone FAILED!")
        
        if not safezone_success:
            self.get_logger().error("safezone FAILED!")
 





    #marker to collision object
    def add_coll_objects_from_markers(self, markers):
        """Transform given markers to collision objects. Returns True on success."""

        try:
            req = AddColObj.Request() #Creates a request message for the AddColObj service, and .Request() builds an empty request object
            req.objects = markers # Assigns our input 'markers' to the request field objects, objects exists in the service definition
            fut = self.add_col_client.call_async(req)# Sends the 'service request' without blocking, and Returns a Future object (fut). The service is now executing in the background
            if not self._wait_future(fut, 15.0):# calls a helper method _wait_future, wait for 15 sec for the service to respond, it Returns: True->response_arrived, False->timeout
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
        





def main():
    rclpy.init()
    node = StartInspection()

    try:
        # ========================================================
        # PHASE 1: Send Goal 1 and wait until first_reached = True
        # ========================================================
        

        node.get_logger().info("Sending Goal 1...")
        node.get_logger().info("Monitoring Goal 1...")
        goal1_tolerance = 0.35
        goal1_target_x = 0.4727249727945442
        goal1_target_y = 4.481985477209297

        while rclpy.ok() and not node.first_reached:
            rclpy.spin_once(node, timeout_sec=0.1)

            if node.current_pose is not None:
                dx = goal1_target_x - node.current_pose.position.x
                dy = goal1_target_y - node.current_pose.position.y
                error = math.sqrt(dx**2 + dy**2)
                node.get_logger().info(f"Goal 1 error = {error:.3f}m")
                if error <= goal1_tolerance:
                    node.first_reached = True
                    node.get_logger().info("✅ GOAL 1 CONFIRMED — Sending Goal 2...")
                    node.navigate_to_goal2()  # Called ONCE from main, the main goal position where the table place present
                    break



        # ========================================================
        # PHASE 2: Wait until second_goal_reached = True
        # ========================================================
        node.get_logger().info("Monitoring Goal 2...")
        goal2_tolerance = 0.45
        
        # Added a counter before the loop starts
        stable_stop_count = 0  

        while rclpy.ok() and not node.second_goal_reached:
            rclpy.spin_once(node, timeout_sec=0.1)

            if node.current_pose is not None: # checks whether pose value is present or not (/amcl_pose topic)
                dx = node.GOAL2_X - node.current_pose.position.x
                dy = node.GOAL2_Y - node.current_pose.position.y
                rz = abs(node.GOAL2_ORI_Z - node.current_pose.orientation.z) # differnece in orientation in z (absolute values)
                rw = abs(node.GOAL2_ORI_W - node.current_pose.orientation.w) # differnece in orientation in w (absolute values)
                error = math.sqrt(dx**2 + dy**2) # calculating error in sqrt 
                
                node.get_logger().info(f"Goal 2 error = {error:.3f}m", throttle_duration_sec=2.0)

                if error <= goal2_tolerance and rz<=0.25 and rw<=0.025:
                    node.get_logger().info("Within distance tolerance, checking orientation & speed...", throttle_duration_sec=2.0)
                    # throttle_duration, help in prevent console spam, it ignore any further request to print this exact line of code
                    
                    # speed of robot, as robot continuously move, and if collision object added it get displace
                    angular_z_speed = abs(node.current_velocity.angular.z) if node.current_velocity else 1.0
                    
                    # 2. Check if the speed is low
                    if angular_z_speed <= 0.160: # here checking speed
                        stable_stop_count += 1  # Increment the counter , will check speed for 5 times, as robot take jerk and again recalibrate hence speed increase
                        
                        # 3. Only declare success if it has been stopped for 5 consecutive ticks (0.5 seconds)
                        if stable_stop_count >= 5:
                            node.get_logger().info(" GOAL 2 REACHED AND COMPLETELY STABLE!")
                            node.second_goal_reached = True
                            time.sleep(0.1) # little sleep to stabilize the rotation
                            break
                        else:
                            node.get_logger().info(f"Speed is low, waiting to stabilize... ({stable_stop_count}/5)")
                    else:
                        # 4. CRITICAL: If the robot moves again, reset the counter to 0!
                        stable_stop_count = 0  
                        node.get_logger().info(f"At Goal 2, but still rotating... (Speed: {angular_z_speed:.3f})", throttle_duration_sec=1.0)
                else:
                    stable_stop_count = 0 # Reset counter if it drifts out of distance tolerance
                    node.get_logger().info("Going towards GOAL 2 !", throttle_duration_sec=2.0)              




        # check second goal the final goal reached or not

        if not node.second_goal_reached:
            node.get_logger().error("Navigation to Goal 2 failed — exiting")
            return

        # ========================================================
        # PHASE 3: Wait for AprilTag detection
        # ========================================================
        if node.second_goal_reached: 

            node.get_logger().info("Searching for AprilTags...")
            tag_found = False

            while rclpy.ok() and not tag_found:
                rclpy.spin_once(node, timeout_sec=0.1)


                if node.pos_TPx != 0.0 and node.second_goal_reached == True:
                    tag_found = True
                    node.get_logger().info("AprilTag found!")
                    node.get_logger().info("Spawning collision objects and starting place sequence...")
                    break
    

            if not tag_found:
                node.get_logger().error("AprilTag not found — exiting")
                return

      
            # ========================================================
            # PHASE 4: Spawn collision objects and run place sequence
            # ========================================================              
            if node.second_goal_reached and tag_found:
                node.get_logger().info("Conditions met. Spawning collision objects and starting place sequence...")
                node.test_collision_object()
            else:
                if not node.second_goal_reached:
                    node.get_logger().error("Cannot start place sequence: Goal 2 was never reached!")
                if not tag_found:
                    node.get_logger().error("Cannot start place sequence: AprilTag was not found!")
        
                return

    # Keep node alive so markers stay visible in RViz
        rclpy.spin(node)

    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()




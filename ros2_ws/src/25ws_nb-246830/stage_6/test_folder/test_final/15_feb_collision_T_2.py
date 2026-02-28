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


class MarkerVisualization(Node):
    def __init__(self):
        super().__init__("marker_visulaization")

        # sending marker to ROS by creating publisher, to topic 'visulaization_marker'
        self.publisher = self.create_publisher(Marker, 'visualization_marker', 10)

        # table place


        self.TABLE_PLACE_ID = 10
        # TP means april tag from table, where object need to be place , for the movemnt or collsion object TPC. 

        self.pos_TPx = self.pos_TPy = self.pos_TPz = 0.0

        # for obj2 collision.
        
        self.pos_TPCx = self.pos_TPCy = self.pos_TPCz = 0.0

        # table place rotation
        self.rot_TPx = self.rot_TPy = self.rot_TPz = self.rot_TPw = 0.0
        # save rotation 
        self.rot_TPCx = self.rot_TPCy = self.rot_TPCz = self.rot_TPCw = 0.0


        



        # ---------- LATCHED POSES ----------
        # bascially save pose when it available, so when something come in front of vision and we don't have real-time pose we can use this.
        self.latched_pose = {}      # tag_id -> (x, y, z)


        self.timer = self.create_timer(0.5, self.get_tag_pose) # calling function
 

        #setup listener  in __init__ method , so the node starts hearing the coordinate frames.

        self.tf_buffer = Buffer() # Buffer is a class constructor it has a data structure for the buffer.
        self.tf_listener = TransformListener(self.tf_buffer, self) # this subscribe to tf statics / transform topics.

        # add collision object
        self.add_col_client = self.create_client(AddColObj, "/moveit_wrapper/add_collision_object")

        # Marker publisher for move_marker1
        self.pub = self.create_publisher(Marker, 'move_markers', 10)

        ##########
        
        # Planning-scene & attach/detach   
        self.plan_client = self.create_client(Plan, "/moveit_wrapper/plan")
        self.execute_client = self.create_client(ExecutePlans, "/moveit_wrapper/execute_plans")
        self.get_attached_client = self.create_client(GetAttachedObjs, "/moveit_wrapper/get_attached_objects")



        # Marker publisher for move_marker1
        self.pub = self.create_publisher(Marker, 'move_markers', 10)


        # create the action client
        self.gripper_client = ActionClient(self, PlayMotion2, 'play_motion2')


        #self.send_gripper_command("open")

        # publisher for gripper partial close
        self.gripper_pub = self.create_publisher(JointTrajectory, '/gripper_controller/joint_trajectory', 10)
        
 
       
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
        
        














        self.wait_for_services()


    def test_collision_object(self):
        self.get_logger().info("sending Marker...")


        # call method to ad collision objects
        
        # collision objects
        self.collision_objects()
        # all markers for position
        self.move_markers()
        self.place_object()

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
        # Creating Pregrasp and grasp position  
        
        # for obj1 x: 0.5, y: 0.5, z:0.8 (this work best) for obj1 
        # for obj2   predefined grasp.
        # x:0.5, y: -0.5, z: 0.8 (for obj3 ok)

        self.pregrasp_obj_1_wp = Waypoint() # issue 29, created pregrasp object 

        #WayPoint(). A MoveIt-specific wrapper that contains a pose and possibly extra metadata (speed, constraints, etc.).
        pregrasp_obj_1_pose = PoseStamped()
        pregrasp_obj_1_pose.header.frame_id = "base_link"
        
        pregrasp_obj_1_pose.header.stamp = self.get_clock().now().to_msg() # Telling the transform tree: "This position is calculated based on the robot's current state right now.
        
        # Adjusting X (distance to robot). 

        a = 0.20
        # If robot is at X=0, subtracting 0.20m from object X makes it closer.
        pregrasp_obj_1_pose.pose.position.x = 0.5 #self.pos_TPCx - 0.15
        pregrasp_obj_1_pose.pose.position.y = 0.5 #-0.3 #self.pos_TPCy + 0.15 - 0.04
        pregrasp_obj_1_pose.pose.position.z = 0.8 #self.pos_TPCz + 0.10 #0.5 #self.pos_TPCz + 0.10 # Lift slightly to avoid dragging
        

        pregrasp_obj_1_pose.pose.orientation.w = 1.0 # 
        self.pregrasp_obj_1_wp.pose = pregrasp_obj_1_pose


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
        
        


        # lift waypoint 
        # 3. Lift Waypoint 
        self.lift_obj_1_wp = Waypoint()
        lift_obj_1_pose = PoseStamped()
        lift_obj_1_pose.header.frame_id = "base_link"
        lift_obj_1_pose.pose.position.x = self.pos_TPCx - 0.02
        lift_obj_1_pose.pose.position.y = self.pos_TPCy + 0.15 - 0.04
        lift_obj_1_pose.pose.position.z = self.pos_TPCz + 3*0.10 
        lift_obj_1_pose.pose.orientation.w = 1.0
        self.lift_obj_1_wp.pose = lift_obj_1_pose



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
 



###############################OBJECT 2 #############################################

        # --- Object 2: Pre-grasp ---
        self.pregrasp_obj_2_wp = Waypoint()
        pregrasp_obj_2_pose = PoseStamped()
        pregrasp_obj_2_pose.header.frame_id = "base_link"
        pregrasp_obj_2_pose.header.stamp = self.get_clock().now().to_msg()
        pregrasp_obj_2_pose.pose.position.x = self.pos_TPCx - 0.20 
        pregrasp_obj_2_pose.pose.position.y = self.pos_TPCy
        pregrasp_obj_2_pose.pose.position.z = self.pos_TPCz + 0.10 - 0.02
        pregrasp_obj_2_pose.pose.orientation.w = 1.0
        self.pregrasp_obj_2_wp.pose = pregrasp_obj_2_pose

        # --- Object 2: Grasp ---
        self.grasp_obj_2_wp = Waypoint()
        grasp_obj_2_pose = PoseStamped()
        grasp_obj_2_pose.header.frame_id = "base_link"
        grasp_obj_2_pose.pose.position.x = self.pos_TPCx - 0.02 - 0.03
        grasp_obj_2_pose.pose.position.y = self.pos_TPCy
        grasp_obj_2_pose.pose.position.z = self.pos_TPCz + 0.10 -0.02
        grasp_obj_2_pose.pose.orientation.w = 1.0
        self.grasp_obj_2_wp.pose = grasp_obj_2_pose

        # --- Object 2: Lift ---
        self.lift_obj_2_wp = Waypoint()
        lift_obj_2_pose = PoseStamped()
        lift_obj_2_pose.header.frame_id = "base_link"
        lift_obj_2_pose.pose.position.x = self.pos_TPCx - 0.02 - 0.03
        lift_obj_2_pose.pose.position.y = self.pos_TPCy
        lift_obj_2_pose.pose.position.z = self.pos_TPCz + 0.30
        lift_obj_2_pose.pose.orientation.w = 1.0
        self.lift_obj_2_wp.pose = lift_obj_2_pose

    

        ###object 2 marker #######


        ######## LIFT 2, object 2 ###########
        move_marker_lift_2 = Marker()
        move_marker_lift_2.header.frame_id = "base_link"
        move_marker_lift_2.header.stamp = self.get_clock().now().to_msg()
        move_marker_lift_2.ns = "lift_2_P"
        move_marker_lift_2.id = 50
        move_marker_lift_2.type = Marker.ARROW
        move_marker_lift_2.action = Marker.ADD
        move_marker_lift_2.pose = lift_obj_2_pose.pose
        move_marker_lift_2.scale.x, move_marker_lift_2.scale.y, move_marker_lift_2.scale.z = 0.3, 0.02, 0.02
        move_marker_lift_2.color.g, move_marker_lift_2.color.a = 1.0, 1.0
        self.pub.publish(move_marker_lift_2)


        # GRASP 2, for object 2 

        move_marker_grasp_2 = Marker()
        move_marker_grasp_2.header.frame_id = "base_link"
        move_marker_grasp_2.header.stamp = self.get_clock().now().to_msg()
        move_marker_grasp_2.ns = "grasp_2_P"
        move_marker_grasp_2.id = 51 # Unique ID for Obj 3
        move_marker_grasp_2.type = Marker.ARROW
        move_marker_grasp_2.action = Marker.ADD
        move_marker_grasp_2.pose = grasp_obj_2_pose.pose # Uses pos_03Cx variables
        move_marker_grasp_2.scale.x, move_marker_grasp_2.scale.y, move_marker_grasp_2.scale.z = 0.3, 0.02, 0.02
        move_marker_grasp_2.color.g, move_marker_grasp_2.color.a = 1.0, 1.0 # Blue
        self.pub.publish(move_marker_grasp_2)






        #  Pregrasp 2, for object 2 #################
        move_marker_pre_2 = Marker()
        move_marker_pre_2.header.frame_id = "base_link"
        move_marker_pre_2.header.stamp = self.get_clock().now().to_msg()
        move_marker_pre_2.ns = "pregrasp_2_P"
        move_marker_pre_2.id = 52 # Unique ID for Obj 2 Pre-grasp
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






######################### OBJECT 3 ###############################

        # --- Object 3: Pre-grasp ---
        self.pregrasp_obj_3_wp = Waypoint()
        pregrasp_obj_3_pose = PoseStamped()
        pregrasp_obj_3_pose.header.frame_id = "base_link"
        pregrasp_obj_3_pose.header.stamp = self.get_clock().now().to_msg()
        pregrasp_obj_3_pose.pose.position.x =  0.5  ##self.pos_TPCx - 0.20
        pregrasp_obj_3_pose.pose.position.y = -0.5 #self.pos_TPCy - 0.15 - 0.005
        pregrasp_obj_3_pose.pose.position.z =  0.8 #self.pos_TPCz + 0.10
        pregrasp_obj_3_pose.pose.orientation.w = 1.0
        self.pregrasp_obj_3_wp.pose = pregrasp_obj_3_pose

        # --- Object 3: Grasp ---
        self.grasp_obj_3_wp = Waypoint()
        grasp_obj_3_pose = PoseStamped()
        grasp_obj_3_pose.header.frame_id = "base_link"
        grasp_obj_3_pose.pose.position.x = self.pos_TPCx - 0.03
        grasp_obj_3_pose.pose.position.y = self.pos_TPCy - 0.15 - 0.005
        grasp_obj_3_pose.pose.position.z = self.pos_TPCz + 0.10
        grasp_obj_3_pose.pose.orientation.w = 1.0
        self.grasp_obj_3_wp.pose = grasp_obj_3_pose

        # --- Object 3: Lift ---
        self.lift_obj_3_wp = Waypoint()
        lift_obj_3_pose = PoseStamped()
        lift_obj_3_pose.header.frame_id = "base_link"
        lift_obj_3_pose.pose.position.x = self.pos_TPCx 
        lift_obj_3_pose.pose.position.y = self.pos_TPCy - 0.15 - 0.005
        lift_obj_3_pose.pose.position.z = self.pos_TPCz + 0.30
        lift_obj_3_pose.pose.orientation.w = 1.0
        self.lift_obj_3_wp.pose = lift_obj_3_pose



      ############### object 3 marker ################




        # GRASP 3, for object 3 


        ######## LIFT 3, object 3 ###########
        move_marker_lift_3 = Marker()
        move_marker_lift_3.header.frame_id = "base_link"
        move_marker_lift_3.header.stamp = self.get_clock().now().to_msg()
        move_marker_lift_3.ns = "lift_3_P"
        move_marker_lift_3.id = 60
        move_marker_lift_3.type = Marker.ARROW
        move_marker_lift_3.action = Marker.ADD
        move_marker_lift_3.pose = lift_obj_3_pose.pose
        move_marker_lift_3.scale.x, move_marker_lift_3.scale.y, move_marker_lift_3.scale.z = 0.3, 0.02, 0.02
        move_marker_lift_3.color.b, move_marker_lift_3.color.a = 1.0, 1.0
        self.pub.publish(move_marker_lift_3)





        move_marker_grasp_3 = Marker()
        move_marker_grasp_3.header.frame_id = "base_link"
        move_marker_grasp_3.header.stamp = self.get_clock().now().to_msg()
        move_marker_grasp_3.ns = "grasp_3_P"
        move_marker_grasp_3.id = 61 # Unique ID for Obj 3
        move_marker_grasp_3.type = Marker.ARROW
        move_marker_grasp_3.action = Marker.ADD
        move_marker_grasp_3.pose = grasp_obj_3_pose.pose # Uses pos_03Cx variables
        move_marker_grasp_3.scale.x, move_marker_grasp_3.scale.y, move_marker_grasp_3.scale.z = 0.3, 0.02, 0.02
        move_marker_grasp_3.color.b, move_marker_grasp_3.color.a = 1.0, 1.0 # Blue
        self.pub.publish(move_marker_grasp_3)



        
        # Pregrasp 3, for object 3 

        move_marker_pre_3 = Marker()
        move_marker_pre_3.header.frame_id = "base_link"
        move_marker_pre_3.header.stamp = self.get_clock().now().to_msg()
        move_marker_pre_3.ns = "pregrasp_3_P"
        move_marker_pre_3.id = 62 # Unique ID for Obj 3 Pre-grasp
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
        
        # # ==========================================
        # # PHASE 0: Move arm to safe transport position
        # # ==========================================
        # self.get_logger().info("Moving to transport position...")
        
        # transport_wp = Waypoint()
        # transport_pose = PoseStamped()
        # transport_pose.header.frame_id = "base_link"
        # transport_pose.header.stamp = self.get_clock().now().to_msg()
        
        # # Safe position - arm pulled back and up
        # transport_pose.pose.position.x = 0.5  # Pulled back from robot
        # transport_pose.pose.position.y = 0.5
        # transport_pose.pose.position.z = 0.8   # High up
        # transport_pose.pose.orientation.w = 1.0
        
        # transport_wp.pose = transport_pose
        
        # transport_success = False


  # transport

        # for attempt in range(1, MAX_RETRIES + 1):
        #     self.get_logger().info(f"🎯 TRANSPORT Attempt {attempt}/{MAX_RETRIES}")
            
        
        #     plan_transport = self.call_planning_service([transport_wp])
            
        #     if plan_transport and plan_transport.success:
        #         self.call_execution_service(plan_transport.plans)
        #         self.get_logger().info("✅ Transport position reached!")
        #         transport_success = True
        #         break
        #     else:
        #         self.get_logger().warn(f"❌ Transport attempt {attempt} FAILED")
        #         time.sleep(0.5)
        
        # if not transport_success:
        #     self.get_logger().error(f"❌ TRANSPORT FAILED after {MAX_RETRIES} attempts!")
        #     return False







   # lift 

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
                self.get_logger().error("LIFT FAILED!")
        
        if not lift_success:
            self.get_logger().error("❌ LIFT FAILED!")
            return False






   # grasp

        # ==========================================
        # PHASE 2: GRASP
        # ==========================================
        grasp_success = False
        
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"🎯 GRASP Attempt {attempt}/{MAX_RETRIES}")
            plan_grasp = self.call_planning_service([self.grasp_obj_1_wp])
            
            if plan_grasp and plan_grasp.success:
                self.call_execution_service(plan_grasp.plans)
            
                self.get_logger().info("✅ Grasp reached")
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
            self.get_logger().error("❌ GRASP FAILED!")
            return False



   # pregrasp     
        
        




        # ==========================================
        # PHASE 1: PREGRASP
        # ==========================================
        # if self.opened == True:
        #     pregrasp_success = False
            
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(f"🎯 PREGRASP Attempt {attempt}/{MAX_RETRIES}")
            plan_pregrasp = self.call_planning_service([self.pregrasp_obj_1_wp])
            
            if plan_pregrasp and plan_pregrasp.success:
                self.call_execution_service(plan_pregrasp.plans)
                self.get_logger().info("✅ Pregrasp reached!")
                pregrasp_success = True
                break
                
            else:
                self.get_logger().error(".....PREGRASP FAILED!")
        
        if not pregrasp_success:
            self.get_logger().error("❌ PREGRASP FAILED!")
        # else:
        #     self.get_logger().error("self.openedc is false  PREGRASP FAILED!")
            



        #============
        # ALL PHASES COMPLETE - CLEANUP AND NAVIGATE
        # ==========================================
        self.get_logger().info("=" * 80)
        self.get_logger().info("✅✅✅ place ✅✅✅")
        self.get_logger().info("=" * 80)
        
        # Remove collision objects
        #self.get_logger().info("detach...")
        #self.remove_collision_obj(["table_1", "obj_2", "obj_3"])
        
        # Remove visualization markers
        #self.delete_visualization_markers()
        
        # Start navigation to Goal 2
        #self.get_logger().info("Starting navigation to Goal 2...")
        #self.navigate_to_goal2()
        
        # ✅✅✅ CRITICAL: RETURN TRUE IMMEDIATELY! ✅✅✅
        # This exits the function so no more Goal 1 waypoints are used!



















####################DETACH OBJECTS ###################
    
    def detach_objects(self, names) -> bool:
        """Detach by object names. Returns True on success."""
        self.get_logger().warn("detach_objects called.")
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




####### GRIPPER ################################

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
        self.opened = True
        return True

####### EXECUTINON AND PLANNING 

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






#############################












    def get_tag_pose(self):
        # Tables + unknown object IDs
        tag_ids = [self.TABLE_PLACE_ID]
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



            # --- PLACE TABLE ---
            if  tag_id == self.TABLE_PLACE_ID:
                self.pos_TPx, self.pos_TPy, self.pos_TPz = px, py, pz
                self.pos_TPCx, self.pos_TPCy, self.pos_TPCz = px, py, pz # **latched**


                                # ROTATION 
                self.rot_TPx, self.rot_TPy, self.rot_TPz, self.rot_TPw = qx, qy, qz, qw

                self.rot_TPCx, self.rot_TPCy, self.rot_TPCz, self.rot_TPCw = qx, qy, qz, qw # LATCH 

                self.get_logger().info("place table pose orientation found")
                self.get_logger().info(f"Tag {tag_id} found at pose ({px}, {py}, {pz})")
                self.get_logger().info(f"Tag {tag_id} found at orientation({qx}, {qy}, {qz},{qw})")



        except TransformException:
            self.get_logger().info(f"Tag {tag_id} not found")

            return False






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
    node = MarkerVisualization()
    # pattern is event waiting loop using spin_once
    try:
        node.get_logger().info("search for tags")
        tag_found = False

        # WAIT until tags are found

        while rclpy.ok() and not tag_found:
            # 1. Update transforms (this updates pos_Tx, pos_TPx, etc.)
            rclpy.spin_once(node, timeout_sec=0.1)
            transform = node.get_tag_pose()  

            # wait for tag detection BEFORE creating collision objects
            # check if critical tags are detected (not zero)
            if transform is not None and (node.pos_TPx != 0.0):
                tag_found = True
                node.get_logger().info("Pick object tags found")
                

        if tag_found:
            node.get_logger().info("Tag located! Spawning collision object...")
            node.test_collision_object() # it runs immidate, when call apriltag hasn't populated values yet
            return True
            
        #Keep spinning so the marker stays alive in Rviz
        rclpy.spin(node)
            
            
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()


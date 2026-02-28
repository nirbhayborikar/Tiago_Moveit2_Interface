# All collision object and valid markers. Red (marker) for obj1 , blue(marker) for obj2 , green(marker) for obj 2

 
import rclpy # ros client library for python, 
from rclpy.node import Node # importing node, it give acess to class node
from visualization_msgs.msg import Marker # visualization a ROS package,  msg is a submodule where message definitions are stored, marker a message type (reperesent visula object)

# Library for using tf2
from tf2_ros import TransformException # tf2_ros, a library from ROS for handling coordinate frame transformation, while TransformException is an error type (when lookup fail: frame not exist)
from tf2_ros.buffer import Buffer # buffer, a container to store transforms, here importing 'Buffer' class
from tf2_ros.transform_listener import TransformListener # TransformListener, a component that listens transforms from /tf topics, and send to buffer.
from moveit_wrapper_interfaces.srv import (AddColObj) #
import time # access time 

# for a PoseStamped object
from geometry_msgs.msg import PoseStamped # .msg is a directory contain definition, posestamped it represent robot, point , a 3d point in space
from moveit_wrapper_interfaces.msg import Waypoint # waypoint equence of position


class MarkerVisualization(Node):
    def __init__(self):
        super().__init__("marker_visulaization")

        # sending marker to ROS by creating publisher, to topic 'visulaization_marker'
        self.publisher = self.create_publisher(Marker, 'visualization_marker', 10)

       
        # initiailze tag pose , so when not found program should not crash

        # Tx means april tag from table 1, for the movemnt TC variable will be taken 

        self.pos_Tx = self.pos_Ty = self.pos_Tz = 0.0

        # for table 1, collsion object publishing
        self.pos_TCx = self.pos_TCy = self.pos_TCz = 0.0


        # 01x means april tag from obj 1, for the movemnt or collsion object 01C. 

        self.pos_01x = self.pos_01y = self.pos_01z = 0.0

        # for obj1 collision.

        self.pos_01Cx = self.pos_01Cy = self.pos_01Cz = 0.0

        # 02x means april tag from obj 2, for the movemnt or collsion object 02C. 

        self.pos_02x = self.pos_02y = self.pos_02z = 0.0

        # for obj2 collision.
        
        self.pos_02Cx = self.pos_02Cy = self.pos_02Cz = 0.0
        
        # 03x means april tag from obj 3, for the movemnt or collsion object 03C. 

        self.pos_03x = self.pos_03y = self.pos_03z = 0.0

        # for obj3 collision.
        
        self.pos_03Cx = self.pos_03Cy = self.pos_03Cz = 0.0

        # TP means april tag from table, where object need to be place , for the movemnt or collsion object TPC. 

        self.pos_TPx = self.pos_TPy = self.pos_TPz = 0.0

        # for obj2 collision.
        
        self.pos_TPCx = self.pos_TPCy = self.pos_TPCz = 0.0



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

        # Marker publisher for move_marker1
        self.pub = self.create_publisher(Marker, 'move_markers', 10)

        self.wait_for_services()


    def test_collision_object(self):
        self.get_logger().info("sending Marker...")
        
        # collision objects
        self.collision_objects()
        # all markers for position
        self.move_markers()

    def collision_objects(self):
        self.get_logger().info("Adding collision objects..")
       
        # 1. marker a object is created for the table 
        
        col_marker_table_1 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker
        col_marker_table_1.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker_table_1.header.stamp = self.get_clock().now().to_msg()
        col_marker_table_1.ns = "Table" # 'ns: Namespace' it allows you to group markers together 
        col_marker_table_1.id = 1
        col_marker_table_1.type = Marker.CYLINDER # tells the shape of marker
        col_marker_table_1.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)
        # position
        col_marker_table_1.pose.position.x = self.pos_TCx + 0.243 # 0.185
        col_marker_table_1.pose.position.y = self.pos_TCy - 0.0180
        col_marker_table_1.pose.position.z = self.pos_TCz - 0.048 #0.030
        #orientation- 
        col_marker_table_1.pose.orientation.w = 1.0
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
        # position
        col_marker_obj_1.pose.position.x = self.pos_01Cx + 0.075
        col_marker_obj_1.pose.position.y = self.pos_01Cy - 0.01
        col_marker_obj_1.pose.position.z = self.pos_01Cz + 0.090 # 0.075
        #orientation- 
        col_marker_obj_1.pose.orientation.w = 1.0
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
        col_marker_obj_2.pose.position.x = self.pos_02Cx + 0.075
        col_marker_obj_2.pose.position.y = self.pos_02Cy - 0.01
        col_marker_obj_2.pose.position.z = self.pos_02Cz + 0.090
        #orientation- 
        col_marker_obj_2.pose.orientation.w = 1.0
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
        col_marker_obj_3.pose.position.x = self.pos_03Cx + 0.075
        col_marker_obj_3.pose.position.y = self.pos_03Cy - 0.01
        col_marker_obj_3.pose.position.z = self.pos_03Cz + 0.090
        #orientation- 
        col_marker_obj_3.pose.orientation.w = 1.0
        # Size  or say scale real object : width, depth, height 0.04, 0.06, 0.15
        col_marker_obj_3.scale.x = 0.06 #Marker diameter (m) 0.06
        col_marker_obj_3.scale.y = 0.03 # diameter (m) 0.04
        col_marker_obj_3.scale.z = 0.15 # height (m)
        # Giving Marker a colorlist
        col_marker_obj_3.color.g = 1.0
        col_marker_obj_3.color.a = 1.0 # 1.0 = Opaque
        
        #MARKER 5, table_2 , placing table
        

        col_marker_table_2 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker

        col_marker_table_2.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker_table_2.header.stamp = self.get_clock().now().to_msg()
        col_marker_table_2.ns = "table_2" # 'ns: Namespace' it allows you to group markers together 
        col_marker_table_2.id = 5
        col_marker_table_2.type = Marker.CUBE# tells the shape of marker
        col_marker_table_2.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)
        # position
        col_marker_table_2.pose.position.x = self.pos_TPCx + 0.11
        col_marker_table_2.pose.position.y = self.pos_TPCy - 0.03
        col_marker_table_2.pose.position.z = self.pos_TPCz - 0.21
        #orientation- 
        col_marker_table_2.pose.orientation.w = 1.0
        # Size  or say scale real object : width, depth, height 0.04, 0.06, 0.15
        col_marker_table_2.scale.x = 0.40 #Marker diameter (m) 0.06
        col_marker_table_2.scale.y = 0.40 # diameter (m) 0.04
        col_marker_table_2.scale.z = 0.40 # heighlistt (m)
        # Giving Marker a color
        col_marker_table_2.color.g = 1.0
        col_marker_table_2.color.a = 1.0 # 1.0 = Opaque
        #create a list
        markers = [col_marker_table_1, col_marker_obj_1, col_marker_obj_2, col_marker_obj_3]
        

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
        

        pregrasp_obj_1_wp = Waypoint() # issue 29, created pregrasp object 

        #WayPoint(). A MoveIt-specific wrapper that contains a pose and possibly extra metadata (speed, constraints, etc.).
        pregrasp_obj_1_pose = PoseStamped()
        pregrasp_obj_1_pose.header.frame_id = "base_link"
        
        pregrasp_obj_1_pose.header.stamp = self.get_clock().now().to_msg() # Telling the transform tree: "This position is calculated based on the robot's current state right now.
        
        # Adjusting X (distance to robot). 
        # If robot is at X=0, subtracting 0.20m from object X makes it closer.
        pregrasp_obj_1_pose.pose.position.x = self.pos_01Cx - 0.20 
        pregrasp_obj_1_pose.pose.position.y = self.pos_01Cy
        pregrasp_obj_1_pose.pose.position.z = self.pos_01Cz + 0.10 # Lift slightly to avoid dragging
        

        pregrasp_obj_1_pose.pose.orientation.w = 1.0 # 
        pregrasp_obj_1_wp.pose = pregrasp_obj_1_pose


        # 2 Grasp Waypoint (5cm closer to robot)
        grasp_obj_1_wp = Waypoint()
        grasp_obj_1_pose = PoseStamped()
        grasp_obj_1_pose.header.frame_id = "base_link"
        grasp_obj_1_pose.header.stamp = self.get_clock().now().to_msg()
        
        grasp_obj_1_pose.pose.position.x = self.pos_01Cx - 0.02
        grasp_obj_1_pose.pose.position.y = self.pos_01Cy 
        grasp_obj_1_pose.pose.position.z = self.pos_01Cz + 0.10
        
        grasp_obj_1_pose.pose.orientation.w = 1.0
        grasp_obj_1_wp.pose = grasp_obj_1_pose
        
        


        # lift waypoint 
        # 3. Lift Waypoint 
        lift_obj_1_wp = Waypoint()
        lift_obj_1_pose = PoseStamped()
        lift_obj_1_pose.header.frame_id = "base_link"
        lift_obj_1_pose.pose.position.x = self.pos_01Cx - 0.02
        lift_obj_1_pose.pose.position.y = self.pos_01Cy
        lift_obj_1_pose.pose.position.z = self.pos_01Cz + 3*0.10 
        lift_obj_1_pose.pose.orientation.w = 1.0
        lift_obj_1_wp.pose = lift_obj_1_pose


        # holdback 1, for object 1
        holdback_obj_1_wp = Waypoint()
        holdback_obj_1_pose = PoseStamped()
        holdback_obj_1_pose.header.frame_id = "base_link"
        holdback_obj_1_pose.pose.position.x = self.pos_01Cx - 0.20
        holdback_obj_1_pose.pose.position.y = self.pos_01Cy
        holdback_obj_1_pose.pose.position.z = self.pos_01Cz + 3*0.10 # 
        holdback_obj_1_pose.pose.orientation.w = 1.0
        holdback_obj_1_wp.pose = holdback_obj_1_pose



     

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
        pregrasp_obj_2_wp = Waypoint()
        pregrasp_obj_2_pose = PoseStamped()
        pregrasp_obj_2_pose.header.frame_id = "base_link"
        pregrasp_obj_2_pose.header.stamp = self.get_clock().now().to_msg()
        pregrasp_obj_2_pose.pose.position.x = self.pos_02Cx - 0.20 
        pregrasp_obj_2_pose.pose.position.y = self.pos_02Cy
        pregrasp_obj_2_pose.pose.position.z = self.pos_02Cz + 0.10
        pregrasp_obj_2_pose.pose.orientation.w = 1.0
        pregrasp_obj_2_wp.pose = pregrasp_obj_2_pose

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

        self.get_logger().info(",.........................................................")  # <-- debug log
        self.get_logger().info(",.........................................................")
        self.get_logger().info(",.........................................................")
        self.get_logger().info("............MARKER PUBLISHING SUCCESSFUL................")
        self.get_logger().info("............MARKER PUBLISHING SUCCESSFUL................")
        self.get_logger().info("............MARKER PUBLISHING SUCCESSFUL................")
        self.get_logger().info(",.........................................................")
        self.get_logger().info(",.........................................................")

    def get_tag_pose(self):
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
        target_frame = f"tag36h11_{tag_id}"
        source_frame = "base_link"

        try:
            trans = self.tf_buffer.lookup_transform(source_frame, target_frame, rclpy.time.Time())
            px = trans.transform.translation.x
            py = trans.transform.translation.y
            pz = trans.transform.translation.z

            # --- PICK TABLE ---
            if tag_id == self.TABLE_PICK_ID:
                self.pos_Tx, self.pos_Ty, self.pos_Tz = px, py, pz   # live TF
                self.pos_TCx, self.pos_TCy, self.pos_TCz = px, py, pz # **latched**

            # --- PLACE TABLE ---
            elif tag_id == self.TABLE_PLACE_ID:
                self.pos_TPx, self.pos_TPy, self.pos_TPz = px, py, pz
                self.pos_TPCx, self.pos_TPCy, self.pos_TPCz = px, py, pz # **latched**

            # --- OBJECTS ---
            else:
                self.update_object_pose(tag_id, px, py, pz)              # live TF
             #self.update_object_cached_pose(tag_id, px, py, pz)       # **latched**
            
            # print values 
            self.get_logger().info(f"Tag {tag_id} found at ({px:.2f}, {py:.2f}, {pz:.2f})")

            return True

        except TransformException:
            self.get_logger().info(f"Tag {tag_id} not found")
            
            if tag_id in self.latched_pose:
                px, py, pz = self.latched_pose[tag_id]
                self.update_object_pose(tag_id, px, py, pz)
            return False


#### ASSIGNING SLOT IF IDS CHANGED 
    def assign_slot(self, tag_id):
        """
        Assigns a tag to a free object slot (1,2,3)
        """
        # CHECK: Have we seen this ID before?
        # If the tag_id is already in our dictionary, just return its existing slot number.
        if tag_id in self.object_slots:
            return self.object_slots[tag_id]

        # CAPACITY GUARD: Is the "parking lot" full?
        # If we already have 3 objects (max_objects), don't assign a slot to any new IDs.
        if len(self.object_slots) >= self.max_objects:
            return None  # This ignores the 4th, 5th, etc., objects found.

        # ASSIGNMENT: Give the new ID the next available number.
        # If the dictionary has 0 items, slot = 1. If it has 1 item, slot = 2.
        slot = len(self.object_slots) + 1
        
        # SAVE: Store the relationship (e.g., {tag_id_101: 1})
        self.object_slots[tag_id] = slot
        
        return slot

# UPDATE OBJECT POSE ONCE , AVAILABLE

    def update_object_pose(self, tag_id, px, py, pz):
        slot = self.assign_slot(tag_id)
        if slot is None:
            return
        
            # Update latched pose
        self.latched_pose[tag_id] = (px, py, pz)

        if slot == 1:
            self.pos_01x, self.pos_01y, self.pos_01z = px, py, pz
            self.pos_01Cx, self.pos_01Cy, self.pos_01Cz = px, py, pz
        elif slot == 2:
            self.pos_02x, self.pos_02y, self.pos_02z = px, py, pz
            self.pos_02Cx, self.pos_02Cy, self.pos_02Cz = px, py, pz

        elif slot == 3:
            self.pos_03x, self.pos_03y, self.pos_03z = px, py, pz
            self.pos_03Cx, self.pos_03Cy, self.pos_03Cz = px, py, pz





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
            (self.add_col_client, "/moveit_wrapper/add_collision_object")        
        ] # with the list, it allows the code to wait for multiple services in a loop.

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
            rclpy.spin_once(node, timeout_sec=0.4)
            transform = node.get_tag_pose()  

            # wait for tag detection BEFORE creating collision objects
            # check if critical tags are detected (not zero)
            if transform is not None and (node.pos_Tx != 0.0 and node.pos_03x != 0.0 and node.pos_02x != 0.0 and node.pos_01Cx != 0.0):
                tag_found = True
                node.get_logger().info("Pick object tags found")

        if tag_found:
            node.get_logger().info("Tag located! Spawning collision object...")
            node.test_collision_object() # it runs immidate, when call apriltag hasn't populated values yet
            
        #Keep spinning so the marker stays alive in Rviz
        rclpy.spin(node)
            
            
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()

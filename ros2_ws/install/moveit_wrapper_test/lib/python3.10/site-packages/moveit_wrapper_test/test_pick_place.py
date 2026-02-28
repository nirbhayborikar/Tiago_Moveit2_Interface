# Testing marker visulaization 
import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
# added library for using tf2
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
from moveit_wrapper_interfaces.srv import (AddColObj, ExecutePlans, Plan, AttachObj, DettachObj, GetAttachedObjs)
import time
#import sys
# for a PoseStamped object
from geometry_msgs.msg import Point, PoseStamped
from moveit_wrapper_interfaces.msg import Waypoint
from moveit_msgs.msg import Constraints, RobotState
# adding playmotion
from play_motion2_msgs.action import PlayMotion2
# Instead of calculating a path every time,
#  play_motion2 stores specific joint configurations (motions) in a configuration file.
#  When calling a motion like "open", "close", or "home", the package retrieves a list of joint positions and sends them directly to the controller.
# partially close 
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint



from rclpy.action import ActionClient

class MarkerVisualization(Node):
    def __init__(self):
        super().__init__("marker_visulaization")

        # send marker to ROS by creating publisher 
        self.publisher = self.create_publisher(Marker, 'visualization_marker', 10)

        # set a timer so that it keep publishing marker, and it stay visible in RVIZ
        # initiailze tag pose , so when not found program should not crash
        self.pos_x = 0.0
        self.pos_y = 0.0
        self.pos_z = 0.0

        # just for robto arm ,  later saving this value from tag pose
        self.pos_x2 = 0.0
        self.pos_y2 = 0.0
        self.pos_z2 = 0.0

        self.timer = self.create_timer(1.0, self.get_tag_pose)


        #setup listener  in __init__ method , so the node starts hearing the coordinate frames.

        self.tf_buffer = Buffer() # Buffer is a class constructor it has a data structure for the buffer.
        self.tf_listener = TransformListener(self.tf_buffer, self) # this subscribe to tf statics / transform topics.



        # Planning-scene & attach/detach
        self.add_col_client = self.create_client(AddColObj, "/moveit_wrapper/add_collision_object")
        
        self.plan_client = self.create_client(Plan, "/moveit_wrapper/plan")
        self.execute_client = self.create_client(ExecutePlans, "/moveit_wrapper/execute_plans")

        # Marker publisher for move_marker1
        self.pub = self.create_publisher(Marker, 'move_markers', 10)

        # service client for attach , detach an get attach client

        self.attach_col_client = self.create_client(
            AttachObj, "/moveit_wrapper/attach_object"
        )
        self.detach_col_client = self.create_client(
            DettachObj, "/moveit_wrapper/detach_object"
        )
        self.get_attached_client = self.create_client(
            GetAttachedObjs, "/moveit_wrapper/get_attached_objects"
        )


        # create the action client
        self.gripper_client = ActionClient(self, PlayMotion2, 'play_motion2')


        self.send_gripper_command("open")

        # publisher for gripper partial close
        self.gripper_pub = self.create_publisher(JointTrajectory, '/gripper_controller/joint_trajectory', 10)
        
        #all_service = False
        self.wait_for_services()

        # when service available
        # if all_service == True:
        #     self.send_gripper_command("open")


    def test_collision_object(self):
        
        self.get_logger().info("sending Marker...")

        # 1. marker a object is created
        col_marker1 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker
        col_marker1.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker1.header.stamp = self.get_clock().now().to_msg()
        col_marker1.ns = "Table" # 'ns: Namespace' it allows you to group markers together 
        col_marker1.id = 1
        col_marker1.type = Marker.CYLINDER # tells the shape of marker
        col_marker1.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)

        # position
        col_marker1.pose.position.x = self.pos_x + 0.185
        col_marker1.pose.position.y = self.pos_y + 0.01
        col_marker1.pose.position.z = self.pos_z - 0.045 # 0.040 more minus o.045 going down

        #orientation- 
        col_marker1.pose.orientation.w = 1.0

        # Size  or say scale 
        col_marker1.scale.x = 0.5 #Marker diameter (m)
        col_marker1.scale.y = 0.5 # diameter (m)
        col_marker1.scale.z = 0.1 # height (m)

        # Giving Marker a color
        col_marker1.color.r = 1.0
        col_marker1.color.g = 0.0
        col_marker1.color.b = 0.0
        col_marker1.color.a = 1.0 # 1.0 = Opaque


        # marker 2

        
        col_marker2 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: marker) based
        # on the visulaizatin_msgs/msg/marker
        col_marker2.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker2.header.stamp = self.get_clock().now().to_msg()
        col_marker2.ns = "OBJ1" # 'ns: Namespace' it allows you to group markers together 
        col_marker2.id = 1
        col_marker2.type = Marker.CUBE# tells the shape of marker
        col_marker2.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)

        # position
        col_marker2.pose.position.x = self.pos_x + 0.075
        col_marker2.pose.position.y = self.pos_y - 0.01
        col_marker2.pose.position.z = self.pos_z + 0.090 # 0.075 ---> 0.090. GO up in + so object go up to

        #orientation- 
        col_marker2.pose.orientation.w = 1.0

        # Size  or say scale real object : width, depth, height 0.04, 0.06, 0.15
        col_marker2.scale.x = 0.06 #Marker diameter (m) 0.06
        col_marker2.scale.y = 0.03 # diameter (m) 0.04
        col_marker2.scale.z = 0.15 # height (m)

        # Giving Marker a color
        col_marker2.color.r = 1.0
        col_marker2.color.g = 0.0
        col_marker2.color.b = 0.0
        col_marker2.color.a = 1.0 # 1.0 = Opaque


        # Creating Pregrasp and grasp position
        
    
        pregrasp_wp = Waypoint() # issue 29, created pregrasp object 

        #WayPoint(). A MoveIt-specific wrapper that contains a pose and possibly extra metadata (speed, constraints, etc.).
        pregrasp_pose = PoseStamped()
        pregrasp_pose.header.frame_id = "base_link"
        
        pregrasp_pose.header.stamp = self.get_clock().now().to_msg() # Telling the transform tree: "This position is calculated based on the robot's current state right now.
        
        # Adjusting X (distance to robot). 
        # If robot is at X=0, subtracting 0.20m from object X makes it closer.

        b = 0.10
        c = 0.15
        pregrasp_pose.pose.position.x = self.pos_x2 - c  # -0.20
        pregrasp_pose.pose.position.y = self.pos_y2
        pregrasp_pose.pose.position.z = self.pos_z2 + b # Lift slightly to avoid dragging
        
        # Maintain a standard "gripper down" orientation (adjust if needed)
        pregrasp_pose.pose.orientation.w = 1.0 # 0.707
        pregrasp_wp.pose = pregrasp_pose

        # 2 Grasp Waypoint (5cm closer to robot)
        grasp_wp = Waypoint()
        grasp_pose = PoseStamped()
        grasp_pose.header.frame_id = "base_link"
        grasp_pose.header.stamp = self.get_clock().now().to_msg()
        


        a = 0.02
        grasp_pose.pose.position.x = self.pos_x2 - a
        grasp_pose.pose.position.y = self.pos_y2 # make shift left
        grasp_pose.pose.position.z = self.pos_z2 + b
        
        grasp_pose.pose.orientation.w = 1.0
        grasp_wp.pose = grasp_pose


        #Store waypoints in a list
        # waypoints = [pregrasp_wp, grasp_wp] 

        
        
        ######test 

                # Creating Pos1, poststampes object
        wp1 = Waypoint()

        #WayPoint(). A MoveIt-specific wrapper that contains a pose and possibly extra metadata (speed, constraints, etc.).
        pose3 = PoseStamped()
        pose3.header.frame_id = "base_link"
        pose3.pose.position.x = 0.5
        pose3.pose.position.y = 0.5
        pose3.pose.position.z = 0.8
        pose3.pose.orientation.x = 0.0
        pose3.pose.orientation.y = 0.0
        pose3.pose.orientation.z = 0.0
        pose3.pose.orientation.w = 1.0
        # adding waypoint to move arm fast
        wp1.pose = pose3 # attach pose to waypoint


        # lift waypoint 
        # 3. Lift Waypoint (5cm higher than grasp)
        lift_wp = Waypoint()
        lift_pose = PoseStamped()
        lift_pose.header.frame_id = "base_link"
        lift_pose.pose.position.x = self.pos_x2 - a
        lift_pose.pose.position.y = self.pos_y2
        lift_pose.pose.position.z = self.pos_z2 + 3*b #10cm higher + 10cm offset
        lift_pose.pose.orientation.w = 0.1
        lift_wp.pose = lift_pose


        #after lift
        

        holdback_wp = Waypoint()
        holdback_pose = PoseStamped()
        holdback_pose.header.frame_id = "base_link"
        holdback_pose.pose.position.x = self.pos_x2 - c
        holdback_pose.pose.position.y = self.pos_y2
        holdback_pose.pose.position.z = self.pos_z2 + 3*b #10cm higher + 10cm offset
        holdback_pose.pose.orientation.w = 0.1
        holdback_wp.pose = holdback_pose





        #Store waypoints in a list
        #waypoints = [pregrasp_wp, grasp_wp] 





        # marker5  hold back 
        move_marker5 = Marker()
        move_marker5.header.frame_id = "base_link"
        move_marker5.header.stamp = self.get_clock().now().to_msg()
        move_marker5.ns = "handleback_arrow"
        move_marker5.id = 29 # Unique ID
        move_marker5.type = Marker.ARROW
        move_marker5.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker5.pose = holdback_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker5.scale.x = 0.2  # Length of arrow
        move_marker5.scale.y = 0.02 # Arrow head width
        move_marker5.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker5.color.r = 1.0
        move_marker5.color.a = 1.0 # Opaque




        
        # --- NEW: Create move_marker1 object ---
        move_marker3 = Marker()
        move_marker3.header.frame_id = "base_link"
        move_marker3.header.stamp = self.get_clock().now().to_msg()
        move_marker3.ns = "movement_arrow"
        move_marker3.id = 16 # Unique ID
        move_marker3.type = Marker.ARROW
        move_marker3.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker3.pose = pose3.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker3.scale.x = 0.2  # Length of arrow
        move_marker3.scale.y = 0.02 # Arrow head width
        move_marker3.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker3.color.r = 1.0
        move_marker3.color.a = 1.0 # Opaque

        # Publish the marker so it shows in Rviz
        #self.pub.publish(move_marker3)


        #  lift marker 
        move_marker4 = Marker()
        move_marker4.header.frame_id = "base_link"
        move_marker4.header.stamp = self.get_clock().now().to_msg()
        move_marker4.ns = "lift_arrow"
        move_marker4.id = 15 # Unique ID
        move_marker4.type = Marker.ARROW
        move_marker4.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker4.pose = lift_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker4.scale.x = 0.3  # Length of arrow
        move_marker4.scale.y = 0.02 # Arrow head width
        move_marker4.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker4.color.g = 1.0
        move_marker4.color.a = 1.0 # Opaque


        # Publish the marker so it shows in Rviz
        

        #######
        
        # visualization for debugging


        # --- NEW: Create move_marker1 object ---
        move_marker1 = Marker()
        move_marker1.header.frame_id = "base_link"
        move_marker1.header.stamp = self.get_clock().now().to_msg()
        move_marker1.ns = "pregrasp_arrow"
        move_marker1.id = 10 # Unique ID
        move_marker1.type = Marker.ARROW
        move_marker1.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker1.pose = pregrasp_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker1.scale.x = 0.2  # Length of arrow
        move_marker1.scale.y = 0.02 # Arrow head width
        move_marker1.scale.z = 0.02 # Arrow head height

        # Set color (Red)
        move_marker1.color.r = 1.0
        move_marker1.color.a = 1.0 # Opaque



        # grasp marker visulaization

        # --- NEW: Create move_marker2 object ---
        move_marker2 = Marker()
        move_marker2.header.frame_id = "base_link"
        move_marker2.header.stamp = self.get_clock().now().to_msg()
        move_marker2.ns = "grasp_arrow"
        move_marker2.id = 12 # Unique ID
        move_marker2.type = Marker.ARROW
        move_marker2.action = Marker.ADD

        # Use pose1 as the pose for the marker
        move_marker2.pose = grasp_pose.pose

        # Set scale for the arrow (Length, Width, Height)
        move_marker2.scale.x = 0.2  # Length of arrow
        move_marker2.scale.y = 0.02 # Arrow head width
        move_marker2.scale.z = 0.02 # Arrow head height

        # Set color (Green)
        move_marker2.color.g = 1.0
        move_marker2.color.a = 1.0 # Opaque


        # Publish the marker so it shows in Rviz

        self.pub.publish(move_marker5) # marker for holdback
        self.pub.publish(move_marker4) # marker for lift
        #self.pub.publish(move_marker3) #  this is constant waypoint wp1
        self.pub.publish(move_marker2) # grasp
        self.pub.publish(move_marker1) # pregrasp





        # create a list
        markers = [col_marker1, col_marker2]

        


        # --- PHASE 1: PRE-GRASP ---
        # 1. Plan to Pregrasp

        # self.get_logger().info("Concrete_position...")
        # plan_concrete= self.call_planning_service([wp1])

        #         # check whether pregrasp done or not (Phase 1)
        # if plan_concrete and plan_concrete.success:
        #     self.call_execution_service(plan_concrete.plans)# if plan succeds, the planner return one or more trajectory segments, these will pass to execution service
        # else:
        #     return
        
        self.get_logger().info("Planning to Pre-grasp...")

        # again open gripper if not done 
        self.send_gripper_command("open")
        
        plan_pregrasp = self.call_planning_service([pregrasp_wp])


        # # NEW: Call planning and execution services
        # self.get_logger().info("Starting planning to move to marker position...")
        # planning_response = self.call_planning_service(waypoints) # sending the waypoint list to a motion planning service


        # (Doing this after planning pre-grasp avoids start-state collision errors), adding collision object later as one marker inside the collision object
        self.add_coll_objects_from_markers(markers)


        # check whether pregrasp done or not (Phase 1)
        if plan_pregrasp and plan_pregrasp.success:
            self.call_execution_service(plan_pregrasp.plans)





        else:
            return # Stop if pre-grasp fails


        # if planning_response and planning_response.success: # checking planning passed or not
        #     self.get_logger().info("Planning successful, executing trajectory...")
        #     execution_response = self.call_execution_service(planning_response.plans) # if plan succeds, the planner return one or more trajectory segments, these will pass to execution service
            
        #     # execution success check 
        #     if execution_response and execution_response.success: 
        #         self.get_logger().info("Robot moved to marker position successfully!")
        #     else: # execution can fail due to : control issues, safety stops, Hardware Limits, Timeout 
        #         self.get_logger().error("Execution failed!")
        # else:
        #     self.get_logger().error("Planning failed!")

    # --- PHASE 2: GRASP ---
        # 3. Plan and move from Pre-grasp to Grasp
        self.get_logger().info("Moving to Grasp position...")
        plan_grasp = self.call_planning_service([grasp_wp])

        #checking done or not 
        if plan_grasp and plan_grasp.success:
            self.call_execution_service(plan_grasp.plans)

    # 4. Close Gripper & Attach
 # OBJ1 is the ns/id of your object

        else:
            self.get_logger().error("Grasp position not reached")

        self.get_logger().info("Closing gripper and attaching object...")
            #self.send_gripper_command("close")
# partial close
        self.send_partial_gripper_command()
        self.attach_objects(["OBJ1"])

        self.get_logger().info("Lifting object...")
        plan_lift = self.call_planning_service([lift_wp])


    # 4. Close Gripper & Attach
 # OBJ1 is the ns/id of your object
    
    
    # --- PHASE 3: LIFT ---
        # 5. Plan and move to Lift (Must replan because robot is now holding an object)
        # self.get_logger().info("Lifting object...")
        # plan_lift = self.call_planning_service([lift_wp])
        #plan_lift = self.call_planning_service([pregrasp_wp]) # test
        # checkong done or not
        if plan_lift and plan_lift.success:
            self.call_execution_service(plan_lift.plans)
            self.get_logger().info("lift position reached...")
        else:
            self.get_logger().error("lift position not reached")
    

        plan_holdback = self.call_planning_service([holdback_wp])
        if plan_holdback and plan_holdback.success:
            self.call_execution_service(plan_holdback.plans)
            self.get_logger().info("holdback reached ...")
  
        else:
            self.get_logger().error("holdback not reached")
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   # close partialy left
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
    # gripper

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
            if not self._wait_future(fut, 15.0):
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



    def get_tag_pose(self):
        """
        To get the transform from base_link to apriltag, we need TF2 Buffer.. and a transform listener. 
       
        """
        self.get_logger().info('see the pose from base link to tag36h11:1')

        target_frame = 'tag36h11:1'
        source_frame = 'base_link'


# test consition
    # Check if the transform exists, wait up to 1 second for it to appear
        if not self.tf_buffer.can_transform(source_frame, target_frame, rclpy.time.Time(), rclpy.duration.Duration(seconds=1.0)):
            self.get_logger().info(f"Waiting for transform {source_frame} -> {target_frame}...")
            return None



# look for trnasform 
        try:
            # look for transformation (position and orientation)
            now = rclpy.time.Time() # time giving to ros say , so that we give a tf at the moment one not past stored 
            trans = self.tf_buffer.lookup_transform(
                source_frame,
                target_frame,
                now)  # this is request to buffer to find the relation between this frames. in result it return transform stamped
            # Extract Position
            # self.pos_x1 = trans.transform.translation.x
            # self.pos_y1 = trans.transform.translation.y
            # self.pos_z1 = trans.transform.translation.z
            
            self.pos_x = trans.transform.translation.x
            self.pos_y = trans.transform.translation.y
            self.pos_z = trans.transform.translation.z

            # saving tag pose so when even not available robot will move
            self.pos_x2 = self.pos_x
            self.pos_y2 = self.pos_y
            self.pos_z2 = self.pos_z

            # Extract Orientation
            ori_x = trans.transform.rotation.x
            ori_y = trans.transform.rotation.y
            ori_z = trans.transform.rotation.z
            ori_w = trans.transform.rotation.w

            self.get_logger().info(f"Tag found at Position: x={self.pos_x:.4f}, y={self.pos_y:.4f}, z={self.pos_z:.4f} and orientation: x={ori_x:.4f}, y={ori_y:.4f}, z={ori_z:.4f}, w ={ori_w:.4f}")
            return trans.transform # returning the transform stamps.
        
        except TransformException as ex:
            self.get_logger().info(f'Could not transform {source_frame} to {target_frame}: {ex}')
            return None
        

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
            (self.add_col_client, "/moveit_wrapper/add_collision_object"),
            (self.plan_client, "/moveit_wrapper/plan"),
            (self.execute_client, "/moveit_wrapper/execute_plans"),
            (self.attach_col_client, "/moveit_wrapper/attach_object"),
            (self.detach_col_client, "/moveit_wrapper/detach_object"),
            (self.get_attached_client, "/moveit_wrapper/get_attached_objects"),
        
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
        #all_service = True
        
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




    def call_execution_service(self, plans):
        """Call the trajectory execution service."""
        self.get_logger().info("Calling trajectory execution service...")

        request = ExecutePlans.Request() # .Request creating a empty object.
        request.plans = plans #plans -> joint trajectory, passing to request object

        request.move_group = "arm_torso" # this tells move_group which robot joint to move

        try:
            future = self.execute_client.call_async(request) # request send, waiting to get it done 
            if not self._wait_future(future, 60.0): # if execution take more than 30 sec it aborts # 30 to 60 
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
            if not self._wait_future(future, 15.0): # wait for 15 sec           
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


def main():
    rclpy.init()
    node = MarkerVisualization()

    try:
        # 1. Wait until the TF buffer has the transform we need
        node.get_logger().info("Searching for AprilTag...")
        tag_found = False
        
        while rclpy.ok() and not tag_found:
            # We call get_tag_pose manually here
            rclpy.spin_once(node, timeout_sec=0.1) # node alive to receive tfs
            transform = node.get_tag_pose()
            
            if transform is not None:
                tag_found = True
            # else:
            #     # We MUST spin_once so the TF listener can actually receive data
            #     #rclpy.spin_once(node, timeout_sec=0.1)
            #     time.sleep(0.2)

        # 2. Once tag_found is True, now call the spawn function
        if tag_found:
            node.get_logger().info("Tag located! Spawning collision object...")
            node.test_collision_object()
            
            # 3. Keep spinning so the marker stays alive in Rviz
            rclpy.spin(node)

    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
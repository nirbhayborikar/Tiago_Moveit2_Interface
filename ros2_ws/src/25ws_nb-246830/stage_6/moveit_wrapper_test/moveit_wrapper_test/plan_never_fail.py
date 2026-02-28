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
        
        self.wait_for_services()


    def test_collision_object(self):
        
        self.get_logger().info("sending Marker...")

        # 1. marker a object is created
        col_marker1 = Marker() 
        col_marker1.header.frame_id = 'base_link' 
        col_marker1.header.stamp = self.get_clock().now().to_msg()
        col_marker1.ns = "Table" 
        col_marker1.id = 1
        col_marker1.type = Marker.CYLINDER 
        col_marker1.action = Marker.ADD 

        # position
        col_marker1.pose.position.x = self.pos_x + 0.185
        col_marker1.pose.position.y = self.pos_y + 0.01
        col_marker1.pose.position.z = self.pos_z - 0.045 

        #orientation- 
        col_marker1.pose.orientation.w = 1.0

        # Size  
        col_marker1.scale.x = 0.5 
        col_marker1.scale.y = 0.5 
        col_marker1.scale.z = 0.1 

        # Giving Marker a color
        col_marker1.color.r = 1.0
        col_marker1.color.g = 0.0
        col_marker1.color.b = 0.0
        col_marker1.color.a = 1.0 


        # marker 2
        col_marker2 = Marker() 
        col_marker2.header.frame_id = 'base_link' 
        col_marker2.header.stamp = self.get_clock().now().to_msg()
        col_marker2.ns = "OBJ1" 
        col_marker2.id = 1
        col_marker2.type = Marker.CUBE
        col_marker2.action = Marker.ADD 

        # position
        col_marker2.pose.position.x = self.pos_x + 0.075
        col_marker2.pose.position.y = self.pos_y - 0.01
        col_marker2.pose.position.z = self.pos_z + 0.090 

        #orientation- 
        col_marker2.pose.orientation.w = 1.0

        # Size  
        col_marker2.scale.x = 0.06 
        col_marker2.scale.y = 0.03 
        col_marker2.scale.z = 0.15 

        # Giving Marker a color
        col_marker2.color.r = 1.0
        col_marker2.color.g = 0.0
        col_marker2.color.b = 0.0
        col_marker2.color.a = 1.0 


        # --- WAYPOINT SETUP ---
    
        pregrasp_wp = Waypoint() 
        pregrasp_pose = PoseStamped()
        pregrasp_pose.header.frame_id = "base_link"
        pregrasp_pose.header.stamp = self.get_clock().now().to_msg()
        pregrasp_pose.pose.position.x = self.pos_x2 - 0.20 
        pregrasp_pose.pose.position.y = self.pos_y2
        pregrasp_pose.pose.position.z = self.pos_z2 + 0.10 
        pregrasp_pose.pose.orientation.w = 1.0 
        pregrasp_wp.pose = pregrasp_pose

        grasp_wp = Waypoint()
        grasp_pose = PoseStamped()
        grasp_pose.header.frame_id = "base_link"
        grasp_pose.header.stamp = self.get_clock().now().to_msg()
        grasp_pose.pose.position.x = self.pos_x2
        grasp_pose.pose.position.y = self.pos_y2 
        grasp_pose.pose.position.z = self.pos_z2 + 0.12
        grasp_pose.pose.orientation.w = 1.0
        grasp_wp.pose = grasp_pose

        lift_wp = Waypoint()
        lift_pose = PoseStamped()
        lift_pose.header.frame_id = "base_link"
        lift_pose.pose.position.x = self.pos_x2 
        lift_pose.pose.position.y = self.pos_y2
        lift_pose.pose.position.z = self.pos_z2 + 0.20
        # Normalizing orientation to w=1.0 for stability
        lift_pose.pose.orientation.x = 0.0
        lift_pose.pose.orientation.y = 0.0
        lift_pose.pose.orientation.z = 0.0
        lift_pose.pose.orientation.w = 1.0
        lift_wp.pose = lift_pose

        # Publish Markers for visualization
        self.pub.publish(col_marker1)
        self.pub.publish(col_marker2)
        markers = [col_marker1, col_marker2]

        # --- PHASE 1: PRE-GRASP ---
        self.get_logger().info("Planning to Pre-grasp...")
        
        # plan_never_fail
        success_pregrasp = False
        for attempt in range(3):
            self.get_logger().info(f"Pre-grasp planning attempt {attempt + 1}...")
            plan_pregrasp = self.call_planning_service([pregrasp_wp])
            if plan_pregrasp and plan_pregrasp.success:
                self.add_coll_objects_from_markers(markers)
                self.call_execution_service(plan_pregrasp.plans)
                success_pregrasp = True
                break
            else:
                pregrasp_wp.pose.pose.position.x -= 0.01 
                self.get_logger().warn("Retrying Pre-grasp with 1cm relaxation...")
        
        if not success_pregrasp:
            self.get_logger().error("Pre-grasp failed all attempts.")
            return
        # plan_never_fail

        # --- PHASE 2: GRASP ---
        self.get_logger().info("Moving to Grasp position...")
        
        # plan_never_fail
        success_grasp = False
        for attempt in range(3):
            self.get_logger().info(f"Grasp planning attempt {attempt + 1}...")
            plan_grasp = self.call_planning_service([grasp_wp])
            if plan_grasp and plan_grasp.success:
                self.call_execution_service(plan_grasp.plans)
                self.send_partial_gripper_command()
                self.attach_objects(["OBJ1"])
                success_grasp = True
                break
            else:
                grasp_wp.pose.pose.position.x -= 0.01
                self.get_logger().warn("Retrying Grasp with 1cm relaxation...")
        
        if not success_grasp:
            self.get_logger().error("Grasp failed all attempts.")
            return
        # plan_never_fail

        # --- PHASE 3: LIFT ---
        self.get_logger().info("Lifting object...")
        
        # plan_never_fail
        success_lift = False
        for attempt in range(3):
            self.get_logger().info(f"Lift planning attempt {attempt + 1}...")
            plan_lift = self.call_planning_service([lift_wp])
            if plan_lift and plan_lift.success:
                self.call_execution_service(plan_lift.plans)
                success_lift = True
                break
            else:
                lift_wp.pose.pose.position.x -= 0.01
                self.get_logger().warn("Retrying Lift with 1cm relaxation...")
        
        if not success_lift:
            self.get_logger().error("Lift failed all attempts.")
        # plan_never_fail

    def send_partial_gripper_command(self, target_gap = 0.0250):
        self.get_logger().info(f"Sending partial gripper command: {target_gap}")
        msg = JointTrajectory()
        msg.joint_names = ['gripper_left_finger_joint', 'gripper_right_finger_joint']
        point = JointTrajectoryPoint()
        point.positions = [target_gap, target_gap]
        point.time_from_start.sec = 1 
        msg.points.append(point)
        self.gripper_pub.publish(msg)
        return True

    def send_gripper_command(self, motion_name):
        self.get_logger().info(f"Sending gripper command: {motion_name}")
        if not self.gripper_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("Gripper action server not available!")
            return False
        goal_msg = PlayMotion2.Goal()
        goal_msg.motion_name = motion_name 
        goal_msg.skip_planning = False 
        send_goal_future = self.gripper_client.send_goal_async(goal_msg) 
        if not self._wait_future(send_goal_future, 10.0):
            return False
        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            return False
        result_future = goal_handle.get_result_async()
        if not self._wait_future(result_future, 10.0):
            return False
        return True

    def attach_objects(self, names) -> bool:
        if not names: return True
        try:
            req = AttachObj.Request()
            req.move_group = "arm_torso"
            req.object_names = names
            fut = self.attach_col_client.call_async(req)
            if not self._wait_future(fut, 15.0): return False
            resp = fut.result()
            return getattr(resp, "success", True)
        except Exception as e:
            return False

    def detach_objects(self, names) -> bool:
        if not names: return True
        try:
            req = DettachObj.Request()
            req.move_group = "arm_torso"
            req.object_names = names
            fut = self.detach_col_client.call_async(req)
            if not self._wait_future(fut, 15.0): return False
            resp = fut.result()
            return getattr(resp, "success", True)
        except Exception:
            return False

    def get_tag_pose(self):
        target_frame = 'tag36h11:1'
        source_frame = 'base_link'
        try:
            now = rclpy.time.Time() 
            trans = self.tf_buffer.lookup_transform(source_frame, target_frame, now)  
            self.pos_x = trans.transform.translation.x
            self.pos_y = trans.transform.translation.y
            self.pos_z = trans.transform.translation.z
            self.pos_x2, self.pos_y2, self.pos_z2 = self.pos_x, self.pos_y, self.pos_z
            return trans.transform 
        except TransformException:
            return None
        
    def add_coll_objects_from_markers(self, markers):
        try:
            req = AddColObj.Request() 
            req.objects = markers 
            fut = self.add_col_client.call_async(req)
            if not self._wait_future(fut, 15.0): return False
            return True
        except Exception:
            return False

    def wait_for_services(self):
        self.get_logger().info("Waiting for services...")
        services = [
            (self.add_col_client, "/moveit_wrapper/add_collision_object"),
            (self.plan_client, "/moveit_wrapper/plan"),
            (self.execute_client, "/moveit_wrapper/execute_plans"),
            (self.attach_col_client, "/moveit_wrapper/attach_object"),
            (self.detach_col_client, "/moveit_wrapper/detach_object"),
            (self.get_attached_client, "/moveit_wrapper/get_attached_objects"),
        ] 
        for client, service_name in services:
            while not client.wait_for_service(timeout_sec=1.0):
                self.get_logger().info(f"Service {service_name} not available...") 
        self.get_logger().info("All services available!")

    def _wait_future(self, future, timeout_sec: float) -> bool: 
        start = time.time() 
        while rclpy.ok() and not future.done():
            rclpy.spin_once(self, timeout_sec=0.1)
            if time.time() - start > timeout_sec:
                return False
        return future.done() 

    def call_execution_service(self, plans):
        request = ExecutePlans.Request() 
        request.plans = plans 
        request.move_group = "arm_torso" 
        try:
            future = self.execute_client.call_async(request) 
            if not self._wait_future(future, 30.0): return None
            return future.result()
        except Exception:
            return None
        
    def call_planning_service(self, waypoints, description=""):
        request = Plan.Request()
        request.waypoints = waypoints 
        request.path_constraints = Constraints() 
        request.send_partial = True 
        request.use_start_state = False 
        request.start_state = RobotState() 
        request.move_group = "arm_torso" 
        try:
            future = self.plan_client.call_async(request) 
            if not self._wait_future(future, 15.0): return None
            return future.result()
        except Exception:
            return None

def main():
    rclpy.init()
    node = MarkerVisualization()
    try:
        tag_found = False
        while rclpy.ok() and not tag_found:
            transform = node.get_tag_pose()
            if transform is not None:
                tag_found = True
            else:
                rclpy.spin_once(node, timeout_sec=0.1)
                time.sleep(0.5)
        if tag_found:
            node.test_collision_object()
            rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
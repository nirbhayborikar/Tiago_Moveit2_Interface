# Testing marker visulaization 
import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
# added library for using tf2
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
#

class MarkerVisualization(Node):
    def __init__(self):
        super().__init__("marker_visulaization")

        # send marker to ROS by creating publisher 
        self.publisher = self.create_publisher(Marker, 'visualization_marker', 10)

        # set a timer so that it keep publishing marker, and it stay visible in RVIZ
        self.timer = self.create_timer(1.0, self.marker)

        #setup listener  in __init__ method , so the node starts hearing the coordinate frames.

        self.tf_buffer = Buffer() # Buffer is a class constructor it has a data structure for the buffer.
        self.tf_listener = TransformListener(self.tf_buffer, self) # this subscribe to tf statics / transform topics.

    def marker(self):
        
        self.get_logger().info("sending Marker...")

        # 1. col_marker1 a object is created
        col_marker1 = Marker() # Marker() is a python class constructor, when you call it you creating empty data structire (an object: col_marker1) based
        # on the visulaizatin_msgs/msg/marker
        col_marker1.header.frame_id = 'base_link' # which coordinate system to use to publish marker
        col_marker1.header.stamp = self.get_clock().now().to_msg()
        col_marker1.ns = "visual" # 'ns: Namespace' it allows you to group markers together 
        col_marker1.id = 1
        col_marker1.type = Marker.CYLINDER # tells the shape of marker
        col_marker1.action = Marker.ADD # tells Rviz what to do with that marker (ADD, DELETE DELETEALL)

        # position
        col_marker1.pose.position.x = 0.5
        col_marker1.pose.position.y = 0.5
        col_marker1.pose.position.z = 0.8  

        #orientation
        col_marker1.pose.orientation.w = 1.0

        # Size  or say scale 
        col_marker1.scale.x = 0.1 #Marker diameter (m)
        col_marker1.scale.y = 0.1 # diameter (m)
        col_marker1.scale.z = 0.2 # height (m)

        # Giving Marker a color
        col_marker1.color.r = 1.0
        col_marker1.color.g = 0.0
        col_marker1.color.b = 0.0
        col_marker1.color.a = 1.0 # 1.0 = Opaque


        # now publish everything 
        self.publisher.publish(col_marker1) # publishing through passing object that contain above data.
        self.get_logger().info("Publishing_marker to topic 'visualization_marker' done...")
        self.get_tag_pose()


        # # Add all to planning scene
        # success = self.add_coll_objects_from_markers([col_marker1])
        
        # if success:
        #     self.get_logger().info("Markers successfully spawned relative to AprilTag.")
        # return success


    def get_tag_pose(self):
        """
        To get the transform from base_link to apriltag, we need TF2 Buffer.. and a transform listener. 
       
        """
        self.get_logger().info('see the pose from base link to tag36h11:1')

        target_frame = 'tag36h11:1'
        source_frame = 'base_link'

        try:
            # look for transformation (position and orientation)
            now = rclpy.time.Time() # time giving to ros say , so that we give a tf at the moment one not past stored 
            trans = self.tf_buffer.lookup_transform(
                source_frame,
                target_frame,
                now)  # this is request to buffer to find the relation between this frames. in result it return transform stamped
            # Extract Position
            pos_x = trans.transform.translation.x
            pos_y = trans.transform.translation.y
            pos_z = trans.transform.translation.z
            
            # Extract Orientation
            ori_x = trans.transform.rotation.x
            ori_y = trans.transform.rotation.y
            ori_z = trans.transform.rotation.z
            ori_w = trans.transform.rotation.w

            self.get_logger().info(f"Tag found at Position: x={pos_x:.4f}, y={pos_y:.4f}, z={pos_z:.4f} and orientation: x={ori_x:.4f}, y={ori_y:.4f}, z={ori_z:.4f}, w ={ori_w:.4f}")
            return trans.transform # returning the transform stamps.
        
        except TransformException as ex:
            self.get_logger().info(f'Could not transform {source_frame} to {target_frame}: {ex}')
            return None
def main():
    rclpy.init()
    node = MarkerVisualization()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
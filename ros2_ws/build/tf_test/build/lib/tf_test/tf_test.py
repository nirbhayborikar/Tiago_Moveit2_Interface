import rclpy
from math import sqrt
from rclpy.node import Node
from geometry_msgs.msg import Twist
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener


class FrameListener(Node):

    def __init__(self):
        super().__init__('test_tf2_frame_listener')

        # Publisher for velocity commands
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)

        # Frames for transform lookup
        self.source_frame = "tag36h11:3"
        self.target_frame = "base_link"

        # TF2 Buffer and Listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Timer to check for transform and move robot
        self.timer = self.create_timer(0.1, self.on_timer)  # Reduced interval to 0.1 seconds

    def on_timer(self):
        try:
            # Look up the transform
            t = self.tf_buffer.lookup_transform(
                self.target_frame,
                self.source_frame,
                rclpy.time.Time()  # Use latest available transform
            )

            # Extract translation components
            translation = t.transform.translation
            x = translation.x
            y = translation.y
            z = translation.z

            # Calculate distance
            d = sqrt(x**2 + y**2 + z**2)

            # Log distance for debugging
            self.get_logger().info(f'Distance to target: {d:.2f} meters')

            # Tolerance for stopping condition
            epsilon = 0.05  # 5 cm tolerance

            # Check if distance is within the stopping condition
            if d < 1.0:  # Stop if distance is less than 1 meter
                self.stop_robot()
            else:
                self.move_robot()

        except TransformException as ex:
            self.get_logger().info(f'Could not transform {self.source_frame} to {self.target_frame}: {ex}')
            self.stop_robot()

    def move_robot(self):
        """Move the robot forward with a fixed linear velocity."""
        twist = Twist()
        twist.linear.x = 0.5  # Move forward at 0.5 m/s
        twist.angular.z = 0.0  # Ensure no rotation
        self.publisher_.publish(twist)

    def stop_robot(self):
        """Stop the robot by sending zero velocity."""
        twist = Twist()
        twist.linear.x = 0.0
        twist.linear.y = 0.0
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0
        self.publisher_.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = FrameListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()

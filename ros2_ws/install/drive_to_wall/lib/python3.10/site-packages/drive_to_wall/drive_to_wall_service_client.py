import rclpy
from rclpy.node import Node
from custom_interfaces.srv import DriveToWallS
import sys

class DriveToWallClient(Node):
    def __init__(self):
        super().__init__('drive_to_wall_service_client')
        
        # Create service client
        self.client = self.create_client(DriveToWallS, 'drive_to_wall_service')
        
        # Wait for service to be available
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')
        
        self.call_service()

    def call_service(self):
        # Create request
        request = DriveToWallS.Request()
        
        # Set parameters from command line or defaults
        if len(sys.argv) >= 3:
            request.linear_x = float(sys.argv[1])
            request.min_distance = float(sys.argv[2])
        else:
            # Default values
            request.linear_x = 0.2
            request.min_distance = 0.5
        
        self.get_logger().info(f'Calling service with: speed={request.linear_x}, distance={request.min_distance}')
        
        # Call service asynchronously
        future = self.client.call_async(request)
        future.add_done_callback(self.service_callback)

    def service_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f'Service Response: {response.message}')
            self.get_logger().info(f'Success: {response.success}')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')
        
        # Shutdown after receiving response
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = DriveToWallClient()
    rclpy.spin(node)
    node.destroy_node()

if __name__ == '__main__':
    main()
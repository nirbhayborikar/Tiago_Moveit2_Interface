#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "moveit_wrapper_interfaces/srv/add_col_obj.hpp"
#include "moveit_wrapper_interfaces/srv/remove_col_obj.hpp"

using namespace std::chrono_literals;

class MoveitCollisionManager : public rclcpp::Node {
public:
    MoveitCollisionManager() : Node("collision_scene_manager") {
        // Initialize service clients
        add_col_client_ = this->create_client<moveit_wrapper_interfaces::srv::AddColObj>(
            "/moveit_wrapper/add_collision_object");
        remove_col_client_ = this->create_client<moveit_wrapper_interfaces::srv::RemoveColObj>(
            "/moveit_wrapper/remove_collision_object");

        wait_for_services();
    }

    void wait_for_services() {
        RCLCPP_INFO(this->get_logger(), "Waiting for MoveIt Wrapper services...");
        while (!add_col_client_->wait_for_service(1s) || !remove_col_client_->wait_for_service(1s)) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for services.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Services not available, waiting again...");
        }
        RCLCPP_INFO(this->get_logger(), "All services ready.");
    }

    bool clear_planning_scene() {
        auto request = std::make_shared<moveit_wrapper_interfaces::srv::RemoveColObj::Request>();
        request->object_names = {}; // Empty list removes all objects

        auto result = remove_col_client_->async_send_request(request);
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == 
            rclcpp::FutureReturnCode::SUCCESS) {
            return true;
        }
        return false;
    }

    bool add_coll_objects_from_markers(const std::vector<visualization_msgs::msg::Marker>& markers) {
        auto request = std::make_shared<moveit_wrapper_interfaces::srv::AddColObj::Request>();
        request->objects = markers;

        auto result = add_col_client_->async_send_request(request);
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == 
            rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_INFO(this->get_logger(), "Added %zu collision markers to scene.", markers.size());
            return true;
        }
        RCLCPP_ERROR(this->get_logger(), "Failed to add collision objects.");
        return false;
    }

    void run_setup() {
        RCLCPP_INFO(this->get_logger(), "Clearing scene and spawning markers...");
        clear_planning_scene();

        std::string tag_frame = "marker_frame"; 
        std::vector<visualization_msgs::msg::Marker> markers;

        // 1. col_marker1: CYLINDER (The Table)
        visualization_msgs::msg::Marker col_marker1;
        col_marker1.header.frame_id = tag_frame;
        col_marker1.header.stamp = this->now();
        col_marker1.ns = "environment";
        col_marker1.id = 1;
        col_marker1.type = visualization_msgs::msg::Marker::CYLINDER;
        col_marker1.action = visualization_msgs::msg::Marker::ADD;
        col_marker1.pose.position.z = -0.4;
        col_marker1.pose.orientation.w = 1.0;
        col_marker1.scale.x = 0.6;
        col_marker1.scale.y = 0.6;
        col_marker1.scale.z = 0.8;
        markers.push_back(col_marker1);

        // 2. col_marker2: CUBE (The Object)
        visualization_msgs::msg::Marker col_marker2;
        col_marker2.header.frame_id = tag_frame;
        col_marker2.header.stamp = this->now();
        col_marker2.ns = "objects";
        col_marker2.id = 2;
        col_marker2.type = visualization_msgs::msg::Marker::CUBE;
        col_marker2.action = visualization_msgs::msg::Marker::ADD;
        col_marker2.pose.position.x = 0.1;
        col_marker2.pose.position.z = 0.05;
        col_marker2.pose.orientation.w = 1.0;
        col_marker2.scale.x = 0.05;
        col_marker2.scale.y = 0.05;
        col_marker2.scale.z = 0.15;
        markers.push_back(col_marker2);

        add_coll_objects_from_markers(markers);
    }

private:
    rclcpp::Client<moveit_wrapper_interfaces::srv::AddColObj>::SharedPtr add_col_client_;
    rclcpp::Client<moveit_wrapper_interfaces::srv::RemoveColObj>::SharedPtr remove_col_client_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MoveitCollisionManager>();
    
    node->run_setup();
    
    RCLCPP_INFO(node->get_logger(), "Setup complete. Spinning...");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include "turtlesim/srv/spawn.hpp"
#include <cmath>
#include <iostream>
#include <random>
#include <thread>

class PathPlannerNode : public rclcpp::Node {
public:
    PathPlannerNode() : Node("path_planner") {
       
        client_ = this->create_client<turtlesim::srv::Spawn>("spawn");
        velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
        pose_subscriber_ = this->create_subscription<turtlesim::msg::Pose>(
            "turtle1/pose", 10, std::bind(&PathPlannerNode::pose_callback, this, std::placeholders::_1));

      
        spawn_turtle();

       
     std::string line;
        std::cout << "Enter r to start: ";
        std::getline(std::cin, line);

        if (line == "r") {  
            choose_new_target();
        } else {
            RCLCPP_INFO(this->get_logger(), "Invalid input!");
        }
    }

    ~PathPlannerNode() {
        if (input_thread_.joinable()) {
            input_thread_.join(); //join(), thread'in tamamlanmasını bekler.
        }
    }

private:
    void spawn_turtle() {
        if (!client_->wait_for_service(std::chrono::seconds(1))) {
            RCLCPP_ERROR(this->get_logger(), "The Spawn service is not available!");
            return;
        }

        auto request = std::make_shared<turtlesim::srv::Spawn::Request>();
        request->x = 5.0;
        request->y = 5.0;
        request->theta = 0.0;
        request->name = "turtle1";

        auto future = client_->async_send_request(request);
        future.wait();
    }

    void pose_callback(const turtlesim::msg::Pose::SharedPtr msg) {
       
        current_x_ = msg->x;
        current_y_ = msg->y;
        current_theta_ = msg->theta;
    }

  void choose_new_target() {
    do {
        
        target_x_ = random_double(2.0, 8.0);
        target_y_ = random_double(2.0, 8.0);

        
    } while (is_near_wall(target_x_, target_y_) || 
             std::sqrt(std::pow(target_x_ - current_x_, 2) + std::pow(target_y_ - current_y_, 2)) < 3.0);

    RCLCPP_INFO(this->get_logger(), "New target: (%.2f, %.2f)", target_x_, target_y_);
    move_turtle_to_target();
}


    bool is_near_wall(double x, double y) {
        return x < 2.0 || x > 8.0 || y < 2.0 || y > 8.0;
    }

    void move_turtle_to_target() {
        geometry_msgs::msg::Twist velocity_msg;
        double distance = std::sqrt(std::pow(target_x_ - current_x_, 2) + std::pow(target_y_ - current_y_, 2));

        while (distance > 0.1) {
            double angle_to_target = atan2(target_y_ - current_y_, target_x_ - current_x_);
            double angle_error = normalize_angle(angle_to_target - current_theta_);

            
            velocity_msg.linear.x = 1.0;
            velocity_msg.angular.z = 4.0 * angle_error;  

            velocity_publisher_->publish(velocity_msg);

          
            distance = std::sqrt(std::pow(target_x_ - current_x_, 2) + std::pow(target_y_ - current_y_, 2));
            rclcpp::sleep_for(std::chrono::milliseconds(100));
        }

        
        velocity_msg.linear.x = 0.0;
        velocity_msg.angular.z = 0.0;
        velocity_publisher_->publish(velocity_msg);

        RCLCPP_INFO(this->get_logger(), "Target reached! Waiting for 2 seconds...");
        rclcpp::sleep_for(std::chrono::seconds(2));

      
        choose_new_target();
    }

    double normalize_angle(double angle) {
        while (angle > M_PI) angle -= 2 * M_PI;
        while (angle < -M_PI) angle += 2 * M_PI;
        return angle;
    }

    double random_double(double min, double max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        return dis(gen);
    }

private:
    rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr client_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_subscriber_;

    std::thread input_thread_;
    double current_x_ = 5.0, current_y_ = 5.0, current_theta_ = 0.0;
    double target_x_ = 0.0, target_y_ = 0.0;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PathPlannerNode>());
    rclcpp::shutdown();
    return 0;
}

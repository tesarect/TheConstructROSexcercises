#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>

MobileRobotRobotManager::MobileRobotRobotManager(ros::NodeHandle *node_handle) {
  // assign NodeHandle to nh variable from parent class
  nh = node_handle;
  init_config_output_srv();
  init_odom_subscriber();
}

void MobileRobotRobotManager::init_odom_subscriber() {
  odom_subscriber = nh->subscribe(
      odometry_topic, 1000, &MobileRobotRobotManager::odom_callback, this);
  ROS_INFO("Odometry subscriber created");
}

void MobileRobotRobotManager::odom_callback(
    const nav_msgs::Odometry::ConstPtr &msg) {
  if (output_enabled == true) {
    current_x_position = msg->pose.pose.position.x;
    current_y_position = msg->pose.pose.position.y;
    ROS_INFO("Position (x,y): %lf , %lf", current_x_position,
             current_y_position);
    //   Note: we can still can access the displayRobotDetails() function
    //   declared in the base class if we use the scope resolution operator ::.
    //   For instance in the example above you would need to call
    //   RobotManagerBase::displayRobotDetails(); instead of just
    //   displayRobotDetails();
    // RobotManagerBase::displayRobotDetails();
  }
}

void MobileRobotRobotManager::displayRobotDetails() {
  ROS_INFO("Robot's Details: ");
  ROS_INFO("Name                 : %s", robot_name.c_str());
  ROS_INFO("Location             : %s", robot_location.c_str());
  ROS_INFO("Battery Change Level : %f", battery_charge_level);
  ROS_INFO("Battery Type         : %s", type_of_battery.c_str());
}

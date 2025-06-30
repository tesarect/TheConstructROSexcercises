#pragma once
#include "nav_msgs/Odometry.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>
#include <string>

class MobileRobotRobotManager : public RobotManagerBase {

public:
  MobileRobotRobotManager(ros::NodeHandle *node_handle);
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

private:
  float current_x_position = 0.0;
  float current_y_position = 0.0;
  float battery_charge_level = 0.55;
  std::string type_of_battery = "Lead acid batteries";
  std::string odometry_topic = "/robot1/odom";
  ros::Subscriber odom_subscriber;

  void init_odom_subscriber();
  void displayRobotDetails() override;
};
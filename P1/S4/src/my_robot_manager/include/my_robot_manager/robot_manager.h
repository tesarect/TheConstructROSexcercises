#pragma once
// #include "ros/node_handle.h"
// #include "ros/subscriber.h"
#include "nav_msgs/Odometry.h"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <string>

class RobotManager {

public:
  static int robot_count;

  RobotManager(ros::NodeHandle *nh, std ::string topic, std::string name,
               std::string model);
//   RobotManager(const RobotManager &other);
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
  void print_specifications();
  bool trigger_srv_callback(std_srvs::Trigger::Request &req,
                            std_srvs::Trigger::Response &res);

private:
  std::string robot_name;
  std::string robot_model;
  std::string odom_topic;
  float current_x_position = 0.0;
  float current_y_position = 0.0;
  float battery_capacity_kwh = 0.16;
  int total_operation_hours = 2560;
  ros::Subscriber odom_subscriber;
  ros::ServiceServer trigger_srv;
};
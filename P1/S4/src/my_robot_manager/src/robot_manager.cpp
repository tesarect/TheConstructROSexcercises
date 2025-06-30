#include "my_robot_manager/robot_manager.h"

// initialize static variable
int RobotManager::robot_count = 0;

// Constructor - parameterised list inizilazation constructor
RobotManager::RobotManager(ros::NodeHandle *nh, std::string topic,
                           std::string name, std::string model) {
  odom_topic = topic;
  robot_name = name;
  robot_model = model;
  odom_subscriber =
      nh->subscribe(odom_topic, 1000, &RobotManager::odom_callback, this);

  // Increase counter every time a new object is created
  robot_count++;
  ROS_INFO("Robot %d created", robot_count);

  // define service name and a callback to be invoked when the service is called
  trigger_srv = nh->advertiseService(robot_name + "/log_current_position",
                                     &RobotManager::trigger_srv_callback, this);
}

// Copy constructor
// RobotManager::RobotManager(const RobotManager::RobotManager &other)
//     : robot_name(other.robot_name + "_copy"), robot_model(other.robot_model),
//       odom_topic(other.odom_topic),
//       current_x_position(other.current_x_position),
//       current_y_position(other.current_y_position),
//       battery_capacity_kwh(other.battery_capacity_kwh),
//       total_operation_hours(other.total_operation_hours) {

//   // `ros::NodeHandle *nh` -> seems ros obects are not supposed to be copied.
//   // so seems we should create a separate methond for this . in doubt
//   // TODO this one

//   robot_count++;
//   ROS_INFO("Robot %d created (copied from %s)", robot_count,
//            other.robot_name.c_str());

//   // ROS subscribers and services cannot be directly copied
//   // They need to be re-established with a valid NodeHandle
//   ROS_WARN("Copy constructor created robot without ROS connections. Call "
//            "setupROS() to establish connections.");
// }

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg) {

  this->current_x_position = msg->pose.pose.position.x;
  this->current_y_position = msg->pose.pose.position.y;
}

void RobotManager::print_specifications() {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Model: %s", robot_model.c_str());
  ROS_INFO("Battery Capacity (kWh): %.2f", battery_capacity_kwh);
  ROS_INFO("Total Operation Hours: %d", total_operation_hours);
}

//  Trigger service callback
bool RobotManager::trigger_srv_callback(std_srvs::Trigger::Request &req,
                                        std_srvs::Trigger::Response &res) {

  ROS_INFO("%s position (x,y): %lf , %lf", robot_name.c_str(),
           this->current_x_position, this->current_y_position);

  res.success = true;
  res.message = "Position logged";
  return true;
}
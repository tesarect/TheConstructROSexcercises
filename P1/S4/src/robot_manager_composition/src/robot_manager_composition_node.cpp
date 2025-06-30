/* main - to start a ROS node instance of the RobotManagerComposition class */
#include "robot_manager_composition/robot_manager_composition.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager_using_composition");
  ros::NodeHandle nh;
  RobotManagerComposition rm = RobotManagerComposition(&nh);
  ros::spin();
}

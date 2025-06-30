#include "my_robot_manager/robot_manager.h"
// #include "ros/node_handle.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;

  RobotManager rm = RobotManager(&nh, "/robot1/odom", "Turty1", "TurtleBot3");
  rm.print_specifications();

  RobotManager rm2 = RobotManager(&nh, "/robot2/odom", "Turty2", "TurtleBot3");
  rm2.print_specifications();

  ros::spin();
}
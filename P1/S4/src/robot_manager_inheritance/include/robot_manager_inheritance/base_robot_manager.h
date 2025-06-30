#pragma once
// #include "ros/node_handle.h"
// #include "ros/service_server.h"
// #include "std_srvs/SetBoolRequest.h"
// #include "std_srvs/SetBoolResponse.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <string>

class RobotManagerBase {
public:
  RobotManagerBase(){};
  RobotManagerBase(ros::NodeHandle *nh);

protected:
  bool output_enabled = false;
  std::string robot_name = "xxx";
  std::string robot_location = "yyy";
  ros::NodeHandle *nh;
  
  void init_config_output_srv();
  virtual void displayRobotDetails() = 0;

private:
  ros::ServiceServer config_output_srv;

  bool ConfigOutputCallback(std_srvs::SetBoolRequest &req,
                            std_srvs::SetBoolResponse &response);
};
#! /usr/bin/env python

# service call can be done through cmd line for testing but for real work,
# here is how we can call a service from a ROS program.
# the service call (to take the food/release the food) is initated through this code,
# and for this demonstaration we should execute the "service server"(start the service launch file in this case)
'''
roslaunch trajectory_by_name start_service.launch
'''


import rospy
# Import the service message used by the service /trajectory_by_name
from trajectory_by_name_srv.srv import TrajByName, TrajByNameRequest
import sys

# Initialise a ROS node with the name service_client
rospy.init_node('service_client')
# Wait for the service client /trajectory_by_name to be running
rospy.wait_for_service('/trajectory_by_name')
# Create the connection to the service
traj_by_name_service = rospy.ServiceProxy('/trajectory_by_name', TrajByName)
# Create an object of type TrajByNameRequest
traj_by_name_object = TrajByNameRequest()
# Fill the variable traj_name of this object with the desired value
traj_by_name_object.traj_name = "init_pos"
# traj_by_name_object.traj_name = "get_food"
# traj_by_name_object.traj_name = "release_food"
# Send through the connection the name of the trajectory to be executed by the robot
result = traj_by_name_service(traj_by_name_object)
# Print the result given by the service called
print(result)

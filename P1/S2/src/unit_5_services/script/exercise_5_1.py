#! /usr/bin/env python

import rospy
from iri_wam_reproduce_trajectory.srv import ExecTraj, ExecTrajRequest # Import the service message used by the service /execute_trajectory
import sys

import rospkg
rospack = rospkg.RosPack()
# This rospack.get_path() works in the same way as $(find name_of_package) in the launch files.<br>
trajectory_file_path = rospack.get_path('iri_wam_reproduce_trajectory') + "/config/get_food.txt"
print(f'{trajectory_file_path}-------')
rospy.init_node('service_execute_trajectory_client')
rospy.wait_for_service('/execute_trajectory')

execute_trajectory_service = rospy.ServiceProxy('/execute_trajectory', ExecTraj)

execute_trajectory_req_object = ExecTrajRequest()

execute_trajectory_req_object.file = trajectory_file_path

result = execute_trajectory_service(execute_trajectory_req_object)

print(result)

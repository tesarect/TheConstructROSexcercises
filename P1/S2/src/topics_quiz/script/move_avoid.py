#! /usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from math import isinf

global void_movement_counter
void_movement_counter = 0
is_void = lambda x : all(isinf(i) for i in x)

def callback(msg):
    global void_movement_counter
    _left = max(msg.ranges[709:])
    _front = max(msg.ranges[355:365])
    _right = max(msg.ranges[0:15])
    move = Twist()
    move.linear.x = 0
    move.angular.z = 0

    # if all([_left, _front, _right]) == float('inf'):
    if is_void([_left, _front, _right]):
        print(" all values scans are infinite(entering void space). so stopping the movement in a while . . .")
        move.linear.x = 0.3
        move.angular.z = 0.0
        if void_movement_counter > 250:
            move.linear.x = 0.0
            move.angular.z = 0.0
        void_movement_counter += 1

    else:
        if _front > 1:
            move.linear.x = 0.3
            print(f' - Moving forward')
        else:
            move.linear.x = 0.2
            move.angular.z = 0.5
            print(f' - turning left')
        
        if _right < 1:
            move.angular.z = 0.5
            print(f' - turning left')
        if _left < 1:
            move.angular.z = -0.5
            print(f' - turning right')

    pub.publish(move)


rospy.init_node("topics_quiz_node")
rate = rospy.Rate(2)

sub = rospy.Subscriber('/kobuki/laser/scan', LaserScan, callback)
pub = rospy.Publisher('/cmd_vel', Twist, queue_size=1)

rospy.spin()
#! /usr/bin/env python

import rospy
# from std_msgs.msg import Int32
from nav_msgs.msg import Odometry

def callback(msg): 
  print(msg)

rospy.init_node('odom_subscriber_node')
# count_sub = rospy.Subscriber('/counter', Int32, callback)
odom_sub = rospy.Subscriber('/odom', Odometry, callback)
rospy.spin()


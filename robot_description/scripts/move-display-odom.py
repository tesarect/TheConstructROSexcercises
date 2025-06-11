#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

def callback(msg):
    ## TO DO
    ## Print minimum laser distance detected
    print(f'Minimum distance is: {min(msg.ranges)}')

def main():
    ## TO DO
    ## Add Subscriber for the laser
    sub = rospy.Subscriber('/laser/scan', LaserScan, callback)
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    rospy.init_node('exercise_node', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        msg = Twist()
        msg.linear.x = 0.3
        msg.angular.z = 0.3
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass

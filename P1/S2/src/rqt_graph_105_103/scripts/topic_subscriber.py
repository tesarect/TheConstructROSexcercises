#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def callback(msg):
    rospy.loginfo(f"Received: {msg.data}")

def topic_subscriber():
    # Initialize the node
    rospy.init_node('topic_subscriber', anonymous=True)
    
    # Create subscriber
    rospy.Subscriber('/counter', Int32, callback)
    
    rospy.loginfo("Topic Subscriber started. Listening to /counter topic.")
    
    # Keep the node running
    rospy.spin()

if __name__ == '__main__':
    try:
        topic_subscriber()
    except rospy.ROSInterruptException:
        pass
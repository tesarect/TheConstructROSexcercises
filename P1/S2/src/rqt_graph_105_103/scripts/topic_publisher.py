#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def topic_publisher():
    # Initialize the node
    rospy.init_node('topic_publisher', anonymous=True)
    
    # Create publisher
    pub = rospy.Publisher('/counter', Int32, queue_size=10)
    
    # Set the publishing rate
    rate = rospy.Rate(1)  # 1 Hz
    
    counter = 0
    rospy.loginfo("Topic Publisher started. Publishing to /counter topic.")
    
    while not rospy.is_shutdown():
        # Create and publish message
        msg = Int32()
        msg.data = counter
        pub.publish(msg)
        
        rospy.loginfo(f"Published: {counter}")
        counter += 1
        rate.sleep()

if __name__ == '__main__':
    try:
        topic_publisher()
    except rospy.ROSInterruptException:
        pass
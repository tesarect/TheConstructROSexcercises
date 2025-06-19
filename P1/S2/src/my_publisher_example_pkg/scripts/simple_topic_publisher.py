#! /usr/bin/env python



# So basically, what this code does is to initiate a node and create a publisher that keeps publishing into the /counter topic a sequence of consecutive integers. Summarizing:
# A publisher is a node that keeps publishing a message into a topic. So now... what's a topic?
# A topic is a channel that acts as a pipe, where other ROS nodes can either publish or read information. Let's now see some commands related to topics (some of them you've already used).


# Import the Python library for ROS
import rospy
# Import the Int32 message from the std_msgs package
from std_msgs.msg import Int32             


# Initiate a Node named 'topic_publisher'
rospy.init_node('topic_publisher')

# Create a Publisher object, that will publish on the /counter topic
# messages of type Int32
pub = rospy.Publisher('/counter', Int32, queue_size=1)    
                                           
# Set a publish rate of 2 Hz
rate = rospy.Rate(2)
# Create a variable of type Int32
count = Int32()
# Initialize 'count' variable
count.data = 0                             

# Create a loop that will go until someone stops the program execution
while not rospy.is_shutdown():
  # Publish the message within the 'count' variable
  pub.publish(count)
  # Increment 'count' variable
  count.data += 1
  # Make sure the publish rate maintains at 2 Hz
  rate.sleep()                             

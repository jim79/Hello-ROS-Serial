/*Hello ROS serial node running on Arduino*/

#include <Arduino.h>
#include <ros.h>
#include <std_msgs/String.h>


ros::NodeHandle nh; // instantiate a ROS node handle

std_msgs::String hello_msg;  // instantiate a message instance 'hello_msg' of type String  

// intantiate a ROS publisher with name "arduino_pub1" 
ros::Publisher welcome("arduino_pub1", &hello_msg); 

char message[11] = "Hello ROS!"; // string message to be pubished

void setup() {
  nh.initNode();       // intitialize the ROS node handle nh
  nh.advertise(welcome); // advertise the publishers 
}

void loop() {
  hello_msg.data = message;   
  welcome.publish(&hello_msg);  // publish the message
  nh.spinOnce();  
  delay(1000);
} 


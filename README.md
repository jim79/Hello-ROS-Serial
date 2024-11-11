# Hello ROS serial node running on Arduino 

### Equipment required
1. Arduino Uno or Nano  - 1 nos

### Summary of the experiment
We code a ROS publisher in C++ with the name ```arduino_pub1``` that publishes a string message "Hello ROS!". The code is then dumped into Arduino. Next we connect to Arduino via rosserial_arduino and echo on the terminal the message published by the publisher running on Arduino.

### Steps to code 
1. Include the required headers files ```Arduino.h```, ```ros.h```, ```std_msgs/String.h```
2. Instantiate a ROS node handle
3. Instantiate a message instance ```hello_msg``` of type String  
4. Instantiate a ROS publisher with name ```arduino_pub1```
5. Declare the string message to be published as a ```char``` array
6. Within the Arduino setup function : 
    - Intitialize the ROS node handle nh
    - Advertise the publishers 
7. Within the Arduino loop function : 
    - Publish the message
    - nh.spinOnce() to call all the callbacks waiting to be called at that point in time

### Steps to run the code
1. Launch roscore in a terminal 

```
roscore
```

2. In another terminal launch a rosserial connection with Arduino 

```
rosrun rosserial_arduino serial_node.py
```

3. Echo the topic published by Arduino in a terminal

```
rostopic echo /arduino_pub1 
```

### Additional Resources
- [Configure VS Code for rosserial_arduino](https://jim79.github.io/rosserial-arduino-vscode/)
- [Video tutorial - Configure VS Code for rosserial_arduino](https://youtu.be/RZAXBMoWJcE)
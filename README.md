<!-- # ROS_PKG_TEMPLATE
## AN EASY START FOR YOUR ROS_PKG!
## PREREQUISITE
- install ROS
- install mavros
## REMEMBER TO REMOVE .git BEFORE YOU PUBLISH YOUR OWN WORK! -->


# ROS_WRAPPER_VICON_SDK
## To use VICON SDK [here]()
This mini wrapper allows you to directly to use all functionalities defined in VICON SDK, and directly integrate it with you ROS project. You can easily define your own function under ```ViconMe.hpp```

## PREREQUISITE
- install ROS
- connect to VICON LAN
- set VICON SERVER IP_ADDR

## Do
1. first go to [here](/launch/access.launch) and [here](/launch/viconMe_SUBPUB_topics.yaml) to respectively change ```vicon_ip_addr``` and ```topic_name```
2. then run ```roslaunch ros_vicon_sdk access.launch```

3. go to [here](/src/include/ViconMe.hpp) to define your own functions, the code is pretty much explantory.
    - in this repo, a simple function to get all marker translation (in mm) is defined.
4. you can refer to [here](/Vicon_DataStream_SDK_Developer_s_Guide.pdf) for all ```SDK functions```.

## TO DO
- python version (we welcome pull request, as I'm too lazy to do so hehe)

## Maintainer
[pattylo](https://github.com/pattylo) @ AIRO-LAB @ RCUAS, HKPolyU


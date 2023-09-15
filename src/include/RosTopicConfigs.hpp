/*
    This file is part of ALan - the non-robocentric dynamic landing system for quadrotor

    ALan is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ALan is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ALan.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * \file RosTopicConfigs.h
 * \date 28/11/2022
 * \author pattylo
 * \copyright (c) AIRO-LAB, RCUAS of Hong Kong Polytechnic University
 * \brief classess to configure subscribe and publish topics
 */

#ifndef ROSTOPICCONFIGS_HPP
#define ROSTOPICCONFIGS_HPP

#include <ros/ros.h>
#include <iostream>

#define TOPICTYPE "TOPICTYPE"
#define TOPICNAME "TOPICNAME"
#define SUBORPUB "SUBORPUB"
#define SUB 0
#define PUB 1

#define CAMERA_SUB_TOPIC_A "CAMERA_SUB_TOPIC_A"
#define CAMERA_SUB_TOPIC_B "CAMERA_SUB_TOPIC_B"
#define CAMERA_SUB_TOPIC_C "CAMERA_SUB_TOPIC_C"
#define CAMERA_SUB_TOPIC_D "CAMERA_SUB_TOPIC_D"
#define CAMERA_SUB_TOPIC_E "CAMERA_SUB_TOPIC_E"
#define CAMERA_SUB_TOPIC_F "CAMERA_SUB_TOPIC_F"
#define CAMERA_SUB_TOPIC_G "CAMERA_SUB_TOPIC_G"
#define CAMERA_SUB_TOPIC_H "CAMERA_SUB_TOPIC_H"
#define CAMERA_SUB_TOPIC_I "CAMERA_SUB_TOPIC_I"
#define CAMERA_SUB_TOPIC_J "CAMERA_SUB_TOPIC_J"

#define IMAGE_PUB_TOPIC_A "IMAGE_PUB_TOPIC_A"
#define IMAGE_PUB_TOPIC_B "IMAGE_PUB_TOPIC_B"
#define IMAGE_PUB_TOPIC_C "IMAGE_PUB_TOPIC_C"
#define IMAGE_PUB_TOPIC_D "IMAGE_PUB_TOPIC_D"
#define IMAGE_PUB_TOPIC_E "IMAGE_PUB_TOPIC_R"
#define IMAGE_PUB_TOPIC_F "IMAGE_PUB_TOPIC_F"
#define IMAGE_PUB_TOPIC_G "IMAGE_PUB_TOPIC_G"
#define IMAGE_PUB_TOPIC_H "IMAGE_PUB_TOPIC_H"
#define IMAGE_PUB_TOPIC_I "IMAGE_PUB_TOPIC_I"
#define IMAGE_PUB_TOPIC_J "IMAGE_PUB_TOPIC_J"

#define POSE_SUB_TOPIC_A "POSE_SUB_TOPIC_A"
#define POSE_SUB_TOPIC_B "POSE_SUB_TOPIC_B"
#define POSE_SUB_TOPIC_C "POSE_SUB_TOPIC_C"
#define POSE_SUB_TOPIC_D "POSE_SUB_TOPIC_D"
#define POSE_SUB_TOPIC_E "POSE_SUB_TOPIC_E"
#define POSE_SUB_TOPIC_F "POSE_SUB_TOPIC_F"
#define POSE_SUB_TOPIC_G "POSE_SUB_TOPIC_G"
#define POSE_SUB_TOPIC_H "POSE_SUB_TOPIC_H"
#define POSE_SUB_TOPIC_I "POSE_SUB_TOPIC_I"
#define POSE_SUB_TOPIC_J "POSE_SUB_TOPIC_J"

#define POSE_PUB_TOPIC_A "POSE_PUB_TOPIC_A"
#define POSE_PUB_TOPIC_B "POSE_PUB_TOPIC_B"
#define POSE_PUB_TOPIC_C "POSE_PUB_TOPIC_C"
#define POSE_PUB_TOPIC_D "POSE_PUB_TOPIC_D"
#define POSE_PUB_TOPIC_E "POSE_PUB_TOPIC_E"
#define POSE_PUB_TOPIC_F "POSE_PUB_TOPIC_F"
#define POSE_PUB_TOPIC_G "POSE_PUB_TOPIC_G"
#define POSE_PUB_TOPIC_H "POSE_PUB_TOPIC_H"
#define POSE_PUB_TOPIC_I "POSE_PUB_TOPIC_I"
#define POSE_PUB_TOPIC_J "POSE_PUB_TOPIC_J"

#define TWIST_SUB_TOPIC_A "TWIST_SUB_TOPIC_A"
#define TWIST_SUB_TOPIC_B "TWIST_SUB_TOPIC_B"
#define TWIST_SUB_TOPIC_C "TWIST_SUB_TOPIC_C"
#define TWIST_SUB_TOPIC_D "TWIST_SUB_TOPIC_D"
#define TWIST_SUB_TOPIC_E "TWIST_SUB_TOPIC_E"
#define TWIST_SUB_TOPIC_F "TWIST_SUB_TOPIC_F"
#define TWIST_SUB_TOPIC_G "TWIST_SUB_TOPIC_G"
#define TWIST_SUB_TOPIC_H "TWIST_SUB_TOPIC_H"
#define TWIST_SUB_TOPIC_I "TWIST_SUB_TOPIC_I"
#define TWIST_SUB_TOPIC_J "TWIST_SUB_TOPIC_J"

#define TWIST_PUB_TOPIC_A "TWIST_PUB_TOPIC_A"
#define TWIST_PUB_TOPIC_B "TWIST_PUB_TOPIC_B"
#define TWIST_PUB_TOPIC_C "TWIST_PUB_TOPIC_C"
#define TWIST_PUB_TOPIC_D "TWIST_PUB_TOPIC_D"
#define TWIST_PUB_TOPIC_E "TWIST_PUB_TOPIC_E"
#define TWIST_PUB_TOPIC_F "TWIST_PUB_TOPIC_F"
#define TWIST_PUB_TOPIC_G "TWIST_PUB_TOPIC_G"
#define TWIST_PUB_TOPIC_H "TWIST_PUB_TOPIC_H"
#define TWIST_PUB_TOPIC_I "TWIST_PUB_TOPIC_I"
#define TWIST_PUB_TOPIC_J "TWIST_PUB_TOPIC_J"

#define IMU_SUB_TOPIC_A "IMU_SUB_TOPIC_A"
#define IMU_SUB_TOPIC_B "IMU_SUB_TOPIC_B"
#define IMU_SUB_TOPIC_C "IMU_SUB_TOPIC_C"
#define IMU_SUB_TOPIC_D "IMU_SUB_TOPIC_D"
#define IMU_SUB_TOPIC_E "IMU_SUB_TOPIC_E"
#define IMU_SUB_TOPIC_F "IMU_SUB_TOPIC_F"
#define IMU_SUB_TOPIC_G "IMU_SUB_TOPIC_G"
#define IMU_SUB_TOPIC_H "IMU_SUB_TOPIC_H"
#define IMU_SUB_TOPIC_I "IMU_SUB_TOPIC_I"
#define IMU_SUB_TOPIC_J "IMU_SUB_TOPIC_J"

#define IMU_PUB_TOPIC_A "IMU_PUB_TOPIC_A"
#define IMU_PUB_TOPIC_B "IMU_PUB_TOPIC_B"
#define IMU_PUB_TOPIC_C "IMU_PUB_TOPIC_C"
#define IMU_PUB_TOPIC_D "IMU_PUB_TOPIC_D"
#define IMU_PUB_TOPIC_E "IMU_PUB_TOPIC_E"
#define IMU_PUB_TOPIC_F "IMU_PUB_TOPIC_F"
#define IMU_PUB_TOPIC_G "IMU_PUB_TOPIC_G"
#define IMU_PUB_TOPIC_H "IMU_PUB_TOPIC_H"
#define IMU_PUB_TOPIC_I "IMU_PUB_TOPIC_I"
#define IMU_PUB_TOPIC_J "IMU_PUB_TOPIC_J"

#define ODOM_SUB_TOPIC_A "ODOM_SUB_TOPIC_A"
#define ODOM_SUB_TOPIC_B "ODOM_SUB_TOPIC_B"
#define ODOM_SUB_TOPIC_C "ODOM_SUB_TOPIC_C"
#define ODOM_SUB_TOPIC_D "ODOM_SUB_TOPIC_D"
#define ODOM_SUB_TOPIC_E "ODOM_SUB_TOPIC_E"
#define ODOM_SUB_TOPIC_F "ODOM_SUB_TOPIC_F"
#define ODOM_SUB_TOPIC_G "ODOM_SUB_TOPIC_G"
#define ODOM_SUB_TOPIC_H "ODOM_SUB_TOPIC_H"
#define ODOM_SUB_TOPIC_I "ODOM_SUB_TOPIC_I"
#define ODOM_SUB_TOPIC_J "ODOM_SUB_TOPIC_J"

#define ODOM_PUB_TOPIC_A "ODOM_PUB_TOPIC_A"
#define ODOM_PUB_TOPIC_B "ODOM_PUB_TOPIC_B"
#define ODOM_PUB_TOPIC_C "ODOM_PUB_TOPIC_C"
#define ODOM_PUB_TOPIC_D "ODOM_PUB_TOPIC_D"
#define ODOM_PUB_TOPIC_E "ODOM_PUB_TOPIC_E"
#define ODOM_PUB_TOPIC_F "ODOM_PUB_TOPIC_F"
#define ODOM_PUB_TOPIC_G "ODOM_PUB_TOPIC_G"
#define ODOM_PUB_TOPIC_H "ODOM_PUB_TOPIC_H"
#define ODOM_PUB_TOPIC_I "ODOM_PUB_TOPIC_I"
#define ODOM_PUB_TOPIC_J "ODOM_PUB_TOPIC_J"

#define CUSTOM_SUB_TOPIC_A "CUSTOM_SUB_TOPIC_A"
#define CUSTOM_SUB_TOPIC_B "CUSTOM_SUB_TOPIC_B"
#define CUSTOM_SUB_TOPIC_C "CUSTOM_SUB_TOPIC_C"
#define CUSTOM_SUB_TOPIC_D "CUSTOM_SUB_TOPIC_D"
#define CUSTOM_SUB_TOPIC_E "CUSTOM_SUB_TOPIC_E"
#define CUSTOM_SUB_TOPIC_F "CUSTOM_SUB_TOPIC_F"
#define CUSTOM_SUB_TOPIC_G "CUSTOM_SUB_TOPIC_G"
#define CUSTOM_SUB_TOPIC_H "CUSTOM_SUB_TOPIC_H"
#define CUSTOM_SUB_TOPIC_I "CUSTOM_SUB_TOPIC_I"
#define CUSTOM_SUB_TOPIC_J "CUSTOM_SUB_TOPIC_J"

#define CUSTOM_PUB_TOPIC_A "CUSTOM_PUB_TOPIC_A"
#define CUSTOM_PUB_TOPIC_B "CUSTOM_PUB_TOPIC_B"
#define CUSTOM_PUB_TOPIC_C "CUSTOM_PUB_TOPIC_C"
#define CUSTOM_PUB_TOPIC_D "CUSTOM_PUB_TOPIC_D"
#define CUSTOM_PUB_TOPIC_E "CUSTOM_PUB_TOPIC_E"
#define CUSTOM_PUB_TOPIC_F "CUSTOM_PUB_TOPIC_F"
#define CUSTOM_PUB_TOPIC_G "CUSTOM_PUB_TOPIC_G"
#define CUSTOM_PUB_TOPIC_H "CUSTOM_PUB_TOPIC_H"
#define CUSTOM_PUB_TOPIC_I "CUSTOM_PUB_TOPIC_I"
#define CUSTOM_PUB_TOPIC_J "CUSTOM_PUB_TOPIC_J"

struct CONFIG_SETUP{
    std::string topictypes;
    std::string topicnames;
    int SUB_PUB;
};

class RosTopicConfigs
{
private:
    ros::NodeHandle nh;
    XmlRpc::XmlRpcValue TOPICLIST;

    void setupTOPICLIST();
    std::vector<CONFIG_SETUP> object_ConfigLIST;
    
    
public:
    RosTopicConfigs(ros::NodeHandle& _nh, std::string param_namespace);
    ~RosTopicConfigs();

    std::string getTopicName(std::string designated_name);
};


RosTopicConfigs::RosTopicConfigs(ros::NodeHandle& _nh, std::string param_namespace)
: nh(_nh)
{
    nh.getParam(param_namespace + "/TOPICLIST", TOPICLIST);

    setupTOPICLIST();
}

RosTopicConfigs::~RosTopicConfigs()
{
}

std::string RosTopicConfigs::getTopicName(std::string designated_types)
{
    std::string returnvalue;

    if(object_ConfigLIST.empty())
    {
        ROS_ERROR("PLEASE CHECK ROSLAUNCH .launch FILE...");
        ros::shutdown();
    }
    // cout<<"topic types: "<<designated_types<<endl;

    for(auto what : object_ConfigLIST)    
    {
        if(designated_types == what.topictypes)
            returnvalue = what.topicnames;
    }
        

    return returnvalue;
}

void RosTopicConfigs::setupTOPICLIST()
{
    CONFIG_SETUP config_setup_temp;
    std::string topic_type;

    for(int i = 0; i < TOPICLIST.size(); i++)
    {        
        // static_cast<std::std::string>(TOPICLIST[i][TOPICTYPE]).c_str();
        topic_type = static_cast<std::string>(TOPICLIST[i][TOPICTYPE]).c_str();
        static_cast<std::string>(TOPICLIST[i][TOPICNAME]).c_str();

        if(
            topic_type != CAMERA_SUB_TOPIC_A ||
            topic_type != CAMERA_SUB_TOPIC_B ||
            topic_type != CAMERA_SUB_TOPIC_C ||
            topic_type != CAMERA_SUB_TOPIC_D ||
            topic_type != CAMERA_SUB_TOPIC_E ||
            topic_type != CAMERA_SUB_TOPIC_F ||
            topic_type != CAMERA_SUB_TOPIC_G ||
            topic_type != CAMERA_SUB_TOPIC_H ||
            topic_type != CAMERA_SUB_TOPIC_I ||
            topic_type != CAMERA_SUB_TOPIC_J ||

            topic_type != IMAGE_PUB_TOPIC_A ||
            topic_type != IMAGE_PUB_TOPIC_B ||
            topic_type != IMAGE_PUB_TOPIC_C ||
            topic_type != IMAGE_PUB_TOPIC_D ||
            topic_type != IMAGE_PUB_TOPIC_E ||
            topic_type != IMAGE_PUB_TOPIC_F ||
            topic_type != IMAGE_PUB_TOPIC_G ||
            topic_type != IMAGE_PUB_TOPIC_H ||
            topic_type != IMAGE_PUB_TOPIC_I ||
            topic_type != IMAGE_PUB_TOPIC_J ||

            topic_type != POSE_SUB_TOPIC_A ||
            topic_type != POSE_SUB_TOPIC_B ||
            topic_type != POSE_SUB_TOPIC_C ||
            topic_type != POSE_SUB_TOPIC_D ||
            topic_type != POSE_SUB_TOPIC_E ||
            topic_type != POSE_SUB_TOPIC_F ||
            topic_type != POSE_SUB_TOPIC_G ||
            topic_type != POSE_SUB_TOPIC_H ||
            topic_type != POSE_SUB_TOPIC_I ||
            topic_type != POSE_SUB_TOPIC_J ||

            topic_type != POSE_PUB_TOPIC_A ||
            topic_type != POSE_PUB_TOPIC_B ||
            topic_type != POSE_PUB_TOPIC_C ||
            topic_type != POSE_PUB_TOPIC_D ||
            topic_type != POSE_PUB_TOPIC_E ||
            topic_type != POSE_PUB_TOPIC_F ||
            topic_type != POSE_PUB_TOPIC_G ||
            topic_type != POSE_PUB_TOPIC_H ||
            topic_type != POSE_PUB_TOPIC_I ||
            topic_type != POSE_PUB_TOPIC_J ||

            topic_type != TWIST_SUB_TOPIC_A ||
            topic_type != TWIST_SUB_TOPIC_B ||
            topic_type != TWIST_SUB_TOPIC_C ||
            topic_type != TWIST_SUB_TOPIC_D ||
            topic_type != TWIST_SUB_TOPIC_E ||
            topic_type != TWIST_SUB_TOPIC_F ||
            topic_type != TWIST_SUB_TOPIC_G ||
            topic_type != TWIST_SUB_TOPIC_H ||
            topic_type != TWIST_SUB_TOPIC_I ||
            topic_type != TWIST_SUB_TOPIC_J ||

            topic_type != TWIST_PUB_TOPIC_A ||
            topic_type != TWIST_PUB_TOPIC_B ||
            topic_type != TWIST_PUB_TOPIC_C ||
            topic_type != TWIST_PUB_TOPIC_D ||
            topic_type != TWIST_PUB_TOPIC_E ||
            topic_type != TWIST_PUB_TOPIC_F ||
            topic_type != TWIST_PUB_TOPIC_G ||
            topic_type != TWIST_PUB_TOPIC_H ||
            topic_type != TWIST_PUB_TOPIC_I ||
            topic_type != TWIST_PUB_TOPIC_J ||

            topic_type != IMU_SUB_TOPIC_A ||
            topic_type != IMU_SUB_TOPIC_B ||
            topic_type != IMU_SUB_TOPIC_C ||
            topic_type != IMU_SUB_TOPIC_D ||
            topic_type != IMU_SUB_TOPIC_E ||
            topic_type != IMU_SUB_TOPIC_F ||
            topic_type != IMU_SUB_TOPIC_G ||
            topic_type != IMU_SUB_TOPIC_H ||
            topic_type != IMU_SUB_TOPIC_I ||
            topic_type != IMU_SUB_TOPIC_J ||

            topic_type != IMU_PUB_TOPIC_A ||
            topic_type != IMU_PUB_TOPIC_B ||
            topic_type != IMU_PUB_TOPIC_C ||
            topic_type != IMU_PUB_TOPIC_D ||
            topic_type != IMU_PUB_TOPIC_E ||
            topic_type != IMU_PUB_TOPIC_F ||
            topic_type != IMU_PUB_TOPIC_G ||
            topic_type != IMU_PUB_TOPIC_H ||
            topic_type != IMU_PUB_TOPIC_I ||
            topic_type != IMU_PUB_TOPIC_J ||

            topic_type != ODOM_SUB_TOPIC_A ||
            topic_type != ODOM_SUB_TOPIC_B ||
            topic_type != ODOM_SUB_TOPIC_C ||
            topic_type != ODOM_SUB_TOPIC_D ||
            topic_type != ODOM_SUB_TOPIC_E ||
            topic_type != ODOM_SUB_TOPIC_F ||
            topic_type != ODOM_SUB_TOPIC_G ||
            topic_type != ODOM_SUB_TOPIC_H ||
            topic_type != ODOM_SUB_TOPIC_I ||
            topic_type != ODOM_SUB_TOPIC_J ||

            topic_type != ODOM_PUB_TOPIC_A ||
            topic_type != ODOM_PUB_TOPIC_B ||
            topic_type != ODOM_PUB_TOPIC_C ||
            topic_type != ODOM_PUB_TOPIC_D ||
            topic_type != ODOM_PUB_TOPIC_E ||
            topic_type != ODOM_PUB_TOPIC_F ||
            topic_type != ODOM_PUB_TOPIC_G ||
            topic_type != ODOM_PUB_TOPIC_H ||
            topic_type != ODOM_PUB_TOPIC_I ||
            topic_type != ODOM_PUB_TOPIC_J ||

            topic_type != CUSTOM_SUB_TOPIC_A ||
            topic_type != CUSTOM_SUB_TOPIC_B ||
            topic_type != CUSTOM_SUB_TOPIC_C ||
            topic_type != CUSTOM_SUB_TOPIC_D ||
            topic_type != CUSTOM_SUB_TOPIC_E ||
            topic_type != CUSTOM_SUB_TOPIC_F ||
            topic_type != CUSTOM_SUB_TOPIC_G ||
            topic_type != CUSTOM_SUB_TOPIC_H ||
            topic_type != CUSTOM_SUB_TOPIC_I ||
            topic_type != CUSTOM_SUB_TOPIC_J ||

            topic_type != CUSTOM_PUB_TOPIC_A ||
            topic_type != CUSTOM_PUB_TOPIC_B ||
            topic_type != CUSTOM_PUB_TOPIC_C ||
            topic_type != CUSTOM_PUB_TOPIC_D ||
            topic_type != CUSTOM_PUB_TOPIC_E ||
            topic_type != CUSTOM_PUB_TOPIC_F ||
            topic_type != CUSTOM_PUB_TOPIC_G ||
            topic_type != CUSTOM_PUB_TOPIC_H ||
            topic_type != CUSTOM_PUB_TOPIC_I ||
            topic_type != CUSTOM_PUB_TOPIC_J                         
        )
        {
            config_setup_temp.topictypes = topic_type;
            config_setup_temp.topicnames = static_cast<std::string>(TOPICLIST[i][TOPICNAME]).c_str();
            config_setup_temp.SUB_PUB = TOPICLIST[i][SUBORPUB];

        }
        else
        {
            ROS_ERROR("PLEASE CHECK ROSPARAM .yaml FILE...");
            ros::shutdown();
        }    

        object_ConfigLIST.emplace_back(config_setup_temp);
    }
}

#endif
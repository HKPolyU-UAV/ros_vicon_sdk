/*
    This file is part of {software_name} - {software_description}

    {software_name} is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    {software_name} is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with {software_name}.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * \file ViconMe.hpp
 * \date 14/09/2023
 * \author pattylo
 * \copyright (c) AIRO-Lab, RCUAS of Hong Kong Polytechnic University
 * \brief Define your own function: A ROS Wrapper for using VICON SDK @ FJ005
 */

#include "ViconSDKRosWrapper.hpp"
#include "RosTopicConfigs.hpp"
#include "ros_vicon_sdk/PointArray.h"

namespace myViconFunction
{
    class ViconMe : private airoVICON::ViconSDKRosWrapper
    {
    private:
        ros::NodeHandle nh;
        ViconDataStreamSDK::CPP::Client client_obj;
        std::unique_ptr<RosTopicConfigs> rostopiconfig_ptr;
        ros::Timer pub_timer;
        
        void mainspin_callback(
          const ros::TimerEvent &e
        );
        void initPublisher();

        /*==== my design functionalities ====*/ 
        ros_vicon_sdk::PointArray led_posi_list;
        ros::Publisher led_list_posi_pub;

        bool get_led_position();

    public:
        ViconMe(ros::NodeHandle& _nh);
        ~ViconMe();
        
    };
}

myViconFunction::ViconMe::ViconMe(ros::NodeHandle& _nh)
: nh(_nh)
{
    bool connectSuccess = ViconInit(nh, client_obj);
    if(!connectSuccess)
    {
        ROS_ERROR("CONNECTION EVENTUALLY FAIL...EXIT!");
        ros::shutdown();
    }
    
    initPublisher();
    pub_timer = nh.createTimer(
        ros::Duration(0.04),
        &myViconFunction::ViconMe::mainspin_callback,
        this
    );
    
}

myViconFunction::ViconMe::~ViconMe()
{
    ROS_BLUE_STREAM("END CLASS of ViconMe");
}

void myViconFunction::ViconMe::mainspin_callback(const ros::TimerEvent &e)
{
    /*==== my design functionalities ====*/ 
    // call my functionalities here!
    bool success = get_led_position();

    /*==== my design functionalities ====*/ 

    
    // publish whatever you want
    if(success)
        led_list_posi_pub.publish(led_posi_list);

    // publisher0.publisher(obj0);
    // publisher1.publisher(obj1);
    // publisher2.publisher(obj2);
    // ...
}

/*========================= my design functionalities =========================*/ 

void myViconFunction::ViconMe::initPublisher()
// define what you want to publish
{
    // here RosTopicConfigs class is used to read rostopics from .yaml
    #define LED_LIST_POSITION_TOPIC CUSTOM_PUB_TOPIC_A
    rostopiconfig_ptr = std::make_unique<RosTopicConfigs>(nh, "/a_viconSDK_node");
    
    // define publisher here
    led_list_posi_pub = nh.advertise<ros_vicon_sdk::PointArray>(
        rostopiconfig_ptr->getTopicName(LED_LIST_POSITION_TOPIC), 
        1, 
        true
    );
    // ros::shutdown();
}

bool myViconFunction::ViconMe::get_led_position()
{
    int subjectcount = client_obj.GetSubjectCount().SubjectCount;

    led_posi_list.PointArray.clear();
    geometry_msgs::Point point_temp;

    if(client_obj.GetFrame().Result != 
        ViconDataStreamSDK::CPP::Result::Success
    )
    {
        ROS_WARN("GET FRAME FAILED!");
        return false;
    }

    int led_count = 0;

    for(int i = 0; i < subjectcount; i++)
    {
        std::string SubjectName = client_obj.GetSubjectName(i).SubjectName;

        if(!(SubjectName == "gh034_led"))
            continue;
        
        led_count = client_obj.GetMarkerCount( SubjectName ).MarkerCount;

        for(int j = 0; j < led_count; j++)
        {
            std::string MarkerName = client_obj.GetMarkerName(SubjectName, j).MarkerName;
            ViconDataStreamSDK::CPP::Output_GetMarkerGlobalTranslation LedMarkerTranslation =
                client_obj.GetMarkerGlobalTranslation( SubjectName, MarkerName );

            point_temp.x = LedMarkerTranslation.Translation[0];
            point_temp.y = LedMarkerTranslation.Translation[1];
            point_temp.z = LedMarkerTranslation.Translation[2];
            
            led_posi_list.PointArray.emplace_back(point_temp);
            // std::cout<<"hi"<<std::endl;
        }
    }

    return true;
}





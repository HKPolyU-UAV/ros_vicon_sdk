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
 * \file ViconSDKRosWrapper.hpp
 * \date 14/09/2023
 * \author pattylo
 * \copyright (c) AIRO-Lab, RCUAS of Hong Kong Polytechnic University
 * \brief A ROS Wrapper for using VICON SDK @ FJ005
 */

#include <ros/ros.h>
#include "essential.h"
#include "Vicon/CrossMarket/DataStream/ViconDataStreamSDK_CPP/DataStreamClient.h"

namespace airoVICON
{
    class ViconSDKRosWrapper
    {
    private:
        /* data */
        std::string vicon_ip_addr;
        inline std::string Adapt(const bool i_value);
        ViconDataStreamSDK::CPP::Client DirectClient;
    public:
        ViconSDKRosWrapper(/* args */);
        ~ViconSDKRosWrapper();
        bool ViconInit(
            ros::NodeHandle& _nh,
            ViconDataStreamSDK::CPP::Client& client_obj
        );
    };
}

airoVICON::ViconSDKRosWrapper::ViconSDKRosWrapper()
{

}

airoVICON::ViconSDKRosWrapper::~ViconSDKRosWrapper()
{
    ROS_YELLOW_STREAM("END ViconSdkROS");
}

bool airoVICON::ViconSDKRosWrapper::ViconInit(
    ros::NodeHandle& _nh,
    ViconDataStreamSDK::CPP::Client& client_obj
)
{
    _nh.getParam("vicon_ip_addr", vicon_ip_addr);

    int counter = 0;

    // const ViconDataStreamSDK::CPP::Output_Connect ConnectResult;

    while(!DirectClient.IsConnected().Connected)
    {
        // Direct connection
        std::string display_msg = "ATTEMPT TO CONNECT " + vicon_ip_addr;
        ROS_BLUE_STREAM(display_msg);
        DirectClient.Connect(vicon_ip_addr);
        counter++;

        if(counter > 100)
        {
            ROS_ERROR("CONNECTION TIMEOUT...EXIT");
            return false;
        }
    }
    const ViconDataStreamSDK::CPP::Output_Connect ConnectResult = DirectClient.Connect(vicon_ip_addr);
    const bool ok = (ConnectResult.Result == ViconDataStreamSDK::CPP::Result::Success );

    if(!ok)
    {
        switch (ConnectResult.Result)
        {
        case ViconDataStreamSDK::CPP::Result::ClientAlreadyConnected:
            ROS_YELLOW_STREAM("CLIENT ALREADY CONNECTED!");
            break;

        case ViconDataStreamSDK::CPP::Result::InvalidHostName:
            ROS_RED_STREAM("INVALID HOST NAME!");
            break;

        case ViconDataStreamSDK::CPP::Result::ClientConnectionFailed:
            ROS_RED_STREAM("Client Connection Failed");
            break;

        default:
            ROS_RED_STREAM("UNRECOGNIZED ERROR!");
            break;
        }
        return false;
    }
    else
    {
        ROS_GREEN_STREAM("CONNECTION SUCCESS!");
    }

    DirectClient.EnableSegmentData();
    DirectClient.EnableMarkerData();

    // Set the global up axis
    DirectClient.SetAxisMapping( 
        ViconDataStreamSDK::CPP::Direction::Forward, 
        ViconDataStreamSDK::CPP::Direction::Left,
        ViconDataStreamSDK::CPP::Direction::Up
    );     

    client_obj = DirectClient;

    counter = 0;
    while (
        client_obj.GetFrame().Result != 
        ViconDataStreamSDK::CPP::Result::Success
    )
    {
        /* code */
        ROS_BLUE_STREAM("GET FRAME ATTEMPT...");
        sleep(1);
        counter++;
        if(counter > 100)
        {
            ROS_ERROR("GETFRAME TIMEOUT...EXIT");
            return false;
        }
    }

    ROS_GREEN_STREAM("GETFRAME SUCCESS!");
    unsigned int SubjectCount = client_obj.GetSubjectCount().SubjectCount;
    std::string display_msg = "CURRENTLY YOU HAVE " 
        + std::to_string(SubjectCount)
        + " OBJECT(S)!";
    ROS_YELLOW_STREAM(display_msg);

    ROS_GREEN_STREAM("END VICON INIT!");

    return true;
}

std::string airoVICON::ViconSDKRosWrapper::Adapt(const bool i_value)
{
    return i_value ? "True" : "False";
}



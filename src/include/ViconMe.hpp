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

namespace myViconFunction
{
    class ViconMe : private airoVICON::ViconSDKRosWrapper
    {
    private:
    ros::NodeHandle nh;
        ViconDataStreamSDK::CPP::Client client_obj;
        void initPublisher();
    public:
        ViconMe(ros::NodeHandle& _nh);
        ~ViconMe();
        void init();
    };
}

myViconFunction::ViconMe::ViconMe(ros::NodeHandle& _nh)
: nh(_nh)
{
    bool connectSuccess = ViconInit(nh, client_obj);
}

myViconFunction::ViconMe::~ViconMe()
{
    ROS_BLUE_STREAM("END CLASS of ViconMe");
}

void myViconFunction::ViconMe::init()
{
    

}






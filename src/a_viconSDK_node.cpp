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
 * \file a_viconSDK_node.cpp
 * \date 15/09/2023
 * \author pattylo
 * \copyright (c) AIRO-Lab, RCUAS of Hong Kong Polytechnic University
 * \brief a viconSDK rosnode
 */

#include "include/ViconMe.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "VICON_ROS_WRAPPER");
    ros::NodeHandle nh("~");

    myViconFunction::ViconMe lala(nh);

    ros::spin();

    return 0;
}
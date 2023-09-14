/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

#include <ros/ros.h>
#include "include/Vicon/CrossMarket/DataStream/ViconDataStreamSDK_CPP/DataStreamClient.h"
  std::string MulticastAddress = "192.168.10.1";

std::string Adapt( const bool i_Value )
{
    return i_Value ? "True" : "False";
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "VICON_ROS_WRAPPER");
    ros::NodeHandle nh("~");

    ros::Timer mainspin_timer;


    using namespace ViconDataStreamSDK::CPP;
    
     // Make a new client
    ViconDataStreamSDK::CPP::Client DirectClient;

    if(true)
    {
        // Connect to a server
        std::string HostName = "192.168.10.1";
        std::cout << "Connecting to " << HostName << " ..." << std::endl;
        while ( !DirectClient.IsConnected().Connected )
        {
            // Direct connection

            const Output_Connect ConnectResult = DirectClient.Connect(HostName);
            const bool ok = (ConnectResult.Result == Result::Success );

            if ( !ok )
            {
                std::cout << "Warning - connect failed... ";
                switch (ConnectResult.Result)
                {
                case Result::ClientAlreadyConnected:
                  std::cout << "Client Already Connected" << std::endl;
                  break;
                case Result::InvalidHostName:
                  std::cout << "Invalid Host Name" << std::endl;
                  break;
                case Result::ClientConnectionFailed:
                  std::cout << "Client Connection Failed" << std::endl;
                  break;
                default:
                  std::cout << "Unrecognized Error: " << ConnectResult.Result << std::endl;
                  break;
                }
            }
            else
            {
                std::cout<<"SUCCESS"<<std::endl;
            }
        }
    }
    
    DirectClient.EnableSegmentData();
    DirectClient.EnableMarkerData();
   
    // Set the global up axis
    DirectClient.SetAxisMapping( Direction::Forward, 
                             Direction::Left, 
                             Direction::Up ); // Z-up
    
    ViconDataStreamSDK::CPP::Client & MyClient( DirectClient );
                  
    // Output_GetFrameRate Rate = MyClient.GetFrameRate();


    std::cout << "Waiting for new frame..."<<std::endl;
    while( MyClient.GetFrame().Result != Result::Success )
    {
      // Sleep a little so that we don't lumber the CPU with a busy poll
      #ifdef WIN32
        Sleep( 200 );
      #else
        sleep(1);
      #endif

      std::cout << ".";
    }

    unsigned int SubjectCount = MyClient.GetSubjectCount().SubjectCount;
    std::cout<<SubjectCount<<std::endl;

    for( unsigned int SubjectIndex = 0 ; SubjectIndex < SubjectCount ; ++SubjectIndex )
    {
        // Get the subject name
        std::string SubjectName = MyClient.GetSubjectName( SubjectIndex ).SubjectName;
        std::cout << "    Name: " << SubjectName << std::endl;

          // Count the number of markers
            unsigned int MarkerCount = MyClient.GetMarkerCount( SubjectName ).MarkerCount;
            std::cout << "    Markers (" << MarkerCount << "):" << std::endl;
            
            for( unsigned int MarkerIndex = 0 ; MarkerIndex < MarkerCount ; ++MarkerIndex )
            {
              // Get the marker name
              std::string MarkerName = MyClient.GetMarkerName( SubjectName, MarkerIndex ).MarkerName;

              // Get the marker parent
              std::string MarkerParentName = MyClient.GetMarkerParentName( SubjectName, MarkerName ).SegmentName;

              // Get the global marker translation
              Output_GetMarkerGlobalTranslation _Output_GetMarkerGlobalTranslation =
                MyClient.GetMarkerGlobalTranslation( SubjectName, MarkerName );

              std::cout << "      Marker #" << MarkerIndex            << ": "
                                            << MarkerName             << " ("
                                            << _Output_GetMarkerGlobalTranslation.Translation[ 0 ]  << ", "
                                            << _Output_GetMarkerGlobalTranslation.Translation[ 1 ]  << ", "
                                            << _Output_GetMarkerGlobalTranslation.Translation[ 2 ]  << ") "
                                            << Adapt( _Output_GetMarkerGlobalTranslation.Occluded ) << std::endl;

              
            }

    }

    std::cout<<"gan gan"<<std::endl;
  
    
}
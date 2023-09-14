cmake_minimum_required(VERSION 3.0.2)
project(airo_template)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  mavros_msgs
  roscpp
  std_msgs
  image_transport
  sensor_msgs
  message_generation
  genmsg
  visualization_msgs
  rospy

)

catkin_python_setup()

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES offb
  CATKIN_DEPENDS rospy geometry_msgs mavros_msgs roscpp std_msgs message_generation
#  DEPENDS system_lib
)

find_package(Boost COMPONENTS system filesystem REQUIRED)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}

)

catkin_install_python(PROGRAMS 
  scripts/null.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

include_directories(
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket
)

find_package(Boost 1.5 COMPONENTS system thread REQUIRED)

add_library(ViconDataStreamSDK_CPP STATIC
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconDataStreamSDKCore/CoreClient.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconDataStreamSDKCore/CoreClientTimingLog.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconDataStreamSDKCoreUtils/ClientUtils.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconDataStreamSDKCoreUtils/AxisMapping.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconDataStreamSDKCore/WirelessConfiguration.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconCGStreamClientSDK/CGClient.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconCGStreamClient/ViconCGStreamClient.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconCGStreamClient/CGStreamReaderWriter.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconCGStreamClient/ViconCGStreamBayer.cpp
  ${PROJECT_SOURCE_DIR}/src/include/Vicon/CrossMarket/DataStream/ViconDataStreamSDK_CPP/DataStreamClient.cpp
)

target_link_libraries(ViconDataStreamSDK_CPP
  PRIVATE
    Boost::system
    Boost::thread
    Threads::Threads
)

target_include_directories(ViconDataStreamSDK_CPP PUBLIC
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Vicon/CrossMarket/DataStream/ViconDataStreamSDK_CPP>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>"
)

target_compile_definitions(ViconDataStreamSDK_CPP PRIVATE "_BUILD_STATIC_LIB")


add_executable(a_viconSDK_node
    src/a_viconSDK_node.cpp
    
)
# target_include_directories(a_viconSDK_node PUBLIC 
# ${PROJECT_SOURCE_DIR}/src/include/Vicon/)

target_link_libraries(a_viconSDK_node
  ${catkin_LIBRARIES} 
  ViconDataStreamSDK_CPP
)


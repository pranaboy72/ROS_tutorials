cmake_minimum_required(VERSION 3.0.2)
project(ros_tutorials)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  roscpp
  std_msgs
)

##########Your code here#############
####### 메세지 파일(.msg) 파일, 의존성 추가
######################################
add_message_files(FILES TurtleMsg.msg)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ros_tutorials
  CATKIN_DEPENDS geometry_msgs message_generation roscpp std_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

##########Your code here#############
#executable, target_link_libraries, dependencies 추가 #
#####################################
add_executable(cm_publisher src/circular_motion_publisher.cpp)
add_dependencies(cm_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(cm_publisher ${catkin_LIBRARIES})

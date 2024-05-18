cmake_minimum_required(VERSION 3.0.2)
project(msg_topics_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

# Generate messages in the 'msg' folder
add_message_files(
  FILES
  Person.msg
)


# Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  #  INCLUDE_DIRS include
  #  LIBRARIES topic
      CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
  #  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(include  ${catkin_INCLUDE_DIRS})


## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
add_executable(msg_talker src/talker.cpp)
target_link_libraries(msg_talker ${catkin_LIBRARIES})
# add_dependencies(talker beginner_tutorials_generate_messages_cpp)

add_executable(msg_listener src/listener.cpp)
target_link_libraries(msg_listener ${catkin_LIBRARIES})
# add_dependencies(listener beginner_tutorials_generate_messages_cpp)
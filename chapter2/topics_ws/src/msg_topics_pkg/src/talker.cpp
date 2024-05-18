#include "chapter2/topics_ws/devel/include/msg_topics_pkg/Person.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker"); // Node
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<msg_topics_pkg::Person>("chatter", 1000);

    ros::Rate loop_rate(10);
    int count = 0;
    while (ros::ok())
    {

        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str()); // debug
        pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}
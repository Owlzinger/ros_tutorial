#include "msg_topics_pkg/Person.h"
#include "ros/ros.h"

#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker"); // Node
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<msg_topics_pkg::Person>("chatter", 1000);
    msg_topics_pkg::Person p;
    p.name = "Shaw";
    p.age = 26;
    p.height = 1.86;

    ros::Rate loop_rate(1);
    int count = 0;
    while (ros::ok())
    {
        pub.publish(p);
        p.age += 1;
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Name: " << p.name << " Age: " << p.age << " Height: " << p.height;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str()); // debug

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}
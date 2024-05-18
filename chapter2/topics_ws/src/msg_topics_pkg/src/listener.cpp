#include "msg_topics_pkg/Person.h"
#include "ros/ros.h"

void Callback(const msg_topics_pkg::Person::ConstPtr &person_p)
{
    ROS_INFO("info come in:%s, %d, %.2f", person_p->name.c_str(), person_p->age, person_p->height);
}

int main(int argc, char *argv[])
{

    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe<msg_topics_pkg::Person>("chatter", 10, Callback);

    // 4.回调函数中处理 person

    ros::spin();
    return 0;
}

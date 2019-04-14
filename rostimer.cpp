#include <ros/ros.h>
#include <std_msgs/Int32.h>
//#include "boost/bind.hpp"

//roscpp
void callback1(const ros::TimerEvent& ){
    static ros::Time start = ros::Time::now();
    //std_msgs::Int32  ii;
    //ii.data = 1000000;
    //MyPub.publish(ii);
    ROS_INFO("callback 1 triggered");
    ros::Time end =ros::Time::now();
    ROS_INFO("___%f",(end.toSec() - start.toSec()));
    start = end;
}

/*void callback2(const ros::TimerEvent& ){
    ROS_INFO("callback 2 trigered");
}*/
 int main(int argc, char *argv[])
{
    ros::init(argc, argv, "roscpp_rostime");
    ros::NodeHandle nh;
    ros::Publisher MyPub = nh.advertise<std_msgs::Int32>("/pub",50000);
    ros::Timer timer1 = nh.createTimer(ros::Duration(0.001),callback1);
    //ros::Timer timer2 = nh.createTimer(ros::Duration(3),callback2);

    ros::spin();
    return 0;
}

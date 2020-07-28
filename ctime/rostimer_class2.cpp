#include "ros/ros.h"
#include <std_msgs/Float32.h>
#include <thread>


class myTimer{
public:
    myTimer(){
        pub = nh.advertise<std_msgs::Float32>("/pub",10000);
        t1 = nh.createTimer(ros::Duration(0.001),&myTimer::callback,this);

        //t2 = nh.createTimer(ros::Duration(1),&myTimer::callback2,this);
    }
    ~myTimer(){}
    void callback(const ros::TimerEvent& ev){
        static ros::Time start = ros::Time::now();
        ROS_INFO("callback 1 triggered");
        std_msgs::Float32  ii;
        ii.data = 1000000.0000;
        pub.publish(ii);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        ros::Time end =ros::Time::now();
        ROS_INFO("___%f",(end.toSec() - start.toSec()));
        start = end;
    }
    void callback2(const ros::TimerEvent& ev){
        ROS_INFO("++1 s callback trigered! ");
    }
private:
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Timer t1;
    //ros::Timer t2;
};

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"myTimer_class");
    //ros::Time begin = ros::Time::now();//获得当前系统时间，1970-1-1
    myTimer mt;
    ros::spin();
    return 0;
}

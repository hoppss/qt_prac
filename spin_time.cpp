#include "ros/ros.h"
#include <std_msgs/Float32.h>
#include <sensor_msgs/JointState.h>
#include <thread>
#include <geometry_msgs/Twist.h>


using namespace std;

class spin_test{
public:
    spin_test(){
        pub_ = node.advertise<std_msgs::Float32>("pub",1000);
        sub_ = node.subscribe("/joint_states",100,&spin_test::cb,this);
        ros::Rate r(1);
        while(ros::ok()){
            ROS_INFO("             cycle start");
            //process();
            ROS_INFO("Start SPIN___");
            ros::spinOnce();
            ROS_INFO("After SPIN___");
            ROS_INFO("+++before sleeo");
            r.sleep();
            ROS_INFO("+++After sleep");
            ROS_INFO("             cycle stop");
        }
    }

    void cb(const sensor_msgs::JointState::ConstPtr msg){
        ROS_INFO("__IN__CB__");
        myMsg_ = *msg;
        this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    void process(){
        ROS_INFO("cycle");
    }


    
private:
    ros::NodeHandle node;
    ros::Publisher pub_;
    ros::Subscriber sub_;
    sensor_msgs::JointState myMsg_;
    
};


int main(int argc,char** argv)
{
    ros::init(argc,argv,"spin_once_test");
    spin_test sp;

    return 0;


/*
[ INFO] [1552726015.607727237]:              cycle start
[ INFO] [1552726015.607772062]: cycle
[ INFO] [1552726015.607822370]: Start SPIN___
[ INFO] [1552726015.607913635]: __IN__CB__
[ INFO] [1552726016.108262558]: After SPIN___
[ INFO] [1552726016.108375500]: +++before sleeo
[ INFO] [1552726016.607401979]: +++After sleep
[ INFO] [1552726016.607505210]:              cycle stop
*/    
}
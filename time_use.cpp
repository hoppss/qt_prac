#include "ros/ros.h"
#include <thread>
#include <chrono>
#include "iostream"
using namespace std;

class mytime{
public:
    ros::Duration getTime(){
        time1 = ros::Time::now();
        cout << "Now 2 toSec " << time1.toSec() << endl; //1.54288e+09
        cout << time1 << endl;
        this_thread::sleep_for(std::chrono::seconds(1));
        time2 = ros::Time::now();

        time3 = ros::Time(0);

        cout << time2 << endl;
        cout << "Time(0)" << time3 << endl;

        ros::Duration temp = time2 -time1;
        cout << "time2 - time1 is " << temp<< endl;  //1.000247462
        cout << "time2 - time1 is " << temp.sec << endl; //1
        cout << "time2 - time1 is " << temp.nsec << endl; //247462
        cout << "time2 - time1 is " << temp.isZero()<< endl; //0
        cout << "time2 - time1 is " << temp.toSec()<< endl;  //1.00025

       //延时
       ros::Duration r(5);
       r.sleep();
       cout << " delay 5 sec " << endl;


        return temp;
    }
    // ros::Duration two_hours = ros::Duration(60*60) + ros::Duration(60*60);
    // ros::Duration one_hour = ros::Duration(2*60*60) - ros::Duration(60*60);
    // ros::Time tomorrow = ros::Time::now() + ros::Duration(24*60*60);
    // ros::Duration negative_one_day = ros::Time::now() - tomorrow;


private:
ros::NodeHandle nh;
ros::Time time1;
ros::Time time2;
ros::Time time3;
};

int main(int argc,char** argv)
{
    ros::init(argc, argv, "ros_time_use");
    mytime mt;
    mt.getTime();


    return 0;

}
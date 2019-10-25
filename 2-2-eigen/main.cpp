#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <cmath>
using namespace std;
using namespace Eigen;


int main()
{
    Matrix4f t1;
    t1 << 1,0,0,10,\
          0,1,0,0,\
          0,0,1,0,\
          0,0,0,1;

    cout << t1 << endl;

    Matrix4f t2;
    t2 << 1,0,0,0,\
          0,1,0,5,\
          0,0,1,0,\
          0,0,0,1;

    Matrix4f rx30;
    rx30 << cos(30.0/180.0*M_PI),-sin(30.0/180.0*M_PI),0,0,\
            sin(30.0/180.0*M_PI),cos(30.0/180.0*M_PI),0,0,\
            0,0,1,0,\
            0,0,0,1;
    cout << rx30 << endl;
    cout << "transpose\n";
    cout << rx30.transpose() << endl;
    cout << "inverse\n";
    cout << rx30.inverse() << endl;

    Vector4f  p(3,7,0,1);
    cout << t1 * t2 * rx30  << endl;
    cout << "vec.data() ?? " << p.data() << endl; //pointer
    cout << "vec.data() ?? " << *(p.data()+1) << endl; //pointer

    //4.27 Eigen::AngleAxis
    Vector3f  yy = Vector3f::UnitY();
    cout << "unity " << yy << endl;  // 0;1;0;

    AngleAxis<double> aa =AngleAxis<double>(M_PI / 6.0, Vector3d::UnitY());// transfrom matrix; axis:y; angle:30
    cout << "aa.matrix " << aa.matrix() << endl;
    cout << "aa.matrix " << aa.Dim << endl;//3
    cout << "aa.matrix " << aa.angle() << endl; //0.523599
    cout << "aa.matrix " << aa.axis() << endl;  //0;1;0

    cout << "aa.identity " << aa.Identity << endl;

    Eigen::Matrix4f xx =  Eigen::Matrix4f::Identity();
    cout << "Identity instance " << endl << xx << endl; // unit y matrix;

    //____atan2(double y, double x) ,return (-pi, +pi]
    cout << "atan2 " << atan2(1,1) << endl; //0.785398


    return 0;
}

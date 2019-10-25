#include <iostream>
#include <Eigen/Geometry>//Transform, Translation, Angle-Axis,Quatenion, Affine3f, Rotation2d
#include <Eigen/Dense>  //matrix , vector
#include <Eigen/Core>


//https://blog.csdn.net/yang__jing/article/details/82316093

using namespace Eigen;
using namespace std;

int main()
{
    cout << "2d rot" << endl;
    Rotation2D<float> rot2(M_PI/3);   //1.0472 - 60
    cout << "2d rot angles " << rot2.angle() << endl; //1.0472
    cout << "2d rot matrix " << rot2.matrix() << endl;
//    0.5            -0.866025
//     0.866025       0.5

    cout << "3d rot  -- angle-axis" << endl;
    AngleAxis<float> aa(M_PI/3, Vector3f(1,0,0));//1.0472 - 60 , x axis
    cout << "3d rot angles " << aa.angle() << endl; //1.0472
    cout << "3d rot matrix " << aa.matrix() << endl;
    cout << "3d rot axis "  << aa.axis() << endl;
//            1         0         0
//            0       0.5 -0.866025
//            0  0.866025       0.5

    cout << "3d rot  -- angle-axis 2 " << endl;
    AngleAxis<float> aa2(M_PI/3, Vector3f::UnitX());//1.0472 - 60 , x axis
    cout << "3d rot angles " << aa2.angle() << endl; //1.0472
    cout << "3d rot matrix 1(3*3): " << endl  << aa2.matrix() << endl;
//            1         0         0
//            0       0.5 -0.866025
//            0  0.866025       0.5
    cout << "3d rot matrix 2(3*3): " << endl  << aa2.toRotationMatrix() << endl;
    //cout << "3d rot matrix to quatenion " << aa2.matrix().w()<< " " << aa2.matrix().x() << endl;
    cout << "3d rot matrix to rpy(ZYX) " << aa2.matrix().eulerAngles(2,1,0) << endl;
//    0
//        -0
//    1.0472

    cout << endl;



    cout << "3d rot  -- quaternion " << endl;
    cout << "x y z = x y z * sin(@/2)  w = cos(@/2)" << endl;
    Quaternion<float> q;
    q = AngleAxis<float>(M_PI/3, Vector3f::UnitX());
    cout << "output quatenion 1: " << endl << q.coeffs() << endl; // x; y; z ; w colomn vector
    cout << "output quatenion 2: " << endl <<  q.w() << " "<< q.x() << " "<< q.y() << " "<< q.z() << endl; //0.866025 0.5 0 0
    cout << "3d rot angles " << q.vec() << endl;
//    0.5
//    0
//    0
    cout << "3d rot matrix " << q.matrix() << endl;
//            1         0         0
//           0       0.5 -0.866025
//           0  0.866025       0.5
    cout << "quatenino norm " << q.norm() << endl; // 1




    cout << endl << "euler angle: rot 45 along z axis " << endl;
    Eigen::Vector3d euler_angle = Eigen::Vector3d(M_PI/4,0,0);// ZYX sequence,it is rpy
    cout << "euler: yaw pitch roll " << euler_angle.transpose() << endl;
    cout << "euler init" << endl;
    //Eigen::Vector3d eulerAngle(yaw,pitch,roll);
    Eigen::Vector3d eulerAngle(0,0,45);
    cout << "euler to angle-axis" << endl;

    Eigen::AngleAxisd rollAngle(AngleAxisd(eulerAngle(2),Vector3d::UnitX()));
    Eigen::AngleAxisd pitchAngle(AngleAxisd(eulerAngle(1),Vector3d::UnitY()));
    Eigen::AngleAxisd yawAngle(AngleAxisd(eulerAngle(0),Vector3d::UnitZ()));

    Eigen::AngleAxisd rotation_vector;
    rotation_vector=yawAngle*pitchAngle*rollAngle;



    cout << "scalling " << endl;
//    Scaling(2,1)
//    Scaling(2,1,1)
//    Scaling(2)
//    Scaling(Vector3d(2,1,1))


    //https://eigen.tuxfamily.org/dox/group__TutorialGeometry.html
    cout << "translations" << endl;
//    Translation<float,2>(tx, ty)
//    Translation<float,3>(tx, ty, tz)
//    Translation<float,N>(s)
//    Translation<float,N>(vecN)
    Translation<float,3> t(Vector3f(1,2,3));
    cout <<"x: " <<  t.x() << "y: " << t.y() << "z: " << t.z() << endl; // 1 2 3
    cout <<"t.dim " << t.Dim << "t.vector:  " << t.vector() << "t.matirx "\
        << t.translation() << endl;  // dim: 3 vector: 1;2;3;
    //t.translation 1;2;3

    cout << "Transform" << endl;
    //Affine: the transformation is stored as a (Dim+1)^2 matrix, where the last row is assumed to be [0 ... 0 1].
    //typedef Transform<float,3,Affine> Eigen::Affine3f

    Affine3f itsaff(Translation3f(Vector3f(1,2,3)));  // cannot use == to initialize
    cout << "tranlation matrix: " << itsaff.matrix() << endl;
//   1 0 0 1
//   0 1 0 2
//   0 0 1 3
//   0 0 0 1
    Affine3f itsaff2(aa);
    cout << "rot matix " << itsaff2.matrix() << endl;
//           1         0         0         0
//           0       0.5 -0.866025         0
//           0  0.866025       0.5         0
//           0         0         0         1

    cout << "concatenation result is also Transform object" << endl;
    //cout << (itsaff * itsaff2).matrix() << endl;
    cout << (itsaff2 * itsaff).matrix() << endl;
//            1         0         0         1
//            0       0.5 -0.866025         2
//            0  0.866025       0.5         3
//            0         0         0         1

//            1         0         0         1
//            0       0.5 -0.866025  -1.59808
//            0  0.866025       0.5   3.23205
//            0         0         0         1



    itsaff2.setIdentity();
    cout << "after setIdentity " << endl << itsaff2.matrix() << endl;  // diag elem is 1;

    Affine3f itsaff3(Affine3f::Identity());  //diag elem is all 1
    cout << itsaff3.matrix() << endl;
//    1 0 0 0
//    0 1 0 0
//    0 0 1 0
//    0 0 0 1
//Affine3d  alias Transform<float,3,Affine>
//Affine3f  alias Transform<double,3,Affine>


    //homogeneous
    Vector3d v = Vector3d::Random();
    cout << v << endl;
    cout << v.homogeneous() << endl;
    cout << v.transpose() << endl;

//    Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>;
//    typedef Matrix<float, 4, 4> Matrix4f;
//    typedef Matrix<double,4, 4> Matrix4d;
//    typedef Matrix<float, 3, 1> Vector3f;
//    typedef Matrix<int, 1, 2> RowVector2i;
//    typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
//    typedef Matrix<int, Dynamic, 1> VectorXi;

    cout << "translation " << endl;
    //Eigen::Translation3f translation(x,y,z);
    Eigen::Translation3f translation(1,2,3);
    cout << "translation vec " << endl << translation.vector() << endl;

    //
    Eigen::Matrix3d mm;
    mm << 0,0,1,0,-1,0,1,0,0;  // from rocky xyz coordiate to default mobilerobot coordinate;
    cout << endl << mm << endl;
    cout << "3d rot matrix to rpy(ZYX) " << mm.matrix().eulerAngles(2,1,0) << endl;
    //first is r(x), third is y(z);  rpy !! check?

    //0
    //-1.5708
    //3.14159


    AngleAxisd az = Eigen::AngleAxisd(M_PI,Vector3d::UnitZ() );
    AngleAxisd ay = Eigen::AngleAxisd(-M_PI/2,Vector3d::UnitY());
    AngleAxisd ax = Eigen::AngleAxisd(0,Vector3d::UnitX());

    cout << az.matrix() * ay.matrix() * ax.matrix() << endl;
//    -6.12323e-17 -1.22465e-16            1
//      7.4988e-33           -1 -1.22465e-16
//               1            0  6.12323e-17


    AngleAxisd aaz = Eigen::AngleAxisd(0,Vector3d::UnitZ() );
    AngleAxisd aay = Eigen::AngleAxisd(-M_PI/2,Vector3d::UnitY());
    AngleAxisd aax = Eigen::AngleAxisd(M_PI,Vector3d::UnitX());

    cout << aaz.matrix() * aay.matrix() * aaz.matrix() << endl;
//    6.12323e-17           0          -1
//              0           1           0
//              1           0 6.12323e-17


    //Eigen::Quaterniond qq(0,0.70710677,0,0.70710677);//(w,x,y,z);
    Eigen::Quaterniond qq(0.390136776492,-1.62119138427,-0.124619001523,-1.52160633355);//(w,x,y,z);

    cout << "\n what \n" << qq.matrix()/*.eulerAngles(2,1,0) */<< endl;

    return 0;
}

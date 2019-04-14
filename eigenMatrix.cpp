#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <ctime>

using namespace std;
int main(){
    Eigen::Matrix<float,2,3> matrix23;
    Eigen::Vector3d v_3d;
    Eigen::Matrix3d matrix3 = Eigen::Matrix3d::Zero();


    matrix23 << 1 ,2 ,3,4, 5,6;
    cout << "matrix23 " << endl;

    for(int i = 0; i< 1; i++){
        for(int j = 0; j< 2;j++){
            cout << matrix23(i,j) << endl;
        }
    }

    v_3d << 3,2,1;
    cout << "v_3d" << v_3d << endl;


    //矩阵matrix 相乘
    Eigen::Matrix<double,2,1> mu = matrix23.cast<double>() * v_3d ;
    cout << mu << endl;

    matrix3 = Eigen::Matrix3d::Random();
    cout << "matrix3" << matrix3  << endl ;

    cout << "matrix3 tranpose" << matrix3.transpose() << endl;

    cout << "matrix3 sum " << matrix3.sum() << endl;

    cout << "matrix3 trace " << matrix3.trace() << endl;

    cout << "10 * matrix3"  << matrix3 * 10 << endl;

    cout << "matrix inverse" << matrix3.inverse() << endl;

    cout << "matrix determinant 行列式" << matrix3.determinant() << endl;


}

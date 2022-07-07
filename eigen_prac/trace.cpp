#include <iostream>
#include <string>
#include <eigen3/Eigen/Eigen>
#include "math.h"

using namespace std;
using namespace Eigen;



int main(){
    Eigen::AngleAxisf rotz = Eigen::AngleAxisf(45.0 / 180 * M_PI, Eigen::Vector3f::UnitZ());
    cout << rotz.matrix() << endl; // 3X 3 T
    cout << rotz.toRotationMatrix() << endl; //same as above
    //Eigen::EigenSolver<MatrixXd> solver(rotz.toRotationMatrix());

    Eigen::EigenSolver<Matrix3f> solver(rotz.matrix());

    Eigen::MatrixXcf  eigen_value = solver.eigenvalues();   //must be Xcf, might be complex
    Eigen::MatrixXcf  eigen_vectors = solver.eigenvectors();

    Eigen::MatrixXf   eigen_values_real = eigen_value.real();
    Eigen::MatrixXf   eigen_vectors_real = eigen_vectors.real(); // (real, complex)
    cout << "eigen_values: " << std::endl << eigen_values_real.transpose() << endl;  //0.707107 0.707107        1
    cout << "eigen_vectors: " << std::endl << eigen_vectors_real << endl;


    cout << "eigen_vectors: " << std::endl << rotz.matrix().trace() << std::endl;
    std::cout << solver.eigenvalues();

}

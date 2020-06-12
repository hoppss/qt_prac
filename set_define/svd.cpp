#include <iostream>
#include <eigen3/Eigen/Eigen>


using namespace std;
using namespace Eigen;

int main(){
    Matrix3f A;
    A(0,0)=1,A(0,1)=0,A(0,2)=1;
    A(1,0)=0,A(1,1)=1,A(1,2)=1;
    A(2,0)=0,A(2,1)=0,A(2,2)=0;

    JacobiSVD<Eigen::MatrixXf> svd(A, ComputeThinU | ComputeThinV );
    Matrix3f V = svd.matrixV(), U = svd.matrixU();
    Matrix3f  S = U.inverse() * A * V.transpose().inverse(); // S = U^-1 * A * VT * -1
    std::cout<<"A :\n"<<A<<std::endl;
    std::cout<<"U :\n"<<U<<std::endl;
    std::cout<<"S :\n"<<S<<std::endl;
    std::cout<<"V :\n"<<V<<std::endl;
    std::cout<<"U * S * VT :\n"<<U * S * V.transpose()<<std::endl;
    system("pause");

    return 0;
}

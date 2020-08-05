#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <string>


using namespace std;
using namespace Eigen;




int main(){
    MatrixXd m = MatrixXd::Ones(2,2);
    std::cout << "m is " << std::endl << m << endl;

    m(1,0) = 10.0;
    m(1,1) = 11.0;
    std::cout << "m is " << std::endl << m << endl;

    m.col(0).swap(m.col(1));
    std::cout << "swap m is " << std::endl << m << endl;

    MatrixXd mm = MatrixXd::Zero(5,5);
    for(int i = 0; i< 5; ++i){
        mm(0, i) = i;
        mm(1, i) = i;
        mm(2, i) = i;
        mm(3, i) = i;
        mm(4, i) = i;
    }
    std::cout << "mm is " << std::endl << mm << endl;
    mm.col(0).swap(mm.col(4));
    std::cout << "swap mm is " << std::endl << mm << endl;

//        mm is
//        0 1 2 3 4
//        0 1 2 3 4
//        0 1 2 3 4
//        0 1 2 3 4
//        0 1 2 3 4
//        swap mm is
//        4 1 2 3 0
//        4 1 2 3 0
//        4 1 2 3 0
//        4 1 2 3 0
//        4 1 2 3 0


    return 0;
}

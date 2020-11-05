#include <cmath>
#include <string>
#include <iostream>




using namespace  std;


int main(){


    double k1_ = 2;

    double theta = 0.5;

    double result1 = (1 + (k1_/1+((k1_*theta)*(k1_*theta))));

    std::cout << "k1_ / 1 + ((k1_ * theta) * (k1_ * theta)) = " << result1 << std::endl;


    double result2 =(1 + (k1_/ ( 1+((k1_*theta)*(k1_*theta)) )));

    std::cout << "k1_ / (1 + ((k1_ * theta) * (k1_ * theta)) ) = " << result2 << std::endl;

    double result3 = k1_/1+(k1_*theta);

    std::cout << "k1_/1+(k1_*theta) = " << result3 << std::endl;

    double result4 = k1_/(1+(k1_*theta));

    std::cout << "k1_/(1+(k1_*theta)) = " << result4 << std::endl;



    return 0;
}

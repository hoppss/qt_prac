#include <math.h>
#include <iostream>



int main() {


    double num;
    while (std::cin >> num)
    {
        double ipart;
        double precious = modf(num, &ipart);
        std::cout << "input: " << num << ", [" << ipart << "," << precious << "]" << std::endl;
    }



}
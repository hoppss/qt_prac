#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <string.h>

using namespace std;

#define RESET "\033[0m"
#define RED   "\033[31m"

enum {
    walking = 'WALK',
    defending = 'DEFN',

    tick = 'tick',
};

int main()
{
     int a = 100, b = 200;
    const int *p= &a;
    a = 200;
    int* q = const_cast<int*>(p);   //

    char cc = 'limao';

    cout << walking << endl;
    cout << defending << endl;
    cout << tick      << endl;
    cout << sizeof (walking) << endl;

//https://blog.csdn.net/realxie/article/details/23304079
    int temp = 'WALKQ';
    char * array = (char *)&temp;
    char buff[5] = {0};
    strncpy(buff, array, 4);
    cout << buff <<endl;

    return 0;
}

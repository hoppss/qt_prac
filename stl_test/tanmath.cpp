#include <iostream>
#include <math.h>       /* atan2 */

using namespace std;

int main()
{
    cout << " --atan2--" << endl;

    cout << " atan2(1,1)   " << atan2(1.0,1.0) / M_PI * 180 << std::endl; //45

    cout << " atan2(-1,1)  " << atan2(-1.0,1.0) / M_PI * 180 << std::endl; //-45

    cout << " atan2(-1,-1) " << atan2(-1.0,-1.0) / M_PI * 180 << std::endl; //-135

    cout << " atan2(1,-1)  " << atan2(1.0,-1.0) / M_PI * 180 << std::endl; //135

    //
    cout << endl << " --atan--" << endl;

    cout << " atan(1,1)   " << atan(1.0/1.0) / M_PI * 180 << std::endl; //45

    cout << " atan(-1,1)  " << atan(-1.0/1.0) / M_PI * 180 << std::endl; //-45

    cout << " atan(-1,-1) " << atan(-1.0/-1.0) / M_PI * 180 << std::endl; //45

    cout << " atan(1,-1)  " << atan(1.0/-1.0) / M_PI * 180 << std::endl; //-45

    //
    cout << endl << " --atan-- test max" << endl;

    cout << " atan(1,0.00001)   " << atan(1.0/0.00001) / M_PI * 180 << std::endl; //89.9994
    // cout << " atan(1/0)         " << atan(1/0) * M_PI * 180 << std::endl;         //core dump

    return 0;
}

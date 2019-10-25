#include <iostream>
#include <limits>
#include <assert.h>
#include <vector>
//How to works with inf data, for examples, ros::sensor_msgs::LaserScan::ranges[inf,inf,inf];
using namespace std;

int main()
{
        std::cout << "Minimum value for int: " << std::numeric_limits<int>::min() << std::endl;
        std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << std::endl;
        std::cout << "int is signed: " << std::numeric_limits<int>::is_signed << std::endl;
        std::cout << "Non-sign bits in int: " << std::numeric_limits<int>::digits << std::endl;
        std::cout << "int has infinity: " << std::numeric_limits<int>::has_infinity << std::endl;//false
        std::cout << "int infinity: " << std::numeric_limits<int>::infinity() << std::endl;//0

        std::cout << "__________" << endl;
        std::cout << "Minimum value for float: " << std::numeric_limits<float>::min() << std::endl;
        std::cout << "Maximum value for float: " << std::numeric_limits<float>::max() << std::endl;
        std::cout << "float is signed: " << std::numeric_limits<float>::is_signed << std::endl;
        std::cout << "Non-sign bits in float: " << std::numeric_limits<float>::digits << std::endl;
        std::cout << "float has infinity: " << std::numeric_limits<float>::has_infinity << std::endl;//true
        std::cout << "float infinity: " << std::numeric_limits<float>::infinity() << std::endl;//inf ***
        std::cout << "__________" << endl;
        float temp = std::numeric_limits<float>::infinity();
        assert(temp > 10000);
        if(temp > 100000000)
            cout << "inf is absolutely bigger" << endl;

        std::cout << "___________" << endl;

        vector<float> tempp{std::numeric_limits<float>::infinity(),std::numeric_limits<float>::infinity(),std::numeric_limits<float>::infinity(),std::numeric_limits<float>::infinity()};
        vector<float>::iterator it;
        for(it = tempp.begin();it != tempp.end();it++){
            std::cout << *it << endl;  //inf; inf; inf; inf;
        }


        cout << "quiet nan : " << std::numeric_limits<float>::quiet_NaN() << endl;

        cout << "quiet nan {int } : "  << int(std::numeric_limits<float>::quiet_NaN() );



    return 0;
}

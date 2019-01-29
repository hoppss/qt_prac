#include <iostream>

using namespace std;
double double_5(double x)
{
    if(x > 0){
        double spd=( (double)( (int)( (x+0.00005)*10000 ) ) )/10000;
        return spd;
    }
    else if(x < 0){
        double spd = ( (double)( (int)( (x - 0.00005)*10000 ) ) )/10000;
        return spd;
    }
    else{
        return 0;
    }
}

int main()
{
    double d1 = 22.5187459999;
    double d2 = 10;
    double d3 = -22.5187559999;
    double d0 = 0;


    cout<< double_5(d1)<<endl;
    cout<< double_5(d2)<<endl;
    cout<< double_5(d3)<<endl;
    cout<< double_5(d0)<<endl;

    return 0;
}

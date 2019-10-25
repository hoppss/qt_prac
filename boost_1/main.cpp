#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <atomic>

using namespace std;
struct square{
    typedef void result_type;//important, must declare result_type!!
    void operator()(int& x){
        x = x*x;
    }//callbale object
};
int main()
{
//    typedef double (*pfunc)(double);// function pointer
//    pfunc pf = sqrt;
//    cout << std::ref(pf)(5.0) << endl; //warper function object,nocopy
//    square sq;
//    int x = 5;
//    ref(sq)(x);//warper object;nocopy
//    cout << "x" << x << endl;

//    vector<int> v{1,2,3,4,5};//for_each, yiyuanweici
//    for_each(v.begin(),v.end(),std::ref(sq));


    atomic<int> a(100);
    cout << "a.load()" << a.load() << endl;
    a.store(300);
    cout << "a.store()" << endl;
    cout << "a.exchange()" << a.exchange(400) << endl;

    return 0;
}

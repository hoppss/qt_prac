/**
  * @author hopps.li
  * @email  hopps.li@cloudminds.com
  * @time   2019-10-25
*/

#include <iostream>
#include <string>
#include <vector>
#include "CSignal.hpp"
#include "unistd.h"
#include <functional>
using namespace std;

class cycle{
public:
    cycle():cnt(0){
        finishSignal = new CSignal<int>;
    }
    void run(){
        for(int i=0; i<10; ++i){
            cout << "   i "  << i << endl;
            sleep(1);
            cnt = i;
        }
        finishSignal->s_Emit(cnt);
    };
    void interupt(){
        for(int i=0; i<10; ++i){
            cout << "   i "  << i << endl;
            sleep(1);
            cnt = i;
            if(i == 3) return;
        }
        finishSignal->s_Emit(cnt);
    };
    int cnt;
    // CSignal<int> finishSignal; 
        CSignal<int> * finishSignal; 

};

class aa{
public:
    aa(){
        c1.finishSignal->connect_member(this,&aa::subscribeSignal);
        cout << "aa construct finish" << endl;
    }
    ~aa(){
        cout << "deconstruct" << endl;
    }
    cycle c1;
    void run(){
        c1.run();
    };
    void subscribeSignal(int signal){
        cout << "oh get !" << endl;
    }

};
void signalCallback(int signal){
    cerr << "_____________" << signal << endl;
};

template<class T>
class callback{
public:
    void operator()(T signal){
        cerr << "functor " << (int)signal << endl;
    }
};


int main(int argc, char** argv){
    //1
    cycle a;
    a.finishSignal->s_Connect([=]( int signal){cerr << " lambda *********"  << signal << endl;});
    a.run();
    
    //2
    aa object;

    object.run();
    object.c1.interupt();

    //3
    cycle b;
    b.finishSignal->s_Connect(&signalCallback);
    b.run();

    //4
    cycle c;
    std::function<void(int)> func = signalCallback;
    c.finishSignal->s_Connect(func);
    c.run();

    //5
    cycle d;
    std::function<void(int)> func2 = callback<int>();
    d.finishSignal->s_Connect(func2);
    d.run();
}
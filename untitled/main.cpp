#include <iostream>
#include <thread>
#include <mutex>


using namespace std;

class t{
public:
    t(int x):a(x){
        n = 5;
    }
    ~t(){
        std::cout << "t deconstruct " << endl;
    }
    void set(int b){
        mu.lock();
        a = b;
        cout << "in main thread " << a  << endl;
        mu.unlock();
    }

    void print(){
        int cnt = 100;
        while(cnt--){
            mu.lock();
            a = 0;
            std::cout << "in son thread " <<  a << endl;
            mu.unlock();
        }
    }
//    std::thread th(){
//        return std::thread(&t::print,this);
//    }
    std::thread th(&t::print,this);
    int n;
    int a;
    std::mutex mu;
};

int main()
{
    t a(1);
    a.th();
    int aa = 100;
    while(aa--){
        a.set(aa);
    }
    return 0;
}

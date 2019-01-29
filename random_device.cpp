#include <iostream>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

int main()
{

    int cnt = 100;
    random_device rd;
    while(cnt--){
        unsigned int ddd = rd();
        cout << ddd << endl;
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}

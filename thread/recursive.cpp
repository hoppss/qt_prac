#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>  // **

using namespace std;

// recursive_mutex 递归的独占互斥锁
// std::mutex 独占互斥量，自己lock 别人lock不了
// recursive_mutex 同一个线程同一个互斥量多次被lock
//
// std::lock_guard<std::recursive_mutex> guard(mu);
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

int main()
{
}
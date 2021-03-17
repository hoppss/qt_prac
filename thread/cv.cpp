#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <condition_variable>

using namespace std;

class A
{
public:
  void inMsg()
  {
    for (int i = 0; i < 1000; ++i)
    {
      cout << "in " << i << endl;
      std::unique_lock<std::mutex> guard(mu);
      msg_queue.push_back(i);

      mcond.notify_one();  // 唤醒wait， 就要马上加锁
    }
  }

  void outMsg()
  {
    int command = 0;
    while (1)
    {
      std::unique_lock<std::mutex> guard(mu);

      // 条件变量需要和互斥量配合
      // 条件变量等一个东西, 第二个成员
      // lambda 返回false, 那么wait 将解锁互斥量，并堵塞本行， 直到其他线程调用notify_one() 为止
      // 初次没有调用notify时， 第二个参数为空时，返回false
      //
      // 如果wait 没有第二个参数， 相当于第二参数是false， 解锁互斥量、堵塞本行、直到其他线程有notify_one()
      // 如果notify唤醒后，不断重试加锁， 如果获取不到， 就卡在wait 这里
      // 如果获取到锁，wait 执行lambda 表达式，如果true 往下走， 如果false， 锁释放， 阻塞，
      // 调用notify 后， 如果第二个参数为空， 返回true
      mcond.wait(guard, [this] {
        if (!msg_queue.empty())
        {
          return true;
        }
        else
          return false;
      });

      command = msg_queue.front();
      msg_queue.pop_front();
      guard.unlock();
      cout << "pop " << command << endl;

      //
    }
  }

  std::mutex mu;
  std::condition_variable mcond;
  std::list<int> msg_queue;
};

int main()
{
  A a;
  thread t1(&A::inMsg, std::ref(a));
  thread t2(&A::outMsg, std::ref(a));  // 第二个参数是引用，才能保证线程里用的是一个对象

  t1.join();
  t2.join();
}
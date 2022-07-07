#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <list>

using namespace std;

// mutex 锁住共享数据后，别的地方只能等待
// lock() 只有一个线程能锁定成功， 如果没锁成功，则会卡在lock()
class A
{
public:
  void inMsg()
  {
    for (int i = 0; i < 100; ++i)
    {
      cout << "push " << i << endl;
      mu.lock();
      queue.push_back(i);
      mu.unlock();
    }
  }

  void outMsg()
  {
    for (int i = 0; i < 2000; ++i)
    {
      int ret = 0;
      if (outMsgLock(ret))
      {
        cout << "pop " << ret << endl;
      }
      else
      {
        cout << "queue empty, waiting" << endl;
      }
    }
  }

  bool outMsgLock(int& c)
  {
    mu.lock();
    if (!queue.empty())
    {
      c = queue.front();
      queue.pop_front();
      mu.unlock();
      return true;
    }
    else
    {
      mu.unlock();
      return false;
    }
  }

  std::list<int> queue;
  std::mutex mu;
};

int main()
{
  A a;

  thread t1(&A::inMsg, std::ref(a));
  thread t2(&A::outMsg, std::ref(a));

  t1.join();
  t2.join();
}

/*
lock_guard

std::lock_guard<std::mutex> guard(mu);    // guard 相当于mu.lock, 析构函数自动unlock


// trick 加{} 添加作用域
*/
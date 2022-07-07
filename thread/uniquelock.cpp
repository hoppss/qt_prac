#include <iostream>
#include <string>
#include <chrono>

#include <thread>
#include <mutex>
#include <list>

using namespace std;

// lock_guard 取代mutex
// unique_lock 取代lock_guard, 声明时默认lock()
// unique_lock 第二个参数
// 1. std::adopt_lock， 表示mutex 已经被lock, (必须把互斥量提前lock), 同lock_guard
// 2. std::try_to_lock, 若果没有锁定成功， 也会立即返回，并不会阻塞， 使用这个标记之前，不能lock， 否则卡死
//    有返回结果，guard1..owns_lock()
// 3. std::defer_lock, 前提不能自己lock，
//    初始化并没有加锁，
//    通过defer_lock 介绍unque_lock的成员函数
//       lock(),
//             std::unique_lock<std::mutex> g(mu1, std::defer_lock); g.lock(); // defer 还要手动加锁
//       unlock(),
//             g.unclock()；  // defer 可以自动解锁非必须， 只有defer类型，lock之后才能unlock
//       bool try_lock();     //返回true表示lock成功
//       mutex* release()            // 将绑定在一起的unique_lock 和 mutex分开，返回mutex 指针
//                                   // 原来mutex 处于加锁状态，release 指针有责任完成解锁
//             std::unique_lock<std::mutex> g(mu1, std::defer_lock); g.lock(); // defer 还要手动加锁
//             std::mutex* ptx = g.release();   // 释放出来指针需要手动解锁
//              ptx->unlock();
//             // 粒度： 锁的代码少，执行的效率高； 粒度体现程序员的能力

// 4. unique_lock 和mutex 所有权的传递，  unique_lock 和lock_guard 需要管理一个mutex 指针, 拥有mutex的所有权
//       unique_lock 将mutex 所有权可以转移， 不能复制,， 怎么转移std::move(), return unique_lock 也是可以的
//            std::unique_lock<std::mutex> g(mu1）； std::unique_lock<std::mutex> g2(std::move(g)); // 移动语义
//
//
//
//
class A
{
public:
  // 转移所有权，也是可以的
  std::unique_lock<std::mutex> rtn_unique_lock()
  {
    std::unique_lock<std::mutex> tmpguard(mu1);
    return tmpguard;  // 这个函数是合法的
    // 返回局部对象tempguard 会导致系统生产临时的uniuqe_ock 对象，并调用unique_lock 的移动构造函数
  }
  void inMsg()
  {
    for (int i = 0; i < 100; ++i)
    {
      cout << "push " << i << endl;
      // mu1.lock();
      // std::unique_lock<std::mutex> guard1(mu1, std::adopt_lock);

      std::unique_lock<std::mutex> guard1(mu1, std::try_to_lock);
      if (guard1.owns_lock())
      {
        queue.push_back(i);
      }
      else
      {
        cout << "inMsg not owns lock, wait " << endl;
      }
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
    std::unique_lock<std::mutex> guard1(mu1);

    std::chrono::microseconds dura(20000);
    this_thread::sleep_for(dura);

    if (!queue.empty())
    {
      c = queue.front();
      queue.pop_front();
      return true;
    }
    else
    {
      return false;
    }
  }

  std::list<int> queue;
  std::mutex mu1;
  std::mutex mu2;
};

int main()
{
  A a;

  thread t1(&A::inMsg, std::ref(a));
  thread t2(&A::outMsg, std::ref(a));

  t1.join();
  t2.join();
}
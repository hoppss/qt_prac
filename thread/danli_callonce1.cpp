#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <list>

using namespace std;

// 单例模式共享数据问题分析
// 在多个线程中创建实例，getInstance 需要做到互斥。
//
//
//
mutex resource_mutex_;  // getInstance 是静态成员函数， 不能操作非静态成员！！
                        // 这里是全局变量，所以类中可以使用

class A
{
public:
  static A* getInstance()  // 操作静态成员， 必须使用静态函数
  {
    // 这种写法可以，但是如果多个线程频繁调用getInstance， 效率降低
    // std::unique_lock<std::mutex> guard(resource_mutex_);
    if (m_instance_ == NULL)
    {
      std::unique_lock<std::mutex> guard(resource_mutex_);  // 提高效率方法
      m_instance_ = new A();
      static GarbageCollectorHelper xl;  // 辅助函数， 用于析构时释放指针, 静态成员，程序退出才会析构；
      // 所以智能指针reset 可能不会释放？？
    }

    return m_instance_;
  }

  void printLog()
  {
    cout << "__" << endl;
  }

  // 定义一个辅助函数用于帮助析构指针分配的内存
  class GarbageCollectorHelper
  {
  public:
    ~GarbageCollectorHelper()
    {
      if (A::m_instance_)  // 第一层类的静态成员就相当于全局变量， 所以可以访问
      {
        delete A::m_instance_;
        m_instance_ = NULL;
      }
    }
  };

private:
  A()
  {  // 防止别的方式构造，所以是私有权限
  }

  static A* m_instance_;  // 静态成员变量
  // mutex resource_mutex_;  // getInstance 是静态成员函数， 不能操作非静态成员！！
};

// 类静态变量初始化
A* A::m_instance_ = NULL;

//
void mythread()
{
  cout << "t start" << endl;
  A* p = A::getInstance();
  cout << "t end" << endl;
  return;
}

int main()
{
  thread t1(mythread);
  thread t2(mythread);

  t1.join();
  t2.join();
}

// call_once()
// c++11, 第一个参数， 第二个参数是一个函数名a()， call_once功能就可以保证函数a() 只被调用一次
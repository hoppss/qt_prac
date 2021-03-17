#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <list>

using namespace std;

// Singleton Pattern
// call_once()
// c++11, 第一个参数， 第二个参数是一个函数名a()， call_once功能就可以保证函数a() 只被调用一次
// call_once 具备互斥量能力，且 效率大于 互斥量
// 与一个标记量配合使用， std::oncee_flag, 根据该标记是否决定执行
//
std::mutex resource_mutex;
std::once_flag g_flag;
class A
{
  static void createInstance()
  {
    m_instance_ = new A;
    static GarbageCollectorHelper xl;
  }

public:
  static A* getInstance()  // 操作静态成员， 必须使用静态函数
  {
    // if (m_instance_ == NULL)
    // {
    //   m_instance_ = new A();
    //   static GarbageCollectorHelper xl;
    //
    // }
    std::call_once(g_flag, createInstance);
    return m_instance_;
  }

  void printLog()
  {
    cout << "__" << endl;
  }

  //定义一个辅助函数用于帮助析构指针分配的内存
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
};

// 类静态变量初始化
A* A::m_instance_ = NULL;

int main()
{
  A* p = A::getInstance();
  A* p2 = A::getInstance();

  p->printLog();

  A::getInstance()->printLog();
}
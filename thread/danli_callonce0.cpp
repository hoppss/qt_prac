#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <list>

using namespace std;

// Singleton Pattern
// 没有构造函数，拷贝构造函数
// 静态成员指针实例维护
// 析构辅助函数
//

class A
{
public:
  static A* getInstance()  // 操作静态成员， 必须使用静态函数
  {
    if (m_instance_ == NULL)
    {
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
#include <iostream>
#include <string>
#include <thread>

using namespace std;

// 引用传参， 有问题，每次结果不同
// 主线程先退出，子线程引用原对象不复存在

class Ta
{
public:
  int& m_i_;  // bug 生产者

  Ta(int& i) : m_i_(i)
  {
    cout << "默认构造函数" << endl;
  }

  Ta(const Ta& t) : m_i_(t.m_i_)
  {
    cout << "拷贝构造函数----- 构造线程时 被拷贝到线程中" << endl;
  }

  ~Ta()
  {
    cout << "~~ 析构" << endl;
  }

  void operator()()
  {
    std::cout << "( " << m_i_ << ")" << endl;
  }
};

int main()
{
  cout << "main start" << endl;
  int i = 6;
  Ta t(i);
  thread my_thread(t);  // t 实际被复制到线程中！！！

  my_thread.detach();  // 此处主线程不等待， 有可能主线程先退出，此时子线程引用的变量有可能不复存在

  cout << "main finish" << endl;
}

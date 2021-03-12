#include <iostream>
#include <string>
#include <thread>

using namespace std;
//总结
// 线程引用传参，即使参数是引用，实际还是进行了拷贝构造， 无法传回主线程
// 1.避免拷贝构造需要使用std::ref
// 2. 使用智能指针
class A
{
public:
  mutable int m_i_;  // mutable 即使在const 函数中（作为参数），也可以被修改  ***
  A(int i) : m_i_(i)
  {
    cout << "A(int i) construct, thread_id " << this_thread::get_id() << endl;
  }

  A(const A& a) : m_i_(a.m_i_)
  {
    cout << "A(const A& i) construct, thread_id " << this_thread::get_id() << endl;
  }

  ~A()
  {
    cout << "~A， thread_id " << this_thread::get_id() << endl;
  }
};

void printLog(const A& buf)
{
  // 第二个参数用引用来接， 否则会构造3次， 引用构造两次
  cout << buf.m_i_ << endl;
  buf.m_i_ = 100;  // 因为A.m_i_ is mutable, ***
  cout << buf.m_i_ << endl;
  return;
}
int main()
{
  cout << "main start, id: " << this_thread::get_id() << endl;
  A a(10);

  // thread my_thread(printLog, a);  // 将对象作为类参数,
  // 虽然是引用传参，但是还是进行了拷贝构造，所以线程不同修改主线程的a

  thread my_thread(printLog, std::ref(a));  // 强制告诉编译器， 使用引用的方式，a 传入线程不会再拷贝构造
  // 这里是因为函数式编程，还是使用了值拷贝的方式，即使是const&
  // thread 构造函数形参接T&& 是C++11新功能万能引用universe reference, T&& 既能绑定右值， 又能绑定坐值

  my_thread.join();

  cout << "main finish， a.m_i_" << a.m_i_ << endl;
}
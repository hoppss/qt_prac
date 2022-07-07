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
  int m_i_;
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
    cout << "~A" << endl;
  }
};

void printLog(const int i, const A& buf)
{
  // 第二个参数用引用来接， 否则会构造3次， 引用构造两次
  cout << i << endl;
  cout << buf.m_i_ << endl;
  return;
}
int main()
{
  cout << "main start, id: " << this_thread::get_id() << endl;
  int mvar = 1;
  int mybuf = 100;

  // thread my_thread(printLog, mvar, A(mybuf));    // 使用临时对象构造，传参在主线程构造
  //   main start, id: 140718165485376
  // A(int i) construct, thread_id 140718165485376
  // A(const A& i) construct, thread_id 140718165485376
  // A(const A& i) construct, thread_id 140718165485376
  // ~A
  // ~A
  // 1
  // 100
  // ~A
  // main finish

  thread my_thread(printLog, mvar, mybuf);  // mybuf参数使用隐式转换， 转换发生在在子线程中， 所以不安全
  //   main start, id: 139663374976832
  // A(int i) construct, thread_id 139663356958464
  // 1
  // 100
  // ~A
  // main finish

  // my_thread.detach();
  my_thread.join();

  cout << "main finish" << endl;
}

// 线程结果不能返回，下一讲线程传参使用指针
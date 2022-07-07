#include <iostream>
#include <string>
#include <thread>

using namespace std;
//总结
// 1. int 值传递
// 2. 若传递类对象，避免隐式转换
// 3. 在线程创建这一行，就需要构建临时对象传参，
// 用引用来接（构造两次，默认构造+拷贝构造），否则系统会构造三次（默认构造+2次拷贝构造）
// 尽量不要用detach

// 创建线程时， 传参通过把参数构造临时对象， 避免外面引用或者指针率先失效
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
  // A(const A& i) construct, thread_id 140718165485376   // 虽然是引用方式，但是传递还是使用了拷贝构造，
  // 不能用来从线程中返回，看下一讲
  // A(const A& i) construct, thread_id 140718165485376
  // ~A
  // ~A
  // 1
  // 100
  // ~A
  // main finish

  thread my_thread(printLog, mvar, mybuf);  // 使用隐式转换， 传参构造在子线程中， 所以不安全
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
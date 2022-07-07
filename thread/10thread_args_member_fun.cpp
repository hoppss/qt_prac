#include <iostream>
#include <string>
#include <thread>

using namespace std;
//总结
// 类成员函数，付给 线程
// 显示指定引用的形式传参
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

  void worker(int num)
  {
    cout << "child_thread " << this << " threadid " << this_thread::get_id() << endl;
  }

  // functor
  void operator()(int num)
  {
    cout << "A()" << this << "threadid " << this_thread::get_id() << endl;
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

  // thread my_thread(&A::worker, a, 15);  // 这里也进行了拷贝构造
  // main start, id: 140195468937024
  // A(int i) construct, thread_id 140195468937024
  // A(const A& i) construct, thread_id 140195468937024
  // A(const A& i) construct, thread_id 140195468937024
  // ~A， thread_id 140195468937024
  // child_thread 0x55d5840d328c threadid 140195450918656
  // ~A， thread_id 140195450918656
  // main finish， a.m_i_10
  // ~A， thread_id 140195468937024

  // thread my_thread(&A::worker, std::ref(a), 15);  // 这里不再拷贝构造，线程中使用的a，还是主线程的a
  // thread my_thread(&A::worker, &a, 15);        // 这两行等效
  // 这两种都不能使用detach

  // 使用functor
  // thread my_thread(a, 15);   // 使用了拷贝构造，
  //   main start, id: 140176742332224
  // A(int i) construct, thread_id 140176742332224
  // A(const A& i) construct, thread_id 140176742332224
  // A(const A& i) construct, thread_id 140176742332224
  // ~A， thread_id 140176742332224
  // A()0x563c7277a28cthreadid 140176724313856
  // ~A， thread_id 140176724313856
  // main finish， a.m_i_10
  // ~A， thread_id 140176742332224

  thread my_thread(std::ref(a), 15);  // 真实传引用进去
  // main start, id: 140286426519360
  // A(int i) construct, thread_id 140286426519360
  // A()0x7ffe0d017be0threadid 140286408500992
  // main finish， a.m_i_10
  // ~A， thread_id 140286426519360

  my_thread.join();

  cout << "main finish， a.m_i_" << a.m_i_ << endl;
}
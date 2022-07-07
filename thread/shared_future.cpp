#include <iostream>
#include <future>
#include <string>

using namespace std;
int mythread(int mypar)
{
  cout << "mythread start, threadid: " << std::this_thread::get_id() << endl;
  std::chrono::milliseconds dura(5000);

  std::this_thread::sleep_for(dura);
  return 5;
}

void mythread2(std::future<int>& tmpf)
{
  cout << "mythread2 start, threadid: " << std::this_thread::get_id() << endl;
  auto result = tmpf.get();  // 只能get一次，否则会报异常!!!
                             // 第二次抛异常， future 实现使用了移动语义，
                             // 这就导致了不能多个线程中使用

  // 引出shared_future， get() 不会转移数据，只会复制数据

  cout << "mythread2 result = " << result << endl;
  return;
}

int main()
{
  // std::shared_future

  std::packaged_task<int(int)> mypt(mythread);
  std::thread t1(std::ref(mypt), 1);  // 线程直接开始执行， 第二个参数作为线程入口函数的参数
  t1.join();                          //等待线程结束

  std::future<int> result = mypt.get_future();
  std::thread t2(mythread2, std::ref(result));
  t2.join();

  //   std::future<int> result = mypt.get_future();
  //   std::shared_future<int> r_s(std::move(result));
  //   std::shared_future<int> r_s(result.share());  // r_s 有值， result 没有了
}

// future<>.valid()   判断是否有效值
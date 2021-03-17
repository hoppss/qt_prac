#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>  // **

using namespace std;

// std::async, std::future 创建后台任务并返回， 希望线程返回一个结果
// async 是函数模板，用来启动一个异步任务，返回一个std::future 对象，std::future 是类模板

// 异步任务： 自动创建一个线程并开始执行线程入口函数，它返回一个std::future 对象
//返回结果， std::future::get()

// std::future 提供一种访问异步结果的机制， 就是说这个结果你可能没有办法马上拿到，将来某个时刻拿到
//

// async 声明后，马上执行，但是调用result.get() 会阻塞，直到返回
//

// get() 阻塞直到返回； wait() 阻塞，不反悔结果
//

// async  带第二个参数, 类型为std::launch enum,
//      1. std::launch::deferred： 表示线程入口函数调用被延迟到std::future::wait/get 调用时才执行
//         如果没调用，线程就没创建
//         延迟调用，实际没有创建子线程，还是在主线程中
//      2. std::launch::async 在调用async 就开始创建子线程，  这个应该就是默认的
//
//

int mythread(int num)
{
  cout << "t_start " << this_thread::get_id() << endl;
  std::chrono::seconds dura(5);

  this_thread::sleep_for(dura);
  cout << "t_end " << std::this_thread::get_id() << endl;

  return num;
}

int main()
{
  cout << "main_start " << std::this_thread::get_id() << endl;
  //   std::future<int> result = std::async(mythread, 5);
  std::future<int> result = std::async(std::launch::deferred, mythread, 5);

  std::cout << "continue...." << endl;

  int def = 0;

  cout << result.get() << endl;  // 程序会卡在此处，等待线程返回
  // result.wait();  阻塞不返回结果
  cout << "main_end" << endl;

  /*
  std::future_status status = result.wait_for(std::chrono::seconds(1));
  if (status == std::future_status::timeout)
    cout << "timeout， 线程还没有返回" << endl;


  if(status == std::future_status::ready) cout << "线程成功执行完毕，返回" << endl;
    */
}
/**
 * Copyright © 2021 xxxx. All rights reserved.
 *
 * @author: limao
 * @date: 2021-04-17
 */

#include <iostream>
#include <string>
#include <functional>
#include <memory>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

// std::promise<>
// 类模板
// 我们可以在某个线程中赋值， 然后可以在其他线程中，把这个值取出来， 线程间传参
// promise 和 future 是绑定的

void my_thread(std::promise<int>& tmpp, int calc)
{
  calc++;
  calc *= 10;

  // 耗时
  std::chrono::milliseconds dura(5000);
  std::this_thread::sleep_for(dura);

  // 赋值
  int result = calc;
  tmpp.set_value(result);
  return;
};

int main()
{
  std::promise<int> myprom;
  std::thread t1(my_thread, std::ref(myprom), 180);  // 线程入口函数&， 也是值传递， 必须用std::ref 表示引用

  // 等待执行结束
  t1.join();

  // 获取结果
  std::future<int> result = myprom.get_future();  // promise 和 future 绑定，用于获得线程返回结果
  auto r = result.get();                          // 只可以调一次， 阻塞的

  cout << "result is " << r << endl;
}
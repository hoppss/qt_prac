#include <iostream>
#include <string>
#include <thread>

using namespace std;

/*
这部分问题来源于detach 使用后，主线程可能先于子线程退出。
1. printLog 第一个int 参数，常引用整形， 实际int 类型，是以拷贝进行传参的，这里引用没气作用
2. printLog 如果使用指针或者引用传参，其实如果外面原始数据析构不再存在，就会引起系统风险
*/

void printLog(const int& i, char* buf)
{
  cout << i << endl;
  cout << buf << endl;
  return;
}
int main()
{
  cout << "main start" << endl;
  int mvar = 1;
  int& mvary = mvar;
  char mybuf[] = "this is a test";

  thread my_thread(printLog, mvar, mybuf);

  my_thread.detach();

  cout << "main finish" << endl;
}

/* 避免引用， 对于int 型数据直接用复制传参
void printLog(int i, char* buf)
{
  cout << i << endl;
  cout << buf << endl;
  return;
}
*/

//避免使用指针， 指针也是不安全的， 那么对于char* 数组怎么传递呢
//包含了一个隐式转换， char* 转成了string 右值, 加const 为了接收右值的引用
//下面这样也是有问题， main 结束， 有可能mybuf还没转成string
// void printLog(int i, const string& str)
// {
//   //
// }
// mybuf 什么时候转换成string
// thread my_thread(printLog, mvar, mybuf);  // 直接使用mybuf， 如果主线程先退出， 是有可能的，
// 参数按照tuple 传进去，线程内部创建子线程后才会将数据参数tuple，执行（完成转换）

// thread my_thread(printLog, mvar, string(mybuf)); // 构造临时对象， 皆可以保证线程中不适用

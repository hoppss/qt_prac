#include <iostream>
#include <string>
#include <thread>

using namespace std;

void printLog()
{
  for (int i = 0; i < 100; ++i)
  {
    cout << "printLog " << i << endl;
  }
}

int main()
{
  cout << "main start" << endl;

  thread my_thread(printLog);
  if (my_thread.joinable())
  {
    cout << "default is joinable" << endl;  //默认是可以joinable
  }

  my_thread.join();  // 一旦join, 不可再join

  if (!my_thread.joinable())
  {
    cout << "disabled after join or detach" << endl;
  }

  cout << "main finish" << endl;
}

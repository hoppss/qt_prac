#include <iostream>
#include <string>
#include <thread>

using namespace std;

int main()
{
  cout << "main start" << endl;

  thread my_thread([]() { cout << "lambda2" << endl; });

  my_thread.join();  // 一旦join, 不可再join

  cout << "main finish" << endl;
}

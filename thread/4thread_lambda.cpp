#include <iostream>
#include <string>
#include <thread>

using namespace std;

int main()
{
  cout << "main start" << endl;

  auto lambda_fun = [] { cout << "lambad " << endl; };  // 无参时， () 可以省略
  thread my_thread(lambda_fun);

  my_thread.join();  // 一旦join, 不可再join

  cout << "main finish" << endl;
}

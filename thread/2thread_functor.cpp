#include <iostream>
#include <string>
#include <thread>

using namespace std;

// 无参

class Ta
{
public:
  void operator()()
  {
    for (int i = 0; i <= 100; ++i)
    {
      std::cout << "( " << i << ")" << endl;
    }
  }
};

int main()
{
  cout << "main start" << endl;

  Ta t;
  thread my_thread(t);

  my_thread.join();

  cout << "main finish" << endl;
}

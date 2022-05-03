#include <iostream>
#include <string>

using namespace std;

int main (int argc, char** argv) {

  // 指针数组
  int data[3] = { 1, 10, 100 };

  int* p[3];  // arr 是指针数组， 等效于 （int*） arr[3]

  for (int i = 0; i < 3; ++i)
  {
    p[i] = &data[i];  // 里面保存的指针
  }

  for (int i = 0; i < 3; ++i) {
    std::cout << *(p + i) << "\t";   // 一层解引用， 获得的是地址，**二层才是值
  }
  std::cout << "\n - 2D - " << std::endl;

  // 指针数组二维

  int data2[2][4] = { 1, 2, 3, 4, 2, 4, 8, 16 };

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j)
    {
      std::cout << data2[i][j] << "\t";
    }
    std::cout << std::endl;
  }

  int* pp[2][4];

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j)
    {
      pp[i][j] = &data2[i][j];
    }
  }

  int k = 0;
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      // std::cout << **(pp[i] + j) << "\t";
      //   std::cout << **(*pp + k++) << "\t";
      std::cout << **(*(pp + i) + j) << "\t";
    }
    std::cout << std::endl;
  }

  // 数组指针
}
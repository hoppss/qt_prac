// 二维数组可以看成是指向数组的指针构成的数组，即指针数组,用来存放数组指针。
// https://blog.csdn.net/weixin_45332776/article/details/116613485

#include <stdio.h>
#include <iostream>

int main(int argc, char** argv)
{
  const int m = 3;  // rows
  const int n = 5;  // cols

  int** p = NULL;
  p = new int*[m];
  for (int i = 0; i < m; i++)
  {
    p[i] = new int[n];
  }

  // show
  int k = 0;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      p[i][j] = k++;
      std::cout << p[i][j] << "\t";
    }

    std::cout << std::endl;
  }

  //   0	1	2	3	4
  // 5	6	7	8	9
  // 10	11	12	13	14
  //释放
  for (int i = 0; i < m; i++)
  {
    delete[] p[i];
  }
  delete[] p;

  std::cout << "a: " << std::endl;
  int a[m][n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      std::cout << a[i][j] << "\t";
    }

    std::cout << std::endl;
  }

//   0	  1	  2	  3	  4	
//   5	  6	  7	  8	  9	
//   10  11	12	13	14
}
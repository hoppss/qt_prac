#include <iostream>

// #define inf 1>>20    //报错。。。
// motion_planning 使用上面的表示很大的数， 应该和backward.h 有关， 废弃吧


int main()
{
  int i = 1;

  std::cout << "i = 1; i = " << i << std::endl;

  std::cout << "i >> 1; i=  " << (i << 1) << std::endl;  //2

  i = 1;
  std::cout << "i >> 2; i=  " << (i << 2) << std::endl;  //4

  i = 1;
  std::cout << "i >> 3; i=  " << (i << 3) << std::endl; //8

  i = 1;
  std::cout << "i >> 4; i=  " << (i << 4) << std::endl; //16

  i = 1;
  std::cout << "i >> 20; i=  " << (i << 20) << std::endl; //1048576

//   std::cout << "inf 1>>20" << inf << std::endl;
}
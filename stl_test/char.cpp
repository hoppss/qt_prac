#include <iostream>
#include <string>

using namespace std;

int main() {

  char a = 0;
  char b = 1;

  char c = 50;

  char d = 100;

  char e = 254;
  char f = 255;
  char e_1 = 253;
  char max = 127;
  char mid = 128;

  char g = 256;   //overflow

  char neg = -1;

  std::cout << "CHAR_INT 0: " << (int)a << endl;
  std::cout << "CHAR_INT 1: " << (int)b << endl;
  std::cout << "CHAR_INT 50: " << (int)c << endl;
  std::cout << "CHAR_INT 100: " << (int)d << endl;
  std::cout << "CHAR_INT 127: " << (int)max << endl;  // 127
  std::cout << "CHAR_INT 128: " << (int)mid << endl;  // -128
  std::cout << "CHAR_INT 253: " << (int)e_1 << endl;  // -3
  std::cout << "CHAR_INT 254: " << (int)e << endl;   // -2
  std::cout << "CHAR_INT 255: " << (int)f << endl;   // -1
  std::cout << "CHAR_INT 256: " << (int)g << endl;   // 0
  std::cout << "CHAR_INT -1: " << (int)neg << endl;   //-1

  std::cout << "---" << endl;
  std::cout << "CHAR_UINT 0: " << (unsigned int)a << endl;
  std::cout << "CHAR_UINT 1: " << (unsigned int)b << endl;
  std::cout << "CHAR_UINT 50: " << (unsigned int)c << endl;
  std::cout << "CHAR_UINT 100: " << (unsigned int)d << endl;
  std::cout << "CHAR_UINT 127: " << (unsigned int)max << endl;   // 127
  std::cout << "CHAR_UINT 128: " << (unsigned int)mid << endl;   // 4294967168
  std::cout << "CHAR_UINT 253: " << (unsigned int)e_1 << endl;   // 4294967293
  std::cout << "CHAR_UINT 254: " << (unsigned int)e << endl;     // 4294967294
  std::cout << "CHAR_UINT 255: " << (unsigned int)f << endl;     // 4294967295
  std::cout << "CHAR_UINT 256: " << (unsigned int)g << endl;     // 0
  std::cout << "CHAR_UINT -1: " << (unsigned int)neg << endl;    // 4294967295 (255 == -1)

  std::cout << "---" << endl;

}
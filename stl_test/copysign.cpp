#include <iostream>
#include <string>

#include <cmath>

using namespace std;

/**
 * std::copysign(x, y)
 * return x_magnitude * sign(y)
 *
*/


int main ()
{
  cout << "std::copysign(1.1, -1.1) " << std::copysign(1.1, -1.1) << std::endl;
  cout << "std::copysign(1.1, -1.2) " << std::copysign(1.1, -1.2) << std::endl;
  cout << "std::copysign(1.2, -1.1) " << std::copysign(1.2, -1.1) << std::endl;

  cout << "std::copysign(-1.1, -1.1) " << std::copysign(-1.1, -1.1) << std::endl;
  cout << "std::copysign(-1.1, 1.1) " << std::copysign(-1.1, 1.1) << std::endl;
  cout << "std::copysign(-1.2, 1.1) " << std::copysign(-1.2, 1.1) << std::endl;

/**
 *
 * std::copysign(1.1, -1.1) -1.1
 * std::copysign(1.1, -1.2) -1.1
 * std::copysign(1.2, -1.1) -1.2
 * std::copysign(-1.1, -1.1) -1.1
 * std::copysign(-1.1, 1.1) 1.1
 * std::copysign(-1.2, 1.1) 1.2
*/
}
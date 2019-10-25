#include <iostream>

using namespace std;

int main()
{

    char c ='\x1';  //hex data

    cout << c << endl;
    cout << static_cast<int>(c) << endl;

    double cd = c;
    int ci = c;   // automatic transform format

    cout << c << endl;
    cout << cd  << endl;
    cout << ci << endl;
    return 0;
}

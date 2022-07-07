#include <iostream>
#include <string>
#include <vector>

using namespace std;

static string data="1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,";
static vector<double> array;

int main()
{
    size_t cnt = 0;
    size_t comma = 0;
    size_t curCommaPos = 0;

           comma = data.find(',',0);

          array.push_back(atof(data.substr(0,comma).c_str()));

          cout << "current comma is " << comma << endl;
          cout << "current curCommaPos is " << curCommaPos << endl;
          cout << "array at [ " << cnt << " ] is " << array[cnt] << endl;
          cout << "_________________________________________" << endl;


          while (cnt++ < 8)
          {

            curCommaPos = data.find(',',comma + 1);
            // sencond arg is about to first charactor in the string to be considered in the search

            array.push_back(atof(data.substr(comma + 1,curCommaPos-comma-1).c_str()));

            cout << "current comma is " << comma << endl;
            cout << "current curCommaPos is " << curCommaPos << endl;
            cout << "array at [ " << cnt << " ] is " << array[cnt] << endl;

            comma = curCommaPos;
          }

    return 0;
}

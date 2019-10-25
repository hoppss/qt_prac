#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

void getDate(){
    cout << system("date \+\"\%Y\-\%m\-\%d\ \%H\:\%M\:\%S\"") << endl;
}
int main()
{
    while(1){
        /*cout << "date---: " << */
        getDate();
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}

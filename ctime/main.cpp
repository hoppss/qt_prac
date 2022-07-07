#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t t;
    t = time(NULL);

    cout <<"自UTC时间1970年1月1日0时0分0秒至今经过的秒数为： " << t << endl;

    time(&t);              //参数timer不为空指针
    std::cout<<"自UTC时间1970年1月1日0时0分0秒至今经过的秒数为："<<t<<'\n';  // equal




    //


    struct tm* timeinfo;

    time(&t);
    timeinfo = localtime(&t);
    std::cout<<"(asctime)Current local time and date is: "<<  asctime(timeinfo); //char *
    //char* asctime (const struct tm * timeptr);
    std::cout<<"(ctime)Current local time and date is: "<<  ctime(&t); //char *
    //char* ctime (const time_t * timer);


    return 0;
}

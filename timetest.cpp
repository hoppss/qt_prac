#include <iostream>
#include "time.h"


using namespace std;

long diff_second(int hour,int min, int sec){
    //use to calc time from utc long time

    struct tm *local;
    time_t t;   // long
    t =time(NULL);
    std::cout <<" utc time now is " << t << std::endl;    //seconds from 1970

    //
    local=localtime(&t);   //year - month - day , hour - minite - second
    std::cout <<"now hour is " <<  local->tm_hour << std::endl;
    std::cout <<"now min is " << local->tm_min << std::endl;
    std::cout <<"now sec is " << local->tm_sec << std::endl;

    int hour_diff, min_diff, sec_diff;
    int secFlag, min_flag, hour_flag;

      if( (sec - local->tm_sec) < 0 ){
          secFlag = -1;
          sec_diff = 60 + sec - local->tm_sec;
          cout << "sec_diff " << sec_diff << endl;
      }
      else{
          secFlag = 0;
          sec_diff = sec - local->tm_sec;
          cout << "sec_diff " << sec_diff << endl;

      }

      if( ( min + secFlag - local->tm_min) < 0 ){
          min_flag = -1;
          min_diff = 60 + min - local->tm_min;
          cout << "min_diff " << min_diff << endl;

      }
      else{
          min_flag = 0;
          min_diff = min - local->tm_min;
          cout << "min_diff " << min_diff << endl;
      }

      if( ( hour + min_flag - local->tm_hour) < 0){
          std::cerr << "calc error " << std::endl;
      }
      else{
          hour_diff = hour - local->tm_hour;
          cout << "hour_diff " << hour_diff << endl;
      }

      long diff = hour_diff * 3600 + min_diff * 60 + sec_diff;
      std::cout << "diff second is " << diff << std::endl;
      return diff;
}
long getUtcSecs(int hour, int min, int sec){
    struct tm *local;
    time_t t;   // long
    t =time(NULL);
    std::cout <<" utc time now is " << t << std::endl;    //seconds from 1900

    //
    local=localtime(&t);   //year - month - day , hour - minite - second
    std::cout <<"now hour is " <<  local->tm_hour << std::endl;
    std::cout <<"now min is " << local->tm_min << std::endl;
    std::cout <<"now sec is " << local->tm_sec << std::endl;

    //
    struct tm mmm{sec , min, hour , local->tm_mday , local->tm_mon, 2019-1900};
      time_t ttt;

      ttt = mktime(&mmm);
      cout << "utc time of month: " << local->tm_mon + 1 << " day: " << local->tm_mday <<" hour: " \
      << hour << " min: " << min << " sec: " << sec << " utc clocks " <<  ttt << endl;
      return ttt;
}

//struct tm
//{
//    int tm_sec;
//    int tm_min;
//    int tm_hour;
//    int tm_mday; // [0-11]
//    int tm_mon;  //[1-31]
//    int tm_year;
//    int tm_wday;
//    int tm_yday;
//    int tm_isdst;
//};

int main()
{
    struct tm *local, *local2;
    time_t t;   // long
    t =time(NULL);
    cout << t << endl;    //seconds from 1970

    //
    local=localtime(&t);   //year - month - day , hour - minite - second
    cout << local->tm_hour << endl;
    cout << local->tm_min << endl;
    cout << local->tm_sec << endl;

//    local2 = gmtime(&t); // < 8h than beijing time utc ?
//    cout << local2->tm_hour << endl;
//    cout << local2->tm_min << endl;
//    cout << local2->tm_sec << endl;

      int hour = 22, min = 12, sec = 0;
      int hour_diff, min_diff, sec_diff;
      int secFlag, min_flag, hour_flag;

      if( (sec - local->tm_sec) < 0 ){
          secFlag = -1;
          sec_diff = 60 + sec - local->tm_sec;
          cout << "sec_diff " << sec_diff << endl;
      }
      else{
          secFlag = 0;
          sec_diff = sec - local->tm_sec;
          cout << "sec_diff " << sec_diff << endl;

      }

      if( ( min + secFlag - local->tm_min) < 0 ){
          min_flag = -1;
          min_diff = 60 + min - local->tm_min;
          cout << "min_diff " << min_diff << endl;

      }
      else{
          min_flag = 0;
          min_diff = min - local->tm_min;
          cout << "min_diff " << min_diff << endl;
      }

      if( ( hour + min_flag - local->tm_hour) < 0){
          std::cerr << "calc error " << std::endl;
      }
      else{
          hour_diff = hour - local->tm_hour;
          cout << "hour_diff " << hour_diff << endl;
      }

      long diff = hour_diff * 3600 + min_diff * 60 + sec_diff;
      std::cout << "diff second is " << diff << std::endl;


      //create utc seconds from 1900

      struct tm mmm{50 , 3, 11 , 30 , 6, 2019-1900};
      time_t ttt;

//      mmm.tm_year = 2019;
//      mmm.tm_mon = 06;
//      mmm.tm_mday = 30;
//      mmm.tm_hour = 11;
//      mmm.tm_min = 03;
//      mmm.tm_sec = 50;

      ttt = mktime(&mmm);
      cout << "utc time of 2019.6.30  11:03:50 " << ttt << endl;

    return 0;
}

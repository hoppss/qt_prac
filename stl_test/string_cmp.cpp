#include <string>
#include <iostream>


using namespace  std;

int main(){
    string evt1 = "EVT1.0";
    string evt2 = "EVT2.0";
    string evt2_1 = "EVT2.1";
    string dvt1 = "DVT1.0";


    if(evt1 < evt2) cout << "EVT2.0 > EVT1.0" << endl;

    if(evt2_1 > evt2) cout << "EVT2.1 > EVT2.0" << endl;

}

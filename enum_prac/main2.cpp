#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

enum mode{
    pos=1,
    vel=2,
    cur=3,
};
class publish{
public:
    publish(){
        nData = vector<int>(3,0);
    }
    //~publish();
    void set(std::vector<double> v)
    {
        if(v.at(0) != 0.0){
            cout << mode::pos << endl;}
        else if(v.at(1)!= 0.0){
            cout << mode::vel << endl;}
        else if(v.at(2)!=0.0){
            cout << mode::cur << endl;}

    }
    std::vector<int> nData;
};
int main()
{

    string s;
    publish pb;
    vector<double> v;
    while(getline(cin,s))
    {
        stringstream ss(s);
        string temp;
        while(getline(ss,temp,' ')){
            v.push_back(stod(temp));
            pb.set(v);
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}

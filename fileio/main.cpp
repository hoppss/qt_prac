#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


class myifstream
{
public:
    myifstream(const string filename):myFileName_(filename),countLine_(0){
//        myif_.open(filename);
//        if(!myif_.is_open()){
//            cout << "open error!" << endl;
//        }

    }
    ~myifstream(){
        cout << " deconstruct~!" << endl;
        cout << "total line count number is" << countLine_ << endl;
        myif_.close();
    }
    int countLines(){
        myif_.open(myFileName_);
        int cnt= 0 ;
        if(!myif_.is_open()){
            cout << "file open error!" << endl;
            return -1;
        }
        else{
            string temp;
            while(std::getline(myif_,temp)){
                cnt++;
            }
            myif_.close();
            countLine_ = cnt;
            return cnt;
        }
    }
    void getLinesFromFiles(){
        myif_.open(myFileName_);
        while(getline(myif_,jointsPos_)){
            countLine_++;
            line2vector(jointsPos_,pos_);
            print(pos_);
            pos_.clear();
        }
    }
    void line2vector(const string& s, vector<int>& vi){
        stringstream ss(s);
        int cnt = 0;
        string temp;
        while(getline(ss,temp,',') && cnt < 9){
            vi.push_back(std::stoi(temp));
            cnt++;
        }
    }
    void print(vector<int>& vi){
        cout << "Printing _____________" << endl;
        for(auto it = vi.begin();it != vi.end(); it++)
        {
            cout << " - " << *it << " - " ;
        }
        cout << endl;
    }
private:
    string myFileName_;
    string jointsPos_;
    vector<int> pos_;
    ifstream myif_;
    int countLine_;

};
int main()
{
    myifstream myif("/home/limao/Documents/qt_prac/ifstream/joints.txt");
    cout << myif.countLines() << endl;

    myif.getLinesFromFiles();


    return 0;
}

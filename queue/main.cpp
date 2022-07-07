#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
//    std::queue<int> my_q;
//    for(int i = 0; i< 10; ++i){
//        my_q.push(i);
//        cout << my_q.size() << " ";
//    }

//    cout << endl;
//    while(!my_q.empty()){
//        cout << "front " << my_q.front()  << "\t\t\t now size is " << my_q.size() << endl;
//        my_q.pop();

//    }

    std::vector<int>  v, front;
    for (int i = 0; i < 10; ++i){
        v.push_back(100);
        front.push_back(i);
    }

    cout << endl << endl << v.size() << endl << front.size() << endl;

    //reverse cycle
    for(std::vector<int>::reverse_iterator it=front.rbegin();it != front.rend();++it){
        v.insert(v.begin(), *it);
        cout << *it << endl;
    }

//    for(std::vector<int>::iterator it=myvec.end()-1;it>=myvec.begin();it--)
    for(int i = 0; i < v.size() ; i++){
        cout << v.at(i) << " ";
    }
    return 0;
}

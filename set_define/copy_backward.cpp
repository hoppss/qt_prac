#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


int main(){
    std::vector<int> v{1,3,5,7,9,100};
    for(auto it= v.begin(); it != v.end(); ++it){
        std::cout << *it << " ";
    }

    std::cout << endl;

    std::vector<int> copy(v.size() + 10);

    std::copy_backward(v.end() - v.size(),v.end(),copy.end()); //doesnot resort data,  copy is same with v;

    for(auto it= copy.begin(); it != copy.end(); ++it){
        std::cout << *it << " ";
    }

}

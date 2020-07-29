#include <iostream>
#include <string>
#include <list>


using namespace std;


int main(int argc, char** argv){

    list<int> lists;
    lists.push_back(3);
    lists.push_back(4);
    lists.push_back(5);
    lists.push_back(0);
    lists.push_back(2);
    lists.push_back(1);
    lists.push_back(1000);
    lists.push_back(45);





    for(std::list<int>::iterator i = lists.begin(); i!= lists.end(); ++i){
        cout << "_ " << *i << std::endl;
    }

    cout << " " << std::endl;


    for(std::list<int>::iterator i = lists.begin(); i!= (lists.end()); ++i){
        auto ii = i;
        std::advance(ii, 4); // same to i+n, resort iterators

        cout << "+ " << *ii << std::endl;
    }
    //(i+4), (i+5),(i+6),(i+7), 8 (size, end is 8), 0, 1, 2, 3,
    return 0;
}

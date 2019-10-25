#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

    cout << "0 - size " << v.size() << endl;
    for(int i = 0; i < 14; ++i){
        cout << "____i " << i << "___\t";
        for(int j = 0; j < v.size(); ++j){
            cout << j << "_" ;
        }
        cout << endl << " %% i %3 " << i%3 << endl;
        if(i % 3 !=0){
            v.erase( v.begin() + i );
            cout  << "*** " << v.size() << endl;
        }
    }

    cout << "1 - size " << v.size() << endl;
    return 0;
}

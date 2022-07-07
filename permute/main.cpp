#include <iostream>
#include <vector>
using namespace std;

void help(vector<vector<int> > & res, vector<int> nums, int pos){
    if(pos == nums.size() - 1){
        res.push_back(nums);
        return;
    }
    else{
        for(int i = pos; i < nums.size(); ++i){
            swap(nums[i], nums[pos]);
            help(res, nums, pos + 1);
        }
    }
};

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        help(res, nums, 0);
        return res;
    };

int main()
{
    vector<int> vi{1,2,3};
    vector<vector<int>> vvi = permute(vi);
    for(auto it = vvi.begin();it != vvi.end();it++){
        cout << (*it).at(0) << " " << (*it).at(1) << " " << (*it).at(2)  << endl;
    }
    return 0;
}

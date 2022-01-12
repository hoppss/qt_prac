#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void print(const std::vector<double> & v) {
    for(auto & i : v) {
        std::cout << i << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::vector<double> data;
    for(int i=0; i<10; ++i) {
      data.push_back(i * 0.1);
    }
    // 0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9
    //                   ↑

    print(data);

    auto erase_it = std::find_if(
    std::rbegin(data), std::rend(data),
    [&](const auto & v) {
      return v < 0.;  // v < 0.6
    });
    std::cout << "erase_it " << *erase_it << std::endl;    // *erase_it = 0.5   //当=rend 输出一个特别小的数
    // data.erase(data.begin(), erase_it.base());   // 0.6 - 0.9
    if(erase_it.base() != data.begin()){
        data.erase(data.begin(), std::prev(erase_it.base()));  // 0.5 - 0.9
    }else {
        std::cerr << "outloop" << std::endl;
        if(erase_it == std::rend(data)) {
            std::cout << "rend" << std::endl;
        }
        data.erase(data.begin(), erase_it.base());  // api 没有风险， 0 删除
    }

    print(data);
}

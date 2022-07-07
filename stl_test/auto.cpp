#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void test(const std::vector<std::shared_ptr<int>>& vec) {
   // auto
   // 这里auto带不带&， 因为即使是拷贝了，拷贝的只是指针，背后指向的元素不变
   int i = 0;
   for(auto& it : vec) {
    //    *it = *it * 10;
       std::cout << *it << " ";
       std::cout << "address: " << &it << " vs " << &vec[i] << std::endl; // auto & 同地址， 不加&, 地址不同
       ++i;
   }
   std::cout << std::endl << "original data" << std::endl;

   for(int i = 0;  i < vec.size(); ++i) {
       std::cout << *vec[i] << " ";
   }
   std::cout << std::endl;
}

void test_i(const std::vector<int>& vec) {
   // auto
   // 这里auto it 应该只是拷贝， 如果加上&, it+1 it 赋值就会报错
   int i = 0;
   for(auto it : vec) {
    //    it = it + 1;
       std::cout << it << " " << "" << std::endl;
       std::cout << "address: " << &it << " vs " << &(vec[i]) << std::endl; // auto & 同地址， 不加&, 地址不同
       ++i;
   }
   std::cout << std::endl << "original data" << std::endl;

   for(int i = 0;  i < vec.size(); ++i) {
       std::cout << vec[i] << " ";
   }
   std::cout << std::endl;
}



int main(int argc, char** argv) {

   std::vector<std::shared_ptr<int>>  vec;
   std::vector<int> vec_i;

   vec.reserve(5);
   vec_i.reserve(5);
   for(int i = 0;  i < 5; ++i) {
       auto ptr = std::make_shared<int>(i);
       vec.push_back(ptr);
       vec_i.push_back(i);
       std::cout << "-- address-- " << &vec[vec.size()-1] << " . ptr_adress " << &ptr <<  std::endl;
   }


   for(int i = 0;  i < vec.size(); ++i) {
       std::cout << *vec[i] << " ";
   }
   std::cout << std::endl << "auto " << std::endl;

   test(vec);

//    test_i(vec_i);



   return 0;
}
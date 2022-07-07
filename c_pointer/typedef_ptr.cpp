#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

// https://www.cnblogs.com/mq0036/p/3382732.html
class Node {


    public:
      Node(int num) : x(num) {
        std::cout << "Node_C: " << x << std::endl;
      }

      void show() {
       std::cout << "Node_S: " << x << "\t";
      }

    typedef Node* Ptr;

    private:
      int x;
};



int main(int argc, char** argv) {
  Node::Ptr p = new Node(10);  // ok, p是指针，
  Node::Ptr* ptr = nullptr;    // ptr 是指针的指针，是指向指针的指针
  // ptr = p;   // 非法
  ptr = &p;

  std::cout << "Node::Ptr* pointer to pointer\n";
  (*ptr)->show();

  cout << "\n\n\n";
    // 坐标属于（x, y） = (col_num, row_num) = (n, m)
  const int m = 5;  // rows - y
  const int n = 3;  // cols - x

  // 申请空间，但是都是空指针
  // x 维度
  // 先创建n个， 为了数组索引时方便， 第一位是x坐标
  Node::Ptr** pp = new Node::Ptr*[n];


  for (int i = 0; i < n; ++i) {
    pp[i] = new Node::Ptr[m];

    for (int j = 0; j < m; ++j)
    {
      pp[i][j] = nullptr;
    }
  }

  // set data, i: x_coor col index;   j: y_coor, row index

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
    {
      pp[j][i] = new Node(i * n + j);
    }
  }

  for (int i = 0; i < m; ++i) {

    for (int j = 0; j < n; ++j)
    {
      pp[j][i]->show();
    }

    cout << endl;
  }
}

/**
  Node::Ptr  = (Node*)  // 数据类型是指针
  Node::Ptr *  指针数组， (Node*) *p  = (Node*) p[]

  Node::Ptr *** ppp 指针数组， （Node*）***ppp = (Node*)ppp [][][]  // 三个* 三维数组，元素是指针

  Node array[][][] = Node()
  Node::Ptr array[][][] = &object;


  // 数组指针
  int a[3] = {1,2,3};
  void fun(int* ptr, int k);  // 把a 传给ptr， k 用来防止越界

  int (*p)[3]    // p 是 数组指针， p 指针 指向一个大小为3的数组；
                 // 数组指针，也叫行指针； [3] 是p的步长； p+1 跨过整个步长


  int a[3][4];
  int (*p)[4]; //该语句是定义一个数组指针，指向含4个元素的一维数组。
  p=a;         //将该二维数组的首地址赋给p，也就是a[0]或&a[0][0]
  p++;         //该语句执行过后，也就是p=p+1; p跨过行a[0][]指向了行a[1][]

  所以数组指针也称指向一维数组的指针，亦称行指针。

  // 指针数组
  int *p[3] = (int*) p[3],  // 数据类型 是 指针， p 是 数组
 */



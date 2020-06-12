#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <queue>

using namespace  std;

/*Student结构bai体*/
struct Student {
    Student(string name_, int age_, string sex_):name(name_),age(age_), sex(sex_){};
    Student(){};
    Student(int age_):age(age_){};
    string name;
    int age;
    string sex;
};
typedef std::shared_ptr<Student> StudentPtr;

struct CompareStudent {
  bool operator()(StudentPtr a, StudentPtr b) {
    return (a->age > b->age); //candidates, FIFO,  lower age range front
    //>   first > second, less type, lower front
    //<   first < second, greater type, bigger front
  }
};


int main(){
    //<, , ,> range
    //<,>     not range
    std::priority_queue<StudentPtr, std::vector<StudentPtr>, CompareStudent> candidates;

    std::shared_ptr<Student> p1 = std::make_shared<Student>(10);
    candidates.push(p1);

    std::shared_ptr<Student> p2 = std::make_shared<Student>(20);
    candidates.push(p2);

    std::shared_ptr<Student> p3 = std::make_shared<Student>(12);
    candidates.push(p3);

    std::shared_ptr<Student> p4 = std::make_shared<Student>(1);
    candidates.push(p4);

    size_t size = candidates.size();
    std::cout << size << std::endl;
    for(int i=0; i< size; ++i){
        auto p = candidates.top();
        cout << p->age << std::endl;
        candidates.pop();
    }


}


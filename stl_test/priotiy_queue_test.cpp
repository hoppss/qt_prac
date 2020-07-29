#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <queue>
#include <list>

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
    std::vector<StudentPtr> vec;
    std::list<StudentPtr> list;

    std::shared_ptr<Student> p1 = std::make_shared<Student>(10);
    candidates.push(p1);

    vec.push_back(p1);
    list.push_back(p1);

    std::shared_ptr<Student> p2 = std::make_shared<Student>(20);
    candidates.push(p2);

    vec.push_back(p2);
    list.push_back(p2);

    std::shared_ptr<Student> p3 = std::make_shared<Student>(12);
    candidates.push(p3);

    vec.push_back(p3);
    list.push_back(p3);

    std::shared_ptr<Student> p4 = std::make_shared<Student>(1);
    candidates.push(p4);

    vec.push_back(p4);
    list.push_back(p4);

    size_t size = candidates.size();
    std::cout << size << std::endl;
    auto p = candidates.top();

    for(int i=0; i< size; ++i){
        p = candidates.top();
        cout << p->age << std::endl;
        candidates.pop();
    }


    std::cout << "eeeeee" << candidates.size() << " " << p->age << std::endl; //even candidate queue is clear, but top pointer object exits


    if( 3 > 5 - 3){
        cerr << "go" << endl;
    }


    for(auto i = vec.begin(); i != vec.end(); ++i){
        std::cout << "vec begin " << (*i)->age <<"  " << *i << std::endl;
    }

    cout << std::endl;

    for(auto i = list.begin(); i != list.end(); ++i){
        std::cout << "list begin " << (*i)->age << " " << *i << std::endl;
    }

    cout << std::endl;



}


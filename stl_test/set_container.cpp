#include <iostream>
#include <set>
using namespace std;

/*Student结构bai体*/
struct Student {
    Student(string name_, int age_, string sex_):name(name_),age(age_), sex(sex_){};
    Student(){};
    string name;
    int age;
    string sex;
};

/*“仿函数"。为Student set指定排序准则*/
class studentSortCriterion {
    public:
        bool operator() (const Student &a, const Student &b) const {
            /*先比较名du字；若名字相同，则比较年龄zhi。小的dao返回true*/
            if(a.name < b.name)
                return true;
            else if(a.name == b.name) {
                if(a.age < b.age)
                    return true;
                else
                    return false;
            } else
                return false;
        }
};
class studentSortCriterionptr {
    public:
        bool operator() (const Student* a, const Student* b) const {
            /*先比较名du字；若名字相同，则比较年龄zhi。小的dao返回true*/
            if(a->name < b->name)
                return true;
            else if(a->name == b->name) {
                if(a->age < b->age)
                    return true;
                else
                    return false;
            } else
                return false;
        }
};

int main()
{
    set<Student, studentSortCriterion> stuSet;

    Student stu1, stu2;
    stu1.name = "zhangsan";
    stu1.age = 13;
    stu1.sex = "male";

    stu2.name = "lisi";
    stu2.age = 23;
    stu2.sex = "female";

    stuSet.insert(stu1);
    stuSet.insert(stu2);

    /*构造一个测试的Student，可以看到，即使stuTemp与stu1实际上并不是同一个对象，
     *但当在set中查找时，仍会查找成功。这是因为已定义的studentSortCriterion的缘故。
     */
    Student stuTemp;
    stuTemp.name = "zhangsan";
    stuTemp.age = 13;

    set<Student, studentSortCriterion>::iterator iter;
    iter = stuSet.find(stuTemp);
    if(iter != stuSet.end()) {
        cout <<"yes" << (*iter).name << endl;
    } else {
        cerr << "Cannot fine the student!" << endl;
    }

    cerr  << "----------------------" << endl;


    set<Student*, studentSortCriterionptr> stuSet2;

    Student* stu1ptr;
    Student* stu2ptr;
    stu1ptr = new Student( "zhangsan",13, "male");

    stu2ptr = new Student("lisi", 23, "female");


    stuSet2.insert(stu1ptr);
    stuSet2.insert(stu2ptr);

    /*构造一个测试的Student，可以看到，即使stuTemp与stu1实际上并不是同一个对象，
     *但当在set中查找时，仍会查找成功。这是因为已定义的studentSortCriterion的缘故。
     */
    Student* stuTempptr = new Student("zhangsan",13,"male");

    set<Student*, studentSortCriterionptr>::iterator iter2;
    iter2 = stuSet2.find(stuTempptr); // functor actually check its name rather than pointer address
    if(iter2 != stuSet2.end()) {
        cout << "yes" << (*iter2)->name << endl;
    } else {
        cerr << "Cannot fine the student!" << endl;
    }
    return 0;
}

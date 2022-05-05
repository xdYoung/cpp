#include <iostream>
#include <list>
using namespace std;

// 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名，年龄，身高
// 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

class Person{
public:
    Person(string name, int age, int height):m_name(name),m_age(age),m_height(height){}
public:
    string getName()const{return m_name;}
    int getAge()const{return m_age;}
    int getHeight()const{return m_height;}
private:
    string m_name;
    int m_age;
    int m_height;
};

// 指定排序规则
bool personCompare(Person& p1, Person& p2){
    // return p1.getName() > p2.getName();
    if(p1.getAge() == p2.getAge()){
        return p1.getHeight() > p2.getHeight();
    }
    else{return p1.getAge() < p2.getAge(); }
}

void test01(){
    list<Person> lst;

    Person p1("young", 32, 176);
    Person p11("young1", 32, 180);
    Person p12("young2", 32, 179);
    Person p13("young3", 32, 181);
    Person p14("young4", 32, 177);
    Person p15("young5", 32, 188);
    Person p2("ting", 28, 167);
    Person p3("shohn", 30, 182);
    Person p4("peng", 29, 172);
    Person p5("chuan", 29, 170);
    Person p6("jindou", 29, 166);
    Person p7("nana", 26, 160);

    lst.push_back(p1);
    lst.push_back(p11);
    lst.push_back(p12);
    lst.push_back(p13);
    lst.push_back(p14);
    lst.push_back(p15);
    lst.push_back(p2);
    lst.push_back(p3);
    lst.push_back(p4);
    lst.push_back(p5);
    lst.push_back(p6);
    lst.push_back(p7);

    cout << "排序前： " << endl;
    for(list<Person>::iterator it = lst.begin(); it != lst.end(); it++){
        cout << "姓名： " << it->getName() << "  \t年龄： " << it->getAge() << "  \t身高： " << it->getHeight() << endl;
    }

    // 排序
    cout << "排序后： " << endl;
    // 如果操作的是自定义的数据类型，则排序需要指定排序的规则
    lst.sort(personCompare);
    for(list<Person>::iterator it = lst.begin(); it != lst.end(); it++){
        cout << "姓名： " << it->getName() << "  \t年龄： " << it->getAge() << "  \t身高： " << it->getHeight() << endl;
    }

    
}

int main(){
    test01();
    return 0;
}
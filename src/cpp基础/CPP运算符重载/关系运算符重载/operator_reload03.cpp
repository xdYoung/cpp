#include <iostream>
using namespace std;

class Person{
public:
    Person(string name="noName", int age=0):m_Name(name), m_Age(age){}
public:
    bool operator==(Person &p){
        return m_Age == p.m_Age;
    }
    bool operator!=(Person &p){
        return m_Age != p.m_Age;
    }
    bool operator>(Person &p){
        return m_Age > p.m_Age;
    }
    bool operator<(Person &p){
        return m_Age < p.m_Age;
    }
public:
    string getName(){ return m_Name; }
    void setName(string name){ m_Name = name; }
    int getAge(){ return m_Age; }
    void setAge(int age){ m_Age = age; }
private:
    string m_Name;
    int m_Age;
};

void test01(){
    Person p;
    p.setName("young");p.setAge(32);
    Person ting("ting", 28);
    cout << "初始化p的信息：" << "Name: " << p.getName() << ", Age: " << p.getAge() << endl;
    if(ting == p){
        cout << p.getName() << " 和 " << ting.getName() << " 年龄相等" << endl;
    }else{
        cout << p.getName() << " 和 " << ting.getName() << " 年龄不相等" << endl;
    }

    if(p > ting){
        cout << p.getName() << " 大于 " << ting.getName() << " 的年龄" << endl;
    }else if(p < ting){
        cout << p.getName() << " 小于 " << ting.getName() << " 的年龄" << endl;
    }else{
        cout << p.getName() << " 与 " << ting.getName() << " 的年龄相等" << endl;
    }

}

int main(){
    test01();
    return 0;
}
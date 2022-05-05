#include <iostream>
using namespace std;

// 模版对于自定义数据类型需要具体化自定义数据类型的版本实现代码，具体化的实现代码优先调用

// 声明Person类的数据类型
class Person;
// 声明比较函数的模版
template<typename T>
bool compare_custom(T &a, T &b);
// 声明具体化的比较函数模版，前面要加上 template<>
template<> bool compare_custom(Person &p1, Person &p2);

// Person的实现
class Person{
public:
    Person(){}
    Person(string name, int age){
        m_Name = name;
        m_Age = age;
    }
public:
    string getName(){return m_Name;}
    int getAge(){return m_Age;}
private:
    string m_Name;
    int m_Age;
};

// 测试案例
void test01(){
    int a = 1;
    int b = 2;
    if(compare_custom(a, b)) { cout << " a > b " << endl;}
    else { cout << " a < b " << endl;}

    cout << "-------------------------------------" << endl;

    // 自定义数据类型调用具体化的函数模版
    Person p1("young", 32);
    Person p2("ting", 28);
    if(compare_custom(p1, p2)) {cout << "p1和p2想等" << endl;}
    else {cout << "p1和p2不相等" << endl;}
}

int main(){
    test01();
    return 0;
}

// 模版compare的实现
template<typename T>
bool compare_custom(T &a, T &b){
    if(a > b) return true;
    else return false;
}

// 具体Person数据类型的compare函数模版的版本实现，优先调用
template<> bool compare_custom(Person &p1, Person &p2){
    if(p1.getName() == p2.getName() && p1.getAge() == p2.getAge()) return true;
    else return false;
}
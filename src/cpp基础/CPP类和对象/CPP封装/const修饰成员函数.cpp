#include <iostream>
using namespace std;

// const修饰成员函数
// 常函数：
    // 成员函数后加 const 后我们称这个成员函数为常函数
    // 常函数内不可以修改成员属性
    // 成员属性声明时加关键字 mutable 后，在常函数中就可以被修改了

// 常对象
    // 声明对象前加 const 称该对象为常对象
    // 常对象只能调用常函数

// 常函数
class Person{
public:
    // this指针的本质，是指针常量，指针常量的指向是不可以修改的。
    // this指针的本质：person* const this
    // 成员函数后加const本质是修饰的this指针，变成：const Person* const this，即指针指向的值也不允许修改了。
    void showPerson() const{
        // this->m_Name = "yang";  // 如果成员函数不加const，this指针指向的值可以修改。
        this->m_Age = 32;   // 成员函数加了const，成员函数变成常函数，成员属性加了mutable以后可以修改成员属性的值。
        //this = NULL;    // this指针不可以修改指针的指向的
    }
    string getName()const{ return m_Name;}
    int getAge()const{ return m_Age; }
    void setName(string name) {m_Name = name;}
    void setAge(int age)const{m_Age = age;}

public:
    mutable string lover;
private:
    string m_Name;
    mutable int m_Age;
};

void test01(){
    Person p;
    p.showPerson();
    cout << "Person::m_Age = " << p.getAge() << endl;
    cout << "Person::m_Name = " << p.getName() << endl;
}

// 常对象
void test02(){
    const Person p; // 对象前加了const，此对象就变成常对象
    //p.setName("young"); // const修饰了对象后，本质就是：const Person* const this;即指向对象的指针不可以修改指向并且指针指向的对象不可以修改值
    p.showPerson(); // 常对象可以调用常函数
    p.lover = string("ting");   // mutable修饰的成员属性可以被常对象修改
    // p.setName(); // 常对象不可以调用普通成员函数，因为普通成员函数可以修改成员属性的值，所有常对象只能调用常函数。
    cout << "Person::lover = " << p.lover << endl;
    p.setAge(28);
    cout << "Person::m_Name = " << p.getName() << endl;
    cout << "Person::m_Age = " << p.getAge() << endl;

    Person p1;
    p1.showPerson();    // 普通对象可以调用常函数
    
}

int main(){
    test01();
    test02();
    return 0;
}
#include <iostream>
using namespace std;

// 问题：当子类与父类出现同名的成员，如果通过子类对象，访问到子类或者父类中同名的数据？
    // 访问子类同名成员，直接访问即可
    // 访问父类同名成员，需要加作用域
    // 当子类与父类有同名的成员函数，子类会隐藏掉父类中所有的成员函数，加作用域可以访问到父类中的同名函数

class Base{
public:
    Base(){ m_A = 100; }
public:
    void func(){
        cout << "父类中的函数调用" << endl;
    }
    void func(int a){
        cout << "父类中->func(int a)的调用" << endl;
    }
public:
    int m_A;
};

class Sub:public Base{
public:
    void func(){
        cout << "子类中的函数调用" << endl;
    }
public:
    int m_A;
};

void test01(){
    Sub sub;
    sub.m_A = 200;
    cout << "子类中的同名成员属性" << sub.m_A << endl;
    cout << "子类中的同名成员函数 -> "; sub.func();

    cout << "父类中的同名成员属性" << sub.Base::m_A << endl;
    cout << "父类中的同名成员函数 -> "; sub.Base::func();
    sub.Base::m_A = 300;
    cout << "父类中的同名成员属性" << sub.Base::m_A << endl;

    // 如果子类中出现和父类同名的成员函数，子类的同名成员函数会隐藏掉父类中所有的同名成员函数，包括重载的同名成员函数
    // 如果像访问到父类中被隐藏的同名成员函数，需要加作用域
    sub.Base::func(500);
}
int main(){
    test01();
    return 0;
}
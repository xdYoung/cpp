#include <iostream>
using namespace std;

// 问题：继承中同名静态成员在子类对象上如何进行访问？
    // 静态成员和非静态成员出现同名，处理方式一致
    // 访问子类同名成员，直接访问即可
    // 访问父类同名成员，需要加作用域
    // 当子类与父类有同名的成员函数，子类会隐藏掉父类中所有的成员函数，加作用域可以访问到父类中的同名函数

class Base{
public:
    // Base(){ m_A = 100; }
public:
    // 静态成员函数
        // 所有对象共享同一个函数
        // 静态成员函数只能访问静态成员变量
    static void func(){
        cout << "Base -> static func()调用" << endl;
    }
    static void func(int a){
        cout << "Base -> static func(int a)调用" << endl;
    }
    static void bfunc(){
        cout << "Base -> static bfunc()调用" << endl;
    }
public:
    // 静态成员属性，所有对象共享同一份数据
    // 静态成员属性，类内声明，类外初始化。
    // 因为静态成员属性在编译阶段就分配内存，先于对象创建，所以不能在构造函数中初始化。
    static int m_A;
};
int Base::m_A = 100;

class Sub:public Base{
public:
    Sub(){ m_A = 200; }
public:
    void func(){
        cout << "Sub -> func()调用" << endl;
    }
    static void func(int a){
        cout << "Sub -> func(int a)调用" << endl;
    }
public:
    // static int m_A;
    int m_A;
};
// int Sub::m_A = 200;

void test01(){
    // 通过对象访问同名成员属性
    cout << "通过对象访问同名成员属性: " << endl;
    Sub sub;
    cout << "Sub sub.m_A = " << sub.m_A << endl;
    cout << "Base sub.Base::m_A = " << sub.Base::m_A << endl;
    cout << endl;
    // 通过类名访问同名成员属性
    cout << "通过类名访问同名成员属性：" << endl;
    // cout << "Sub::m_A = " << Sub::m_A << endl;
    cout << "Sub::Base::m_A = " << Sub::Base::m_A << endl;
    cout << endl;

    // 通过对象访问同名成员函数
    cout << "通过对象访问同名成员函数: " << endl;
    sub.func();
    sub.Base::func();
    // 子类和父类有同名函数，子类会隐藏掉父类所有的成员函数，加作用域可以访问到父类的成员函数
    sub.Base::func(300);
    cout << endl;

    // 通过类名访问同名成员函数
    cout << "通过类名访问同名成员函数：" << endl;
    Sub::func(100);
    Sub::Base::func();
    Sub::Base::func(200);
    Sub::bfunc();
    cout << endl;
}

int main(){
    test01();
    return 0;
}
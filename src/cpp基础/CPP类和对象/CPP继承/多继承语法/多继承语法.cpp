#include <iostream>
using namespace std;

// C++允许一个类继承多个类
// 语法：class 子类：继承方式 父类1，继承方式 父类2，...
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分
// C++实际开发中不建议用多继承

class Base01{
public:
    Base01(){
        m_A = 100;
        m_Base = 101;
    }
    int m_A;
    int m_Base;
};

class Base02{
public:
    Base02(){
        m_B = 200;
        m_Base = 102;
    }
    int m_B;
    int m_Base;
};

// 子类，需要继承 Base01 和 Base02
class Sub:public Base01, public Base02{
public:
    Sub(){
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

void test01(){
    Sub sub;
    cout << "sizeof(sub) = " << sizeof(sub) << endl;
    cout << "sub.Base::m_A = " << sub.m_A << endl;
    cout << "sub.Base::m_B = " << sub.m_B << endl;
    cout << "sub.m_C = " << sub.m_C << endl;
    cout << "sub.m_D = " << sub.m_D << endl;
    // 当多继承的父类中出现了同名的成员，需要加作用域加以区分
    // cout << "m_Base = " << sub.m_Base << endl;
    cout << "Base01::m_Base = " << sub.Base01::m_Base << endl;
    cout << "Base02::m_Base = " << sub.Base02::m_Base << endl;
}

int main(){
    test01();
    return 0;
}
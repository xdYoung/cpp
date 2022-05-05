#include <iostream>
#include <ostream>
using namespace std;

class Person{
    // 左移运算符重载不能使用成员函数重载，只能用全局函数运算符重载。
    friend ostream& operator<<(ostream &cout, Person &p); // 友元可以访问类中的私有属性
public:
    Person(int a, int b=10):m_A(a), m_B(b){}
    // 利用成员函数重载 左移运算符。本质是 p.operator<<(cout)，简化为 p << cout 。
    // 不会利用成员函数重载左移动运算符，不能实现 cout 在左边。
    // void operator<<(ostream &cout){};

private:
    int m_A;
    int m_B;
};
// 只能利用全局函数重载左移运算符，本质是oprator<<(cout, p)， 简化形式为：cout << p;
// 需返回cout对象的引用，打印了p后还是返回cout的引用。链式编程。
ostream& operator<<(ostream &cout, Person &p){
    cout << "m_A =  " << p.m_A << ", m_B = " << p.m_B;
    return cout;
}

void test01(){
    Person p(10);
    cout << p << endl;
}

int main(){
    test01();
    // system("pause");
    return 0;
}
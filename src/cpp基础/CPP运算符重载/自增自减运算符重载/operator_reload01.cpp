#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class MyInt{
    friend ostream& operator<<(ostream & cout, MyInt myInt);
public:
    MyInt(int a):m_Int(a){}
public:
    // 前置++运算符重载，需要返回引用为了一直对一个数据进行递增操作
    MyInt& operator++(){
        m_Int++;
        return *this;   // this是指代自身的指针
    }
    // 重载后置++运算符，传入一个占位参数，编译器会自动区分前置和后置操作
    MyInt operator++(int){
        MyInt temp = *this;
        m_Int++;
        return temp;
    }

    MyInt& operator--(){
        m_Int--;
        return *this;   // this是指代自身的指针
    }

    MyInt operator--(int){
        MyInt temp = *this;
        m_Int--;
        return temp;
    }
private:
    int m_Int;
};
// 这里不可以穿入myInt的引用，引用的本质是指针常量，指针的指向不可以修改。
// 如果穿入引用，对于后置++/--运算，改变了指针的指向会报错。
ostream& operator<<(ostream & cout, MyInt myInt){
    cout << myInt.m_Int << endl;
    return cout;
}
// 重载++运算符
void test01(){
    MyInt myInt(0);
    cout << "myInt的初始值： " << myInt << endl;
    cout << "前置++运算符重载，前置++之前" << ++myInt << endl;
    cout << "前置++运算符重载，前置++之后" << myInt << endl;
    cout << "后置++运算符重载，后置++之前" << myInt++ << endl;
    cout << "后置++运算符重载，后置++之后" << myInt << endl;
}

// 重载--运算符
void test02(){
    MyInt myInt(0);
    cout << "myInt的初始值： " << myInt << endl;
    cout << "前置--运算符重载，前置--之前" << --myInt << endl;
    cout << "前置--运算符重载，前置--之后" << myInt << endl;
    cout << "后置--运算符重载，后置--之前" << myInt-- << endl;
    cout << "后置--运算符重载，后置--之后" << myInt << endl;
}

int main(){
    test01();
    test02();
    return 0;
}
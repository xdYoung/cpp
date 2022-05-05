#include <iostream>
using namespace std;

// 函数对象概念
    // 重载函数调用()操作符的类，其对象常称为函数对象
    // 函数对象使用重载的()时，行为类似函数调用，也叫仿函数
// 本质：函数对象（仿函数）是一个类，不是一个函数

// 函数对象使用：
// 特点：
    // 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
    // 函数对象超出普通函数的概念，函数对象可以有自己的状态
    // 函数对象可以作为参数传递

void printLine(){
    cout << "-------------------------------------" << endl;
}

class AddTwoNum{
public:
    int operator()(int n1, int n2){
        return n1 + n2;
    }
};
// 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01(){
    AddTwoNum addTwoNum;
    cout << addTwoNum(10, 10) << endl;
}

class MyPrint{
public:
    MyPrint(int count=0):m_count(count){}
public:
    void operator()(string test){
        cout << test << endl;
        m_count++;
    }
    int m_count;  // 内部可以添加自己的状态
};
// 函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02(){
    MyPrint myPrint;
    cout << "初始化时myPrint调用的次数为： " << myPrint.m_count << endl;
    myPrint("hello world!");
    myPrint("hello world!");
    myPrint("hello world!");
    myPrint("hello world!");
    cout << "myPrint调用的次数为： " << myPrint.m_count << endl;
}

// 函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test){
    mp(test);
    cout << "打印的次数为： " << mp.m_count << endl;
}

void test03(){
    MyPrint myPrint;
    doPrint(myPrint, "hello world!!!!!!");
}

int main(){
    test01();
    printLine();
    test02();
    printLine();
    test03();
    return 0;
}
#pragma once
#include <iostream>
using namespace std;

// 类模版成员函数的类外实现
template<class T1, class T2>
class Base{
public:
    // Base(T1 t1, T2 t2){
    //     this->t1 = t1;
    //     this->t2 = t2;
    // }
    // 构造函数的类外实现
    Base(T1 t1, T2 t2);
public:
    // T1 getT1(){return t1;}
    // T2 getT2(){return t2;}
    // 成员函数的类外实现
    T1 getT1();
    T2 getT2();
private:
    T1 t1;
    T2 t2;
};

// 类模版之构造函数的类外实现
template<class T1, class T2>
Base<T1, T2>::Base(T1 t1, T2 t2){
    this->t1 = t1;
    this->t2 = t2;
}
// 类模版之成员函数的类外实现
template<class T1, class T2>
T1 Base<T1, T2>::getT1(){return t1;}
template<class T1, class T2>
T2 Base<T1, T2>::getT2(){return t2;}
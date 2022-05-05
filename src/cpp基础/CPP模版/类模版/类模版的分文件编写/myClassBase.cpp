#include "../../../../../include/myClassBase.h"

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
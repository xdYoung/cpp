#include <iostream>
using namespace std;
// #include "../../../../../include/myClassBase.h"
// 第一种方式：直接包含.cpp文件
#include "myClassBase.cpp"

// 掌握类模版成员函数的分文件编写产生的问题以及解决方式
// 问题：类模版中成员函数的创建时机时在调用阶段，导致分文件编写时链接不到
// 解决：
    // 解决方式1: 直接包含.cpp源文件
    // 解决方式2: 将声明和实现写到同一个文件中，并更改后缀名为.hpp ， hpp是约定的名称，并不是强制

void test01(){
    Base<char, int> base('a', 10);
    cout << "Base类模版成员函数的类外实现，Base::t1 = " << base.getT1() << endl;
    cout << "Base类模版成员函数的类外实现，Base::t2 = " << base.getT2() << endl;
}

int main(){
    test01();
    return 0;
}
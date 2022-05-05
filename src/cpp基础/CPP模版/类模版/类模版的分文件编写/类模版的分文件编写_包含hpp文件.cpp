#include <iostream>
using namespace std;
// 第二种方式：将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
// 总结：主流的解决方式是第二种，将类模版成员函数写到一起，并将后缀名改为.hpp
#include "../../../../../include/myClassBase.hpp"

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
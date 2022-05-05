#include <iostream>
using namespace std;

// 普通函数与函数模版的区别：
    // 普通函数调用时可以发生自动类型转换（隐式类型转换）
    // 函数模版调用时，如果利用自动类型推导，不会发生隐式类型转换
    // 如果函数模版利用显式指定类型的方式，可以发生隐式类型转换

// 1.普通函数调用可以发生隐式类型转换
// 2.函数模版，用自动类型推导，不可以发生隐式类型转换
// 3.函数模版，用显式指定类型，可以发生隐式类型转换

// 普通函数
int myAdd(int a, int b){
    return a + b;
}

// 函数模版
template<typename T>
T myAdd01(T a, T b){
    return a + b;
}

void test01(){
    // 普通函数可以发生隐生类型转化
    int a = 10;
    int b = 20;
    char c = 'c'; // 对应的ascii码： a - 97 c - 99 ， 发生了隐式类型转换
    cout << endl;
    cout << "myAdd(a,b): (int)a + (int)b = " << myAdd(a, b) << endl;
    cout << "普通函数发生隐式类型转换：" << "myAdd(a,b): (int)a + (char)c = " << myAdd(a, c) << endl;
    cout << "-------------------------------------" << endl;

    // 函数模版如果是自动类型推导，不可以发生隐式类型转换
    cout << "函数模版进行自动类型推导，不可以发生隐式类型转换：" << "myAdd01(a,b): (int)a + (int)b = " 
         << myAdd01(a, b) << endl;
    // 函数模版进行自动类型推导，不可以发生隐生类型转换，报错了！
    // cout << "函数模版进行自动类型推导：" << "(int)a + (char)c = " << myAdd01(a, c) << endl;
    cout << "-------------------------------------" << endl;

    // 函数模版如果是显式指定了类型，就可以发生隐式类型转换
    cout << "函数模版显示指定了类型：" << "myAdd01<int>(a,b): (int)a + (int)b = " 
         << myAdd01<int>(a, b) << endl;
    cout << "函数模版显示指定了类型，可以进行隐式类型转换：" << "myAdd01<int>(a,b): (int)a + (char)c = " 
         << myAdd01<int>(a, c) << endl;
    cout << endl;


}

int main(){
    test01();
    return 0;
}
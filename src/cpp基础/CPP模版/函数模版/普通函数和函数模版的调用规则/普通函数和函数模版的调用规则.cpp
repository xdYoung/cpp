#include <iostream>
using namespace std;

// 普通函数和函数模版的调用规则：
    // 如果函数模版和普通函数都可以实现，优先调用普通函数
    // 可以通过空模版参数列表来强制调用函数模版
    // 函数模版也可以发生重载
    // 如果函数模版可以产生更好的匹配，优先调用函数模版

void myPrint(int a, int b){
    cout << "调用了普通函数！" << endl;
}

template<typename T>
void myPrint(T a, T b){
    cout << "调用了函数模版！" << endl;
}

template<typename T>
void myPrint(T a, T b, T c){
    cout << "调用了重载的函数模版！" << endl;
}

void test01(){
    int a = 1;
    int b = 1;
    // 普通函数和函数模版都有实现，优先调用普通函数
    myPrint(a, b);
}

void test02(){
    int a = 1;
    int b = 2;
    // 通过空模版参数列表或者有参数的列表，可以强制调用函数模版
    myPrint<>(a, b);
    myPrint<int>(a, b);
}

void test03(){
    int a = 1;
    int b = 2;
    int c = 3;
    // 函数模版也可以发生函数重载
    myPrint<>(a, b, c);
}

void test04(){
    char c1 = 'a';
    char c2 = 'b';
    int c3 = 10;
    // 如果函数模版可以产生更好的匹配，优先调用函数模版
    // 因为普通函数的参数是int类型的，需要发生隐式的类型转换，而模版只需推导出来是char就行，更好的匹配了。
    myPrint(c1, c2);

    // 如果是不同类型的，则调用普通函数更好匹配
    myPrint(c1, c3);
    // 如果调用模版，需显式指定参数类型，才可以进行隐式类型转换
    myPrint<int>(c1,c3);
}

int main(){
    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}
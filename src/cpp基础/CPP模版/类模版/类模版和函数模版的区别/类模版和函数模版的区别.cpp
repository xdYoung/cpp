#include <iostream>
#include <string>
using namespace std;

// 类模版和函数模版的区别：
    // 1.类模版没有自动类型推导的使用方式
    // 2.类模版在模版参数列表中可以有默认参数

// 类模版在模版的参数列表中可以有默认参数
template<typename T1, typename T2=int>
class Vector_Custom{
public:
    Vector_Custom(T1 t1, T2 t2){
        m_t1 = t1;
        m_t2 = t2;
    }
public:
    T1 getT1(){return m_t1;}
    T2 getT2(){return m_t2;}
private:
    T1 m_t1;
    T2 m_t2;
};

void test01(){
    // 类模版没有自动类型推导的使用方式
    // Vector_Custom<> vc("hello", 10); // 错误，无法使用自动类型推导
    Vector_Custom<string, int> vc("hello", 10); // 正确，只能使用显式指定类型
    cout << "vc.m_t1 = " << vc.getT1() << ", vc.m_t2 = " << vc.getT2() << endl;
}

void test02(){
    // 类模版在模版参数列表中可以有默认参数
    Vector_Custom<string, char> vc("world", 99);
    cout << "vc.m_t1 = " << vc.getT1() << ", vc.m_t2 = " << vc.getT2() << endl;
}

int main(){
    test01();
    cout << "------------------------------------" << endl;
    test02();
    return 0;
}
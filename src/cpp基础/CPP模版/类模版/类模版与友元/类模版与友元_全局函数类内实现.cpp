#include <iostream>
using namespace std;

// 学习目标：掌握类模版配合友元函数的类内和类外实现
// 全局函数类内实现 - 直接在类内声明友元即可
// 全局函数类外实现 - 需要提前让编译器知道全局函数的存在

// 通过全局函数，显示类中私有的成员属性
template<class T1, class T2>
class Base{
    // 全局函数类内实现 - 直接在类内声明友元即可
    friend T1 getT1(Base<T1, T2> &base){return base.m_t1;}
    friend T2 getT2(Base<T1, T2> &base){return base.m_t2;}
public:
    Base(T1 t1, T2 t2){
        m_t1 = t1;
        m_t2 = t2;
    }
private:
    T1 m_t1;
    T2 m_t2;
};

// 全局函数在类内实现的测试
void test01(){
    Base<string, int> base("young", 32);
    cout << "全局函数类内实现：m_t1 = " << getT1(base) << endl;
    cout << "全局函数类内实现：m_t2 = " << getT2(base) << endl;
}

int main(){
    test01();
    return 0;
}
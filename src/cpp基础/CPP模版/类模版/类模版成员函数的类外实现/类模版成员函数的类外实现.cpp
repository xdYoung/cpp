#include <iostream>
using namespace std;

// 总结：类模版中成员函数的类外实现时，需要加上类模版参数列表的作用域，每个成员函数都需要加上template<class T1, ...>
// 语法：
    // template<class T1, class T2>
    // 返回值类型参数1 类模版名<T1, T2>::成员函数(){ 实现代码 }
    // template<class T1, class T2>
    // 返回值类型参数2 类模版名<T1, T2>::成员函数(){ 实现代码 }

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

void test01(){
    Base<char, int> base('a', 10);
    cout << "Base类模版成员函数的类外实现，Base::t1 = " << base.getT1() << endl;
    cout << "Base类模版成员函数的类外实现，Base::t2 = " << base.getT2() << endl;
}

int main(){
    test01();
    return 0;
}
#include <iostream>
using namespace std;

// 类模版对象做函数的参数
// 一共有三种传入的方式：
    // 1.指定传入的类型：传入对象直接显示指定数据类型
    // 2.类对象参数模版化：将传入对象中的参数变为模版进行传递
    // 3.整个类对象模版化：将这个对象类型模版化进行传递
// 开发中，使用比较广泛的是第一种方式：指定传入函数的对象类型

template<class T1, class T2>
class A{
public:
    A(T1 t1, T2 t2){
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

// 1.指定传入类型
void showA01(A<string, int> &a){
    cout << "指定传入类型的方式：a.m_t1 = " << a.getT1() << endl;
    cout << "指定传入类型的方式：a.m_t2 = " << a.getT2() << endl;
}
void test01(){
    A<string, int> a("young", 32);
    showA01(a);
}

// 2.传入函数的对象参数模版化
template<class T1, class T2>
void showA02(A<T1, T2> &a){
    cout << "传入函数的对象参数模版化：a.m_t1 = " << a.getT1() << endl;
    cout << "传入函数的对象参数模版化：a.m_t2 = " << a.getT2() << endl;
    // 函数typeid()可以查看数据类型
    cout << "T1的数据类型为：" << typeid(T1).name() << endl;
    cout << "T2的数据类型为：" << typeid(T2).name() << endl;
}
void test02(){
    A<string, int> a("ting", 28);
    showA02(a);
}

// 3.传入函数的对象类型整个模版化
template<class T>
void showA03(T &a){
    cout << "传入函数的对象类型整个模版化：a.m_t1 = " << a.getT1() << endl;
    cout << "传入函数的对象类型整个模版化：a.m_t2 = " << a.getT2() << endl;
    cout << "T的数据类型为：" << typeid(T).name() << endl;
}
void test03(){
    A<string, int> a("shohn", 30);
    showA03(a);
}

int main(){
    test01();
    cout << "-------------------------------------------" << endl;
    test02();
    cout << "-------------------------------------------" << endl;
    test03();
    return 0;
}
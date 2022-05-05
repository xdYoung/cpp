#include <iostream>
using namespace std;

// 当类模版碰到继承时，需要注意以下几点：
    // 当子类继承的父类时一个类模版时，子类在声明的时候，需指定出父类中T的类型
    // 如果不指定，编译器无法给子类分配内存，因为子类不知道类型就无法确定分配的内存大小
    // 如果想灵活的指定出父类中T的类型，子类也需要变成类模版，子类模版需要指定出父类中T的数据类型

// 类模版与继承
template<class T>
class Base{
    // 类模版中的成员属性和成员函数不加权限，默认时私有权限
    T m;
public:
    T getM(){return m;}
    void setM(T m){this->m = m;}
};

// class Sub:public Base{}; // 错误，必须要知道父类中的T数据类型，才能继承给子类。因为不指定T的数据类型，子类无法确定分配多少空间
class Sub01:public Base<int>{
public:
    int m;
};

void test01();

// 如果想灵活指定父类中的T数据类型，子类也需要变成类模版，并且需要指定出父类中T的数据类型
template<class T1, class T2=string>
class Sub02:public Base<T2>{
public:
    Sub02(){
        cout << "T1的数据类型为： " << typeid(T1).name() << endl;
        cout << "T2的数据类型为： " << typeid(T2).name() << endl;
    }
public:
    T1 m;
};

void test02();

int main(){
    test01();
    cout << "------------------------------------" << endl;
    test02();
    return 0;
}

void test01(){
    Sub01 s01;
    s01.m = 100;
    s01.setM(520);
    cout << "这是子类Sub01的成员属性m： " << s01.m << endl;
    cout << "这是父类Base的成员属性m： " << s01.getM() << endl;
}

void test02(){
    Sub02<int> s02;
    s02.m = 520;
    s02.setM("ting");
    cout << "这是子类Sub02的成员属性m： " << s02.m << endl;
    cout << "这是父类Base的成员属性m： " << s02.getM() << endl;
}


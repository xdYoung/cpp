#include <iostream>
using namespace std;

// C++多态原理分析
class Animal{
    // c++中类的成员属性和成员函数是分开存储的
    // sizeof(Animal) = 1;
    // 所以空类占一个字节空间作为占位，以区分不同的类对象
public:
    void spark(){
        cout << "动物在叫叫啊！" << endl;
    }
};

class Animal_Virtual_Func{
    // 如果在父类的成员函数前加上了关键字 virtual 则成员函数就变成了虚函数
    // sizeof(Animal_Virtual_Func) = 8;（在64位机器上，指针的大小是8个字节大小）
    // 所以在父类的内部结构中增加了一个 vfptr（virtual function pointer: 虚函数指针），指向一个 vftable（virtual function table: 虚函数表）
    // 虚函数表中记录了类中的虚函数的地址: &Animal_Virtual_Func::spark, &Animal_Virtual_Func::eat
public:
    virtual void spark(){
        cout << "动物在叫叫啊！" << endl;
    }
    virtual void eat(){
        cout << "动物在吃吃啊！" << endl;
    }
};

class Cat:public Animal_Virtual_Func{
    // 当子类继承了父类以后，同样继承了虚函数指针并指向一个虚函数表，虚函数表记录了函数地址
    // 子类重写父类的虚函数，子类用自己的实现在虚函数表记录的函数地址中覆盖了虚函数中的实现，变成了子类自己的实现
    // 所以当父类对象的引用或者指针指向子类对象，子类对象调用重写了的虚函数，即动态的实现了子类自己的不同实现
public:
    void spark(){
        cout << "小猫在叫叫啊！" << endl;
    }
};

void test01(){
    cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
    cout << "sizeof(Animal_Virtual_Func) = " << sizeof(Animal_Virtual_Func) << endl;
}

int main(){
    test01();
    return 0;
}
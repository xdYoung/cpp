#include <iostream>
using namespace std;

// 多态的基本概念：
    // 多态是C++面向对象的三大特性之一
    // 多态分为两类：
        // 静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
        // 动态多态：派生类和虚函数实现运行时多态
    // 静态多态和动态多态的区别：
        // 静态多态的函数地址早绑定：编译阶段确定函数地址
        // 动态多态的函数地址晚绑定：运行阶段确定函数地址
    // 动态多态的满足条件：
        // 需要有继承关系
        // 子类需要重写父类的虚函数
    // 动态多态的使用
        // 父类的指针或者引用，指向子类对象

// 总结：虚函数是C++中用于实现多态(polymorphism)的机制。核心理念就是通过基类访问派生类定义的函数。

// 多态
// 动物类
class Animal{
public:
    // void spark(){
    //     cout << "动物在叫啊！" << endl;
    // }
    // void eat(){
    //     cout << "动物在吃吃啊！" << endl;
    // }
    
    // 虚函数
    virtual void spark(){
        cout << "动物在叫啊！" << endl;
    }
    virtual void eat(){
        cout << "动物在吃吃啊！" << endl;
    }
};

// 派生类：猫类
class Cat:public Animal{
public:
    void spark(){
        cout << "小猫在叫啊！" << endl;
    }
    void eat(){
        cout << "小猫在吃吃啊！" << endl;
    }
};

// 派生类：狗类
class Dog:public Animal{
public:
    void spark(){
        cout << "小狗在叫啊！" << endl;
    }
    void eat(){
        cout << "小狗在吃吃啊！" << endl;
    }
};

// 执行动物叫叫的函数
// 函数sprak()地址早绑定，在编译阶段就确定了函数spark()地址。所以执行函数是调用的父类的spark()
// 如果想执行让猫叫，那函数spark()就不能早绑定。需要在运行阶段进行绑定，即函数spark()地址晚绑定。
// 方法是在父类中的需要的调用的成员函数前加上关键字 virtual （虚函数）
void doSpark(Animal &animal){   // 父类的引用指向子类的对象
    animal.spark();
    animal.eat();
}
// 也可以是父类的指针指向子类对象，编译器会自动进行父类和子类之间的类型转换。
void do_spark(Animal *animal){
    animal->spark();
}

void test01(){
    Cat cat;
    doSpark(cat);   // 本质是：Animal &animal = cat;（父类的引用指向子类对象），C++中允许父类和子类之间的类型转换，不需要强制类型转换。
    // animal本质是一个指针常量，指针指向不变，指向的是父类的对象的地址，但指向的值可以修改。（父类和子类可以自动进行类型转换）

    Dog dog;
    doSpark(dog);

    do_spark(&dog);
}

int main(){
    test01();
    return 0;
}
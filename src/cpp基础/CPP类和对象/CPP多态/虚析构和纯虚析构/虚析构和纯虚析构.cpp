#include <iostream>
using namespace std;

// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 解决方式：将父类中的析构函数改为虚析构或者纯虚析构

// 虚析构和纯虚析构共性：
    // 可以解决父类指针释放子类对象
    // 都需要有具体的函数实现
// 虚析构和纯虚析构的区别：
    // 如果是出虚析构，该类属于抽象类，无法实例化对象。

// 虚析构语法： virtual ~类名(){}
// 纯虚析构语法：virtual ~类名() = 0;

class Animal{
public:
    Animal(){
        cout << "Animal的构造函数被调用了！" << endl;
    }
    // 纯虚函数
    virtual void spark() = 0;
    // 父类的虚析构函数，如果子类有数据在堆区，需要将父类的析构函数变成虚析构，才能调用到子类的析构函数
    // virtual ~Animal(){
    //     cout << "Animal的析构函数被调用了！" << endl;
    // }

    // 父类的 纯虚析构函数
    // 纯虚析构需要有具体的实现，因为如果父类有数据开辟到堆区，需要在析构函数中释放，所以需要有实现，不然会报链接错误。
    // 纯虚析构的实现方式是在类外实现
    // 纯虚析构，需要声明也需要实现
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
};
Animal::~Animal(){ cout << "Animal的纯虚析构函数的类外实现被调用了！" << endl; }

class Cat:public Animal{
public:
    Cat(string name){
        m_Name = new string(name);
        cout << "Cat的构造函数被调用了！" << endl;
    }
public:
    virtual void spark(){
        cout << *m_Name << "这只猫在说话" << endl;
    }
public:
    ~Cat(){
        if(m_Name != NULL){
            delete m_Name;
            m_Name = NULL;
            cout << "Cat的析构函数被调用了！" << endl;
        }
    }
private:
    string * m_Name;
};

void test01(){
    Animal * animal = new Cat("爱喜");
    animal->spark();
    delete animal;
    animal = NULL;
}

int main(){
    test01();
    return 0;
}
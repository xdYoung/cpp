#include <iostream>
using namespace std;

class Person{
public:
    Person(int age = 0){
        m_Age = new int(age);
    }
    Person(const Person & p){
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age);
    }
    // 一个类至少提供四个默认的成员函数：默认构造函数、拷贝构造函数、析构函数、=赋值运算符函数
    // 如果在类中的成员属性在堆区创建了内存地址，则不能使用默认的拷贝构造函数和=赋值运算符函数
    // 需要重写，在拷贝构造函数和=赋值运算符函数中重新开辟新的内存空间进行深拷贝，否则会造成堆区内存重复释放的错误。
    Person& operator=(Person &p){
        // 编译器是提供的浅拷贝
        //m_Age = p.m_Age;    // 简单的内存地址拷贝，这会造成释放的时候重复释放

        // 因为初始化已经在堆区创建了一块内存
        // 所以应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if(m_Age != NULL){
            cout << "判断是否有属性在堆区，进行判断" << "true" << endl;
            delete m_Age;
            m_Age = NULL;
        }
        // 深拷贝
        m_Age = new int(*p.m_Age);
        return *this;
    }
public:
    int * getAge(){
        return m_Age;
    }
public:
    ~Person(){
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }
private:
    int * m_Age;
};

void test01(){
    Person p1(10);
    // 调用拷贝构造函数
    Person p2(p1);
    *p2.getAge() = 32;
    Person p3;
    cout << "Person p1.age = " << *p1.getAge() << endl;
    cout << "Person p2.age = " << *p2.getAge() << endl;
    // 调用=赋值运算符赋值，因为=赋值运算符返回的是对象的引用，所以可以链式赋值。
    p3 = p2 = p1;
    cout << "Person p3.age = " << *p3.getAge() << endl;


}
int main(){
    test01();

    return 0;
}
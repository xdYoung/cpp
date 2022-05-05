#include <iostream>
using namespace std;

// 菱形继承概念：
    // 两个派生类（子类）继承同一个基类
    // 又有某个派生类继承这个两个派生类
    // 这种继承类似于菱形所以被称为菱形继承，或者钻石继承

// 动物类
class Animal{
public:
    // static int m_Age;
    int m_Age;
};
// int Animal::m_Age = 10;

// 利用虚继承，解决菱形继承的问题
// 继承之前，加上关键字 virtual 变为虚继承
// 羊类
// class Sheep:public Animal{};
class Sheep:virtual public Animal{};

// 驼类
// class Tuo:public Animal{};
class Tuo:virtual public Animal{};

// 羊驼类
class SheepTuo:public Sheep, public Tuo{};

void test01(){
    SheepTuo st;
    // 非静态成员属性菱形继承会产生ambiguous（不明确的，歧义的）二异性。
    st.m_Age = 18;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    st.m_Age = 24;
    // 当出现菱形继承的时候，有两个父类拥有相同的数据，需要加以作用域区分
    // 但这两份数据，我们只需要一份就可以，菱形继承导致数据继承了多份，资源浪费。
    // cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    // cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "----------------------------------------------------------------" << endl;
    // 当在基类的派生类上加上了 virtual 关键字后，派生类的继承则为虚继承
    // 虚继承只是继承了 vbptr（ virtual base pointer：虚基类指针）
    // vbptr 指向了一个 vbtable（virtual base table：虚基类表）
    // vbtable 维护了 vbptr 的一个偏移量，通过这个偏移量可以找到唯一的一份虚基类的成员
    // 由此虚继承就解决了菱形继承的多份相同数据继承的问题。保证了继承的数据只有一份。
    cout << "st.Animal::m_Age = " << st.Animal::m_Age << endl;
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age" << st.m_Age << endl;

}

int main(){
    test01();
    return 0;
}
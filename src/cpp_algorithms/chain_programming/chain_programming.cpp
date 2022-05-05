#include <iostream>
using namespace std;

class A{
public:
    // 构造函数初始化成员属性语法
    A(int n):m_num(n){}

    // 链式追加返回的必须是引用，表示是返回对象本身。如果不是返回的引用那么是A，那么会调用拷贝构造函数返回的是A对象的拷贝副本,不是本身。
    A& a_add_num(A &a){
        m_num += a.m_num;
        return *this;
    }
    // 返回值不是引用类型,是返回值类型的话，则会返回一个副本。相当于没有调用都是新的副本在调用，本身没有继续再变化。
    A a_add_num_no_ref(A &a){
        m_num += a.m_num;
        return *this;
    }

    int getNum(){return m_num;}

    // 析构函数
    ~A(){}
private:
    int m_num;
};

int main(){
    A a1(20);
    A a2(10);
    A a3(5);
    printf("a1.m_num = %d \n", a1.getNum());
    printf("a2.m_num = %d \n", a2.getNum());
    printf("a3.m_num = %d \n", a3.getNum());

    printf("以下是返回值 “是” 引用类型的链式调用吸附a1的结果：\n");
    a2.a_add_num(a1).a_add_num(a1).a_add_num(a1);
    printf("a2.m_num = %d \n", a2.getNum());
    printf("以下是返回值 “不是” 引用类型的链式调用吸附a1的结果：\n");
    a3.a_add_num_no_ref(a1).a_add_num_no_ref(a1).a_add_num_no_ref(a1);
    printf("a3.m_num = %d \n", a3.getNum());

    return 0;
}
#include <iostream>
using namespace std;

// 类模版作用：建立一个通用类，类中的成员，数据类型可以不具体指定，用一个虚拟的类型代表。
// 类模版语法：
    // template<typename T>
    // 类代码
// 类模版语法解释：
    // template - 声明创建模版
    // typename - 表明其后面的符号是一种数据类型，可以用 class 代替
    // T - 通用的数据类型，名称可以替换，通常为大写字母

// 创建一个类模版
template<class T1, class T2>
class A{
public:
    A(T1 t1, T2 t2){
        m_t1 = t1;
        m_t2 = t2;
        cout << "通用的类模版被调用了" << endl;
    }
public:
    T1 getT1(){return m_t1;}
    T2 getT2(){return m_t2;}
private:
    T1 m_t1;
    T2 m_t2;
};

// 具体化数据类型的类模版版本，优先调用，语法是前面加上：template<> class className<typeName1, typeName2>{}
template<> class A<string, int>{
public:
    A(string t1, int t2){
        m_t1 = t1;
        m_t2 = t2;
        cout << "具体化类模版版本被调用了" << endl;
    }
public:
    string getT1(){return m_t1;}
    int getT2(){return m_t2;}
private:
    string m_t1;
    int m_t2;
};

void test01(){
    // 具体化的类模版版本
    A<string, int> a1("young", 32);
    cout << "a1.t1 = " << a1.getT1() << ", a1.t2 = " << a1.getT2() << endl;
    cout << "------------------------------------------" << endl;
    // 通用的类模版会被调用
    A<int, int> a2(18, 28);
    cout << "a2.t1 = " << a2.getT1() << ", a2.t2 = " << a2.getT2() << endl;
}

int main(){
    test01();
    return 0;
}
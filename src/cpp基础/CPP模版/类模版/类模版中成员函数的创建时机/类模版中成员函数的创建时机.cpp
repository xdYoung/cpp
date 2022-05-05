#include <iostream>
using namespace std;

// 类模版中成员函数的创建时机
// 类模版中成员函数和普通函数中成员函数的创建时机是有区别的：
    // 普通类中的成员函数一开始就可以创建
    // 类模版中的成员函数在调用时才创建

class Person01{
public:
    void showPerson01(){
        cout << "Person01 show" << endl;
    }
};

class Person02{
public:
    void showPerson02(){
        cout << "Person02 show" << endl;
    }
};

template<class T>
class MyClass{
private:
    T obj;
public:
    // 类模版中的成员函数，并不是一开始就创建的，而是在模版调用时再生成。
    // 一开始并不确定模版中的成员属性，所以一开始无法创建成员函数
    // 在通过模版创建好实例化对象后，成员函数调用了才会再创建成员函数。
    void func01(){
        obj.showPerson01();
    }
    void func02(){
        obj.showPerson02();
    }
};

void test01(){
    // Person01 p1;
    // p1.showPerson01();
    MyClass<Person01> m;
    m.func01();
    // m.func02();  
    // 在MyClass<Person01>m的实例化对象中：m.func02();会编译出错，说明成员函数调用才会去创建成员函数（No member named 'showPerson02' in 'Person01'）
    // 因为创建了成员函数后，因为m中的obj时Person01中没有Person02()函数，就编译报错了。如果不调用成员函数，就可编译。
}

int main(){
    test01();
    return 0;
}
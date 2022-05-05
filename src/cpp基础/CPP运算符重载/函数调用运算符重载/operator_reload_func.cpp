#include <iostream>
using namespace std;
// 函数调用运算符()也可以重载
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数
// 仿函数没有固定写法，非常灵活
template <class T>
class MyPrint{
public:
    void operator()(T text){
        cout << "仿函数调用打印的内容：" << text << endl;
    }
    // void operator()(int content){
    //     cout << "仿函数调用打印的内容：" << content << endl;
    // }
};

class AddTest{
public:
    int operator()(int a, int b){
        return a + b;
    }
};

void test01(){
    MyPrint<string> myPrint;
    string t;
    cout << "请输入内容：" ;
    cin >> t;
    myPrint(t);
    // 匿名函数对象
    MyPrint<string>()(t);
}

void test02(){
    MyPrint<int> myPrint;
    AddTest add;
    int a,b;
    cout << "请输入数字a：";
    cin >> a;
    cout << "请输入数字b：";
    cin >> b;
    cout << endl;
    myPrint(add(a, b));
    // 匿名函数对象
    MyPrint<int>()(AddTest()(a, b));
}

int main(){
    // test01();
    test02();
    return 0;
}
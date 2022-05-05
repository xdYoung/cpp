#include <iostream>
using namespace std;

// string基本概念
// 本质：string是C++风格的字符串，而string本质上是一个类
// string 和 char* 区别：
    // char* 是一个指针
    // string 是一个类，类内部封装了 char* ，管理这个字符串，是一个 char* 型的容器
// 特点：
// string类内部封装了很多成员方法
// 例如：查找 find 、 拷贝 copy 、 删除 delete 、 替换 replace 、 插入 insert 等。
// string 管理 char* 所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

// string构造函数
// 构造函数原型：
    // string();                        // 创建一个空的字符串，例如：string str;
    // string(const char* s);           // 使用字符串s初始化
    // string(const string& str);       // 使用一个string对象初始化另一个string对象
    // string(int n, char c);           // 使用n个字符c初始化

void printLine(){
    cout << "----------------------------------------" << endl;
}
// string的构造函数
void test01(){
    string s1;  // 默认构造

    const char* str = "hello world!";   // c语言风格字符串
    string s2(str);
    string s21 = string(str);
    string s22 = str;
    cout << "s2 = " << s2 << endl;
    cout << "s21 = " << s21 << endl;
    cout << "s22 = " << s22 << endl;
    printLine();

    string s3(s2);
    string s31 = string(s2);
    string s32 = s2;
    cout << "s3 = " << s3 << endl;
    cout << "s31 = " << s31 << endl;
    cout << "s32 = " << s32 << endl;
    printLine();

    string s4(10, 'a');
    string s41 = string(10, 'c');
    cout << "s4 = " << s4 << endl;
    cout << "s41 = " << s41 << endl;
}

int main(){
    test01();
    return 0;
}
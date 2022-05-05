#include <iostream>
using namespace std;

// string字符串拼接
// 实现在字符串末尾拼接字符串
// 函数原型：
    // string& operator+=(const char* s);                           // 重载+=操作符
    // string& operator+=(const char c);                            // 重载+=操作符
    // string& operator+=(const string str);                        // 重载+=操作符
    // string& append(const char* s);                               // 把字符串s连接到当前字符串结尾
    // string& append(const char* s, int n);                        // 把字符串s的前n个字符连接到当前字符串结尾
    // string& append(const string& str);                           // 同 string& operator+=(const string str);
    // string& append(const string& str, int pos, int n);           // 字符串str中从pos开始的n个字符连接到字符串结尾

void printLine(){
    cout << "-------------------------------------------" << endl;
}
void test01(){
    string str1 = "我"; // 隐式赋值，等价于 string str1 = string("我");或者 string str1("我");
    // string str1 = string("我");
    // string str1("我");
    str1 += "爱C++";
    cout << "str1 = " << str1 << endl;
    printLine();

    string str2 = "我是个";
    str2 += 'a';
    cout << "str2 = " << str2 << endl;
    printLine();

    string str3 = "告诉你，";
    str3 += str1;
    cout << "str3 = " << str3 << endl;
    printLine();

    string str4 = "我爱";
    str4.append("赵宝贝");
    cout << "str4 = " << str4 << endl;
    printLine();

    string str5("我想说：");
    str5.append("hello world!", 5);
    cout << "str5 = " << str5 << endl;
    printLine();

    string str6("(将str4字符串的内容添加到本字符串末尾：)");
    str6.append(str4);
    cout << "str6 = " << str6 << endl;
    printLine();

    string str7("(截取str5的n1到n2之间的字符串添加到本字符串末尾：)");
    str7.append(str5,0,17);
    cout << "str7 = " << str7 << endl;
}

int main(){
    test01();
    return 0;
}
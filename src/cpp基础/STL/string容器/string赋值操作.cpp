#include <iostream>
using namespace std;

// 给string字符串进行赋值
// 赋值的函数原型
    // string operator=(const char* s);           // char*类型字符串赋值给当前的字符串
    // string operator=(const string& s);         // 把字符串s赋值给当前的字符串
    // string operator=(char c);                  // 字符赋值给当前的字符串
    // string assign(const char* s);              // char*类型字符串s赋值给当前的字符串
    // string assign(const char* s, int n);       // char*类型字符串s的前n个字符赋值给当前的字符串
    // string assign(const string& s);            // 把字符串s赋值给当前的字符串
    // string assign(int n, char* c);             // 用n个字符c赋值给当前的字符串

void printLine(){
    cout << "-----------------------------------------" << endl;
}
void test01(){
    string str1;
    str1 = "hello world!";
    cout << "str1 = " << str1 << endl;
    printLine();
    
    string str2 = str1;
    cout << "str2 = " << str2 << endl;
    printLine();

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;
    printLine();

    string str4;
    str4.assign("hello yang!");
    cout << "str4 = " << str4 << endl;
    printLine();

    string str5;
    str5.assign("hello ting!", 5);
    cout << "str5 = " << str5 << endl;
    printLine();

    string str6;
    str6.assign(str4);
    cout << "str6 = " << str6 << endl;
    printLine();

    string str7;
    str7.assign(5, 'a');
    cout << "str7 = " << str7 << endl;
    printLine();
}

int main(){
    test01();
    return 0;
}
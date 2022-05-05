#include <iostream>
using namespace std;

// string 插入和删除：对string字符串进行插入和删除字符操作
// 函数原型：
    // string& insert(int pos, const char* s);                  // 在指定位置插入c风格字符串s
    // string& insert(int pos, const string& str);              // 在指定位置插入c++风格字符串str
    // string& insert(int pos, int n, char c);                  // 在指定位置向当前字符串中插入n个c字符
    // string& erase(int pos, int n=npos);                      // 删除当前字符串中从pos位置开始的n个字符


void printLine(){
    cout << "--------------------------------------" << endl;
}
void test01(){
    string str = "hello";
    char s[] = " world!";
    string str1 = ", 你好 世界!";
    string str2 = "dsfasdgjdkhgfsakjdkgaslf";
    cout << "str: " << str << endl;
    cout << "s: " << s << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    printLine();

    // 插入c风格的字符串
    str.insert(str.size(), s);
    cout << "插入c风格字符串后的str为： " << str << endl;
    printLine();

    // 插入string风格的字符串
    str.insert(str.size(), str1);
    cout << "插入string风格的字符串后的str为： " << str << endl;
    printLine();

    // 插入n个字符c
    str.insert(str.size(), 5, 'a');
    cout << "插入n个字符c后的字符串str为： " << str << endl;
    printLine();

    // 删除字符串中从pos位置开始的n个字符
    str2.erase(3,6);
    cout << "删除字符串中从pos位置开始的n个字符后的str2为： " << str2 << endl;
    printLine();
}

int main(){
    test01();
    return 0;
}
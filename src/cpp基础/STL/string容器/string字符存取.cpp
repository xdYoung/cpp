#include <cstring>
#include <iostream>
using namespace std;

// string字符存取
// string中单个字符存取方式有两种
    // char& operator[](int n);         // 重载了[]运算符，通过[]方式取字符
    // char& at(int n);                 // 提供at成员函数，通过at方法获取字符

void printLine(){
    cout << "----------------------------------------------" << endl;
}

void test01(){
    string s1 = "I love ting!";
    cout << "s1: " << s1 << endl;

    // c风格字符串
    char s2[10] = {'h', 'e', 'l', 'l', 'o'};
    int len = strlen(s2);
    cout << "s2: " << s2 << endl;
    cout << "c风格字符串s2: " << s2 << "s2字符串长度为： " << len << endl;
    printLine();

    // 通过[]访问s1中的单个字符
    // string方式的字符串本身是个类，提供了成员函数size()方法返回字符串的大小
    for(int i = 0; i < s1.size(); i++){
        cout << "通过[]访问s1中的第 " << i << " 个字符为： " << s1[i] << endl;
    }
    printLine();

    // 通过at方式访问s1中的单个字符
    for(int i = 0; i < s1.size(); i++){
        cout << "通过at方法访问s1中的第 " << i << " 个字符为： " << s1.at(i) << endl;
    }
    printLine();

    // 因为s2是c风格的字符串，本身是一个数组，所以直接通过[]的方式可以访问。
    for(int i = 0; i < len; i++){
        cout << "c风格的字符串s2中的第 " << i << " 个字符为： " << s2[i] << endl;
    }
    printLine();
}

void test02(){
    string s = "hello";
    cout << "s: " << s << endl;
    printLine();

    // 通过[]修改字符串的字符，因为重载的中括号[]返回的是char&字符本身，所以可以对其进行修改
    s[1] = 'a';
    cout << "s: " << s << endl;
    printLine();

}

int main(){
    test01();
    test02();
    return 0;
}
#include <iostream>
#include <sys/resource.h>
using namespace std;

// string字串截取：从字符串中获取想要的子串
// 函数原型：
    // string substr(int pos=0, int n=npos) const;              // 返回从pos位置开始的n个字符组成的子字符串

void printLine(){
    cout << "-----------------------------------" << endl;
}
void test01(){
    string str = string("hello world! I'm yang!");
    cout << "str: " << str << endl;
    printLine();

    // substr获取子字符串
    string substr = str.substr(13, 9);  // 截取是左闭右开[)
    cout << "substr: " << substr << endl;
    printLine();

}

// 截取子串的实用操作
void test02(){
    string str = "yang@126.com";
    cout << "str: " << str << endl;
    printLine();

    int pos = str.find("@");
    cout << "str中@的位置： " << pos << endl;
    printLine();

    string userName = str.substr(0,pos);
    cout << "userName: " << userName << endl;
    printLine();
}

string test03(string &email){
    int pos = email.find("@");
    string userName = email.substr(0, pos);
    return userName;
}

int main(){
    test01();
    test02();
    string email = "ting@126.com";
    string userName = test03(email);
    cout << test03(email) << endl;
    // cout << test03(email) << endl;
    cout << "userName: " << userName << endl;
    // cout << "userName: " << userName << endl;
    printLine();
    return 0;
}
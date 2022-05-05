#include <iostream>
using namespace std;

// string字符串比较
// 比较方式：字符串比较是按照字符的ASCII码进行对比
// = 返回 0
// > 返回 1
// < 返回-1

// 函数原型：
    // int compare(const string &s) const;                      // 与c++方式string字符串s比较
    // int compare(const char* s) const;                        // 与c风格字符串s比较

// 总结：字符串对比主要是判断两个字符串是否相等，判断两个字符串大小除了在排序中，似乎意义不大。

void printLine(){
    cout << "------------------------------------------------" << endl;
}

void test01(){
    string s1 = "yang";
    string s2 = string("ting");
    string s3("shohn");
    string s6 = "yang";
    cout << "s1: " << s1 << "  "
         << "s2: " << s2 << "  "
         << "s3: " << s3 << "  "
         << "s6: " << s6
         << endl;
    printLine();
    cout << "s1与s2比较： ";
    int res = s1.compare(s2);
    if(res == 0){
        cout << "s1与s2相等" << endl;
    }else if(res == 1){
        cout << "s1大于s2" << endl;
    }else{
        cout << "s1小于s2" << endl;
    }
    printLine();
    cout << "s1与s3比较： ";
    cout << (s1.compare(s3) == 0 ? "s1与s3相等" : (s1.compare(s3) == 1 ? "s1大于s3" : "s1小于s3")) << endl;
    printLine();
    cout << "s1与s6比较： ";
    cout << (s1.compare(s6) == 0 ? "s1与s6相等" : (s1.compare(s6) == 1 ? "s1大于s6" : "s1小于s6")) << endl;
}

int main(){
    test01();
    return 0;
}
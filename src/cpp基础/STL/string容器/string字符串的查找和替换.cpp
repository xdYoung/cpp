#include <iostream>
using namespace std;

// string字符串的查找和替换
// 功能描述：
    // 查找：查找指定字符串是否存在
    // 替换：在指定的位置替换字符串
// 函数原型
    // 函数后面加上const表明是常函数，常函数内不可以修改成员属性，本质是修饰了this指针：const string* const this;
    // 因为查找操作最好不要修改了对象本身的属性，所以用const修饰变成常函数
    // int find(const string& str, int pos=0) const;                // 查找str第一次出现的位置，从pos开始查找
    // int find(const char* s, int pos=0) const;                    // 查找s第一次出现的位置，从pos开始查找
    // int find(const char* s, int pos, int n) const;               // 从pos位置查找s的第n个字符第一次出现的位置
    // int find(const char c, int pos=0) const;                     // 查找字符c第一次出现的位置，从pos开始查找
    // int rfind(const string& str, int pos=npos) const;            // 查找str最后一次出现的位置，从pos开始查找
    // int rfind(const char* s, int pos=npos) const;                // 查找s最后一次出现的位置，从pos开始查找
    // int rfind(const char* s, int pos, int n) const;              // 从pos位置查找s的前n个字符最后一次出现的位置
    // int rfind(const char c, int pos=0) const;                    // 查找字符c最后一次出现的位置
    // string& replace(int pos, int n, const string& str);          // 替换从pos开始的n个字符为字符串str
    // string& replace(int pos, int n, const char* s);              // 替换从pos开始的n个字符为字符串s
// find和rfind的区别
    // find是从左往右查找
    // rfind是从右往左查找

void printLine(){
    cout << "------------------------------------------" << endl;
}
// 1.字符串的查找：find
void test01(){
    printLine();
    string s1 = "kasjdklsahlkdgaslkdfjeigoiasnvsakdjaeij";
    cout << "s1 = " << s1 << endl;
    printLine();
    int pos = s1.find("sa");
    cout << "sa->pos = " << pos << endl;
    if(pos != -1){
        cout << "在字符串s1中查找到了子字符串sa，sa的下标为：" << pos << endl;
    }
    printLine();
    pos = s1.find("ds");
    cout << "ds->pos = " << pos << endl;
    if(pos == -1){
        cout << "没有在字符串s1中找到子字符串ds" << endl;
    }
    printLine();
}

// 2.字符串查找：rfind
void test02(){
    printLine();
    string s1 = "kasjdklsahlkdgaslkdfjeigoiasnvsakdjaeij";
    cout << "s1 = " << s1 << endl;
    printLine();
    int pos = s1.rfind("sa");
    cout << "sa->pos = " << pos << endl;
    if(pos != -1){
        cout << "在字符串s1中查找到了子字符串sa，sa的下标为：" << pos << endl;
    }
    printLine();
    pos = s1.rfind("ds");
    cout << "ds->pos = " << pos << endl;
    if(pos == -1){
        cout << "没有在字符串s1中找到子字符串ds" << endl;
    }
    printLine();
}

// 3.字符串替换：replace
void test03(){
    printLine();
    string s2 = "我爱赵千婷！希望她天天开心，每天好心情！";
    string s3 = "I love zhao,wish her happy!";
    cout << "没有替换的字符串s2为：" << s2 << endl;
    cout << "没有替换的字符串s3为：" << s3 << endl;
    s2.replace(28,10,"高高兴兴的");
    s3.replace(21,6,"happiness!");
    printLine();
    cout << "替换后的字符串s2为：" << s2 << endl;
    cout << "替换后的字符串s3为：" << s3 << endl;
}

int main(){
    cout << "find查找：" << "*********************************************************" << endl;
    test01();
    cout << "rfind查找：" << "*********************************************************" << endl;
    test02();
    cout << "find查找：" << "*********************************************************" << endl;
    test03();
    return 0;
}
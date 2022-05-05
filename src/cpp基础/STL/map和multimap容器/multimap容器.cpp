#include <iostream>
#include <map>
using namespace std;

// multimap 在插入数据的时候允许容器可以插入重复的 key 值。

void printLine(){
    cout << "----------------------------------------------" << endl;
}

void printMultiMap(const multimap<string, int>& imp){
    for(multimap<string, int>::const_iterator it = imp.begin(); it != imp.end(); it++){
        cout << "key: " << it->first << "   value: " << it->second << " | ";
    }
    cout << endl;
}

void test01(){
    // 默认构造函数
    multimap<string, int> imp;
    pair<string, int> p1("young", 32);
    pair<string, int> p11("young", 32);
    pair<string, int> p2("ting", 28);
    pair<string, int> p3("shohn", 30);
    pair<string, int> p5("young", 18);
    pair<string, int> p6("young", 20);
    pair<string, int> p7("young", 24);

    imp.insert(p1);
    imp.insert(p11);
    imp.insert(p2);
    imp.insert(p3);
    imp.insert(p5);
    imp.insert(p6);
    imp.insert(p7);
    imp.insert(p1);

    printMultiMap(imp);
    printLine();

    // 拷贝构造函数
    multimap<string, int> imp1(imp);
    printMultiMap(imp1);
    printLine();

    // multimap& imp(const multimap& imp);
    multimap<string, int> imp2;
    imp2 = imp;
    printMultiMap(imp2);
    printLine();
}

int main(){
    test01();
    return 0;
}
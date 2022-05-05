#include <iostream>
#include <list>
using namespace std;

// list链表的数据存取：对list容器中数据进行存取
// 函数原型
    // front();                 // 返回第一个元素
    // back();                  // 返回最后一个元素
// 由于list容器在内存中是不连续的空间，所有没有at()方法和没有重载opretor[]的方式访问元素
// 所以list的迭代器也是不支持随机访问的，只能每次++操作。不支持+1操作。

void printLine(){
    cout << "---------------------------------------------" << endl;
}

void printList(const list<string>& lst){
    for(list<string>::const_iterator it = lst.begin(); it != lst.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    list<string> lst;
    lst.push_back("young");
    lst.push_back("ting");
    lst.push_back("shohn");
    lst.push_back("peng");
    lst.push_back("dou");
    lst.push_back("chuan");
    lst.push_back("na");
    printList(lst);
    printLine();
    cout << "lst.front(): " << lst.front() << endl;
    cout << "lst.back(): " << lst.back() << endl;
    printLine();
    lst.front() = "yang";
    lst.back() = "nana";
    printList(lst);
    printLine();
}

int main(){
    test01();
    return 0;
}
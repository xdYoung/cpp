#include <iostream>
#include <list>
using namespace std;

// list链表的反转和排序：将list容器中的元素反转，以及将list容器中的数据进行排序
// 函数原型
    // reverse();               // 反转链表
    // sort();                  // 链表排序

void printLine(){
    cout << "---------------------------------------------" << endl;
}

void printList(const list<string>& lst){
    for(list<string>::const_iterator it = lst.begin(); it != lst.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(string s1, string s2){
    return s1 > s2;
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
    // reverse();list容器反转
    lst.reverse();
    printList(lst);
    printLine();

    // 内置sort算法不支持list
    // 因为所有不支持随机访问迭代器的容器，不可以用标准算法
    // sort(lst.begin(), lst.end());   // 这个会报错，list不支持标准的算法

    // sort();list链表排序。这个是list链表的成员函数
    // 不支持随机访问迭代器的容器，内部会提供对应的一些算法，比如排序算法。
    cout << "升序排列： " << endl;
    lst.sort(); // 默认是升序排列
    printList(lst);
    printLine();

    // 降序排列
    cout << "降序排列： " << endl;
    lst.sort(myCompare);
    printList(lst);
    printLine();
}

int main(){
    test01();
    return 0;
}
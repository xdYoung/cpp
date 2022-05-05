#include <iostream>
#include <list>
using namespace std;

// list链表的赋值和交换：给list容器进行赋值，以及交换list容器
// 函数原型
    // assign(begin, end);                      // 将[begin, end)区间中的数据拷贝赋值给本身
    // assign(n, element);                      // 将n个element拷贝赋值给本身
    // list& operatro=(const list& lst);        // 重载等号=操作赋，将lst中的数据赋值给本身
    // swap(lst);                               // 将lst与本身的元素互换

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
    cout << "lst: ";
    printList(lst);
    printLine();

    // assign(begin, end)
    list<string> lst1;
    lst1.assign(lst.begin(), lst.end());
    cout << "lst1: ";
    printList(lst1);
    printLine();

    // assign(n, element)
    list<string> lst2;
    lst2.assign(10,"abc");
    cout << "lst2: ";
    printList(lst2);
    printLine();

    // list& operator=(const list& lst)
    list<string> lst3;
    lst3 = lst1;
    cout << "lst3: ";
    printList(lst3);
    printLine();

    // swap(const char* s)
    lst3.swap(lst2);
    cout << "交换后： " << endl;
    cout << "lst2: ";
    printList(lst2);
    printLine();
    cout << "lst3: ";
    printList(lst3);
    printLine();
}

int main(){
    test01();
    return 0;
}
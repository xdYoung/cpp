#include <iostream>
#include <list>
using namespace std;

// list链表的大小操作：对list容器的大小进行操作
// 函数原型
    // size();                  // 返回容器中元素的个数
    // empty();                 // 判断容器是否为空
    // resize(num);             // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置，若容器变短，则末尾超出容器长度的元素被删除
    // resize(num, element);    // 重新指定容器的长度为num，若容器变长，则以element值填充新位置，若容器变短，则末尾超出容器长度的元素被删除

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
    cout << "初始化时lst链表的大小： " << lst.size() << endl;
    cout << (lst.empty() ? "初始化时lst容器为空" : "初始化时lst容器不为空") << endl;
    printLine();

    lst.push_back("young");
    lst.push_back("ting");
    lst.push_back("shohn");
    lst.push_back("peng");
    lst.push_back("dou");
    lst.push_back("chuan");
    lst.push_back("na");
    printList(lst);
    cout << "添加元素后lst链表的大小： " << lst.size() << endl;
    cout << (lst.empty() ? "lst容器为空" : "lst容器不为空") << endl;
    printLine();

    // resize(num);容器变长
    lst.resize(10);
    printList(lst);
    cout << "resize(num)变长后lst链表的大小： " << lst.size() << endl;
    cout << (lst.empty() ? "lst容器为空" : "lst容器不为空") << endl;
    printLine();

    // resize(num, element);容器变长
    lst.resize(16, "money");
    printList(lst);
    cout << "resize(num, element)变长后lst链表的大小： " << lst.size() << endl;
    cout << (lst.empty() ? "lst容器为空" : "lst容器不为空") << endl;
    printLine();

    // resize(num);容器变短
    lst.resize(8);
    printList(lst);
    cout << "resize(num)变短后lst链表的大小： " << lst.size() << endl;
    cout << (lst.empty() ? "lst容器为空" : "lst容器不为空") << endl;
    printLine();
}

int main(){
    test01();
    return 0;
}
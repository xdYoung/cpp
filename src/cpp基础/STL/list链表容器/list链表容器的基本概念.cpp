#include <iostream>
#include <list>
using namespace std;

// list链表容器基本概念：将数据进行链式存储
// 链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中指针链接实现的
// 链表的组成：链表由一系列结点组成
// 结点的组成：一个是存储数据元素的 数据域 ， 另一个是存储下一个结点地址的 指针域
// STL中的链表是一个双向循环链表（每个结点有两个指针prev和next分别指向前一个结点和下一个结点）
// 链表的优点：可以对任意位置进行快速的插入和删除元素（对于数据量级很大的情况下，数组的插入删除要移动元素，效率低。链表效率高）
// 链表的缺点：链表因为在物理存储单元上是非连续的，需要通过指针寻找下一个结点的位置。所以链表容器的遍历速度没有数组快。链表占用的空间比数组大。
// 链表的优点就是数组的缺点，链表的缺点就是数组的优点。

// 由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

// list的优点：
    // 采用动态存储分配，不会造成内存浪费和溢出
    // 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量的元素
// list的缺点：
    // 链表灵活，但是空间（指针域）和时间（遍历）额外耗费较大
// list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。

// 总结：STL 中 list 和 vector 是两个最常被使用的容器，各有优缺点。

// list构造函数：创建list容器
// 函数原型
    // list<T> list;                            // list采用模版类实现，默认构造函数
    // list<T> list(begin, end);                // 构造函数将[begin, end)区间中的元素拷贝给本身
    // list<T> list(n, element);                // 构造函数将n个element拷贝给本身
    // list<T> list(const list& list);          // 拷贝构造函数

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
    list<string> lst;       // 默认构造函数
    lst.push_back("young");
    lst.push_back("ting");
    lst.push_back("shohn");
    lst.push_back("peng");
    lst.push_back("dou");
    lst.push_back("chuan");
    lst.push_back("na");
    printList(lst);
    printLine();
    // list(begin, end); 有参构造函数
    list<string> lst1(lst.begin(), lst.end());
    printList(lst1);
    printLine();
    // list(n, element); 有参构造函数
    list<string> lst2(10, "a");
    printList(lst2);
    printLine();
    // list<string> lst(const list& lst); 拷贝构造函数
    list<string> lst3(lst);
    printList(lst3);
    printLine();
}

int main(){
    test01();
    return 0;
}
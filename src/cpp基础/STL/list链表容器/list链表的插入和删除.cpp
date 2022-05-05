#include <iostream>
#include <list>
using namespace std;

// list链表的插入和删除：对list容器进行数据的插入和删除
// 函数原型
    // push_back(element);              // 在容器尾部加入一个元素
    // pop_back();                      // 删除容器中最后一个元素
    // push_front(element);             // 在容器的开头插入一个元素
    // pop_front();                     // 删除容器开头的元素
    // insert(pos, element);            // 在pos（pos是迭代器）位置插入element元素的拷贝，返回新数据的位置
    // insert(pos, n, element);         // 在pos（pos是迭代器）位置插入n个element数量的元素，无返回值
    // insert(pos, begin, end);         // 在pos（pos是迭代器）位置插入[begin, end)区间的数据，无返回值。begin和end是迭代器
    // clear();                         // 移除容器的所有数据
    // erase(begin, end);               // 删除[begin, end)区间的数据，返回下一个数据的位置
    // erase(pos);                      // 删除pos位置的数据，返回下一个数据的位置
    // remove(element);                 // 删除容器中所有与element值匹配的元素

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
    list<string> lst1;
    lst1.push_back("a");
    lst1.push_back("a");
    lst1.push_back("a");
    lst1.push_back("a");
    lst1.push_back("a");
    lst1.push_back("a");
    // push_back(elem)
    lst.push_back("young");
    lst.push_back("ting");
    lst.push_back("shohn");
    lst.push_back("abc");
    lst.push_back("ab");
    lst.push_back("a");
    // push_front(elem)
    lst.push_front("chuan");
    lst.push_front("peng");
    lst.push_front("jindou");
    lst.push_front("na");
    lst.push_front("def");
    lst.push_front("de");
    lst.push_front("d");
    printList(lst);
    printList(lst1);
    printLine();
    // pop_back()
    lst.pop_back();
    printList(lst);
    printLine();
    // pop_front()
    lst.pop_front();
    printList(lst);
    printLine();
    // insert(pos, elem)
    lst.insert(lst.begin()++, "hello");
    printList(lst);
    printLine();
    // insert(pos, n, elem)
    lst.insert(lst.begin()++, 5, "ok");
    printList(lst);
    printLine();
    // insert(pos, begin, end)
    lst.insert(++lst.begin(), lst1.begin(), lst1.end());
    printList(lst);
    printLine();
    // erase(begin, end)
    lst.erase(lst.begin(), ++lst.begin());
    printList(lst);
    printLine();
    // erase(pos)
    lst.erase(lst.begin());
    printList(lst);
    printLine();
    // remove(elem)
    lst.remove("a");
    printList(lst);
    printLine();
    // clear()
    lst.clear();
    printList(lst);
    printLine();

}

int main(){
    test01();
    return 0;
}
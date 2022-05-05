#include <iostream>
#include <deque>
using namespace std;

// deque容器的大小操作：对deque容器的大小进行操作

// 函数原型
    // deque.empty();                       // 判断容器是否为空
    // deque.size();                        // 返回容器中元素的个数
    // deque.resize(num);                   // 重新指定容器的长度为num，若容器变长，则以默认值填充新的位置，若容器变短，则末尾超出容器长度的元素被删除
    // deque.resize(num, element);          // 重新指定容器的长度为num，若容器变长，则以element值填充新的位置，若容器变短，则末尾超出容器长度的元素被删除

// deque容器没有容量的概念

void printLine(){
    cout << "-----------------------------------------------------" << endl;
}

void printDeque(const deque<int> &deq){
    for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    deque<int> deq;
    cout << "容器deq的初始大小为： " << deq.size() << endl;
    cout << "判断容器deq是否为空： " << (deq.empty() ? "容器deq为空！" : "容器deq不为空！") << endl;
    printLine();

    for(int i = 0; i < 10; i++){
        deq.push_back(i*10 + 66);
    }
    printDeque(deq);
    cout << "容器deq的大小为： " << deq.size() << endl;
    cout << "判断容器deq是否为空： " << (deq.empty() ? "容器deq为空！" : "容器deq不为空！") << endl;
    printLine();

    // 重新指定容器的大小超过原容器的大小
    deq.resize(15);
    printDeque(deq);
    cout << "容器deq的大小为： " << deq.size() << endl;
    cout << "判断容器deq是否为空： " << (deq.empty() ? "容器deq为空！" : "容器deq不为空！") << endl;
    printLine();

    // 重新指定容器的大小超过原容器的大小
    deq.resize(20, 888);
    printDeque(deq);
    cout << "容器deq的大小为： " << deq.size() << endl;
    cout << "判断容器deq是否为空： " << (deq.empty() ? "容器deq为空！" : "容器deq不为空！") << endl;
    printLine();

    // 重新指定容器的大小小于原容器的大小
    deq.resize(5);
    printDeque(deq);
    cout << "容器deq的大小为： " << deq.size() << endl;
    cout << "判断容器deq是否为空： " << (deq.empty() ? "容器deq为空！" : "容器deq不为空！") << endl;
    printLine();

}

int main(){
    test01();
    return 0;
}
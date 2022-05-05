#include <iostream>
#include <deque>
using namespace std;

// deque容器的插入和删除：向deque容器中插入和删除数据
// 函数原型：
    // 两端插入操作
        // push_back(element);                  // 在容器尾部添加一个元素
        // push_front(element);                 // 在容器头部插入一个元素
        // pop_back();                          // 删除容器最后一个元素
        // pop_front();                         // 删除容器第一个元素
    // 指定位置操作
        // insert(pos, elment);                 // 在pos位置插入一个element元素的拷贝，返回新数据的位置
        // insert(pos, n, elment);              // 在pos位置插入n个element元素，无返回值
        // insert(pos, begin, end);             // 在pos位置插入[begin, end)区间的元素，无返回值
        // clear();                             // 清空容器的所有数据
        // erase(begin, end);                   // 删除[begin, end)区间的数据，返回下一个数据的位置
        // erase(pos);                          // 删除pos位置的数据，返回下一个数据的位置

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
    // push_back
    deq.push_back(16);
    deq.push_back(18);
    deq.push_back(28);
    deq.push_back(78);
    deq.push_back(88);
    printDeque(deq);
    printLine();
    // push_front
    deq.push_front(38);
    deq.push_front(58);
    deq.push_front(68);
    deq.push_front(98);
    deq.push_front(108);
    printDeque(deq);
    printLine();
    // pop_back
    deq.pop_back();
    printDeque(deq);
    printLine();
    // pop_front
    deq.pop_front();
    printDeque(deq);
    printLine();

    // insert(pos, element)
    deque<int>::iterator pos = deq.insert(deq.begin()+3, 66);
    cout << "返回插入元素的迭代器的位置的元素为： " << *pos << endl;
    printDeque(deq);
    printLine();

    // insert(pos, n, element)
    deq.insert(deq.begin()+5, 2, 168);
    printDeque(deq);
    printLine();

    // insert(pos, begin, end)
    deq.insert(deq.begin()+1, deq.begin()+1, deq.begin()+3);
    printDeque(deq);
    printLine();

    // erase(begin, end)
    deq.erase(deq.begin(), deq.begin()+1);
    printDeque(deq);
    printLine();

    // erase(pos)
    deq.erase(deq.end()-1);
    printDeque(deq);
    printLine();

    // clear()
    deq.clear();
    printDeque(deq);
    printLine();
}

int main(){
    test01();
    return 0;
}
#include <iostream>
#include <deque>
using namespace std;

// deque容器的赋值操作：给deque容器进行赋值
// 函数原型：
    // deque& operator=(const deque& deq);      // 重载等号赋值运算符给容器赋值
    // assign(begin, end);                      // 将[begin, end)区间中的数据拷贝赋值给本身
    // assing(n, element);                      // 将n个element拷贝赋值给本身

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
    deq.push_back(16);
    deq.push_front(18);
    deq.push_back(66);
    deq.push_back(88);
    printDeque(deq);
    printLine();

    // deque& operator=(const deque& deq)
    // deque<int> deq1 = deq;  // 这是调用构造函数的方式，不是等号赋值的方式。类似于 deque<int> deq1 = deque<int>(deq);
    deque<int> deq1;
    deq1 = deq; // 这才是=赋值的方式
    printDeque(deq1);
    printLine();

    // assign(begin, end)
    // deque<int> deq2(deq.begin(), deq.end());    // 这是调用的构造函数的方式
    deque<int> deq2;
    deq2.assign(deq.begin(), deq.end());
    printDeque(deq2);
    printLine();

    // assign(n, element)
    deque<int> deq3(10, 66);
    printDeque(deq3);
    printLine();
}

int main(){
    test01();
    return 0;
}
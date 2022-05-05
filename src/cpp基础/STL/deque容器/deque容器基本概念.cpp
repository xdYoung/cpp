#include <iostream>
#include <deque>
using namespace std;

// deque容器的基本概念：deque容器被称为双端数组，可以对头端进行插入删除操作
// deque与vector区别：
    // vector对于头部的插入删除效率低，数据量越大，效率越低
    // deque相对而言，对头部的插入删除速度会比vector快
    // vector访问元素时的速度会比deque快，这和两者内部实现有关
// deque内部工作原理：
    // deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实的数据
    // 中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
// deque容器的迭代器也是支持随机访问的

// deque构造函数：deque容器构造
// 函数原型：
    // deque<T> deq;                               // 默认构造函数
    // deque<T> deq(begin, end);                   // 构造函数将[begin, end)区间中的元素拷贝给本身
    // deque<T> deq(n, element);                   // 构造函数将n个element拷贝给本身
    // deque<T> deq(const deque& deq);             // 拷贝构造函数

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

// deque容器的构造函数
void test01(){
    // STL容器在使用的时候都需要包含相应的头文件
    // deque的默认构造函数
    deque<int> deq1;
    for(int i = 0; i < 10; i++){
        deq1.push_back(i);
    }
    printDeque(deq1);
    printLine();

    // deque(begin, end)
    deque<int> deq2(deq1.begin(), deq1.end());
    printDeque(deq2);
    printLine();

    // deque(n, element);
    deque<int> deq3(10, 66);
    printDeque(deq3);
    printLine();

    // deque(const deque& deq);
    deque<int> deq5(deq1);
    printDeque(deq5);
    printLine();

}

int main(){
    test01();
    return 0;
}
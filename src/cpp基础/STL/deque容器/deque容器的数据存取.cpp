#include <iostream>
#include <deque>
using namespace std;

// deque容器的数据存取：对deque中的数据的存取操作
// 函数原型
    // at(int index);                   // 返回索引index位置的数据
    // operator[](int index);           // 重载了[]操作赋返回索引index位置的数据
    // front();                         // 返回容器中第一个数据
    // back();                          // 返回容器中最后一个数据

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
    for(int i = 0; i < 10; i++){
        deq.push_back(i*10 + 66);
    }
    printDeque(deq);
    printLine();

    // at(int index)
    int num = deq.at(2);
    cout << "通过at()获取容器中的第3个元素为： " << num << endl;

    // operator[](int index)
    num = deq[3];
    cout << "通过[]获取容器中的第4个元素为： " << num << endl;

    // front()
    num = deq.front();
    cout << "通过front()获取容器中的第一个数据为： " << num << endl;

    // back()
    num = deq.back();
    cout << "通过back()获取容器中的最后一个数据为： " << num << endl;
}

int main(){
    test01();
    return 0;
}
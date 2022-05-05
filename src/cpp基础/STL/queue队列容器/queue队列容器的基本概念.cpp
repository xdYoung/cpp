#include <iostream>
#include <queue>
using namespace std;

// queue队列容器的基本概念：queue是一种先进先出（First In First Out）FIFO 的数据结构
// 队列容器允许从一端新增元素，从另一端移除元素
// 队列中只有队头和队尾才可以被外界使用，因此队列也不允许有遍历行为
// 队列中进数据称为：入队（push）
// 队列中出数据称为：出队（pop）

// queue常用接口：队列容器常用的对外接口
// 构造函数
    // queue<T> que;                                            // queue采用模版类实现，queue对象的默认构造函数
    // queue<T> que(const queue& que);                          // 拷贝构造函数
// 赋值操作
    // queue& operator=(const queue& que);                      // 重载等号操作赋，将que中的元素赋值给本身
// 数据存取
    // push(element);                                           // 往队尾添加元素
    // pop();                                                   // 从队头移除第一个元素
    // back();                                                  // 返回最后一个元素
    // front();                                                 // 返回第一个元素
// 大小操作
    // empty();                                                 // 判断队列是否为空
    // size();                                                  // 返回队列的大小

void printLine(){
    cout << "------------------------------------------" << endl;
}

void printStack(queue<string> que){ // 这里不传入que的引用，因为查看队列元素会弹出队列的第一个元素，传入引用会修改队列中的元素
    // 队列不允许有遍历行为
    while(!que.empty()){
        cout << "栈中的元素为(FILO)： " << que.front() << endl;
        que.pop();
    }
}

void test01(){
    // 默认构造函数
    queue<string> que;
    // 判断队列是否为空
    cout << (que.empty() ? "que队列为空！" : "que队列不为空！") << endl;
    // 返回队列的大小
    cout << "que队列的大小为： " << que.size() << endl;
    printLine();
    // 向队列尾添加元素
    que.push("young");
    que.push("ting");
    que.push("shohn");
    que.push("hello");
    que.push("world");
    que.push("你好");
    que.push("世界");
    que.push("啊");
    cout << (que.empty() ? "que队列为空！" : "que队列不为空！") << endl;
    cout << "que队列的大小为： " << que.size() << endl;
    printStack(que);
    printLine();
    // 从队列头部移除一个元素
    que.pop();
    // 返回队列头部元素
    string s1 = que.front();
    string s2 = que.back();
    cout << "que队列头部元素为： " << s1 << endl;
    cout << "que队列尾部元素为： " << s2 << endl;
    printLine();

    // 拷贝构造函数
    queue<string> que1(que);
    s1 = que1.front();
    s2 = que1.back();
    cout << "que1队列头部元素为： " << s1 << endl;
    cout << "que1队列尾部元素为： " << s2 << endl;
    printStack(que1);
    printLine();

    // 栈的赋值操作
    // stack<string> stk2 = stk;   // 这个是不是栈的赋值操作，是栈的拷贝构造。本质是 stack<string> stk2 = stack<string>(stk);
    // stack<string> stk2 = stack<string>(stk);
    queue<string> que2;
    que2 = que; // 这个是栈的=赋值操作
    s1 = que2.front();
    s2 = que2.back();
    cout << "que2队列头部元素为： " << s1 << endl;
    cout << "que2队列尾部元素为： " << s2 << endl;
    printStack(que2);
    printLine();

}

int main(){
    test01();
    return 0;
}
#include <cstddef>
#include <iostream>
#include <stack>
using namespace std;

// stack栈容器的基本概念：stack是一种先进后出（First In Last Out）FILO 的数据结构，它只有一个出口
// 栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
// 栈中进入数据称为：入栈（push）
// 栈中弹出数据称为：出栈（pop）
// 栈可以判断容器是否为空, empty()
// 栈可以返回元素个数，size()

// stack栈常用接口：栈容器常用的对外接口
// 构造函数
    // stack<T> stk;                        // stack采用模版类实现，stack对象的默认构造函数
    // stack<T> stk(const stack& stk);      // 拷贝构造函数
// 赋值操作
    // stack& operator=(const stack& stk);  // 重载=好赋值运算符，将stk中的元素赋值给本身
// 数据存取
    // push(element);                       // 向栈顶添加元素
    // pop();                               // 从栈顶移除一个元素
    // top();                               // 返回栈顶元素
// 大小操作
    // empty();                             // 判断堆栈是否为空
    // size();                              // 返回栈的大小

void printLine(){
    cout << "------------------------------------------" << endl;
}

void printStack(stack<string> stk){ // 这里不传入stk的引用，因为查看栈会弹出栈顶元素，传入引用会修改栈中的元素
    while(!stk.empty()){
        cout << "栈中的元素为(FILO)： " << stk.top() << endl;
        stk.pop();
    }
}

void test01(){
    // 默认构造函数
    stack<string> stk;
    // 判断栈是否为空
    cout << (stk.empty() ? "stk栈为空！" : "stk栈不为空！") << endl;
    // 返回栈的大小
    cout << "stk栈的大小为： " << stk.size() << endl;
    printLine();
    // 向栈顶添加元素
    stk.push("young");
    stk.push("ting");
    stk.push("shohn");
    stk.push("hello");
    stk.push("world");
    stk.push("你好");
    stk.push("世界");
    stk.push("啊");
    cout << (stk.empty() ? "stk栈为空！" : "stk栈不为空！") << endl;
    cout << "stk栈的大小为： " << stk.size() << endl;
    printStack(stk);
    printLine();
    // 从栈顶移除一个元素
    stk.pop();
    // 返回栈顶元素
    string s = stk.top();
    cout << "stk的栈顶元素为： " << s << endl;
    printLine();

    // 拷贝构造函数
    stack<string> stk1(stk);
    s = stk1.top();
    cout << "stk1的栈顶元素为： " << s << endl;
    printStack(stk1);
    printLine();

    // 栈的赋值操作
    // stack<string> stk2 = stk;   // 这个是不是栈的赋值操作，是栈的拷贝构造。本质是 stack<string> stk2 = stack<string>(stk);
    // stack<string> stk2 = stack<string>(stk);
    stack<string> stk2;
    stk2 = stk; // 这个是栈的=赋值操作
    s = stk2.top();
    cout << "stk2的栈顶元素为： " << s << endl;
    printStack(stk2);
    printLine();

}

int main(){
    test01();
    return 0;
}
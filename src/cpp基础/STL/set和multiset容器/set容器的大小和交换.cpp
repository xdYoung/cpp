#include <iostream>
#include <set>
using namespace std;

// set容器的大小和交换：统计set容器大小以及交换set容器
// 函数原型
    // size();                  // 返回容器中元素的数目
    // empty();                 // 判断容器是否为空
    // swap();                  // 交换两个集合容器

// set容器没有resize()方法，因为set容器不允许有重复的值

void printLine(){
    cout << "------------------------------------" << endl;
}

void printSet(const set<int>& st){
    for(set<int>::const_iterator it = st.begin(); it != st.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    set<int> st;
    cout << "初始化set容器，st的大小为： " << st.size() << endl;
    cout << "初始化set容器： " << (st.empty() ? "set容器为空" : "set容器不为空") << endl;
    printLine();

    st.insert(50);
    st.insert(30);
    st.insert(60);
    st.insert(28);
    st.insert(66);
    st.insert(18);
    st.insert(16);
    st.insert(66);
    st.insert(10);

    cout << "st的大小为： " << st.size() << endl;
    cout << (st.empty() ? "set容器为空" : "set容器不为空") << endl;
    printLine();

    set<int> st1;
    st1.insert(36);
    st1.insert(88);
    cout << "st1的大小为： " << st1.size() << endl;
    cout << (st.empty() ? "set1容器为空" : "set1容器不为空") << endl;
    printLine();

    // swap(st);交换两个容器
    cout << "交换前： " << endl;
    cout << "st: ";
    printSet(st);
    cout << "st1: ";
    printSet(st1);
    printLine();

    cout << "交换后： " << endl;
    st1.swap(st);
    cout << "st: ";
    printSet(st);
    cout << "st1: ";
    printSet(st1);
    printLine();

}

int main(){
    test01();
    return 0;
}
#include <iostream>
#include <set>
using namespace std;

// set 容器的基本概念：所有元素都会在插入时自动被排序
// set 容器的本质：set/multiset 属于关联式容器，底层结构是用二叉树实现的。
// set 和 multiset 的区别：
    // set 不允许容器中有重复的元素
    // multiset 允许容器中有重复的元素

// set 容器的构造和赋值：创建 set 容器以及赋值
// set 容器的构造函数
    // set<T> st;                            // 默认构造函数
    // set<T> st(begin, end);
    // set<T> st(const set& st);             // 拷贝构造函数
// set 容器的赋值
    // set& operator=(const set& st);        // 重载等号=操作赋，将st中元素赋值给本身

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
    // 默认构造函数
    set<int> st;
    // set容器在插入数据的时候，只有insert()方式
    st.insert(50);
    st.insert(30);
    st.insert(60);
    st.insert(28);
    st.insert(66);
    st.insert(18);
    st.insert(16);
    st.insert(66);
    st.insert(10);
    // set容器在插入数据的时候会自动进行排序，默认按升序的方式排序
    cout << "st: " << endl;
    printSet(st);
    cout << "st的大小为： " << st.size() << endl;
    st.insert(10);  // 无法向set容器中插入重复的元素
    cout << "st的大小为： " << st.size() << endl;
    printLine();

    // set<T> st(begin, end)
    set<int> st1(++st.begin(), --st.end());
    cout << "st1: " << endl;
    printSet(st1);
    printLine();

    // 拷贝构造函数
    set<int> st3(st);
    cout << "st3: " << endl;
    printSet(st3);
    printLine();

    // set& operator=(const set& st)
    set<int> st6;
    st6 = st;
    cout << "st6: " << endl;
    printSet(st6);
    printLine();
}

int main(){
    test01();
    return 0;
}
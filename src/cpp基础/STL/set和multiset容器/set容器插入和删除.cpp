#include <iostream>
#include <set>
using namespace std;

// set容器的插入和删除：set容器进行插入数据和删除数据
// 函数原型
    // insert(element);                 // 在容器中插入元素
    // clear();                         // 清除所有元素
    // erase(pos);                      // 删除pos（pos是迭代器）所指定的元素，返回下一个元素的迭代器
    // erase(begin, end);               // 删除[begin, end)区间的所有元素，返回下一个元素的迭代器
    // erase(element);                  // 删除容器中值为elem的元素

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
    // insert(elem)
    st.insert(50);
    st.insert(30);
    st.insert(60);
    st.insert(28);
    st.insert(66);
    st.insert(18);
    st.insert(16);
    st.insert(66);
    st.insert(10);
    cout << "st: ";
    printSet(st);
    printLine();

    // erase(pos);
    st.erase(++st.begin());
    cout << "st: ";
    printSet(st);
    printLine();

    // erase(begin, end)
    st.erase(st.begin(), ++st.begin());
    cout << "st: ";
    printSet(st);
    printLine();

    // erase(elem)
    st.erase(30);
    cout << "st: ";
    printSet(st);
    printLine();

    // clear()
    st.clear();
    cout << "st: ";
    printSet(st);
    printLine();

}

int main(){
    test01();
    return 0;
}
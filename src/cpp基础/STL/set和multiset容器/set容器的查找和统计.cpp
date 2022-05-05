#include <iostream>
#include <set>
using namespace std;

// set容器的查找和统计：对set容器进行查找数据以及统计数据
// 函数原型
    // find(key);                   // 查找key是否存在。若存在，则返回该键的元素的迭代器；若不存在，则返回set.end()
    // count(key);                  // 统计key的元素个数

// 在set容器中因为不允许存在重复的数字，所以count返回的数字要么是0，要么是1.

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

    // find(key)
    set<int>::iterator pos = st.find(28);
    cout << ((pos != st.end()) ? "在set容器中找到了28" : "在set容器中没有找到28") << endl;
    pos = st.find(68);
    cout << ((pos != st.end()) ? "在set容器中找到了68" : "在set容器中没有找到68") << endl;
    
    // count(key)
    int cnt = st.count(66); // 在set容器中因为不允许存在重复的数字，所以count返回的数字要么是0，要么是1.
    cout << ((cnt == 1) ? "66存在于set容器中" : "66不存在于容器中") << endl;
}

int main(){
    test01();
    return 0;
}
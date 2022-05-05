#include <iostream>
#include <set>
using namespace std;

// set和multiset的区别
// 区别
    // set不可以插入重复数据，而multiset可以
    // set插入数据的同时会返回插入结果，表示插入是否成功
    // multiset不会检测数据，因此可以插入重复数据

void printLine(){
    cout << "------------------------------------" << endl;
}

void printSet(const set<int>& st){
    for(set<int>::const_iterator it = st.begin(); it != st.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printMultiSet(const multiset<int>& mst){
    for(multiset<int>::const_iterator it = mst.begin(); it != mst.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
// set和multiset的区别
void test01(){
    cout << "set: " << endl;
    set<int> st;
    // set容器插入数据返回的是一个 pair 对组类型，对组中包含一个迭代器和一个布尔值，可以通过 .first 和 .second 的方式拿到结果
    pair<set<int>::iterator, bool> ret = st.insert(10);
    cout << (ret.second ? "第一次数据10插入成功" : "第一次数据10插入失败") << endl;
    ret = st.insert(10);
    cout << (ret.second ? "第二次数据10插入成功" : "第二次数据10插入失败") << endl;
    cout << "set<int> st = ";
    printSet(st);

    printLine();

    cout << "multiset: " << endl;
    multiset<int> mst;  // multiset 允许插入重复的值
    // multiset容器插入数据返回的是一个迭代器，不会对插入数据进行校验
    multiset<int>::iterator multi_ret = mst.insert(10);
    cout << *multi_ret << endl;
    multi_ret = mst.insert(10);
    cout << *multi_ret << endl;
    cout << "multiset<int> mst = ";
    printMultiSet(mst);
}

int main(){
    test01();
    return 0;
}
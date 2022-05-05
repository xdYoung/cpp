#include <iostream>
#include <set>  // set容器和multiset容器都只需要包含<set>头文件
using namespace std;

// multiset插入元素时也会被自动排序，但multiset允许插入重复的数据

// multiset 容器的构造和赋值：创建 multiset 容器以及赋值
// multiset 容器的构造函数
    // multiset<T> st;                            // 默认构造函数
    // multiset<T> st(begin, end);
    // multiset<T> st(const multiset& st);             // 拷贝构造函数
// multiset 容器的赋值
    // multiset& operator=(const multiset& st);        // 重载等号=操作赋，将st中元素赋值给本身
// multiset插入元素时也会被自动排序，但multiset允许插入重复的数据

void printLine(){
    cout << "------------------------------------" << endl;
}

void printMultiSet(const multiset<int>& st){
    for(multiset<int>::const_iterator it = st.begin(); it != st.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    // 默认构造函数
    multiset<int> mst;
    // set容器在插入数据的时候，只有insert()方式
    mst.insert(50);
    mst.insert(30);
    mst.insert(60);
    mst.insert(28);
    mst.insert(66);
    mst.insert(18);
    mst.insert(16);
    mst.insert(66);
    mst.insert(10);
    // multiset容器在插入数据的时候会自动进行排序，默认按升序的方式排序
    cout << "mst: " << endl;
    printMultiSet(mst);
    cout << "mst的大小为： " << mst.size() << endl;
    mst.insert(10);  // 可以向multiset容器中插入重复的元素
    cout << "mst的大小为： " << mst.size() << endl;
    printMultiSet(mst);
    printLine();

    // multiset<T> mst(begin, end)
    multiset<int> mst1(++mst.begin(), --mst.end());
    cout << "mst1: " << endl;
    printMultiSet(mst1);
    printLine();

    // 拷贝构造函数
    multiset<int> mst3(mst);
    cout << "mst3: " << endl;
    printMultiSet(mst3);
    printLine();

    // multiset& operator=(const multiset& st)
    multiset<int> mst6;
    mst6 = mst;
    cout << "mst6: " << endl;
    printMultiSet(mst6);
    printLine();
}

int main(){
    test01();
    return 0;
}
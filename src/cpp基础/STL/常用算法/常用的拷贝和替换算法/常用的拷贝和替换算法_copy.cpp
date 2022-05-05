#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 常用的拷贝和替换算法 copy：容器内指定范围的元素拷贝到另一个容器中
// 函数原型：
    // copy(Inputiterator begin, InputIterator end, OutputIterator destBegin);
    // 将容器内指定范围的元素拷贝到另一个容器中
    // begin：起始迭代器
    // end：结束迭代器
    // destBegin：目标容器的起始迭代器
// 总结：利用copy算法拷贝时，目标容器需要提前开辟空间，否则无法拷贝

void printLine(){
        cout << "-----------------------------------------" << endl;
}

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printV(const vector<string>& v){
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printV(v1);
    printLine();

    vector<int> v2;
    // 目标容器要提前开辟空间，否则无法拷贝
    v2.resize(v1.size());
    // copy(Inputiterator begin, InputIterator end, OutputIterator destBegin)
    copy(v1.begin(), v1.end(), v2.begin());
    printV(v2);
    printLine();
}

void myPrint(const int& val){
    cout << val << " ";
}

void test02(){
    list<int> lst;
    for(int i = 10; i < 20; i++){
        lst.push_back(i);
    }
    for_each(lst.begin(), lst.end(), myPrint);
    cout << endl;
    printLine();

    list<int> lst1;
    // 目标容器需要提前开辟空间，否则无法拷贝
    lst1.resize(lst.size());
    // copy(Inputiterator begin, InputIterator end, OutputIterator destBegin)
    copy(lst.begin(), lst.end(), lst1.begin());
    for_each(lst1.begin(), lst1.end(), myPrint);
    cout << endl;
}

int main(){
    test01();
    test02();
    return 0;
}
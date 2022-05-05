#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 常用的排序算法 reverse：将容器内元素进行反转
// 函数原型：
    // reverse(InputIterator begin, InputIterator end);
    // 反转指定范围的元素
    // begin：起始迭代器
    // end：结束迭代器

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
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    printV(v);
    printLine();

    // reverse(InputIterator begin, InputIterator end)
    reverse(v.begin(), v.end());
    printV(v);
    printLine();
}

int main(){
    test01();
    return 0;
}
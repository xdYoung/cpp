#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 常用的拷贝和替换算法 swap：互换两个容器的元素
// 函数原型：
    // swap(container c1, container c2);
    // 互换两个容器的元素
    // c1：容器1
    // c2：容器2

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
    vector<int> v2;
    v1.push_back(6);
    v1.push_back(68);
    v1.push_back(16);
    v1.push_back(60);
    v1.push_back(86);
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(666);
    v1.push_back(888);
    v1.push_back(686);

    v2.push_back(168);
    v2.push_back(188);
    v2.push_back(108);
    v2.push_back(68);
    v2.push_back(118);

    cout << "互换前： " << endl;
    cout << "v1: ";
    printV(v1);
    cout << "v2: ";
    printV(v2);
    printLine();

    // swap(container c1, container c2);
    swap(v1, v2);
    cout << "互换后： " << endl;
    cout << "v1: ";
    printV(v1);
    cout << "v2: ";
    printV(v2);
    printLine();
}

int main(){
    test01();
    return 0;
}
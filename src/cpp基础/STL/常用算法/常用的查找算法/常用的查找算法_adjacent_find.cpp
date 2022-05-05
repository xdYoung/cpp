#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 常用的查找算法 adjacent_find：查找相邻重复元素
// 函数原型：
    // adjacent_find(InputIterator begin, InputIterator end);
    // 查找相邻重复元素，返回相邻重复元素的第一个重复元素的位置的迭代器
    // begin：起始迭代器
    // end；结束迭代器

void printLine(){
        cout << "-----------------------------------------" << endl;
    }

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(30);
    v.push_back(30);
    printV(v);
    printLine();

    // adjacent_find()查找相邻重复元素
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    cout << (pos != v.end() ? "查找到相邻重复元素： \"" + to_string(*pos) + "\"" : "未找到相邻重复元素") << endl;
}

int main(){
    test01();
    return 0;
}
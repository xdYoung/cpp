#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 常用的集合算法 set_union：求两个集合的并集
// 函数原型：
    // set_union(InputIterator begin1, InputIterator end1, InputIterator begin2, InputIterator end2, OutputIterator destBegin);
    // 求两个容器的并集
    // 注意：两个集合必须是有序序列
    // begin1：容器1起始迭代器
    // end1：容器1的结束迭代器
    // begin2：容器2的起始迭代器
    // end2：容器2的结束迭代器
    // destBegin：目标容器的起始迭代器
// 总结：
    // 两个容器求交集，两个容器必须是有序序列
    // 考虑极限情况：目标容器需要提前开辟空间，否则无法向目标容器中填入元素，取两个容器大小相加的值。
    // set_union()返回值是并集中最后一个元素的迭代器位置

void printLine(){
        cout << "-----------------------------------------" << endl;
}

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printVec(const int& val){
    cout << val << " ";
}

void test01(){
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 20; i++){
        v1.push_back(i);
        v2.push_back(i+8);
    }
    cout << "v1: ";
    printV(v1);
    cout << "v2: ";
    printV(v2);
    printLine();

    vector<int> vTarget;
    // 需要提前给目标容器开辟空间，否则无法写入
    // 考虑极限情况：两个容器的交集取两个容器大小相加的值给目标容器开辟空间
    vTarget.resize(v1.size()+v2.size());

    // set_intersection()，求两个容器的并集
    // 要求两个容器必须是有序序列
    // 返回目标容器并集最后一个元素的迭代器的位置
    vector<int>::iterator posEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    cout << "vTarget: ";
    printV(vTarget);
    cout << "vTarget: ";
    for_each(vTarget.begin(), posEnd, printVec);
    cout << endl;
}

int main(){
    test01();
    return 0;
}
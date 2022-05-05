#include <iostream>
#include <vector>
using namespace std;

// 常用的排序算法 merge：将两个容器中的元素合并，并存储在另一个容器中
// 函数原型：
    // merge(Iterator begin1, Iterator end1, Iterator begin2, Iterator end2, Iteratror destBegin);
    // 容器元素合并，并存储到另一个容器中
    // 注意：两个容器合并前必须是有序的
    // begin1：容器1的起始迭代器
    // end1：容器1的结束迭代器
    // begin2：容器2的起始迭代器
    // end2：容器2的结束迭代器
    // destBegin：目标容器的起始迭代器
// 注意：
    // 两个容器合并前必须是有序的
    // 目标容器需要提前开辟空间，否则无法合并到目标容器

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
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
        v2.push_back(i+6);
    }

    printV(v1);
    printLine();
    printV(v2);
    printLine();

    vector<int> vTarget;
    // 目标容器需要提前开辟空间
    vTarget.resize(v1.size()+v2.size());
    // merge合并两个容器，合并前两个容器必须是有序容器,排序规则必须都是升序排列
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    printV(vTarget);
    printLine();

}

int main(){
    test01();
    return 0;
}
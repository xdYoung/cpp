#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// 常用的遍历算法_transform：搬运容器到另一个容器中
// 函数原型：
    // tranform(InputIterator begin, InputIterator end, OutputIterator dest_begin, _func);
    // begin：原容器的起始迭代器
    // end：原容器的结束迭代器
    // des_begin：目标容器的起始迭代器
    // _func：函数或者函数对象（仿函数）

void printLine(){
    cout << "---------------------------------------"  << endl;
}

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// 普通函数作为transform的参数
int addOneNum(const int& v){
    return v+16;
}

// 函数对象（仿函数）作为transform的参数
class MultiOneNum{
public:
    int operator()(const int& v){
        return v*66;
    }
};

void test01(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    printV(v);
    printLine();

    // 普通函数作为transform的参数
    vector<int> v1;
    // 目标容器需要提前开辟空间
    v1.resize(v.size());
    transform(v.begin(), v.end(), v1.begin(), addOneNum);
    printV(v1);
    printLine();

    // 函数对象（仿函数）作为transform的参数
    vector<int> v2;
    // 目标容器需要提前开辟空间
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), MultiOneNum());
    printV(v2);
    printLine();

    // 内建函数对象作为transform的参数
    vector<int> v3;
    // 在使用transform之前需要指定目标容器的大小，否则无法transform到目标容器
    v3.resize(v.size());
    transform(v.begin(), v.end(), v3.begin(), negate<int>());
    printV(v3);
    printLine();

}

int main(){
    test01();
    return 0;
}
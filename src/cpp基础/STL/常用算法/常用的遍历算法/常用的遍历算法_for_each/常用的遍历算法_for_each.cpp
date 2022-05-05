#include <iostream>
// #include <algorithm>
#include <vector>
using namespace std;

// 常用的遍历算法：掌握常用的遍历算法
// 算法简介：
    // for_each                 // 遍历容器
    // transform                // 搬运容器到另一个容器中

// for_each：实现遍历容器
// 函数原型：
    // for_each(iterator begin, iterator end, _func);
    // 遍历算法：遍历容器元素
    // begin：起始迭代器
    // end：结束迭代器
    // _func：函数或者函数对象

// 普通函数作为for_each的参数
void printV(const int& v){
    cout << v << " ";
}

// 仿函数作为for_each的参数
class PrintV{
public:
    void operator()(const int& v){
        cout << v << " ";
    }
};

void test01(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    // for_each 算法遍历容器，普通函数作为for_each的参数
    for_each(v.begin(), v.end(), printV);
    cout << endl;

    // for_each 算法遍历容器，仿函数作为for_each的参数
    for_each(v.begin(), v.end(), PrintV());
    cout << endl;
}

int main(){
    test01();
    return 0;
}
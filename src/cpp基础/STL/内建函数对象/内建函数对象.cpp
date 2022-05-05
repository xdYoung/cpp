#include <functional>
#include <algorithm>
#include <iostream>
#include <functional>   // 内建的函数对象头文件
#include <vector>
using namespace std;

// 内建函数对象概念：STL内建了一些函数对象
// 内建函数对象分类：
    // 算术仿函数
    // 关系仿函数
    // 逻辑仿函数
// 内建函数对象用法：
    // 这些仿函数所产生的对象，用法和一般函数完全相同
    // 使用内建仿函数对象，需要引入头文件 #include <functional>

// 算术仿函数：
    // 功能描述：
        // 实现四则运算
        // 其中 negate 是一元运算仿函数，其它都是二元运算仿函数
    // 仿函数原型
        // template<typename T> struct plus<T>{};              // 加法仿函数
        // template<typename T> struct minus<T>{};             // 减法仿函数
        // template<typename T> struct multiplies<T>{};        // 乘法仿函数
        // template<typename T> struct divides<T>{};           // 除法仿函数
        // template<typename T> struct modulus<T>{};           // 取模仿函数
        // template<typename T> struct negate<T>{};            // 取反仿函数

// 关系仿函数
    // 功能描述：实现关系对比
    // 仿函数原型：
        // template<class T> struct equal_to<T>{};              // 等于
        // template<class T> struct not_equal_to<T>{};          // 不等于
        // template<class T> struct greater<T>{};               // 大于
        // template<class T> struct greater_equal<T>{};         // 大于等于
        // template<class T> struct less<T>{};                  // 小于
        // template<class T> struct less_equal<T>{};            // 小于等于

// 逻辑仿函数
    // 功能描述：实现逻辑运算
    // 函数原型：
        // template<class T> struct logical_and<T>;             // 逻辑与
        // template<class T> struct logical_or<T>;              // 逻辑或
        // template<class T> struct logical_not<T>;             // 逻辑非

void printLine(){
    cout << "--------------------------------------" << endl;
}

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printVector(const vector<string>& v){
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printVector(const vector<bool>& v){
    for(vector<bool>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// 算术仿函数
void test01(){
    // 针对一元二元分别做一个用例

    // negate 一元仿函数，取反仿函数
    negate<int> n;
    int n1 = n(10);
    cout << "negate<int>一元取反仿函数调用结果 n1 为：" << n1 << endl;
    printLine();

    // plus 二元仿函数，加法仿函数。其它二元仿函数同样的方式。
    plus<int> p;
    n1 = p(10, 20);
    cout << "plus<int>二元加法仿函数调用结果 n1 为： " << n1 << endl;
    printLine();
    plus<string> p1;
    string s = p1("young ", " ting");
    cout << "plus<string> p1()调用结果 s 为： " << s << endl;
}

// 关系仿函数
void test02(){
    // 针对greater<>大于仿函数做一个用例，其它相同

    vector<int> v;

    v.push_back(66);
    v.push_back(16);
    v.push_back(28);
    v.push_back(6);
    v.push_back(1);
    v.push_back(88);
    v.push_back(68);
    v.push_back(86);

    printVector(v);
    printLine();

    // sort(begin, end)，sort算法默认排序规则是升序排列
    cout << "sort(begin, end): ";
    sort(v.begin(), v.end());
    printVector(v);
    printLine();

    // 用greater大于关系仿函数，改变排序规则实现降序排列
    // greater<int>()，是内建的函数对象
    cout << "sort(begin, end, pred): ";
    sort(v.begin(), v.end(), greater<int>());
    printVector(v);
}

// 逻辑仿函数
void test03(){
    // 以logical_not逻辑仿函数做用例，其它同样
    vector<bool> v;

    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);

    printVector(v);
    printLine();

    // 利用logical_not<bool>()仿函数将容器v搬运到容器v1中，并执行取反操作
    vector<bool> v1;
    v1.resize(v.size());

    transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());
    printVector(v1);
    
}

int main(){
    test01();
    printLine();
    test02();
    printLine();
    test03();
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// vector容器基本概念
// vector容器基本功能：vector数据结构和数组非常相似，也称为单端数组
// vector与普通数组的区别：不同之处在于数组是静态空间，而vector可以动态扩展
// 动态扩展：
    // 并不是在原空间之后续接空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间
// vector容器的迭代器是支持随机访问的迭代器
// vector构造函数：创建vector容器
// vector构造函数的函数原型：
    // vector<T> v;                              // 采用模版类实现，默认构造函数
    // vector<T> v(v.begin(), V.end());          // 将v[begin(), end())区间中的元素拷贝给本身，左闭右开，左边可以取到，右边取不到。
    // vector<T> v(n, element);                  // 构造函数将n个element拷贝给本身
    // vector<T> v(const vector &v);             // 拷贝构造函数

void printLine(){
    cout << "-------------------------------------------" << endl;
}

void printVector(const vector<int> &v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// vector容器的构造
void test01(){
    // STL中所有的容器在使用时都需要包含相应的头文件
    // 默认构造函数
    cout << "通过默认构造方式 -> vector<int> v: " << endl;
    vector<int> v;  // 默认构造，无参构造
    for(int i = 0; i < 10; i++){
        v.push_back(i+10);
    }
    printVector(v);
    printLine();

    // 通过区间方式进行构造
    cout << "通过区间方式进行构造 -> vector<int> v1: " << endl;
    vector<int> v1(v.begin(), v.end());
    printVector(v1);
    printLine();

    // 通过n个element方式进行构造
    cout << "通过n个element方式进行构造 -> vector<int> v2: " << endl;
    vector<int> v2(10, 66);
    printVector(v2);
    printLine();

    // 通过拷贝构造函数进行赋值
    cout << "通过拷贝构造函数进行赋值 -> vector<int> v3: " << endl;
    vector<int> v3(v);
    printVector(v3);
    printLine();

}
int main(){
    test01();
    return 0;
}
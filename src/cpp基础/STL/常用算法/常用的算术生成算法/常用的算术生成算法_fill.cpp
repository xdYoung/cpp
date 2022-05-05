#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// 常用的算术生成算法 fill：向容器中填充指定的元素
// 函数原型：
    // fill(InputIterator begin, InputIterator end, value);
    // 将容器区间内的元素填充为指定的value值。
    // begin：起始迭代器
    // end：结束迭代器
    // value：填充的值

void printLine(){
        cout << "-----------------------------------------" << endl;
}

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// 常用的算术生成算法 fill
void test01(){
    vector<int> v;
    // 如果不指定填充值，会给容器添加默认填充值
    v.resize(10);
    printV(v);
    printLine();
    // 如果指定填充值，超出容器原大小的部分容器会添加指定的填充值。
    v.resize(15, 168);
    printV(v);
    printLine();

    // 后期重新填充值，可以使用fill
    // fill会将容器中所有元素全部填充为指定的value值。
    fill(v.begin(), v.end(), 888);
    printV(v);
    printLine();


}

int main(){
    test01();
    return 0;
}
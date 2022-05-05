#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// 常用的算术生成算法 accumulate：计算容器区间内元素的累计总和
// 函数原型：
    // int accumulate(InputIterator begin, InputIterator end, initValue);
    // 计算容器区间内元素的累计总和
    // begin：起始迭代器
    // end；结束迭代器
    // initValue：起始值
// 总结：使用accumulate算法是要包含头文件 #include <numeric>

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
    for(int i = 0; i <= 100; i++){
        v.push_back(i);
    }

    // 使用accumulate算法是要包含头文件 #include <numeric>
    // accumulate(InputIterator begin, InputIterator end, initValue)
    // 第三个参数init是起始的累加值
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "accumulate()累计的总和为（起始累加值为0）： " << sum << endl;
    printLine();
    sum = accumulate(v.begin(), v.end(), 1000);
    cout << "accumulate()累计的总和为（起始累加值为1000）： " << sum << endl;
}

int main(){
    test01();
    return 0;
}
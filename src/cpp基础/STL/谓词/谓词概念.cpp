#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 谓词概念：
    // 返回bool类型的仿函数称为谓词
    // 如果operator()接收一个参数，那么叫做一元谓词
    // 如果operator()接收两个参数，那么叫做二元谓词

void printLine(){
    cout << "----------------------------------" << endl;
}

void printVector(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

struct GreatFive{
    bool operator()(int n){
        return n > 5;
    }
};

// 一元谓词
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    // struct GreatFive greatFive;
    // 查找容器中有没有大于5的数字
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreatFive());   // 匿名函数对象
    cout << (pos != v.end() ? "有大于5的数: " + to_string(*pos) : "没有大于5的数") << endl;
}

struct MyCompare{
    bool operator()(const int& v1, const int& v2){
        return v1 > v2;
    }
};

bool myCompare(const int& v1, const int& v2){
    return v1 > v2;
}

// 二元谓词
void test02(){
    vector<int> v;
    v.push_back(88);
    v.push_back(10);
    v.push_back(30);
    v.push_back(80);
    v.push_back(68);
    v.push_back(16);
    // sort默认时从小到大排序
    sort(v.begin(), v.end());
    printVector(v);
    // 通过二元谓词（仿函数），改变排序规则，从大到小排序
    sort(v.begin(), v.end(), MyCompare());  // 匿名的函数对象
    printVector(v);
    // 通过普通函数改变排序规则
    sort(v.begin(), v.end(), myCompare);
    printVector(v);

}

int main(){
    test01();
    printLine();
    test02();
    return 0;
}
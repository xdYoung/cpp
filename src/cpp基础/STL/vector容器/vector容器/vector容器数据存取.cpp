#include <iostream>
#include <vector>
using namespace std;

// vector容器数据存取：对vector容器中的数据的存取操作
// 函数原型
    // at(int index);                   // 返回索引index所指的数据
    // opretor[](int index);            // 重载[]运算符，返回索引index所指的数据
    // front();                         // 返回容器中第一个数据元素
    // back();                          // 返回容器中最后一个数据元素

void printLine(){
    cout << "-------------------------------------------" << endl;
}

void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i+66);
    }
    printVector(v);
    printLine();
    // 通过at()访问vector中的元素
    for(int i = 0; i < v.size(); i++){
        cout << "通过at()访问v中的元素 " << i << " 为： " << v.at(i) << endl;
    }
    printLine();

    // 通过[]访问vector中的元素
    for(int i = 0; i < v.size(); i++){
        cout << "通过[]访问v中的元素 " << i << " 为：" << v[i] << endl;
    }
    printLine();

    // 通过front()访问v中的第一个元素
    cout << "通过front()访问v中的第一个元素： " << v.front() << endl;
    printLine();

    // 通过back()访问v中的最后一个元素
    cout << "通过back()访问v中的最后一个元素： " << v.back() << endl;
    printLine();

    // 通过at()修改v中指定的元素
    v.at(6) = 666;
    printVector(v);
    printLine();

    // 通过重载的[]修改v中指定的元素
    v[3] = 888;
    printVector(v);
    printLine();
}

int main(){
    test01();
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// vector 容器的赋值操作：给vector容器进行赋值
// 函数原型：
    // vector& operator=(const vector &v);                  // 重载等号=操作符
    // void assign(begin, end);                                  // 将[begin, end)区间中的数据拷贝赋值给本身
    // void assign(n, element);                                  // 将n个element拷贝赋值个本身

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
    // STL中所有的容器在使用时都需要包含相应的头文件
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i+10);
    }
    printVector(v);
    printLine();

    // 通过等号=操作赋赋值
    cout << "通过等号=操作符赋值 -> vector<int> v1: " << endl;
    vector<int> v1 = v;
    printVector(v1);
    printLine();

    // 通过assign(begin, end)方式赋值
    cout << "通过assign(begin, end)方式赋值 -> vector<int> v2: " << endl;
    vector<int> v2;
    v2.assign(v.begin(), v.end());
    printVector(v2);
    printLine();

    // 通过assign(n, element)方式赋值
    cout << "通过assign(n, element)方式赋值 -> vector<int> v2: " << endl;
    vector<int> v3;
    v3.assign(10, 66);
    printVector(v3);
    printLine();
}

int main(){
    test01();
    return 0;
}
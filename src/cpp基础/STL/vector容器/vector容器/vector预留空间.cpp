#include <iostream>
#include <vector>
using namespace std;

// vector预留空间：减少vector在动态扩展容量时的扩展次数
// 函数原型：
    // reserve(int len);        // 容器预留len个元素长度，预留位置不初始化，元素不可访问
// 总结：如果数据量级较大，一开始就可以利用reserve()预留空间，避免多次开辟内存空间，降低效率。

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
    vector<int> v1;
    int num = 0; // 统计vector添加元素时内存开辟的次数
    int* p = NULL;  // 定义一个指针指向vector的首地址
    for(int i = 0; i < 10000; i++){
        v1.push_back(i);
        if(p != &v1[0]){
            p = &v1[0];
            num++;
        }
    }
    printLine();
    cout << "在给容器 v1 添加元素的时候开辟了 " << num << " 次内存空间" << endl;
    cout << "添加元素后，容器 v1 的容量为： " << v1.capacity() << endl;
    cout << "添加元素后，容器 v1 的大小为： " << v1.size() << endl;
    printLine();
}

void test02(){
    vector<int> v2;
    // 给容器预留空间
    v2.reserve(10000);
    cout << "预留空间后，容器 v2 的容量为： " << v2.capacity() << endl;
    cout << "预留空间后，容器 v2 的大小为： " << v2.size() << endl;
    printLine();

    // 统计在预留了容器空间后，容器开启的内存次数
    int num = 0;
    int* p = NULL;
    for(int i = 0; i < 10000; i++){
        v2.push_back(i);
        if(p != &v2[0]){
            p = &v2[0];
            num++;
        }
    }
    cout << "给容器预留了空间后，容器添加元素开辟的内存次数为： " << num << " 次内存空间" << endl;
    cout << "预留空间添加元素后，容器 v2 的容量为： " << v2.capacity() << endl;
    cout << "添加元素后，容器 v2 的大小为： " << v2.size() << endl;
    printLine();
    // 继续给容器添加元素
    v2.push_back(10001);
    cout << "添加元素超过预留空间后，容器 v2 的容量为： " << v2.capacity() << endl;
    cout << "添加元素超过预留空间后，容器 v2 的大小为： " << v2.size() << endl;
    printLine();
    vector<int> (v2).swap(v2);
    cout << "swap()收缩空间后，容器 v2 的容量为： " << v2.capacity() << endl;
    cout << "swap()收缩空间后，容器 v2 的大小为： " << v2.size() << endl;
    printLine();

}

int main(){
    test01();
    test02();
    return 0;
}
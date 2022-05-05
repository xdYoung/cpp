#include <iostream>
#include <vector>
using namespace std;

// vector互换容器：实现两个容器内元素进行互换
// 函数原型：
    // swap(vec);       // 将vec与本身的元素进行互换

void printLine(){
    cout << "-------------------------------------------" << endl;
}

void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
// vector容器互换
// 1.vector容器互换的基本使用
void test01(){
    cout << "vector容器v和v1交换前： " << endl;
    vector<int> v;
    cout << "容器v： ";
    for(int i = 0; i < 10; i++){
        v.push_back(i*10 + 66);
    }
    printVector(v);
    cout << "交换前v的容量为： " << v.capacity() << endl;
    cout << "交换前v的大小为： " << v.size() << endl;
    printLine();

    vector<int> v1;
    cout << "容器v1: ";
    for(int i = 6; i > 0; i--){
        v1.push_back(i*6 + 88);
    }
    printVector(v1);
    cout << "交换前v1的容量为： " << v1.capacity() << endl;
    cout << "交换前v1的大小为： " << v1.size() << endl;
    printLine();

    cout << "vector容器v和v1交换后： " << endl;
    v.swap(v1);
    cout << "交换后容器v： ";
    printVector(v);
    cout << "交换后v的容量为： " << v.capacity() << endl;
    cout << "交换后v的大小为： " << v.size() << endl;
    printLine();
    cout << "交换后容器v1: ";
    printVector(v1);
    cout << "交换后v1的容量为： " << v1.capacity() << endl;
    cout << "交换后v1的大小为： " << v1.size() << endl;
    printLine();
}

// 2.vector容器互换的实际用途
// 巧用swap()可以收缩内存空间
void test02(){
    vector<int> v;
    for(int i = 0; i < 10000; i++){
        v.push_back(i);
    }
    cout << "v的容量为： " << v.capacity() << endl;
    cout << "v的大小为： " << v.size() << endl;
    printLine();

    // 重新指定v的大小
    v.resize(3);
    cout << "重新指定v的大小后，v的容量为： " << v.capacity() << endl;
    cout << "重新指定v的大小后，v的大小为： " << v.size() << endl;
    printLine();

    // 巧用swap()收缩内存空间
    vector<int> (v).swap(v);
    // 解释：
    // vector<int> (v)：这是一个匿名对象，将重新指定了大小的v传入，调用了拷贝构造函数，新创建了一个匿名的vector容器。
    // 匿名对象的特点，当前行执行完后，编译器会回收内存。
    // .swap(v)与原来的容器v交换后，原来的容器v和匿名容器对象交换后会被回收。匿名容器对象交换给了原来的容器v。
    cout << "利用swap()交换收缩空间后，v的容量为： " << v.capacity() << endl;
    cout << "利用swap()交换收缩空间后，v的大小为： " << v.size() << endl;
    printLine();
}

int main(){
    test01();
    test02();
    return 0;
}
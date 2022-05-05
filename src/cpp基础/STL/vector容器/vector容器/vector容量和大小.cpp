#include <iostream>
#include <vector>
using namespace std;

// vector的容量和大小：对vector的容量和大小操作
// 函数原型：
    // bool empty();                            // 判断容器是否为空
    // int capacity();                          // 容器的容量
    // int size();                              // 返回容器中元素的个数
    // void resize(int num);                    // 重新指定容器的长度为num，如果容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除
    // void resize(int num, element);           // 重新指定容器的长度为num，如果容器变长，则以element值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除

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
    cout << "初始化容器时容器的capacity即容器的容量为： " << v.capacity() << endl;
    cout << "初始化容器时容器的size即容器中元素的个数为： "  << v.size() << endl;
    cout << "判断初始化容器是否为空： " << (v.empty() ? "容器为空！" : "容器不为空！") << endl;
    printLine();
    for(int i = 0; i < 10; i++){
        v.push_back(i+10);
    }
    printVector(v);
    printLine();

    // 给vector容器加入元素后：
    cout << "给容器加入元素后容器的capacity即容器的容量为： " << v.capacity() << endl;
    cout << "给容器加入元素后容器的size即容器中元素的个数为： "  << v.size() << endl;
    cout << "给容器加入元素后判断容器是否为空： " << (v.empty() ? "容器为空！" : "容器不为空！") << endl;
    printLine();

    // 给容器重新指定大小，重新指定的大小小于当前容器的大小，超出重新制定大小的元素被删除
    v.resize(5);
    cout << "容器的capacity即容器的容量为： " << v.capacity() << endl;  // 容量增加后不会被改变。
    cout << "容器的size即容器中元素的个数为： "  << v.size() << endl;
    cout << "判断容器是否为空： " << (v.empty() ? "容器为空！" : "容器不为空！") << endl;
    printVector(v);
    printLine();

    // 给容器重新指定大小，重新指定的大小大于当前容器的大小,超过原容器大小长度的元素赋值为element。
    v.resize(20, 66);
    cout << "容器的capacity即容器的容量为： " << v.capacity() << endl;  // 容量扩充后不会改变
    cout << "容器的size即容器中元素的个数为： "  << v.size() << endl;
    cout << "判断容器是否为空： " << (v.empty() ? "容器为空！" : "容器不为空！") << endl;
    cout << v.at(19) << endl;
    printVector(v);
    printLine();

    // 给容器重新指定大小，比原容器小的话，赋值元素没有作用。
    v.resize(16, 30);
    cout << "容器的capacity即容器的容量为： " << v.capacity() << endl;
    cout << "容器的size即容器中元素的个数为： "  << v.size() << endl;
    cout << "判断容器是否为空： " << (v.empty() ? "容器为空！" : "容器不为空！") << endl;
    cout << v.at(15) << endl;
    printVector(v);
    printLine();
    
    
}

int main(){
    test01();
    return 0;
}
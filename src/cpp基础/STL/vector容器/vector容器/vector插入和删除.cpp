#include <iostream>
#include <vector>
using namespace std;

// vector的插入和删除：对vector容器进行插入，删除操作
// 函数原型：
    // void push_back(element);                                            // 尾部插入元素element
    // void pop_back();                                                    // 删除最后一个元素
    // void insert(const_iterator pos, element);                           // 迭代器指向位置pos插入元素element
    // void insert(const_iterator pos, int count, element);                // 迭代器指向位置pos插入count个元素element
    // void erase(const_iterator pos);                                     // 删除迭代器指向的元素
    // void erase(const_iterator start, const_interator end);              // 删除迭代器从start位置到end位置之间的元素
    // void clear();                                                       // 删除容器中所有的元素

void printLine(){
    cout << "-------------------------------------------" << endl;
}

void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// vector容器的插入和删除
void test01(){
    vector<int> v;
    // 尾插法插入数据push_back
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    v.push_back(90);
    printVector(v);
    printLine();
    // 尾删法删除数据
    v.pop_back();
    printVector(v);
    printLine();
    // 插入insert(const_iterator pos, element);
    v.insert(v.begin(), 66);    // 第一个参数是迭代器
    printVector(v);
    printLine();
    // 插入insert(const_iterator start, int count, element);
    v.insert(v.begin(), 2, 88);
    printVector(v);
    printLine();
    // 删除erase(const_iterator pos)
    v.erase(v.begin());
    printVector(v);
    printLine();
    // 删除erase(const_iterator start, const_iterator end) ,删除区间中的元素
    v.erase(v.begin(), ++v.begin());
    printVector(v);
    printLine();
    // 清空vector容器
    v.clear();
    printVector(v);
    printLine();
}


int main(){
    test01();
    return 0;
}
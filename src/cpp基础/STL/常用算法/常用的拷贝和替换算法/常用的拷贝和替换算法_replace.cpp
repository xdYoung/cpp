#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 常用的拷贝和替换算法 replace：将容器内指定范围的旧元素替换为新元素
// 函数原型：
    // replace(InputIterator begin, InputIterator end, oldValue, newValue);
    // 将区间内旧元素替换为新元素
    // begin：起始迭代器
    // end：结束迭代器
    // oldValue：旧元素
    // newValue：新元素
// 总结：区间内只要满足oldValue值的元素都会被替换为newValue值

void printLine(){
        cout << "-----------------------------------------" << endl;
}

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printV(const vector<string>& v){
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(60);
    v.push_back(18);
    v.push_back(50);
    v.push_back(60);
    v.push_back(80);
    v.push_back(60);
    v.push_back(20);
    v.push_back(60);
    cout << "替换前： " << endl;
    printV(v);
    printLine();

    // replace(InputIterator begin, InputIterator end, oldValue, newValue)
    replace(v.begin(), v.end(), 60, 66);
    cout << "替换后： " << endl;
    printV(v);
    printLine();
}
void test02(){
    vector<string> v;
    v.push_back("hello");
    v.push_back("jdshf");
    v.push_back("world");
    v.push_back("good");
    v.push_back("replace");
    v.push_back("mac");
    v.push_back("pro");
    v.push_back("mri");
    v.push_back("jdshf");
    v.push_back("jdshf");
    cout << "替换前： " << endl;
    printV(v);
    printLine();

    // replace(InputIterator begin, InputIterator end, oldValue, newValue)
    replace(v.begin(), v.end(), "jdshf", "money");
    cout << "替换后： " << endl;
    printV(v);
    printLine();
}

int main(){
    test01();
    test02();
    return 0;
}
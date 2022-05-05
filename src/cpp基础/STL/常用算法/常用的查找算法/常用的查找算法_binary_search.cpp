#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// 常用的查找算法 binary_search ：查找指定元素是否存在
// 函数原型：
    // bool binary_search(InputIterator begin, InputIterator end, value);
    // 查找指定的元素，查到返回 true， 未查到返回 false
    // 注意： 二分查找法要求容器中的元素必须是有序的，在无序序列中不可用
    // begin：起始迭代器
    // end： 结束迭代器
    // value：查找的元素
// 总结：二分查找法查找的效率很高，但是注意的是查找的容器中元素必须是有序序列

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
    for(int i = 0; i < 100; i++){
        v.push_back(i);
    }
    // 定义查找的元素
    cout << "请输入查找的元素num： ";
    int num;
    cin >> num;
    printLine();
    // binary_search()二分查找法查找容器中指定的元素
    // 注意：容器必须是有序序列
    bool res = binary_search(v.begin(), v.end(), num);
    cout << (res ? "查找到元素：" + to_string(num) : "未找到元素：" + to_string(num)) << endl;
}

void printList(const list<string>& lst){
    for(list<string>::const_iterator it = lst.begin(); it != lst.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test02(){
    list<string> lst;
    lst.push_back("d");
    lst.push_back("f");
    lst.push_back("h");
    lst.push_back("w");
    lst.push_back("u");
    lst.push_back("h");
    lst.push_back("q");
    lst.push_back("k");
    lst.push_back("l");
    lst.push_back("o");
    lst.push_back("u");
    lst.push_back("i");
    lst.push_back("p");
    lst.push_back("z");
    lst.push_back("x");
    lst.push_back("b");
    lst.push_back("n");

    lst.sort();
    printList(lst);
    printLine();

    // 定义查找的元素
    cout << "请输入查找的元素s: ";
    string s;
    cin >> s;
    printLine();
    // binary_search()二分查找法查找list容器中的元素
    // 二分查找法要求查找的容器实现是有序的排列
    bool res = binary_search(lst.begin(), lst.end(), s);
    cout << (res ? "查找到元素：" + s : "未找到元素：" + s) << endl;

}

int main(){
    test01();
    printLine();
    test02();
    return 0;
}
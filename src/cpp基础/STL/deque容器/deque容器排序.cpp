#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

// deque容器的排序：利用算法实现对deque容器进行排序
// 算法：
    // sort(iterator begin, iterator end);      // 对begin和end区间内元素进行排序，默认排序规则是从小到大
// 对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
// vector容器也可以利用 sort 算法进行排序

void printLine(){
    cout << "-----------------------------------------------------" << endl;
}

void printDeque(const deque<int> &deq){
    for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}
void printDeque(const deque<string> &deq){
    for(deque<string>::const_iterator it = deq.begin(); it != deq.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    deque<string> deq;
    deq.push_back("f");
    deq.push_back("a");
    deq.push_back("e");
    deq.push_back("x");
    deq.push_back("b");
    deq.push_back("q");
    deq.push_back("m");
    deq.push_back("j");
    cout << "排序前： " << endl;
    printDeque(deq);
    printLine();
    // 利用sort(iterator begin, iterator end)算法对deque容器的begin和end区间进行排序
    cout << "对某个区间排序后：" << endl;
    sort(deq.begin()+1, deq.end()-2);
    printDeque(deq);
    printLine();

    cout << "对deque排序后： " << endl;
    sort(deq.begin(), deq.end());
    printDeque(deq);
    printLine();
}

int main(){
    test01();
    return 0;
}


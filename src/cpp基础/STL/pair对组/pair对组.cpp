#include <iostream>
#include <utility>
using namespace std;

// pair对组创建：成对出现的数据，利用对组可以返回两个数据
// 两种创建方式：
    // pair<type, type> p(value1, value2);
    // pair<type, type> p = make_pair(value1, value2);
// 如果考虑返回两个数据，可以考虑使用对组
// 成员函数
    // swap(pair<type, type>& p);

void test01(){
    // pair对组的创建
    cout << "交换前： " << endl;
    pair<string, int> p("young", 32);
    cout << "p.first = " << p.first << "   p.second = " << p.second << endl;

    pair<string, int> p1 = make_pair("ting", 28);
    cout << "p1.first = " << p1.first << "   p1.second = " << p1.second << endl;

    cout << "交换后： " << endl;
    p.swap(p1);
    cout << "p.first = " << p.first << "   p.second = " << p.second << endl;
    cout << "p1.first = " << p1.first << "   p1.second = " << p1.second << endl;

    cout << "---------------------------" << endl;
    pair<int, int> p2(6, 8);
    // p2.swap(p); // 不同类型的pair对组不能够交换

}

int main(){
    test01();
    return 0;
}
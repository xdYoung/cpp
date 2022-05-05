#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

// 常用的查找算法 count：统计元素的个数
// 函数原型：
    // int count(InputIterator begin, InputIterator end, value);
    // 统计容器中指定元素出现的次数
    // begin：起始迭代器
    // end：结束迭代器
    // value：统计的元素
// 总结：统计自定义数据类型的时候，需要配合重载 operator==

void printLine(){
        cout << "-----------------------------------------" << endl;
    }

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// 统计内置数据类型的元素
void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    v.push_back(50);
    v.push_back(80);
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(100);
    v.push_back(100);
    v.push_back(80);
    v.push_back(60);
    v.push_back(10);

    // 输入要统计的元素
    cout << "请输入要统计的元素num： ";
    int num;
    cin >> num;
    printLine();

    printV(v);
    printLine();

    // count 统计指定元素的个数
    int cnt = count(v.begin(), v.end(), num);
    cout << "容器v中元素 " + to_string(num) + " 的个数为： " << cnt << endl;

}

class Person{
public:
    Person(string c, int n):m_char(c), m_num(n){}
public:
    string getC()const{return m_char;}
    int getNum()const{return m_num;}
public:
    bool operator==(const Person& p){
        if(this->m_num == p.getNum()) return true;
        return false;
    }
private:
    string m_char;
    int m_num;
};



void printList(const list<Person>& lst){
    for(list<Person>::const_iterator it = lst.begin(); it != lst.end(); it++){
        cout << " Person字母编号： " 
             << it->getC() 
             << " Person数字编号： " 
             << it->getNum() << endl;
    }
}
// 统计自定义数据类型的元素
void test02(){
    list<Person> lst;
    Person p1("a", 16);
    Person p2("b", 16);
    Person p3("c", 15);
    Person p4("d", 18);
    Person p5("e", 19);
    Person p6("f", 20);
    Person p7("g", 16);
    Person p8("h", 12);
    Person p9("i", 12);
    Person p10("j", 18);
    Person p11("k", 20);
    Person p12("l", 15);
    lst.push_back(p1);
    lst.push_back(p2);
    lst.push_back(p3);
    lst.push_back(p4);
    lst.push_back(p5);
    lst.push_back(p6);
    lst.push_back(p7);
    lst.push_back(p8);
    lst.push_back(p9);
    lst.push_back(p10);
    lst.push_back(p11);
    lst.push_back(p12);
    lst.push_back(p1);

    // 输入要查找Person数字编号：
    cout << "请输入要查找的Person的数字编号num：";
    int num;
    cin >> num;
    Person fp("a", num);
    printLine();
    printList(lst);
    printLine();

    // count 统计Person数据类型中数字编号的个数
    int cnt = count(lst.begin(), lst.end(), fp);
    cout << "容器lst中Person的数字编号值为：" << num << " 的个数为： " << cnt << endl;

}

int main(){
    test01();
    printLine();
    test02();
    return 0;
}
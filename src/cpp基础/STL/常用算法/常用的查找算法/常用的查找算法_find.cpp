#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 常用的查找算法 - find ：查找指定元素的迭代器，找不到返回结束迭代器 end()
// 函数原型：
    // find(InputIterator begin, InputIterator end, value);
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器的位置
    // begin：起始迭代器
    // end：结束迭代器
    // value：查找的元素
// 总结：利用find可以在容器中查找指定的元素，返回的是迭代器

void printLine(){
    cout << "-----------------------------------------" << endl;
}

void printV(const vector<string>& v){
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// 查找内置的数据类型
void test01(){
    vector<string> v;
    v.push_back("young");
    v.push_back("ting");
    v.push_back("shohn");
    v.push_back("peng");
    v.push_back("chuan");
    v.push_back("zhang");
    v.push_back("jindou");
    v.push_back("juan");
    printV(v);
    printLine();
    // find
    vector<string>::iterator pos = find(v.begin(), v.end(), "ting");
    cout << (pos != v.end() ? "在容器v中查找到 \"" + *pos + "\" 这个元素" : "未在容器v中查找到元素") << endl;
}

class Person{
public:
    Person(string name, int age):m_name(name), m_age(age){}
public:
    string getName()const{return m_name;}
    int getAge()const{return m_age;}
public:
    bool operator==(const Person& that){
        if(m_name == that.getName() && m_age == that.getAge()){
            return true;
        }
        return false;
    }
private:
    string m_name;
    int m_age;
};
void printVP(const vector<Person>& v){
    for(vector<Person>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名： " << it->getName() << " 年龄：" << it->getAge() << endl;
    }
}

// 查找自定义的数据类型
void test02(){
    vector<Person> v;
    Person p1("young", 32);
    Person p2("ting", 28);
    Person p3("shohn", 30);
    Person p5("peng", 29);
    Person p6("chuan", 29);
    Person p7("zhang", 29);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);
    printVP(v);
    printLine();

    // find()查找自定义数据类型
    // 要查找的元素
    Person fp1("young", 32);
    Person fp2("li", 35);
    vector<Person>::iterator pos = find(v.begin(), v.end(), fp1);
    cout << (pos != v.end() ? "在容器v中查找到 \"" + pos->getName() + "\" 这个Person" : "未在容器v中查找到元素") << endl;
    printLine();
    pos = find(v.begin(), v.end(), fp2);
    cout << (pos != v.end() ? "在容器v中查找到 \"" + pos->getName() + "\" 这个Person" : "未在容器v中查找到元素") << endl;

}

int main(){
    test01();
    printLine();
    test02();
    return 0;
}
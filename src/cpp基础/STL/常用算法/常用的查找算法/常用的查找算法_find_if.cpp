#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// find_if：按条件查找元素
// 函数原型：
    // find_if(InputIterator first, InputIterator last, Predicate pred)
    // 按条件查找元素，找到返回指定位置的迭代器，找不到返回结束迭代器的位置
    // first：起始迭代器
    // last：结束迭代器
    // pred：函数或者谓词（返回bool类型的仿函数）
namespace yangPrint{
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
}
using namespace yangPrint;

// 普通函数做predicate谓词
bool greatSix(const int& v1){
    return v1 > 6;
}

// 函数对象做predicate谓词
class greatEqualSix{
public:
    bool operator()(const int& v){
        return v >= 6; 
    }
};

// find_if 查找内置数据类型
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    printV(v);
    printLine();

    // find_if 查找内置的数据类型，普通函数做谓词
    vector<int>::iterator pos = find_if(v.begin(), v.end(), greatSix);
    cout << (pos != v.end() ? "在容器v中查找到>6的元素为： \"" + to_string(*pos) + "\"" : "未在容器v中查找到元素") << endl;
    // find_if 查找内置的数据类型，函数对象做谓词
    pos = find_if(v.begin(), v.end(), greatEqualSix());
    cout << (pos != v.end() ? "在容器v中查找到>=6的元素为： \"" + to_string(*pos) + "\"" : "未在容器v中查找到元素") << endl;

}

namespace yangClass {
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
}
using namespace yangClass;

// find_if 查找自定义数据类型，普通函数做谓词
bool great30(const Person& p){
    return p.getAge() > 30;
}
// find_if 查找自定义数据类型，函数对象做谓词
class Great32{
public:
    bool operator()(const Person& p){
        return p.getAge() > 32;
    }
};

class Equal29{
public:
    bool operator()(const Person& p){
        return p.getAge() == 29;
    }
};

void printVP(const vector<Person>& v){
    for(vector<Person>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名： " << it->getName() << " 年龄：" << it->getAge() << endl;
    }
}
// find_if 查找自定义数据类型
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

    // find_if 查找自定义数据类型，普通函数做谓词
    vector<Person>::iterator pos = find_if(v.begin(), v.end(), great30);
    cout << (pos != v.end() ? 
    ("在容器v中找到年龄大于30的Person / 姓名： " + pos->getName() + " 年龄：" + to_string(pos->getAge())) : 
    "未在容器v中查找到符合条件的元素") << endl;

    // find_if 查找自定义数据类型，函数对象做谓词
    pos = find_if(v.begin(), v.end(), Great32());
    cout << (pos != v.end() ? 
    ("在容器v中找到年龄大于30的Person / 姓名： " + pos->getName() + " 年龄：" + to_string(pos->getAge())) : 
    "未在容器v中查找到符合条件的元素") << endl;

    // 查找所有等于29岁的人
    vector<Person>::iterator it = v.begin();
    while(it != v.end()){
        vector<Person>::iterator pos = find_if(it, v.end(), Equal29());
        if(pos == v.end()) cout << "未找到指定元素";
        cout << "在容器v中找到年龄等于29的Person / 姓名： " + pos->getName() + " 年龄：" + to_string(pos->getAge()) << endl;
        it = pos;
        it++;
    }
}
int main(){
    test01();
    printLine();
    test02();
    return 0;
}
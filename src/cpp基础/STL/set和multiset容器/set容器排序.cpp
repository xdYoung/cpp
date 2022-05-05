#include <iostream>
#include <set>
using namespace std;

// set容器的排序：set容器默认排序规则为从小到大，掌握如何改变排序规则
// 主要技术点：利用仿函数，可以改变排序规则
// 对于自定义数据类型，set必须指定排序规则才可以插入数据

void printLine(){
    cout << "------------------------------------" << endl;
}

void printSet(const set<int>& st){
    for(set<int>::const_iterator it = st.begin(); it != st.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

class myCompare{
public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void printSetCompare(const set<int, myCompare>& st){
    for(set<int, myCompare>::const_iterator it = st.begin(); it != st.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// -------------------------------------------------------------------------

class Person{
public:
    Person(string name, int age):m_name(name), m_age(age){}
public:
    string getName()const{return m_name;}
    int getAge()const{return m_age;}
private:
    string m_name;
    int m_age;
};

class PersonCompare{
public:
    bool operator()(const Person& p1, const Person& p2){
        return p1.getName() > p2.getName();
    }
};

void printSetP(const set<Person, PersonCompare>& st){
    for(set<Person>::const_iterator it = st.begin(); it != st.end(); it++){
        cout << "姓名： " << it->getName() << "   年龄： " << it->getAge() << endl;
    }
}



// set容器存放内置数据类型
void test01(){
    set<int> st;
    st.insert(66);
    st.insert(6);
    st.insert(8);
    st.insert(166);
    st.insert(168);
    st.insert(688);
    st.insert(60);
    st.insert(18);
    st.insert(16);
    printSet(st);
    printLine();

    // 指定排序规则为从大到小
    // set<class Key, class Compare = less<Key>, class Allocator = Allocator<Key>>
    // set<>第二类型的默认值 Compare = less<Key> 是从小到大，利用仿函数改变第二个类型参数
    set<int, myCompare> st1;
    st1.insert(66);
    st1.insert(6);
    st1.insert(8);
    st1.insert(166);
    st1.insert(168);
    st1.insert(688);
    st1.insert(60);
    st1.insert(18);
    st1.insert(16);
    printSetCompare(st1);
    printLine();
}
// set容器存放自定义的数据类型
void test02(){
    // 自定义数据类型，都会指定排序规则
    set<Person, PersonCompare> st;
    Person p1("young", 32);
    Person p2("ting", 28);
    Person p3("shohn", 30);
    Person p5("peng", 29);
    Person p6("chuan", 29);
    Person p7("zhang", 27);
    pair<set<Person>::iterator, bool> ret = st.insert(p1);
    cout << (ret.second ? "插入成功" : "插入失败") << endl;
    st.insert(p2);
    st.insert(p3);
    st.insert(p5);
    st.insert(p6);
    st.insert(p7);
    printSetP(st);

}

int main(){
    test01();
    test02();
    return 0;
}
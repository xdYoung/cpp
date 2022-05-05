#include <iostream>
#include <map>
#include <utility>
using namespace std;

// map容器的排序：map容器默认排序规则为按key键进行从小到大排序，掌握如何修改排序规则
// 主要技术点：利用仿函数，可以改变排序规则

namespace test01_{
    void printLine(){
    cout << "----------------------------------------------" << endl;
    }

    class MyCompareInt{
    public:
        bool operator()(int v1, int v2)const{
            return v1 > v2;
        }
    };

    class MyCompareString{
    public:
        bool operator()(string s1, string s2)const{
            return s1 > s2;
        }
    };

    void printMap(const map<int, string>& mp){
        for(map<int, string>::const_iterator it = mp.begin(); it != mp.end(); it++){
            cout << "key: " << it->first << "   value: " << it->second << " | ";
        }
        cout << endl;
    }

    void printMap(const map<int, string, MyCompareInt>& mp){
        for(map<int, string, MyCompareInt>::const_iterator it = mp.begin(); it != mp.end(); it++){
            cout << "key: " << it->first << "   value: " << it->second << " | ";
        }
        cout << endl;
    }

    void printMap(const map<string, int, MyCompareString>& mp){
        for(map<string, int, MyCompareString>::const_iterator it = mp.begin(); it != mp.end(); it++){
            cout << "key: " << it->first << "   value: " << it->second << " | ";
        }
        cout << endl;
    }
}
using namespace test01_;

namespace test02_ {
    class Person{
    public:
        Person(string name, int age, int heigth):m_name(name), m_age(age), m_height(heigth){}
    public:
        string getName()const{return m_name;}
        int getAge()const{return m_age;}
        int getHeight()const{return m_height;}
    private:
        string m_name;
        int m_age;
        int m_height;
    };

    class PersonCompare{
    public:
        bool operator()(const Person& p1, const Person& p2)const{
            if(p1.getName() == p2.getName()){
                if(p1.getAge() == p2.getAge()){
                    return p1.getHeight() > p2.getHeight();
                }
                else {
                    return p1.getAge() > p2.getAge();
                }
            }else{
                return p1.getName() < p2.getName();
            }
        }
    };

    void printMapPerson(const map<Person, int, PersonCompare>& mp){
        for(map<Person, int, PersonCompare>::const_iterator it = mp.begin(); it != mp.end(); it++){
            cout << "姓名： " << it->first.getName() << " 年龄： " << it->first.getAge() << " 身高： " << it->first.getHeight() << endl;
        }
    }

}
using namespace test02_;

// map中的内置数据类型排序
void test01(){
    // map的默认排序规则是从小到大。
    map<int, string> mp;
    mp.insert(pair<int, string>(1, "a"));
    mp.insert(make_pair(6, "b"));
    mp.insert(map<int, string>::value_type(3, "c"));
    mp.insert(make_pair(2, "e"));
    mp.insert(make_pair(7, "f"));
    mp.insert(make_pair(9, "g"));
    mp.insert(make_pair(8, "h"));
    mp.insert(make_pair(3, "j"));
    mp.insert(make_pair(10, "k"));
    printMap(mp);
    printLine();

    // 利用仿函数指定map容器的排序规则
    map<int, string, MyCompareInt> mp1;
    mp1.insert(pair<int, string>(1, "a"));
    mp1.insert(make_pair(6, "b"));
    mp1.insert(map<int, string>::value_type(3, "c"));
    mp1.insert(make_pair(2, "e"));
    mp1.insert(make_pair(7, "f"));
    mp1.insert(make_pair(9, "g"));
    mp1.insert(make_pair(8, "h"));
    mp1.insert(make_pair(3, "j"));
    mp1.insert(make_pair(10, "k"));
    printMap(mp1);
    printLine();

    // 利用仿函数指定map容器的排序规则
    map<string, int, MyCompareString> mp2; 
    mp2.insert(pair<string, int>("a", 1));
    mp2.insert(make_pair("b", 6));
    mp2.insert(map<string, int>::value_type("c", 3));
    mp2.insert(make_pair("e", 2));
    mp2.insert(make_pair("f", 7));
    mp2.insert(make_pair("g", 9));
    mp2.insert(make_pair("h", 8));
    mp2.insert(make_pair("j", 3));
    mp2.insert(make_pair("k", 10));
    printMap(mp2);
    printLine();
}

// map中自定义数据类型的排序
void test02(){
    map<Person, int, PersonCompare> mp;
    // 指定排序规则，如果指定的元素有重复值，则无法重复值无法插入
    Person p1("young", 32, 176);
    Person p2("ting", 28, 167);
    Person p3("shohn", 30, 182);
    Person p5("peng", 29, 169);
    Person p6("chuan", 29, 171);
    Person p7("young", 29, 171);
    Person p8("young", 29, 171);
    mp.insert(make_pair(p1, 1));
    mp.insert(make_pair(p2, 2));
    mp.insert(make_pair(p3, 3));
    mp.insert(make_pair(p5, 4));
    mp.insert(make_pair(p6, 5));
    mp.insert(make_pair(p7, 6));
    mp.insert(make_pair(p8, 7));
    printMapPerson(mp);
    printLine();
    cout << mp[p1] << endl;
}

int main(){
    // test01();
    test02();
    return 0;
}
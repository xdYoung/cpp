#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// STL的每个容器在使用的时候都需要包含相对应的容器的头文件
// STL在使用算法的时候要包含算法的头文件

// STL中最常用的容器为vector，可以理解为数组
// 容器：vector
// 算法：for_each
// 迭代器：vector<int>::iterator
namespace yang{
    template<typename T>
    void printVector(T val){
        cout << "通过for_each遍历vector中的元素：" << val << endl;
    }
    
    template<typename T>
    void printPerson(T p){
        cout << "通过for_each循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << p->getName() << endl;
        cout << "通过for_each循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << p->getAge() << endl;
    }

    template<class TypeName, class TypeInt>
    class Person;
    template<class T1, class T2>
    void printVector(T2 &p){
        cout << "通过for_each循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << p.getName() << endl;
        cout << "通过for_each循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << p.getAge() << endl;
    }

    void printLine(){
        cout << "---------------------------------------------" << endl;
    }

    template<class TypeName, class TypeInt>
    class Person{
    public:
        Person(TypeName name, TypeInt age){
            m_name = name;
            m_age = age;
        }
    public:
        TypeName getName(){return m_name;}
        TypeInt getAge(){return m_age;}
    private:
        TypeName m_name;
        TypeInt m_age;
    };
}
using namespace yang;

// vector容器存放内置的数据类型
void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // 通过迭代器访问容器中的数据
    vector<int>::iterator it_begin = v.begin(); // 起始迭代器，指向容器中的第一个元素
    vector<int>::iterator it_end = v.end(); // 结束迭代器，指向容器中最后一个元素的下一个位置。

    // 第一种遍历的方式:while循环
    while(it_begin != it_end){
        cout << "vector中的元素：" << *it_begin << endl;
        it_begin++;
    }
    printLine();
    // 第二种遍历的方式:for
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << "通过for循环遍历vector中的元素：" << *it << endl;
    }
    printLine();
    // 第三种遍历的方式:for_each
    for_each(v.begin(), v.end(), printVector<int>);
}

// vector容器存放自定义数据类型
void test02(){
    Person<string,int> p1("young", 32);
    Person<string,int> p2("ting", 28);
    Person<string,int> p3("shohn", 30);
    vector< Person<string,int> > v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    vector< Person<string,int> >::iterator it_begin = v.begin();
    vector< Person<string,int> >::iterator it_end = v.end();
    while(it_begin != it_end){
        cout << "通过while循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << it_begin->getName() << endl;
        cout << "通过while循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getAge() = " << it_begin->getAge() << endl;
        it_begin++;
    }
    printLine();
    
    for(vector< Person<string,int> >::iterator it = v.begin(); it != v.end(); it++){
        cout << "通过for循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << it->getName() << endl;
        cout << "通过for循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << it->getAge() << endl;
    }
    printLine();

    for_each(v.begin(), v.end(), printVector<int, Person<string,int> >);
}

// vector容器存放自定义数据类型的指针
void test03(){
    vector<Person<string,int>*> v;
    Person<string,int> p1("孙悟空", 1000);
    Person<string,int> p2("猪八戒", 800);
    Person<string,int> p3("沙悟净", 800);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    vector<Person<string,int>*>::iterator it_begin = v.begin();
    vector<Person<string,int>*>::iterator it_end = v.end();
    while(it_begin != it_end){
        cout << "通过while循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << (*it_begin)->getName() << endl;
        cout << "通过while循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getAge() = " << (*it_begin)->getAge() << endl;
        it_begin++;
    }
    printLine();
    
    for(vector<Person<string,int>*>::iterator it = v.begin(); it != v.end(); it++){
        cout << "通过for循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << (*it)->getName() << endl;
        cout << "通过for循环遍历存放自定数据类型的vector容器：自定义数据类型的属性getName() = " << (*it)->getAge() << endl;
    }
    printLine();

    for_each(v.begin(), v.end(), printPerson<Person<string,int>*>);
}

int main(){
    cout << "test01():" << endl;
    test01();
    printLine();
    cout << "test02():" << endl;
    test02();
    printLine();
    cout << "test03():" << endl;
    test03();
    return 0;
}
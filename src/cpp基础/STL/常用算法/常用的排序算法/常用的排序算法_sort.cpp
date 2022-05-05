#include <iostream>
#include <vector>
using namespace std;

// 常用的排序算法 sort：对容器内元素进行排序
// 函数原型：
    // sort(InputIterator begin, InputIterator end, Predicate pred);
    // 对指定区间内的元素按照指定的排序规则排序
    // begin：起始迭代器
    // end：结束迭代器
    // pred：普通函数或者谓词（仿函数）

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

// sort()的排序算法，普通函数作为参数传入
bool my_greater(const string& v1, const string& v2){
    return v1 > v2;
}

// sort()算法排序，谓词（仿函数）作为参数传入
class My_Greater{
    public:
        bool operator()(const string& v1, const string& v2){
            m_count++;
            return v1 > v2;
        }
    public:
        static int getCount(){return m_count;}
    private:
        static int m_count;
};
int My_Greater::m_count = 0;

// sort()内置数据类型的算法排序
void test01(){
    vector<string> v;
    v.push_back("s");
    v.push_back("g");
    v.push_back("h");
    v.push_back("j");
    v.push_back("q");
    v.push_back("e");
    v.push_back("y");
    v.push_back("u");
    v.push_back("o");
    v.push_back("i");
    v.push_back("x");

    printV(v);
    printLine();

    // sort(InputIterator begin, InputIterator end, Predicate pred);
    // sort排序默认是升序排列
    sort(v.begin(), v.end());
    printV(v);
    printLine();

    // sort()的排序算法，普通函数作为参数传入
    sort(v.begin(), v.end(), my_greater);
    printV(v);
    printLine();

    // sort()算法排序，谓词（仿函数）作为参数传入
    // 谓词（仿函数）可以在内部维护一些状态
    sort(v.begin(), v.end(), My_Greater());
    printV(v);
    cout << "排序对比了： " << My_Greater::getCount() << " 次" << endl;
    printLine();

    // sort()算法排序，内置函数对象作为参数传入
    sort(v.begin(), v.end(), greater<string>());
    printV(v);
    printLine();
}

class Person{
    public:
        Person(string name, int age, int height){
            this->m_name = name;
            this->m_age = age;
            this->m_height = height;
        }
    public:
        string getName()const{return m_name;}
        int getAge()const{return m_age;}
        int getHeight()const{return m_height;}
    private:
        string m_name;
        int m_age;
        int m_height;
};

void PrintVP(const vector<Person>& v){
    for(vector<Person>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名：" << it->getName() << " 年龄：" << it->getAge() << " 身高：" << it->getHeight() << endl;
    }
}

// sort()自定义数据类型排序算法，普通函数作为参数传入
bool comparePerson(const Person& p1, const Person& p2){
    if(p1.getAge() == p2.getAge()) return p1.getHeight() < p2.getHeight();
    else return p1.getAge() > p2.getAge();
}
// sort()自定义数据类型排序算法，谓词（仿函数）作为参数传入
class ComparePerson{
    public:
        bool operator()(const Person& p1, const Person& p2){
            if(p1.getAge() == p2.getAge()){
                count++;
                return p1.getHeight() < p2.getHeight();
            }else{
                count++;
                return p1.getAge() > p2.getAge();
            }
        }
    public:
        static int count;
};
int ComparePerson::count = 0;

// sort()自定义数据类型的算法排序
void test02(){
    vector<Person> v;
    Person p1("a", 17, 178);
    Person p2("b", 21, 181);
    Person p3("e", 18, 170);
    Person p4("t", 24, 172);
    Person p5("q", 35, 176);
    Person p6("w", 39, 182);
    Person p7("g", 21, 181);
    Person p8("i", 22, 178);
    Person p9("o", 19, 170);
    Person p10("l", 17, 171);
    Person p11("k", 31, 188);
    Person p12("s", 33, 185);
    Person p13("d", 28, 186);
    Person p14("f", 27, 190);
    Person p15("v", 26, 173);
    Person p16("c", 24, 177);
    Person p17("z", 26, 183);
    Person p18("x", 28, 186);
    Person p19("n", 17, 181);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);
    v.push_back(p8);
    v.push_back(p9);
    v.push_back(p10);
    v.push_back(p11);
    v.push_back(p12);
    v.push_back(p13);
    v.push_back(p14);
    v.push_back(p15);
    v.push_back(p16);
    v.push_back(p17);
    v.push_back(p18);
    v.push_back(p19);

    PrintVP(v);
    printLine();
    // sort()自定义数据类型排序算法，普通函数作为参数传入
    sort(v.begin(), v.end(), comparePerson);
    PrintVP(v);
    printLine();
    // sort()自定义数据类型排序算法，谓词（仿函数）作为参数传入
    sort(v.begin(), v.end(), ComparePerson());
    PrintVP(v);
    cout << "自定义数据类型排序了： " << ComparePerson::count << " 次" << endl;
    printLine();
    
}

int main(){
    test01();
    test02();
    return 0;
}
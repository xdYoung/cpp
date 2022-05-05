#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 常用的查找算法 count_if：按条件统计元素个数
// 函数原型：
    // int count_if(InputIterator begin, InputIterator end, Predicate pred);
    // 按条件统计元素出现的次数
    // begin：起始迭代器
    // end；结束迭代器
    // pred：普通函数或者谓词（bool仿函数）


void printLine(){
        cout << "-----------------------------------------" << endl;
    }

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// count_if查找，普通函数作为参数传入
bool great28(const int& v){
    return v > 28;
}
// count_if查找，谓词（仿函数）作为参数传入
class GreatNum{
    public:
        GreatNum(int n):m_num(n){}
    public:
        bool operator()(const int& v){
            return v > m_num;
        }
    private:
        int m_num;
};

// count_if 查找内置数据类型
void test01(){
    vector<int> v;
    for(int i = 0; i < 100; i++){
        v.push_back(i);
    }
    
    // printV(v);
    printLine();
    // count_if查找，普通函数作为参数传入
    int cnt = count_if(v.begin(), v.end(), great28);
    cout << "查找到大于 " << 28 << " 的元素有 " << cnt << " 个" << endl;
    printLine();
    // count_if查找，谓词（仿函数）作为参数传入
    cout << "请输入查找大于num的num值： ";
    int num;
    cin >> num;
    cnt  = count_if(v.begin(), v.end(), GreatNum(num));
    cout << "查找到大于 " << num << " 的元素有 " << cnt << " 个" << endl;
}

class Person{
    public:
        Person(string name, int age):m_name(name), m_age(age){}
    public:
        string getName() const{return m_name;}
        int getAge() const{return m_age;}
    private:
        string m_name;
        int m_age;
};

// count_if 查找自定义数据类型，普通函数作为参数传入
bool great15(const Person& p){
    return p.getAge() > 15;
}
// count_if 查找自定义数据类型，谓词（仿函数）作为参数传入
class GreatAge{
    public:
        GreatAge(int n):m_num(n){}
    public:
        bool operator()(const Person& p){
            return p.getAge() > m_num;
        }
    private:
        int m_num;
};

// count_if 查找自定义数据类型
void test02(){
    vector<Person> v;
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

    // count_if 查找自定义数据类型，普通函数作为参数传入
    int cnt = count_if(v.begin(), v.end(), great15);
    cout << "Person年龄大于 15 的有 " << cnt << " 个" << endl;
    printLine();
    // // count_if 查找自定义数据类型，谓词（仿函数）作为参数传入
    cout << "请输入插叙大于age的age：";
    int age;
    cin >> age;
    cnt = count_if(v.begin(), v.end(), GreatAge(age));
    cout << "Person年龄大于 " << age << " 的有 " << cnt << " 个" << endl;
}

int main(){
    test01();
    printLine();
    test02();
    return 0;
}
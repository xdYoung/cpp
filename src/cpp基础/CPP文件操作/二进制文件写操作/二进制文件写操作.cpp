#include <iostream>
#include <fstream>
using namespace std;

class Person{
// public:
//     Person(string name, int age){
//         for(int i=0; i < name.size(); i++){m_Name[i] = name.at(i);}
//         m_Age = age;
//     }
public:
    // c++语言最好使用字符数组进行读写文件操作，因为c++底层是由c语言写的
    char m_Name[64];
    int m_Age;
};

void test01(){
    Person p = {"ting", 28};
    // Person p = {28};
    // Person p{"young", 32};
    // Person p("young", 32);
    ofstream ofs;
    ofs.open("../files/Person.txt", ios::out | ios::binary);
    ofs.write((const char *)&p, sizeof(Person));
    ofs.close();
}

int main(){
    test01();
    return 0;
}
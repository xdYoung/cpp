#include <iostream>
#include <fstream>
using namespace std;

class Person{
public:
    // c++语言最好使用字符数组进行读写文件操作，因为c++底层是由c语言写的
    char m_Name[64];
    int m_Age;
};

void test01(){
    Person p;
    ifstream ifs;
    ifs.open("../files/Person.txt", ios::in | ios::binary);
    if(!ifs.is_open()){
        cout << "打开文件错误！" << endl;
        return;
    }
    ifs.read((char *)&p, sizeof(Person));
    cout << "name = " << p.m_Name << "\tage = " << p.m_Age << endl;
    ifs.close();
}

int main(){
    test01();
    return 0;
}
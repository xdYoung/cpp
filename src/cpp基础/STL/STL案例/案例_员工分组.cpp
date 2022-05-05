#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

// 案例_员工分组
// 案例描述：
    // 公司招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在哪个部门工作
    // 员工信息有：姓名 工资组成； 部门分为：策划 美术 研发
    // 随机给10名员工分配部门和工资
    // 通过multimap进行信息的插入：key（部门编号） value（员工）
    // 分部门显示员工信息
// 实现步骤：
    // 创建10名员工，放到vector容器中
    // 遍历vector容器，取出每个员工，进行随机分组
    // 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
    // 分部门显示员工信息

#define CHEHUA 1
#define MEISHU 2
#define YANFA 3

// 员工类
class Employee{
    public:
        Employee(string name, float salary){
            this->m_name = name;
            this->m_salary = salary;
        }
    public:
        string getName()const{return m_name;}
        float getSalary()const{return m_salary;}
    private:
        string m_name;
        float m_salary;
};

// 打印分割线
void printLine(){
    cout << "-------------------------------------------------------------------" << endl;
}

// 打印员工信息
void printE(const vector<Employee>& v){
    for(vector<Employee>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名： " << it->getName() << "\t 薪资： " << it->getSalary() << endl;
    }
}
// 打印部门中的员工信息
void printDE(const multimap<int, Employee>& m){
    for(multimap<int, Employee>::const_iterator it = m.begin(); it != m.end(); it++){
        cout << "部门编号： " << it->first
             << "\t 姓名： " << it->second.getName()
             << "\t 薪资： " << it->second.getSalary()
             << endl; 
    }
}

// 1.创建员工
void creatEmployee(vector<Employee>& v){
    srand((unsigned int)time(NULL));
    // srandom((unsigned int)time(NULL));
    string seed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++){
        string name = "员工";
        float salary = 0;
        name += seed.at(i);
        salary += rand()%10000 + 10000;
        v.push_back(Employee(name,salary));
    }
}

// 2.设置分组
void setGroup(const vector<Employee>& v, multimap<int, Employee>& m){
    srand((unsigned int)time(NULL));
    for(vector<Employee>::const_iterator it = v.begin(); it != v.end(); it++){
        // 产生一个随机的部门编号
        int deptID = rand()%3 + 1;
        // 将员工插入到multimap分组中
        m.insert(make_pair(deptID, *it));
        
    }

}

// 按部门显示员工信息
void showEmployeeByGroup(const multimap<int, Employee>& m, int deptID){
    multimap<int, Employee>::const_iterator pos;
    int num;
    int index;
    switch(deptID){
        case 1:
            cout << "策划部门的人员信息：" << endl;
            pos = m.find(CHEHUA);
            num = m.count(CHEHUA);
            index = 0;
            for(; pos != m.end() && index < num; pos++, index++){
                cout << "姓名： " << pos->second.getName() << "\t 薪资： " << pos->second.getSalary() << endl;
            }
            break;
        case 2:
            cout << "美术部门的人员信息：" << endl;
            pos = m.find(MEISHU);
            num = m.count(MEISHU);
            index = 0;
            for(; pos != m.end() && index < num; pos++, index++){
                cout << "姓名： " << pos->second.getName() << "\t 薪资： " << pos->second.getSalary() << endl;
            }
            break;
        case 3:
            cout << "研发部门的人员信息：" << endl;
            pos = m.find(YANFA);
            num = m.count(YANFA);
            index = 0;
            for(; pos != m.end() && index < num; pos++, index++){
                cout << "姓名： " << pos->second.getName() << "\t 薪资： " << pos->second.getSalary() << endl;
            }
            break;
    }
}

void test01(){
    // 1.创建员工
    vector<Employee> v;
    creatEmployee(v);
    printE(v);

    printLine();

    // 2.设置分组
    multimap<int, Employee> employeeMap;
    setGroup(v, employeeMap);
    printDE(employeeMap);

    // 3.按部门显示员工信息
    int deptID;
    while(1){
        cout << "请输入部门编号（ 1-策划 2-美术 3-研发 ）输入0退出：";
        cin >> deptID;
        if(deptID == 0) break;
        system("clear");
        showEmployeeByGroup(employeeMap, deptID);
        
    }
}

int main(){
    test01();
    return 0;
}
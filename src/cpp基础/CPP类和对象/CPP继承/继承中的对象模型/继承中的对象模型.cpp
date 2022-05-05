#include <iostream>
using namespace std;

// 继承中的对象模型
// 在visual studio中利用开发人员命令提示工具可以查看对象模型
// 在windows电脑下步骤：
    // 1.跳转盘符到文件路径所在盘符
    // 2.跳转到文件路径
    // 3.查看命令： cl /d1 reportSingleClassLayout<类名> <文件名>
class Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;    // 子类继承的时候被编译器给隐藏了访问不到，但是还是继承下去了。
};

class Sub:public Base{
public:
    int m_D;
};

void test01(){
    Base base;
    Sub sub;
    // 父类中所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性，是被编译器给隐藏了，因此是访问不到的，但是确实是继承下去了。
    cout << "基类对象的大小： " << sizeof(base) << endl;    // 基类对象的大小： 12
    cout << "子类对象的大小： " << sizeof(sub) << endl;     // 子类对象的大小： 16
}

int main(){
    test01();
    return 0;
}
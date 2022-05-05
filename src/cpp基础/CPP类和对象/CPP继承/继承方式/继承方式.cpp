#include <iostream>
using namespace std;
// 基类
class Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

// 公共继承
class Sub01:public Base{
public:
    void func(){
        m_A = 10;   // 父类中的公共权限成员，到子类中依然是公共权限
        m_B = 10;   // 父类中的保护权限成员，到子类中依然是保护权限
        // m_C = 10;   // 父类中私有权限成员，子类访问不到
    }
};
void test01(){
    Sub01 sub01;
    sub01.m_A = 100;
    // sub01.m_B = 100;  // 公共继承的方式，父类的保护权限，在子类中也是保护权限，类外访问不到
}

// 保护继承
class Sub02:protected Base{
    void func(){
        m_A = 10;   // 父类中的公共权限成员，到子类中变成保护权限
        m_B = 10;   // 父类中的保护权限成员，到子类中依然是保护权限
        // m_C = 10;   // 父类中私有权限成员，子类访问不到
    }
};
void test02(){
    Sub02 sub02;
    // sub02.m_A = 100;    // 保护继承的方式，父类的公共权限和保护权限成员，在子类中都是保护权限成员，类外访问不到
    // sub02.m_B = 100;
    // sub02.m_C = 100;
}

// 私有继承
class Sub03:private Base{
    void func(){
        m_A = 10;      // 父类中的公共权限成员，到子类中变成私有权限
        m_B = 10;      // 父类中的保护权限成员，到子类中变成私有权限
        // m_C = 100;   // 父类中私有权限成员，子类访问不到
    }
};
void test03(){
    Sub03 sub03;
    // sub03.m_A = 100;    // 私有继承的方式，父类的公共权限和保护权限成员，在子类中都是私有权限成员，类外访问不到
    // sub03.m_B = 100;
    // sub03.m_C = 100;
}

// ------------------------------------------------------------------------

// 新建类继承上面的子类，验证保护继承和私有继承的区别
class SSub02:public Sub02{
    void func(){
        // 因为Sub02是保护权限，所以Sub02中的保护成员可以被SSub02继承为保护成员而被访问到
        m_A = 20;
        m_B = 20;
    }
};
void test002(){
    SSub02 ssub02;
    // ssub02.m_A = 200;
    // ssub02.m_B = 200;
}

class SSub03:public Sub03{
    void func(){
        // 因为Sub03是私有权限，所以Sub03中的私有成员不可以被SSub03继承并访问到
        // m_A = 20;
        // m_B = 20;
    }
};

int main(){
    return 0;
}
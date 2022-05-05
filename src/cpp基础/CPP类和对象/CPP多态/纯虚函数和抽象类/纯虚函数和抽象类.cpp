#include <iostream>
using namespace std;

// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 纯虚函数的语法：virtual 返回值类型 函数名 (参数列表) = 0;
// 当类中有了纯虚函数，这个类也称为抽象类

// 抽象类的特点：
    // 无法实例化对象
    // 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

class Animal{
public:
    // 纯虚函数
    virtual void spark() = 0;
};

class Cat:public Animal{
public:
    void spark(){
        cout << "小猫在叫叫！" << endl;
    }
};
class AiXi:public Cat{
public:
    void spark(){
        cout << "爱喜在叫！" << endl;
    }
};

void doSpark(Animal & animal){
    animal.spark();
}
// void doSpark(Cat & cat){
//     cat.spark();
// }
int main(){
    // Animal animal;  // 抽象类不可以实例化对象
    Cat * cat = new Cat;
    doSpark(*cat);
    delete cat;
    cat = NULL;
    cout << "这段代码执行了！" << endl;

    AiXi aixi;
    doSpark(aixi);
    return 0;
}
#include <iostream>
using namespace std;

class AbstractDrink{
public:
    virtual void boil() = 0;
    virtual void brew() = 0;
    virtual void pourInCup() = 0;
    virtual void putSomething() = 0;
    void makeDrink(){
        boil();
        brew();
        pourInCup();
        putSomething();
    }
public:
    virtual ~AbstractDrink(){}
};

// 咖啡类
class Coffee: public AbstractDrink{
public:
    void boil(){
        cout << "煮矿泉水" << endl;
    }
    void brew(){
        cout << "冲泡咖啡" << endl;
    }
    void pourInCup(){
        cout << "将咖啡倒入杯子中" << endl;
    }
    void putSomething(){
        cout << "向咖啡中加入牛奶伴侣" << endl;
    }
    virtual ~Coffee(){}
};

// 茶类
class Tea: public AbstractDrink{
public:
    void boil(){
        cout << "煮矿泉水" << endl;
    }
    void brew(){
        cout << "冲泡茶叶" << endl;
    }
    void pourInCup(){
        cout << "将茶水倒入杯子中" << endl;
    }
    void putSomething(){
        cout << "向茶水中加入枸杞" << endl;
    }
    virtual ~Tea(){}
};

class DrinkStore{
public:
    static void makeDrink(AbstractDrink * drink){
        drink->makeDrink();
        delete drink;
        drink = NULL;
    }
};

void doDrink(AbstractDrink * drink){
    drink->makeDrink();
    delete drink;
    drink = NULL;
}

void test01(){
    Coffee * coffee = new Coffee;
    Tea * tea = new Tea;

    // 制作咖啡
    DrinkStore::makeDrink(coffee);
    cout << "----------------------------------------------" << endl;
    // 制作茶水
    DrinkStore::makeDrink(tea);
}
int main(){
    test01();
    return 0;
}
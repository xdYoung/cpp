#include <iostream>
using namespace std;

// 利用多态实现一个计算器类
// 创建一个计算器的抽象类
class AbstractCalculator{
public:
    virtual float getResult(){
        return 0;
    }
public:
    float m_num_a;
    float m_num_b;
};
// 加法计算器类
class AddCalculator:public AbstractCalculator{
public:
    AddCalculator(float a=0, float b=0){
        m_num_a = a;
        m_num_b = b;
    }
public:
    float getResult(){
        return m_num_a + m_num_b;
    }
};
// 减法计算器类
class JanCalculator:public AbstractCalculator{
public:
    JanCalculator(float a=0, float b=0){
        m_num_a = a;
        m_num_b = b;
    }
public:
    float getResult(){
        return m_num_a - m_num_b;
    }
};
// 乘法计算器类
class PlusCalculator:public AbstractCalculator{
public:
    PlusCalculator(float a=0, float b=0){
        m_num_a = a;
        m_num_b = b;
    }
public:
    float getResult(){
        return m_num_a * m_num_b;
    }
};
// 减法计算器类
class ChuCalculator:public AbstractCalculator{
public:
    ChuCalculator(float a=0, float b=0){
        m_num_a = a;
        m_num_b = b;
    }
public:
    float getResult(){
        return m_num_a / m_num_b;
    }
};

class Calculator{
public:
    static float jisuan(AbstractCalculator & calculator){
        return calculator.getResult();
    }
};
float calculator(AbstractCalculator & calculator){
    return calculator.getResult();
}

void test01(){
    float num_a, num_b; int no;
    AddCalculator add;
    JanCalculator jan;
    PlusCalculator plus;
    ChuCalculator chu;
    while(true){
        printf("退出计算器请输入0： ");
        cin >> no;
        if(no == 0) {
            break;
        }
        else
        {
            printf("请输入数字a： ");
            cin >> num_a;
            printf("请输入数字b： ");
            cin >> num_b;
            printf("( 1 + )\t( 2 - )\t( 3 * )\t( 4 / )\n请输入运算符编号: ");
            cin >> no;
            system("clear");
            switch (no){
                case 1:
                    add.m_num_a = num_a;
                    add.m_num_b = num_b;
                    cout << num_a << " + " << num_b << " = " << Calculator::jisuan(add) << endl;
                    break;
                case 2:
                    jan.m_num_a = num_a;
                    jan.m_num_b = num_b;
                    cout << num_a << " - " << num_b << " = " << calculator(jan) << endl;
                    break;
                case 3:
                    plus.m_num_a = num_a;
                    plus.m_num_b = num_b;
                    cout << num_a << " * " << num_b << " = " << calculator(plus) << endl;
                    break;
                case 4:
                    chu.m_num_a = num_a;
                    chu.m_num_b = num_b;
                    cout << num_a << " / " << num_b << " = " << calculator(chu) << endl;
                    break;
                default:
                    break;
            }
        }
    }
}

int main(){
    test01();
    return 0;
}
#include <iostream>
using namespace std;

// 函数模版作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表
// 模版即是泛型编程的思想，将数据类型参数化了。

// 函数模版的语法：
    // template<typename T>  // 注：typename也可以用class来代替
    // 函数声明或者定义
// 语法解释：
    // template - 声明创建模版
    // typename - 表明其后面的符号是一种数据类型，可以用class代替
    // T - 通用的数据类型，名称可以替换，通常为大写字母

// 函数模版注意事项
    // 自动类型推导，必须推导出一致的数据类型T，才可以使用
    // 模版必须要确定出T的数据类型，才可以使用


// 模版的声明，定义可以写在后面。或者直接声明的时候定义也行。
template<typename T>
void swapTemplate(T &a, T &b);

int main(){
    int a = 10;
    int b = 20;
    cout << "交换前：" << "a = " << a << ", b = " << b << endl;
    // 自动类型推到
    swapTemplate(a, b);
    cout << "自动类型推到 - 交换后：" << "a = " << a << ", b = " << b << endl;
    // 显式类型指定
    swapTemplate<int>(a, b);
    cout << "显式类型指定 - 交换后：" << "a = " << a << ", b = " << b << endl;

    return 0;
}

template<typename T>
void swapTemplate(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
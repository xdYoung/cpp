#include <iostream>
using namespace std;
// c++的命名空间是划分作用域用的，使用不同的命名空间以防止同名变量，函数或者类冲突
namespace yang{
    #include "实现一个通用数组类.hpp"
}
using namespace yang;

void printLine(){
    cout << "-----------------------------------------" << endl;
}
void test01(){
    yang::ArrayExercise<int> arr(5);
    std::cout << arr.capacity() << std::endl;
    std::cout << arr.size() << std::endl;
    arr.push_back(10);
    std::cout << arr[0] << std::endl;
    std::cout << arr.capacity() << std::endl;
    std::cout << arr.size() << std::endl;
}

void test02(){
    ArrayExercise<string> s_arr(10);
    cout << s_arr.capacity() << endl;
    cout << s_arr.size() << endl;
    s_arr.push_back("young");
    cout << s_arr[0] << endl;
    cout << s_arr.capacity() << endl;
    cout << s_arr.size() << endl;

}

int main(){
    test01();
    printLine();
    test02();
    return 0;
}
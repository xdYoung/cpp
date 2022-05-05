#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// 读文件与写文件步骤类似，但是读取方式相对比较多
// 读文件步骤如下：
// 1.包含头文件: #include <fstream>
// 2.创建流对象: ifstream ifs;
// 3.打开文件并判断文件是否打开成功: ifs.open("文件路径", 打开方式);
// 4.读数据: 四种方式读取
// 5.关闭文件: ifs.close();

void test01(){
    // 1.包含头文件

    // 2.创建流对象
    ifstream ifs;

    // 3.打开文件并判断文件是否打开成功
    ifs.open("../files/test.txt", ios::in);
    if(!ifs.is_open()){
        cout << "文件打开失败了！" << endl;
        return;
    }
    // 4.读数据
    // 4.1 第一种读取方式
    // char buffer[1024] = {0};
    // while(ifs >> buffer){
    //     cout << buffer << endl;
    // }
    // 4.2 第二种读取方式
    // char buffer[1024] = {0};
    // while(ifs.getline(buffer, sizeof(buffer))){
    //     cout << buffer << endl;
    // }
    // 4.3 第三种读取方式
    // string buffer;
    // while(getline(ifs, buffer)){
    //     cout << buffer << endl;
    // }
    // 4.4 第四种读取方式(不建议这种一个一个字符的方式读取，效率慢)
    char c;
    while((c = ifs.get()) != EOF){
        cout << c;
    }

    // 5.关闭文件
    ifs.close();

}

int main(){
    test01();
    return 0;
}
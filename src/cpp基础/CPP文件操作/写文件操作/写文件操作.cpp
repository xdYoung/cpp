#include <_stdio.h>
#include <ios>
#include <iostream>
#include <fstream>
using namespace std;

// 程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
// 通过文件可以将数据持久化
// C++对文件操作需要包含头文件 <fstream>

// 文件类型分为两种：
    // 1.文本文件：文件以文本的ASCII码形式存储在计算机中
    // 2.二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

// 操作文件的三大类：
    // 1.ofstream：写操作
    // 2.ifstream：读操作
    // 3.fstream：读写操作

// 打开文件的方式：
    // ios::in - 为读文件而打开文件
    // ios::out - 为写文件而打开文件
    // ios::ate - 初始位置，文件尾部
    // ios::app - 以追加方式写入文件
    // ios::trunc - 如果文件存在先删除，再创建
    // ios::binary - 以二进制方式操作文件
// 注意：文件打开方式可以配合使用，利用 ｜ 操作符配合使用。
// 例如：用二进制方式写文件： ios::binary | ios::out

// 写文件操作
    // 写文件步骤如下：
    // 1.包含头文件
        // #include <fstream>
    // 2.创建流对象
        // ofstream ofs;
    // 3.打开文件
        // ofs.open("文件路径", 打开方式)
    // 4.写数据
        // ofs << "写入的数据"
    // 5.关闭文件
        // ofs.close()

void test01(){
    string text;
    // 判断文件夹是否存在，不存在则创建文件夹
    // 1.包含头文件 <fstream>
    // 2.创建流对象
    ofstream ofs;
    // 3.打开文件
    ofs.open("../files/test.txt", ios_base::out | ios_base::app);

    // 4.写入数据
    while(true){
        cout << "请输入要写入文件的数据：" << endl;
        cin >> text;
        if(text == "end") break;
        ofs << text << "\n";
        system("clear");
        // ofs << "name: " << "young\t" << "age: " << 32 << "\n";
    }

    // 5.关闭文件
    ofs.close();
}

int main(){
    test01();
    return 0;
}
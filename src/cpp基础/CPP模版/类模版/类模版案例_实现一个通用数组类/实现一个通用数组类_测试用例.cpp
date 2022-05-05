#include "实现一个通用数组类.hpp"

// 测试数组是否创建成功
void test01(){
    ArrayExercise<int> arr01(10);
    ArrayExercise<int> arr02(arr01);
    ArrayExercise<int> arr03(100);
    arr03 = arr01;
}

// 测试数组的插入删除访问等
void test02(){
    ArrayExercise<int> arr01(1);
    cout << "初始化数组前的容量和大小：" << endl;
    cout << "arr01.capacity() = " << arr01.capacity() << endl;
    cout << "arr01.size() = " << arr01.size() << endl;
    arr01.push_back(10);
    arr01.push_back(20);
    arr01.push_back(30);
    arr01.push_back(30);
    arr01.push_back(30);
    arr01.push_back(30);
    arr01.push_back(30);
    cout << "超过数组容量后数组的容量和大小：" << endl;
    cout << "arr01.capacity() = " << arr01.capacity() << endl;
    cout << "arr01.size() = " << arr01.size() << endl;
    cout << "尾删法删除数组中的元素：" << endl;
    cout << "删除的数组元素为：" << arr01.pop_back() << endl;
    cout << "删除的数组元素为：" << arr01.pop_back() << endl;
    cout << "删除的数组元素为：" << arr01.pop_back() << endl;
    cout << "删除的数组元素为：" << arr01.pop_back() << endl;
    cout << "删除的数组元素为：" << arr01.pop_back() << endl;
    // cout << "删除的数组元素为：" << arr01.pop_back() << endl;
    cout << "超过数组容量后数组的容量和大小：" << endl;
    cout << "arr01.capacity() = " << arr01.capacity() << endl;
    cout << "arr01.size() = " << arr01.size() << endl;
    // cout << arr01[-1] << endl;
    // cout << arr01[2] << endl;
    cout << arr01[1] << endl;

}

int main(){
    // test01();
    cout << "------------------------------------------------" << endl;
    test02();
    // test03();
    return 0;
}
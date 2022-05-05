#include <iostream>
#include <map>
using namespace std;

// map容器的基本概念
    // map 中所有元素都是 pair
    // pair 中第一个元素为 key（键），起到索引作用，第二个元素为 value（值）
    // 所有元素都会根据元素的键的值自动排序
// 本质：map/multimap 属于关联式容器，底层结构是用二叉树实现的。
// 优点：可以根据 key 值快速查找到 value 值

// map 和 multimap 的区别：
    // map 不允许容器中有重复 key 值元素
    // multimap 允许容器中有重复 key 值元素
// map 构造和赋值：对 map 容器进行构造和赋值操作
// 函数原型：
// 构造
    // map<T1, T2> mp;                          // map的默认构造函数
    // map<T1, T2> mp(const map& mp);           // map的拷贝构造函数
// 赋值：
    // map& operator=(const map& mp);           // 重载等号=操作赋，将mp中的数据拷贝到本身

void printLine(){
    cout << "----------------------------------------------" << endl;
}

void printMap(const map<string, int>& mp){
    for(map<string, int>::const_iterator it = mp.begin(); it != mp.end(); it++){
        cout << "key: " << it->first << "   value: " << it->second << " | ";
    }
    cout << endl;
}

void test01(){
    // map<class Key, class Tp, class Compare = less<Key>, class Allocator = allocator<pair<const<Key>, Tp>>>;
    // 默认构造函数
    map<string, int> mp;
    // map容器在插入的时候会自动排序，默认是从小到大排序
    // map容器在插入的时候需要使用对组的形式插入
    // map容器不允许插入重复的数值
    mp.insert(pair<string,int>("young", 32));
    mp.insert(make_pair("young", 32));
    mp.insert(make_pair("ting", 28));
    mp.insert(make_pair("shohn", 30));
    mp.insert(pair<string,int>("peng", 29));
    mp.insert(pair<string,int>("chuan", 29));
    mp.insert(pair<string,int>("young", 18));
    printMap(mp);
    printLine();
    // 拷贝构造函数
    map<string, int> mp1(mp);
    printMap(mp1);
    printLine();

    // map& operator=(const map& mp);
    map<string, int> mp2;
    mp2 = mp;
    printMap(mp2);
    printLine();
    
}

int main(){
    test01();
    return 0;
}
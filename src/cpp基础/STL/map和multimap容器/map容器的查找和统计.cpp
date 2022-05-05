#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

// map容器的查找和统计：对map容器进行查找数据以及统计数据
// 函数原型：
    // find(key);                   // 查找 key 是否存在。若存在，返回该键的元素的迭代器；若不存在，返回mp.end()；
    // count(key);                  // 统计 key 的元素个数
    
// 成员函数count在map容器中，要么为0，要么为1。因为map容器不允许有重复的key值
// 成员函数count在multimap容器中，可以查找的key值的个数。因为multimap可以允许有重复的key值

void printLine(){
    cout << "----------------------------------------------" << endl;
}

void printMap(const map<int, string>& mp){
    for(map<int, string>::const_iterator it = mp.begin(); it != mp.end(); it++){
        cout << "key: " << it->first << "   value: " << it->second << " | ";
    }
    cout << endl;
}

void test01(){
    map<int, string> mp;
    mp.insert(pair<int, string>(1, "a"));
    mp.insert(make_pair(6, "b"));
    mp.insert(map<int, string>::value_type(3, "c"));
    cout << "mp: ";
    printMap(mp);
    printLine();

    // find(key)返回的是查找的key键元素的迭代器
    map<int, string>::iterator pos = mp.find(6);
    cout << (pos != mp.end() ? "mp中查找到了 key = " + to_string((*pos).first) + " 键的元素: value = " + (*pos).second : "未查找到key=6键的元素: ") << endl;
    // if(pos != mp.end()) cout << "key: " << (*pos).first << " value: " << (*pos).second << endl;
    cout << (mp.find(10) != mp.end() ? "mp中查找到了key=10键的元素: " : "未查找到key=10键的元素") << endl;
    printLine();

    // count(key)
    int num = mp.count(1);
    cout << "mp中键为1的元素的数量为： " << num << endl;
    printLine();

}

int main(){
    test01();
    return 0;
}
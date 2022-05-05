#include <iostream>
#include <map>
#include <utility>
using namespace std;

// map容器的插入和删除：map容器进行插入数据和删除数据
// 函数原型
    // insert(element);                 // 在容器中插入元素，元素是一个pair对组
    // clear();                         // 清除所有元素
    // erase(pos);                      // 删除pos迭代器所指的元素，返回下一个元素的迭代器
    // erase(begin, end);               // 删除[begin, end)区间中的元素，返回下一个元素的迭代器
    // erase(key);                      // 删除容器中键为key的元素

void printLine(){
    cout << "----------------------------------------------" << endl;
}

void printMap(const map<int, string>& mp){
    for(map<int, string>::const_iterator it = mp.begin(); it != mp.end(); it++){
        cout << "key: " << it->first << " value: " << it->second << " | ";
    }
    cout << endl;
}

void test01(){
    map<int, string> mp;
    // insert(element)
    // 插入对组的时候有几种方式
    cout << "insert: ";
    mp.insert(pair<int, string>(1, "a"));                   // 匿名的pair对组插入
    mp.insert(make_pair(3, "b"));                           // make_pair方式插入
    mp.insert(map<int, string>::value_type(5, "c"));        // map作用域下的值类型
    // 利用重载的[]插入，但是不建议用[]来做插入操作，因为若key值不存在，则会创建一个key值的对组，并赋予初始值
    // []一般用来访问key值的数据用
    mp[9] = "h";
    mp[10]; // 如果不赋初始值，则默认创建一个key为10的的pair对组。不建议这样使用。
    mp.insert(pair<int, string>(2, "d"));
    mp.insert(pair<int, string>(6, "e"));
    mp.insert(pair<int, string>(8, "f"));
    mp.insert(pair<int, string>(7, "g"));
    printMap(mp);
    printLine();

    // erase(pos)
    cout << "erase(pos): ";
    mp.erase(++mp.begin());
    printMap(mp);
    printLine();

    // erase(begin, end)
    cout << "erase(begin, end): ";
    mp.erase(mp.begin(), ++mp.begin());
    printMap(mp);
    printLine();

    // erase(key)
    cout << "erase(key): ";
    mp.erase(7);
    printMap(mp);
    printLine();

    // clear()
    cout << "clear(): ";
    mp.clear();
    printMap(mp);
    printLine();
}

int main(){
    test01();
    return 0;
}
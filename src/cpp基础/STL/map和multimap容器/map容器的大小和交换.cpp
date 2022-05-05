#include <iostream>
#include <map>
using namespace std;

// map容器的大小和交换：统计map容器的大小以及交换map容器
// 函数原型
    // size();                  // 返回map容器中元素的数目
    // empty();                 // 判断map容器是否为空
    // swap(mp);                // 交换两个map容器

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
    map<string, int> mp;
    cout << "初始化时map容器的大小为： " << mp.size() << endl;
    cout << "判断初始化时map容器是否为空： " << (mp.empty() ? "map容器为空" : "map容器不为空") << endl;
    printLine();
    mp.insert(pair<string,int>("young", 32));
    mp.insert(pair<string,int>("young", 32));
    mp.insert(pair<string,int>("ting", 28));
    mp.insert(pair<string,int>("shohn", 30));
    mp.insert(pair<string,int>("peng", 29));
    mp.insert(pair<string,int>("chuan", 29));
    mp.insert(pair<string,int>("young", 18));
    cout << "初始化后map容器的大小为： " << mp.size() << endl;
    cout << "判断初始化后map容器是否为空： " << (mp.empty() ? "map容器为空" : "map容器不为空") << endl;
    printLine();
    
    map<string, int> mp1;
    mp1.insert(pair<string, int>("hello", 1));
    mp1.insert(pair<string, int>("world", 2));

    cout << "交换前： " << endl;
    cout << "mp: ";
    printMap(mp);
    cout << "mp1: ";
    printMap(mp1);
    cout << "交换后： " << endl;
    mp1.swap(mp);
    cout << "mp: ";
    printMap(mp);
    cout << "mp1: ";
    printMap(mp1);


}

int main(){
    test01();
   return 0; 
}
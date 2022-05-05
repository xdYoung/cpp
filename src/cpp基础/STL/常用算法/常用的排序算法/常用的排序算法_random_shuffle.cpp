#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

// 常用的排序算法 random_shuffle：指定范围内的元素随机调整次序
// 函数原型：
    // random_shuffle(InputIterator begin, InputIterator end);
    // 这个方法已经deprecated废弃
    // 指定范围内的元素随机调整次序
    // begin：起始迭代器
    // end：结束迭代器

    // shuffle(RandomAccessIterator first, RandomAccessIterator last, UniformRandomNumberGenerator &&g)
    // 指定范围内的元素按照随机数生成器的规则打乱顺序
    // begin：起始迭代器
    // end：结束迭代器

void printLine(){
        cout << "-----------------------------------------" << endl;
}

void printV(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printV(const vector<string>& v){
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printV(const vector<char>& v){
    for(vector<char>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    // srand((unsigned int)time(NULL));
    
    vector<int> v;
    for(int i = 0; i < 20; i++){
        v.push_back(i);
    }
    printV(v);
    printLine();

    // random_shuffle(InputIterator begin, InputIterator end)
    // 利用洗牌算法，打乱顺序
    // random_shuffle(v.begin(), v.end());
    // printV(v);
    // printLine();

    // 利用shuffle算法随机打乱顺序
    random_device rd;
    mt19937 g(rd());    // 随机数引擎：基于梅森缠绕器算法的随机数生成器
    shuffle(v.begin(), v.end(), g);
    printV(v);
}

void test02(){
    // srand((unsigned int)time(NULL));
    
    vector<char> v;
    for(int i = 65; i < 91; i++){
        v.push_back(char(i));
    }
    printV(v);
    printLine();

    // random_shuffle(InputIterator begin, InputIterator end)
    // 利用洗牌算法，打乱顺序
    // random_shuffle(v.begin(), v.end());
    // printV(v);
    // printLine();

    // 利用shuffle算法随机打乱顺序
    random_device rd;
    mt19937 g(rd());    // 随机数引擎：基于梅森缠绕器算法的随机数生成器
    shuffle(v.begin(), v.end(), g);
    printV(v);
}

void test03(){
    // srand((unsigned int)time(NULL));
    // srandom((unsigned int)time(NULL));
    
    vector<string> v;
    v.push_back("young");
    v.push_back("ting");
    v.push_back("shohn");
    v.push_back("peng");
    v.push_back("chuan");
    v.push_back("zhou");
    v.push_back("zhang");
    v.push_back("nana");
    v.push_back("jindou");
    v.push_back("hello");
    printV(v);
    printLine();

    // random_shuffle(InputIterator begin, InputIterator end)
    // 利用洗牌算法，打乱顺序
    // random_shuffle(v.begin(), v.end());
    // printV(v);
    // printLine();

    // 利用shuffle算法随机打乱顺序
    random_device rd;
    mt19937 g(rd());    // 随机数引擎：基于梅森缠绕器算法的随机数生成器
    shuffle(v.begin(), v.end(), g);
    printV(v);
}

int main(){
    test01();
    printLine();
    test02();
    printLine();
    test03();
    return 0;
}
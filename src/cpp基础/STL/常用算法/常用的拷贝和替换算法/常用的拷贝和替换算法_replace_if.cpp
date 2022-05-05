#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 常用的拷贝和替换算法 replace_if：将区间内满足条件的元素，替换成指定元素
// 函数原型：
    // replace_if(InputIterator begin, InputIterator end, Predicate pred, newValue);
    // 按条件（普通函数或者谓词）替换元素，满足条件的替换成指定元素
    // begin：起始迭代器
    // end：结束迭代器
    // pred：普通元素或者谓词（bool仿函数）
    // newValue：替换的新元素
// 总结：replace_if会将区间内满足条件的元素全部替换为新的元素

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

// replace_if 按条件替换区间内的元素，普通函数作为参数传入
bool great5(const int& val){
    return val > 5 && val < 8;
}

// replace_if 按条件替换区间内的元素，谓词（仿函数）作为参数传入
// 仿函数可以在内部维护一些状态
class GreatNum{
    public:
        GreatNum(int n):m_num(n){}
    public:
        bool operator()(const int& val){
            return val == m_num;
        }
    private:
        int m_num;
};

void test01(){
    vector<int> v;
    for(int i = 0; i < 20; i++){
        v.push_back(i);
    }
    cout << "替换前： " << endl;
    printV(v);
    printLine();

    // replace_if(InputIterator begin, InputIterator end, Predicate pred, newValue)
    // replace_if 按条件替换区间内的元素，普通函数作为参数传入
    replace_if(v.begin(),v.end(), great5, 66);
    cout << "替换后： " << endl;
    printV(v);
    printLine();

    // replace_if 按条件替换区间内的元素，谓词（仿函数）作为参数传入
    cout << "请输入要替换的值： ";
    int n;
    cin >> n;
    replace_if(v.begin(), v.end(), GreatNum(n), 168);
    printV(v);
    printLine();
}

int main(){
    test01();
    return 0;
}
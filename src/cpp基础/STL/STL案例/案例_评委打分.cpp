#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

// 案例描述：
// 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除最低分，取平均分。

// 实现步骤：
    // 1.创建5名选手，放到vector容器中
    // 2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评委打分存到deque容器中
    // 3.sort算法对deque容器中分数排序，去除最高和最低分
    // 4.deque容器遍历一遍，累加总分
    // 5.获取平均分

class Player{
public:
    Player(string name, int score):m_Name(name),m_score(score){}
public:
    string getName(){return m_Name;}
    int getScore(){return m_score;}
    void setScore(int score){m_score = score;}
private:
    string m_Name;
    int m_score;
};

void printLine(){
    cout << "-------------------------------------" << endl;
}

// 打印选手的信息
void printPlayerV(vector<Player> &v){
    for(vector<Player>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it).getName() << ": 平均分: " << (*it).getScore() << endl;
    }
}

void creatPlayer(vector<Player> &v){
    string nameSeed = "ABCDE";
    for(int i = 0; i < 5; i++){
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        // 将创建的对象放入容器中
        Player p(name, score);
        v.push_back(p);
    }
}

// 打分
void setScore(vector<Player>& v){
    srand((unsigned int)time(NULL));
    for(vector<Player>::iterator it = v.begin(); it != v.end(); it++){
        // 将评委的分数，放入到deque容器中
        deque<int> d;
        for(int i = 0; i < 10; i++){
            int score = rand()%41 + 60;
            d.push_back(score);
        }
        // 排序
        sort(d.begin(), d.end());
        // 选手打分情况
        cout << it->getName() << ": 打分情况： " << endl;
        for(deque<int>::iterator it = d.begin(); it != d.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        printLine();
        // 去除最高分
        d.pop_back();
        // 去除最低分
        d.pop_front();
        // 累计总分
        int sum = 0;
        // 获取平均分
        for(deque<int>::iterator it = d.begin(); it != d.end(); it++){
            sum += (*it);
        }
        int avg = sum / d.size();
        // 将平均分赋值到选手上
        (*it).setScore(avg);
    }
}


void test01(){
    // 1.创建5名选手
    vector<Player> v;
    creatPlayer(v);
    printPlayerV(v);
    printLine();

    // 2.给5名选手打分
    setScore(v);
    printPlayerV(v);
}

int main(){
    test01();
    return 0;
}
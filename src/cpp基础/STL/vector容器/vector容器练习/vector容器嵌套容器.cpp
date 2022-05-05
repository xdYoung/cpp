#include <iostream>
#include <vector>
using namespace std;

void printLint(){
    cout << "------------------------------" << endl;
}

void test01(){
    vector< vector<int> > v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    v1.push_back(110);
    v1.push_back(120);
    v1.push_back(130);

    v2.push_back(210);
    v2.push_back(220);
    v2.push_back(230);

    v3.push_back(310);
    v3.push_back(320);
    v3.push_back(330);

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    // while循环
    cout << "while循环遍历：" << endl;
    vector< vector<int> >::iterator vit_begin = v.begin();
    vector< vector<int> >::iterator vit_end = v.end();
    while(vit_begin != vit_end){
        vector<int>::iterator vvit_begin = vit_begin->begin();
        vector<int>::iterator vvit_end = vit_begin->end();
        while(vvit_begin != vvit_end){
            cout << *vvit_begin << " ";
            vvit_begin++;
        }
        cout << endl;
        vit_begin++;
    }
    printLint();
    // for循环
    cout << "for循环遍历：" << endl;
    for(vector<vector<int> >::iterator it = v.begin(); it != v.end(); it++){
        for(vector<int>::iterator vit = it->begin(); vit != it->end(); vit++){
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main(){
    test01();
    return 0;
}
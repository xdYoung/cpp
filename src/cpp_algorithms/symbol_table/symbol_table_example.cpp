#include <string>
#include <iostream>
using namespace std;

template<class Key, class Value>
class SequentialSearchSTExercise{
public:
    SequentialSearchSTExercise():first(NULL),m_size(0){}
public:
    Value get(Key key){
        for(Node * x = first; x != NULL; x = x->next){
            if(x->key == key) return x->val;
        }
        return -1;
    }
    void put(Key key, Value val){
        for(Node * x = first; x != NULL; x = x->next){
            if(x->key == key) {x->val = val;return;}
        }
        first = new Node(key, val, first);
        m_size++;
        cout << "插入成功" << endl;
    }
    int size(){
        return m_size;
    }
    bool isEmpty(){
        return m_size == 0;
    }
    // Key deleteKey(Key key){
    //     for(Node * x = first; x != NULL; x = x->next){
    //         if(x->key == key){
                
    //         }
    //     }
    // }

public:
    ~SequentialSearchSTExercise<Key, Value>(){
        for(Node * x = first; x != NULL; x = x->next){
            cout << "析构函数调用，即将释放内存： " << (long int)x << endl;
            if(x != NULL){
                delete x;
                // x = NULL;
                cout << "析构函数调用，释放了：" << (long int)x << endl;
                // cout << "析构函数调用，释放了：" << (long int)x << endl;
            }
        }
        
    }

private:
    class Node{
        // friend SequentialSearchSTExercise;
    public:
        Key key;
        Value val;
        Node * next;
    public:
        Node(Key key, Value val, Node * next){
            this->key = key;
            this->val = val;
            this->next = next;
        }
        // Node(const Node &node){}
    // public:
    //     bool operator!=(Node &next){
    //         next = NULL;
    //         return this != next;
    //     }
    };
    Node * first;
    int m_size;
};

int main(){
    // SequentialSearchSTExercise<string, int> * ssST = new SequentialSearchSTExercise<string, int>;
    SequentialSearchSTExercise<string, int> ssST;
    // ssST->put("young", 1);
    // ssST->put("ting", 2);
    // ssST->put("shohn", 3);
    ssST.put("young", 1);
    ssST.put("ting", 2);
    ssST.put("shohn", 3);

    // int i = ssST->get("young");
    int i = ssST.get("young");
    cout << i << endl;
    i = ssST.get("peng");
    cout << i << endl;
    i = ssST.get("ting");
    cout << i << endl;
    i = ssST.get("shohn");
    cout << i << endl;

    cout << "符号表的大小为： " << ssST.size() << endl;
    cout << ssST.isEmpty() << endl;
    cout << false << endl;

    return 0;
}
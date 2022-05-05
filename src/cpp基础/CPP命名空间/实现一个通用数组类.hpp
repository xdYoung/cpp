#pragma once
#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

//案例描述：实现一个通用数组类，要求如下：
    // 可以对内置数据类型以及自定义数据类型的数据进行存储
    // 将数组中的数据存储到堆区
    // 构造函数中可以传入数组的容量
    // 提供对应的拷贝构造函数以及operator=防止浅拷贝的问题
    // 提供尾插法和尾删法对数组中的数据进行增加和删除
    // 可以通过下标的方式访问数组中的元素
    // 可以获取数组中当前元素个数和数组的容量

template<class T>
class ArrayExercise{
public:
    ArrayExercise(int capacity){
        cout << "调用了有参构造函数" << endl;
        m_capacity = capacity;
        m_size = 0;
        p = new T[m_capacity];
    }
private:
    void resizeArray(int max){
        T * temp = new T[max];
        if(this->p != NULL){
            for(int i = 0; i < m_size; i++){
            temp[i] = p[i];
            }
            delete [] this->p;
            this->p = NULL;
            this->m_capacity = max;
            this->p = temp;
        }
        this->p = temp;  
    }
public:
    // 返回数组的容量
    int capacity(){ return m_capacity; }
    // 返回数组的大小
    int size(){ return m_size; }
    // 尾插法
    void push_back(const T &val){
        if(m_capacity == m_size){
            int max = m_size*2;
            resizeArray(max);
        }
        this->p[this->m_size] = val;    // 在数组的末尾插入数据
        this->m_size++; // 更新数组的大小
    }
    // 尾删法
    T pop_back(){
        T item;
        // 让用户访问不到最后一个元素，即逻辑上的删除
        if(this->m_size == 0){
            // cout << "数组为空，无法删除元素！" << endl;
            // return item;
            throw exception();
        }
        item = p[--this->m_size];
        cout << "item" << item << endl;
        // p[this->m_size] = NULL;
        if(this->m_size>0 && this->m_size <= this->m_capacity/4) resizeArray(this->m_capacity/2);
        return item;
    }
    // 通过下标的方式访问数组中的元素
    T& operator[](int index){   // 如果让返回值作为左值，则需要返回引用，即数据本身。例如：arr[0] = 100;
        if(index < 0 || index >= this->m_size){
            // cout << "错误！超过数组的边界了！" << endl;
            // return this->p[index];
            // throw "错误！超过数组的边界了！";
            throw exception();
        }
        return this->p[index];
    }
public:
    // 重写拷贝构造函数，因为在堆区创建了数据，防止默认拷贝造成的浅拷贝问题
    ArrayExercise(const ArrayExercise &arr){
        cout << "调用了拷贝构造函数" << endl;
        m_capacity = arr.m_capacity;
        m_size = arr.m_size;
        // 编译器默认提供的拷贝是简单的赋值操作，会造成浅拷贝的问题
        // p = arr.p;
        // 深拷贝
        p = new T[arr.m_capacity];
    }
    // 重写等号赋值运算符，因为编译器也是提供的简单的赋值操作，会造成浅拷贝问题
    // 返回值需要是返回的引用，因为 a = b = c 的情况会出现
    ArrayExercise& operator=(const ArrayExercise &arr){
        cout << "调用了 = 赋值运算符重载" << endl;
        // 需要先判断原本的数组在堆区是否有数据，如果有数据先要释放
        if(this->p != NULL){
            delete [] this->p;
            this->p = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p = new T[arr.m_capacity];
        for(int i = 0; i < this->m_size; i++){
            this->p[i] = arr.p[i];
        }
        return *this;
    }
public:
    ~ArrayExercise(){
        cout << "调用了析构函数" << endl;
        if(p != NULL){
            delete [] p;
            p = NULL;
        }
    }
private:
    T * p;
    int m_capacity;
    int m_size;
};
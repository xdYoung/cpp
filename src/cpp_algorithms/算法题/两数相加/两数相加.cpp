#include <algorithm>
#include <iostream>
// #include "../../../../include/BinarySearch.h"
using namespace std;

// 二分查找算法
int binarySearch(int key, int arr[], int len){
    int lo = 0;
    int hi =  len - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(key < arr[mid]) hi = mid - 1;
        else if(key > arr[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

// 计算和为0的整数对的数目
int countTwoNumSum(int a[], int len){
    int cnt = 0;
    for (int i = 0; i < len; i++){
        if(binarySearch(-a[i], a, len) > i) cnt++;
    }
    return cnt;
}

void printArr(int a[], int len){
    cout << "数组的长度为：" << len << endl;
    for(int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){

    int a[] = {1,3,-7,8,-10,-5,6,-1,1,12,-3,-8,15,17,18,20,-15};
    int len = sizeof(a)/sizeof(int), key;
    cout << "请输入要查找的元素key：";
    cin >> key;
    printArr(a, len);
    sort(a, a+len);
    printArr(a, len);
    if(binarySearch(key, a, len) != -1){
        cout << "在数组中查找元素key的索引为： " << binarySearch(key, a, len) << endl;
    }else{ cout << "数组中没有找到 " << key << " 的元素！" << endl; }
    
    cout << "数组中有 " << countTwoNumSum(a, len) << " 对两个数相加为0的元素！" << endl;

    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;

// 辅助函数打印数组
void print_arr(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int partition(int arr[], int lo, int hi){
    int i = lo, j = hi + 1, temp;
    int v = arr[lo];
    while(true){
        while(arr[++i] < v){
            if(i == hi) break;
        } 
        while(arr[--j] > v){
            if(j == lo) break;
        }
        if(i>=j) break;
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    temp = arr[j];
    arr[j] = arr[lo];
    arr[lo] = temp;
    return j;
}

void sort(int arr[], int lo, int hi){
    if(lo >= hi) return;
    int j = partition(arr, lo, hi);
    sort(arr, lo, j-1);
    sort(arr, j+1, hi);
}

// 快速排序
void quick_sort(int arr[], int n){
    // print_arr(arr, n);
    sort(arr, 0, n - 1);
}

int main(){
    int arr[] = {15, 5,2,7,12,6,1,4,3,9,8,10};
    // printf("%lu", sizeof(arr)/sizeof(int));
    print_arr(arr, sizeof(arr)/sizeof(int));

    quick_sort(arr, sizeof(arr)/sizeof(int));

    print_arr(arr, sizeof(arr)/sizeof(int));
    return 0;
}
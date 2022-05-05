#include <cstdio>
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

// 希尔排序
void shell_sort(int arr[], int n){
    int i,j,inc,key,count=1;
    // 初始增量：n/2，每一趟之后除以2。
    for(inc = n/2; inc > 0; inc /= 2){
        printf("第%d趟排序: ", count);
        // 每一趟采用插入排序
        for(i = inc; i < n; i++){
            key = arr[i];
            for(j = i; j >= inc && key < arr[j-inc]; j-=inc){
                arr[j] = arr[j-inc];
            }
            arr[j] = key;
        }
        count++;
        print_arr(arr, n);
    }
}

int main(){
    int arr[] = {15, 5,2,7,12,6,1,4,3,9,8,10};
    // printf("%lu", sizeof(arr)/sizeof(int));
    print_arr(arr, sizeof(arr)/sizeof(int));

    shell_sort(arr, sizeof(arr)/sizeof(int));

    print_arr(arr, sizeof(arr)/sizeof(int));
    return 0;
}
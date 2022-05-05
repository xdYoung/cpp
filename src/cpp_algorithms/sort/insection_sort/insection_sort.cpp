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

void insection_sort(int arr[], int n){
    int key;
    for (int i = 1; i < n; i++) {
            // 将a[i]插入到a[i-1],a[i-2],a[i-3]...之中。
            for(int j=i; j>0 && arr[j] < arr[j-1]; j--){
                key = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = key;
            }
        }
}

int main(){
    int arr[] = {15, 5,2,7,12,6,1,4,3,9,8,10};
    print_arr(arr, sizeof(arr)/sizeof(int));

    insection_sort(arr, sizeof(arr)/sizeof(int));

    print_arr(arr, sizeof(arr)/sizeof(int));
    return 0;
}
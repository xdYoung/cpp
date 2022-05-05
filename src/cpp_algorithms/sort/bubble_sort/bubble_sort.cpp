#include <iostream>

// 辅助函数打印数组
void print_arr(int arr[], int n);
void bubble_sort(int arr[], int n);

int main(){
    int arr[] = {15, 5,2,7,12,6,1,4,3,9,8,10};
    // printf("%lu", sizeof(arr)/sizeof(int));
    print_arr(arr, sizeof(arr)/sizeof(int));

    bubble_sort(arr, sizeof(arr)/sizeof(int));

    print_arr(arr, sizeof(arr)/sizeof(int));
    return 0;
}

void print_arr(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void bubble_sort(int arr[], int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1] < arr[j]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
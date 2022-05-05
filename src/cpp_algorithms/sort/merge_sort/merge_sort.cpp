#include <iostream>
#include <malloc/_malloc.h>
using namespace std;

// 辅助函数打印数组
void print_arr(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void merge(int arr[], int tempArr[], int left, int mid, int right){
    // 标记左半区第一个未排序的元素
    int l_pos = left;
    // 标记有半区第一个未排序的元素
    int r_pos = mid + 1;
    // 临时数组元素的下标
    int pos = left;

    // 合并
    while(l_pos <= mid && r_pos <= right){
        if(arr[l_pos] < arr[r_pos]){    // 左半区第一额剩余元素更小
            tempArr[pos++] = arr[l_pos++];
        }else{  // 右半区第一个剩余元素更小
            tempArr[pos++] = arr[r_pos++];
        }
    }
    // 合并左半区剩余的元素
    while(l_pos <= mid){
        tempArr[pos++] = arr[l_pos++];
    }
    // 合并右半区剩余的元素
    while(r_pos <= right){
        tempArr[pos++] = arr[r_pos++];
    }
    // 把临时数组中合并后的元素复制回原来的数组中
    while(left <= right){
        arr[left] = tempArr[left];
        left++;
    }
}

void msort(int arr[], int tempArr[], int left, int right){
    // 如果只有一个元素，那么就不需要再划分
    // 只有一个元素，本身就是有序的，只需要被归并即可
    if(left < right){
        // 找中间点
        int mid = (left + right) / 2;
        // 递归划分左半区
        msort(arr, tempArr, left, mid);
        // 递归划分右半区
        msort(arr, tempArr,mid+1, right);
        merge(arr,tempArr, left, mid, right);
    }
}

// 归并排序入口
void merge_sort(int arr[], int n){
    // 分配一个辅助数组
    int * tempArr = (int *)malloc(n*sizeof(int));
    if(tempArr){    // 辅助数组分配成功
        msort(arr, tempArr, 0, n-1);
        free(tempArr);
    }else{
        printf("error: failed to allocate memory!");
    }
}

int main(){
    int arr[] = {9,5,2,7,12,4,3,1,11};

    print_arr(arr, sizeof(arr)/sizeof(int));

    merge_sort(arr, sizeof(arr)/sizeof(int));

    print_arr(arr, sizeof(arr)/sizeof(int));

    return 0;
}
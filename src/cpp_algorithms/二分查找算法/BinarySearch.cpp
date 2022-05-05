// #include "../../../include/BinarySearch.h"

int binarySearch(int key, int arr[], int len){
    int lo = 0;
    int hi =  len - 1;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(key < arr[mid]) hi = mid - 1;
        else if(key > arr[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

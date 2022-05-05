#include <iostream>
using namespace std;

// 案例描述：
    // 利用函数模版封装一个排序的函数，可以对不同数据类型的数组进行排序
    // 排序规则从大到小，排序算法为选择排序
    // 分别利用char数组和int数据进行测试

// 交换的函数模版
template<typename T>
void swap_template(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
bool compare(T &a, T &b){
    return a < b;
}

template<typename T>
void sort_template(T arr[], int len){
    // for(int i = 0; i < len; i++){
    //     for(int j = i+1; j < len; j++){
    //         if(compare<T>(arr[i], arr[j])){
    //             swap_template<T>(arr[i], arr[j]);
    //         }
    //     }
    // }
    for(int i = 0; i < len; i++){
        int max = i;
        for(int j = i+1; j < len; j++){
            if(arr[max] < arr[j]){
                max = j;
            }
        }
        if(max != i){
            swap_template(arr[i], arr[max]);
        }
    }
}

template<typename T>
void printArr(T arr[], int len){
    for(int i=0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01(){
    // 测试char数组
    char charArr[] = "hgksjfslh";
    int len = strlen(charArr);
    sort_template(charArr, len);
    printArr(charArr, len);

    // 测试整形数组
    int intArr[] = {2,4,5,6,7,8,8,8,9,6,5,4,3,68,46,341};
    len = sizeof(intArr)/sizeof(intArr[0]);
    sort_template(intArr, len);
    printArr(intArr, len);

}

int main(){
    test01();
    return 0;
}
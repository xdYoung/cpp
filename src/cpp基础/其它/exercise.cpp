#include <iostream>
using namespace std;

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8};
    char buffer[10] = {'c', 'd', 'e'};
    cout << arr << endl;
    while(cin >> buffer){
        cout << buffer << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int size;
    cin >> size;
    int* arr;
    arr = new int [size];
    
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int temp;
    for (int i = 1;i < size;i++) {
        temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp ) {
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

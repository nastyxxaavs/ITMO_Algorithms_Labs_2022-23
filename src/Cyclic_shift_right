#include <iostream>
using namespace std;
int main(){
    int size;
    cin >> size;
    int* arr;
    arr = new int [size];
    for (int i=0; i < size; i++){
        cin >> arr[i];
    }
    
    int currNum = arr[0];
    arr[0] = arr[size-1];
    int nextNum;
    for (int i=1; i < size; i++){
        nextNum = arr[i];
        arr[i] = currNum;
        currNum = nextNum;
    }

    for (int i=0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

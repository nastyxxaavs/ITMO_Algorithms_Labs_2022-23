#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 100000;

void Input(int *a, int size) {
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }
}

int Binary_Search_first(int *tempArray, int size, int x){
    int l = -1;
    int r = size;
    int mid;
    bool per = false;//она станет тру, когда элемент будет в массиве(искомый эл-т существует)
    while (l < r - 1) {
        mid = (l + r)/2;
        if (tempArray[mid] >= x){
            r = mid;
        }
        else if (tempArray[mid] < x){
            l = mid;
        }
        if (tempArray[mid] == x){
            per = true;
        }
    }
    if (per == true){
        return r+1;//
    }
    return -1;
}

int Binary_Search_last(int *temparr, int size, int target){
    int l = -1;
    int r = size;
    bool per = false;
    while (l < r - 1){
        int mid = (l + r)/2;
        if (temparr[mid] > target){
            r = mid;
        }
        else if (temparr[mid] <= target){
            l = mid;
        }
        if (temparr[mid] == target){
            per = true;
        }
    }
    if (per == true){
        return r;//просто берем след эл-т
    }
    return -1;
}

int main(){
    int size, x, mainArray[SIZE], not_mainArray[SIZE];
    cin >> size;
    Input(mainArray, size);
    cin >> x;
    Input(not_mainArray, x);
    for (int i=0; i<x;i++){
        int index = Binary_Search_first(mainArray,size,not_mainArray[i]);
        int ind = Binary_Search_last(mainArray, size, not_mainArray[i]);
        cout << index  << " " << ind << "\n";
    }
    return 0;

}

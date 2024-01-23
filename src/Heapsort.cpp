#include <iostream> //Пирамидальная сортировка
#include <algorithm>
using namespace std;
const int SIZE = 100000;

void input(int *a, int size) {
    for(int i = 0; i < size; ++i) {
        cin >> a[i];
    }
}

void output(int *a, int size) {
    for(int i = 0; i < size; ++i){
        cout << a[i] << " ";
    }
}

void sift_down(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i){
        swap(arr[i], arr[largest]);
        sift_down(arr, n, largest);
    }
}

void build_sort(int arr[] , int n){
    int size = n;
    int i = size/2;
    while(i >= 0){
        sift_down(arr, n, i);
        i--;
    }
}

void heapSort(int arr[], int n){
    build_sort(arr,n);
    int size = n;
    for (int i = 0; i < n - 1; i++){
        swap(arr[0], arr[n-1-i]);
        size--;
        sift_down(arr, size, 0);
    }
}

int main(){
    int size, mainArray[SIZE];
    cin >> size;
    input(mainArray, size);
    heapSort(mainArray, size);
    output(mainArray, size);
    return 0;
}

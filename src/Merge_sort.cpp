#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 100000;

void input(int *a, int size) {
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }
}

void output(int *a, int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

void merge(int *mas, int left, int mid, int right){
    int it1, it2, n, i;
    it1 = 0;
    it2 = 0;
    n = right - left;
    int *result = new int[n];
    while ( (left + it1 < mid) && (mid+ it2 < right))
    {
        if (mas[left+it1] < mas[mid+it2]){
            result[it1+it2] = mas[left+it1];
            it1 ++;
        }
        else {
            result[it1+it2] = mas[mid+it2];
            it2 ++;
        }
    }
    while (left + it1 < mid) {
        result[it1+it2] = mas[left+it1];
        it1 ++;
    }
    while (mid + it2 < right)
    {
        result[it1 + it2] = mas[mid + it2];
        it2 ++;
    }
    for (i = 0; i < (it1 + it2); i++) {
        mas[left+i] = result[i];
    }
}

void mergesort(int *mas, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid;
    mid = (left + right) / 2;
    mergesort(mas, left, mid);
    mergesort(mas, mid, right);
    merge(mas, left, mid, right);
}

int main(){
    int size, mainArray[SIZE];
    cin >> size;
    input(mainArray, size);
    mergesort(mainArray, 0, size);
    output(mainArray, size);
    return 0;
}

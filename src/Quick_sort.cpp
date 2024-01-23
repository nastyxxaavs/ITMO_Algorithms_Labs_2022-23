#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 100000;

void input(int *a, int size) { 
    for(int i = 0; i < size; ++i) {
        cin >> a[i];
    }
}

void output(int *a, int size) { 
    for(int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
}

void quickSort(int *tempArray, int start, int end) { 
    int divider;
    divider = tempArray[(start+end)/2];
    int low= start;
    int hi=end;
    while (low < hi) {
        while (tempArray[low] < divider) low++;
        while (tempArray[hi] > divider) hi--;
          if (low <= hi) {
            swap(tempArray[low], tempArray[hi]);
            low++;
            hi--;
          }
    }
    
if (start<hi)quickSort(tempArray, start, hi);
if (low<end)quickSort(tempArray, low, end);
}


int main(){
    int size, mainArray[SIZE];
    cin >> size;
    input(mainArray, size);
    quickSort(mainArray, 0, size - 1);
    output(mainArray, size);
    return 0;
}

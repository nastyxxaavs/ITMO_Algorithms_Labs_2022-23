#include <iostream>
using namespace std;

void CountingSort(string A[], int size, int x, string B[]){

    char max = 'a', min = 'z';
    for (int i = 0; i < size; i++){
        if (A[i][x] > max){
            max = A[i][x];
        }
        if (A[i][x] < min){
            min = A[i][x];
        }
    }

    int n1 = max - min + 1;
    int C[n1];

    for (int i = 0; i < n1; i++){
        C[i] = 0;
    }

    for (int i = 0; i < size; i++){
        C[A[i][x] - min]++;
    }

    for (int i = 1; i < n1; i++){
        C[i] += C[i-1];
    }

    for (int i = size - 1; i >= 0; i--){
        B[C[A[i][x] - min] - 1] = A[i];
        C[A[i][x] - min]--;
    }

    for (int i = 0 ; i < size; i++){
        A[i] = B[i];
    }

}

void RadixSort(string A[], int size, int k, int m, string B[]){

    for (int i = m-1; i >= m-k; i--) {
        CountingSort(A, size, i, B);
    }
}

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    string A[n];
    string B[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    RadixSort(A, n, k, m, B);

    for (int i = 0; i < n; i++){
        cout << B[i] << '\n';
    }

    return 0;
}

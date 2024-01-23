#include <iostream>
using namespace std;

int Max(int a, int b){
    return (a > b) ? a : b;
}

int KnapSack(int W, int wt[], int n){
    int ** array = (int**) malloc (sizeof (int*) *n+1);
    for (int i = 0; i < n+1; i++) {
        array[i] = (int*) malloc (sizeof (int)*W+1);
    }
    int i, w;
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                array[i][w] = 0;
            else if (wt[i - 1] <= w)
                array[i][w] = Max(array[i - 1][w - wt[i - 1]] + wt[i-1],array[i - 1][w]);
            else
                array[i][w] = array[i - 1][w];
        }
    }
    return array[n][W];
}


int main(){
    int W, N, *wt;
    cin >> W >> N;
    wt = new int [N];
    for (int i = 0; i < N; i++){
        cin >> wt[i];
    }
    int result = KnapSack(W,wt,N);
    cout << result;
    return 0;
}


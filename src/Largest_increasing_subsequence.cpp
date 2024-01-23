#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, pos, length, b;
    cin >> N;
    int mass[N];
    for (int i = 0; i < N; i++){
       cin >> mass[i];
    }
    int d[N];
    int prev[N];
    for (int i = 0; i < N; i++){
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++){
            if (mass[j] < mass[i] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }
    pos = 0;
    length = d[0];
    for (int i = 0; i < N; i++){
        if (d[i] > length){
            pos= i;
            length = d[i];
        }
    }
    cout << length << "\n";
    vector <int> answer;
    int k = 0;
    while (pos != -1){
        answer.push_back(mass[pos]);
        pos = prev[pos];
    }
    reverse(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i ++){
        cout << answer[i] << " ";
    }
     return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void Generate_Gray_Code_For_arr(int n){
    if ((n > 0) and (n != 0)) {
        vector <string> arr;
        int i,j;
        arr.push_back("0");
        arr.push_back("1");

        for (i = 2; i < pow(2,n); i = i << 1) {
            for (j = i - 1; j >= 0; j--) {
            arr.push_back(arr[j]);
            }
           
            for (j = 0; j < i; j++) {
                arr[j] = "0" + arr[j];
            }
            
            for (j = i; j < 2 * i; j++) {
                arr[j] = "1" + arr[j];
            }
        }

        for (i = 0; i < arr.size(); i++)
            cout << arr[i] << "\n";
    }
}

int main(){
    int n;
    cin >> n;
    Generate_Gray_Code_For_arr(n);
    return 0;
}

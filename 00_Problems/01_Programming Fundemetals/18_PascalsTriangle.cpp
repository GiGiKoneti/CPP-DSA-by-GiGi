// Print Pascal's triangle up to N rows.

#include <iostream>
using namespace std;

int nCr(int n,int r){
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int main() {
    int n = 5;

    for(int i = 0; i < n; i++) {

        // Print spaces
        for(int s = 0; s < n - i - 1; s++) {
            cout << " ";
        }

        // Print values
        for(int j = 0; j <= i; j++) {
            cout << nCr(i, j) << " ";
        }

        cout << endl;
    }

    return 0;
}
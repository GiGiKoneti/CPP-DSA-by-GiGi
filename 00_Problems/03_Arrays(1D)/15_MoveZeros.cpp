// Remove all zeros to the end.

#include <iostream>
using namespace std;

int main() {
    int arr[5]={0,2,3,0,5};
    int m = 0, n = 0;

    for (int idx = 0; idx < 5; idx++) {
        if (arr[idx] != 0) {
            swap(arr[m], arr[idx]); 
            m++;
        }
    }

    for (int x : arr) cout << x << " ";
    cout << endl;
}
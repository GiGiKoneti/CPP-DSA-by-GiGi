// Input and print a 2D Matrix.
#include <iostream>
using namespace std;

int main() {
    int arr[3][3];
    cout << "Enter the elements for a 3x3 matrix (9 elements):";

    int *p = &arr[0][0];

    for(int i = 0; i < 9; i++) {
        cin >> p[i];
    }

    
    for(int i = 0; i < 9; i++) {
        cout << p[i] << " ";
        if(i % 3 == 2)
            cout << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows (m) : ";
    cin >> m;
    cout << "Enter columns (n) : ";
    cin >> n;

    // ✅ STEP 1: Allocate memory for 'm' rows (array of int pointers)
    int** matrix = new int*[m];

    // ✅ STEP 2: Allocate memory for 'n' columns in each row
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n]; // Each row is a 1D dynamic array
    }

    // ✅ STEP 3: Fill the matrix with incrementing values and print
    int x = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    
    cout << matrix[2][2] << endl;
    cout << *(*(matrix + 2) + 2) << endl;

    // ✅ STEP 4: Deallocate memory to avoid memory leaks
    for (int i = 0; i < m; i++) {
        delete[] matrix[i]; // Deleting each row
    }

    delete[] matrix; // Deleting the array of row pointers

    return 0;
}
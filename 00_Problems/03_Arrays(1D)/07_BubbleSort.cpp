// Sort an array in ascending order using bubble sort.
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {5, 1, 4, 2, 8, 10, 3, 7, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {              // Number of passes
        for (int j = 0; j < n - i - 1; j++) {      // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {             // If out of order, swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Array after Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
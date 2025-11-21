// Find maximum and minimum elements in an array.

#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    int min = arr[0];
    int max = arr[0];

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    cout << "Maximum : " << max << endl;
    cout << "Minimum : " << min << endl;

    return 0;
}
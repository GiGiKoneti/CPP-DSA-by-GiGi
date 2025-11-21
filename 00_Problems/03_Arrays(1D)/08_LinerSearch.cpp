// Search for an element using linear search.

#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element found at index: " << i << endl;
            found = true;
            break;     
        }
    }

    if (!found) {
        cout << "Element not found in array." << endl;
    }

    return 0;
}
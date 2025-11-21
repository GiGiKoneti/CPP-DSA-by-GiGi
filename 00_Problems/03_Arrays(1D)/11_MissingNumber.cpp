// Find the missing number in 1 to N sequence.
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        int diff = arr[i+1] - arr[i];

        if (diff > 1) {  // gap detected
            for (int missing = arr[i] + 1; missing < arr[i+1]; missing++) {
                cout << missing << " is missing." << endl;
            }
        }
    }

    return 0;
}
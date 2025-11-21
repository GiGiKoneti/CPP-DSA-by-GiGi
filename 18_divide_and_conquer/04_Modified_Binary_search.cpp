#include <iostream>
using namespace std;

/*
Modified Binary Search in Rotated Sorted Array
----------------------------------------------
Problem:
- Array = {4, 5, 6, 7, 0, 1, 2}
- This is a sorted array rotated at some pivot (7 → 0).
- Task: Find index of target element (e.g., target = 0).

Approach:
1. Use binary search (O(log n)) with modifications.
2. At each step, check which half is sorted (left or right).
3. Decide whether target lies in sorted half or unsorted half.
4. Narrow down search accordingly.
*/

// Function to search target in rotated sorted array
int searchRotated(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // found target
        }

        // Check if left half [low..mid] is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1; // Target lies in left half
            } else {
                low = mid + 1;  // Target lies in right half
            }
        }
        // Otherwise, right half [mid..high] is sorted
        else {
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;  // Target lies in right half
            } else {
                high = mid - 1; // Target lies in left half
            }
        }
    }

    return -1; // not found
}

// Driver code
int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int index = searchRotated(arr, n, target);

    if (index != -1)
        cout << "Target " << target << " found at index: " << index << endl;
    else
        cout << "Target " << target << " not found in array." << endl;

    return 0;
}

/*
Dry Run:
---------
Array = {4, 5, 6, 7, 0, 1, 2}, target = 0
low=0, high=6
mid=3 → arr[mid]=7

Left half [4,5,6,7] is sorted, but 0 not in it → search right half.

low=4, high=6
mid=5 → arr[mid]=1

Right half [1,2] is sorted, but 0 not in it → search left half.

low=4, high=4
mid=4 → arr[mid]=0 → found at index 4.

Output:
Target 0 found at index: 4
*/
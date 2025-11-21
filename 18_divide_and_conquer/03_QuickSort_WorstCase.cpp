#include <iostream>
using namespace std;

/*
QuickSort Worst Case Explanation:
---------------------------------
- If we always pick the last element as pivot, and the array is already sorted,
  then each partition call only reduces the size of the array by 1.
- This leads to n + (n-1) + (n-2) + ... + 1 = O(n^2) comparisons/swaps.
- Example: Array = {1, 2, 3, 4, 5, 6}
    Pivot chosen = last element (6, then 5, then 4, etc.)
    → Unbalanced partitions (n-1 elements on one side, 0 on the other).
*/

// Partition function (last element as pivot)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot is always last element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {  // All elements will be smaller (array is sorted)
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Worst case: pivot divides array into (n-1) and (0)
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Already sorted array (worst-case for last element pivot)
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Sorted Array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Array After QuickSort (Worst Case): ";
    printArray(arr, n);

    return 0;
}

/*
Output:
Original Sorted Array: 1 2 3 4 5 6
Array After QuickSort (Worst Case): 1 2 3 4 5 6

Explanation:
- Each time, pivot is the last element (largest in sorted array).
- Subproblem sizes: n-1, n-2, ..., 1
- Time Complexity = O(n^2)
*/
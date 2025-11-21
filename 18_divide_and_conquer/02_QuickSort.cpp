#include <iostream>
using namespace std;

/*
QuickSort Algorithm Explanation:
--------------------------------
- QuickSort is a divide-and-conquer algorithm.
- We pick a pivot element (here we choose the last element).
- Partition function rearranges the array:
    - Elements <= pivot move to the left.
    - Elements > pivot move to the right.
- Then we recursively apply QuickSort to the left and right subarrays.

Time Complexity:
    - Average Case: O(n log n)
    - Worst Case: O(n^2) (when array is already sorted and pivot chosen poorly)
    - Best Case: O(n log n)
Space Complexity:
    - O(log n) (due to recursive stack)
*/

// Partition function: places pivot in its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Index for smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // If element smaller than pivot
            i++;
            swap(arr[i], arr[j]); // Place it in correct position
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1; // Return pivot index
}

// QuickSort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
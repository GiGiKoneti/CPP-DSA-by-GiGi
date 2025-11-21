#include <iostream>
#include <vector>
using namespace std;

/* =====================================================
   MERGE FUNCTION
   Purpose:
   - Merge two sorted subarrays into one sorted array.
   Subarrays:
   - Left half  -> arr[si..mid]
   - Right half -> arr[mid+1..ei]

   Logic:
   1. Compare elements from both halves using 2 pointers.
   2. Pick the smaller element and push it into temp.
   3. Copy remaining elements if one half finishes early.
   4. Finally, copy everything back from temp[] to arr[].
===================================================== */
void merge(int arr[], int si, int mid, int ei) {
    vector<int> temp;  // temporary storage
    int i = si;        // pointer for left half
    int j = mid + 1;   // pointer for right half

    // Step 1: Compare and merge
    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);  // take from left half
        } else {
            temp.push_back(arr[j++]);  // take from right half
        }
    }

    // Step 2: Copy remaining elements (if any)
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= ei) {
        temp.push_back(arr[j++]);
    }

    // Step 3: Copy merged elements back to original array
    for (int idx = si, x = 0; idx <= ei; idx++, x++) {
        arr[idx] = temp[x];
    }
}

/* =====================================================
   MERGE SORT FUNCTION
   Purpose:
   - Recursively divide array into halves until one element remains.
   - Merge them back in sorted order using merge().

   Logic:
   - Base Case: If si >= ei, stop (array has 1 element).
   - Recursive Case:
     1. Find mid index.
     2. Recursively call mergeSort for left half.
     3. Recursively call mergeSort for right half.
     4. Merge both sorted halves.
===================================================== */
void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return; // Base case
    }

    int mid = si + (ei - si) / 2;

    // Recursive calls: divide into left & right halves
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    // Conquer step: merge the two sorted halves
    merge(arr, si, mid, ei);
}

/* =====================================================
   HELPER FUNCTION
   - Just prints the array elements.
===================================================== */
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* =====================================================
   MAIN FUNCTION
   Flow of execution:
   1. Create an unsorted array.
   2. Call mergeSort() on entire array.
   3. Print sorted array.

   Example:
   Original: 6 3 7 5 2 4
   Sorted:   2 3 4 5 6 7
===================================================== */
int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    cout << "Original Array: ";
    printArr(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array:   ";
    printArr(arr, n);

    return 0;
}

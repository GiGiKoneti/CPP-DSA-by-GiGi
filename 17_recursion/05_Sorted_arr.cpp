#include <iostream>
using namespace std;

/* ===========================================================
   RECURSION EXAMPLE: CHECK IF ARRAY IS SORTED
   -----------------------------------------------------------
   Problem:
   Check if a given array is sorted in ascending order 
   using recursion.

   Logic:
   - Base Case: If array has 0 or 1 element → sorted.
   - Recursive Case: Check first two elements, then recurse 
     for the rest of the array.
=========================================================== */

bool isSorted(int arr[], int n) {
    // Base Case
    if (n == 0 || n == 1) {
        return true; // 0 or 1 element is always sorted
    }

    // If first element is greater than second → not sorted
    if (arr[0] > arr[1]) {
        return false;
    }

    // Recursive call for rest of the array
    return isSorted(arr + 1, n - 1);
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 3, 2, 4, 5};

    cout << "Array 1 is sorted? " 
         << (isSorted(arr1, 5) ? "Yes" : "No") << endl;

    cout << "Array 2 is sorted? " 
         << (isSorted(arr2, 5) ? "Yes" : "No") << endl;

    return 0;
}

/* ===========================================================
   OUTPUT:
   Array 1 is sorted? Yes
   Array 2 is sorted? No

   CALL FLOW (for arr1 = {1,2,3}):
   isSorted({1,2,3}, 3)
   → check 1 <= 2 → true, call isSorted({2,3},2)
   → check 2 <= 3 → true, call isSorted({3},1)
   → Base case reached → true
=========================================================== */
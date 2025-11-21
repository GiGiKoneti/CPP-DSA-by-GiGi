#include <iostream>
#include <vector>
using namespace std;

/* ===========================================================
   RECURSION EXAMPLE: FIND FIRST OCCURRENCE
   -----------------------------------------------------------
   Problem:
   Find the index of the first occurrence of a target element
   in a vector using recursion.

   Logic:
   - Base Case 1: If vector is empty → return -1 (not found)
   - Base Case 2: If first element == target → return 0
   - Recursive Case: Search in the rest of the vector. If found, 
     adjust index by adding 1
=========================================================== */

int firstOccurrence(const vector<int>& v, int target, int index = 0) {
    // Base Case: End of vector
    if (index == v.size()) {
        return -1;  // target not found
    }

    // Base Case: Found target
    if (v[index] == target) {
        return index;
    }

    // Recursive Call: move to next element
    return firstOccurrence(v, target, index + 1);
}

int main() {
    vector<int> vec = {5, 3, 7, 3, 9};
    int target = 3;

    int idx = firstOccurrence(vec, target);

    if (idx != -1) {
        cout << "First occurrence of " << target << " is at index " << idx << endl;
    } else {
        cout << target << " not found in the vector." << endl;
    }

    return 0;
}

/* ===========================================================
   OUTPUT:
   First occurrence of 3 is at index 1

   CALL FLOW:
   firstOccurrence({5,3,7,3,9}, 3, 0) → 5 != 3 → call index 1
   firstOccurrence({5,3,7,3,9}, 3, 1) → 3 == 3 → return 1
=========================================================== */
#include <iostream>
#include <vector>
using namespace std;

/* ===========================================================
   RECURSION EXAMPLE: FIND LAST OCCURRENCE
   -----------------------------------------------------------
   Problem:
   Find the index of the last occurrence of a target element
   in a vector using recursion.

   Logic:
   - Base Case: If vector is empty (index == size) → return -1
   - Recursive Case: Check in the rest of the vector first,
     then compare current element
=========================================================== */

int lastOccurrence(const vector<int>& v, int target, int index = 0) {
    // Base Case: End of vector
    if (index == v.size()) {
        return -1; // not found
    }

    // Recursive Call: check rest of the vector
    int restIndex = lastOccurrence(v, target, index + 1);

    // If found in rest, return that index
    if (restIndex != -1) {
        return restIndex;
    }

    // Otherwise, check current element
    if (v[index] == target) {
        return index;
    }

    return -1; // not found anywhere
}

int main() {
    vector<int> vec = {5, 3, 7, 3, 9};
    int target = 3;

    int idx = lastOccurrence(vec, target);

    if (idx != -1) {
        cout << "Last occurrence of " << target << " is at index " << idx << endl;
    } else {
        cout << target << " not found in the vector." << endl;
    }

    return 0;
}

/* ===========================================================
   OUTPUT:
   Last occurrence of 3 is at index 3

   CALL FLOW:
   lastOccurrence({5,3,7,3,9}, 3, 0)
   → Recursive calls until end
   → index 4 (9 != 3) → returns -1
   → index 3 (3 == 3) → returns 3
=========================================================== */
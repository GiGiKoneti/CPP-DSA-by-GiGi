#include <iostream>
using namespace std;

/* ===========================================================
   RECURSION EXAMPLE: PRINT N TO 1
   -----------------------------------------------------------
   Problem:
   Print numbers from N down to 1 using recursion.

   Logic:
   - Base Case: When N == 0, stop recursion.
   - Recursive Case: Print N, then call function with (N-1).
=========================================================== */

void printDecreasing(int n) {
    // Base Case
    if (n == 0) {
        return; // stop recursion
    }

    // Work
    cout << n << " ";

    // Recursive Call
    printDecreasing(n - 1);
}

int main() {
    int n = 5;
    cout << "Printing numbers from " << n << " to 1: ";
    printDecreasing(n);
    cout << endl;
    return 0;
}

/* ===========================================================
   OUTPUT:
   Printing numbers from 5 to 1: 5 4 3 2 1

   CALL FLOW (when n = 5):
   printDecreasing(5) → prints 5
       → printDecreasing(4) → prints 4
           → printDecreasing(3) → prints 3
               → printDecreasing(2) → prints 2
                   → printDecreasing(1) → prints 1
                       → printDecreasing(0) → stops
=========================================================== */
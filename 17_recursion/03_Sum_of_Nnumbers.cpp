#include <iostream>
using namespace std;

/* ===========================================================
   RECURSION EXAMPLE: SUM OF NATURAL NUMBERS
   -----------------------------------------------------------
   Problem:
   Find the sum of first N natural numbers using recursion.

   Logic:
   - Base Case: If N == 1, sum is 1.
   - Recursive Case: sum(N) = N + sum(N-1)
=========================================================== */

int sumOfNaturalNumbers(int n) {
    // Base Case
    if (n == 1) {
        return 1;
    }

    // Recursive Case
    return n + sumOfNaturalNumbers(n - 1);
}

int main() {
    int n = 5;
    cout << "Sum of first " << n << " natural numbers: " 
         << sumOfNaturalNumbers(n) << endl;  // Expected: 15
    return 0;
}

/* ===========================================================
   OUTPUT:
   Sum of first 5 natural numbers: 15

   CALL FLOW:
   sumOfNaturalNumbers(5)
   = 5 + sumOfNaturalNumbers(4)
   = 5 + 4 + sumOfNaturalNumbers(3)
   = 5 + 4 + 3 + sumOfNaturalNumbers(2)
   = 5 + 4 + 3 + 2 + sumOfNaturalNumbers(1)
   = 5 + 4 + 3 + 2 + 1 
   = 15
=========================================================== */
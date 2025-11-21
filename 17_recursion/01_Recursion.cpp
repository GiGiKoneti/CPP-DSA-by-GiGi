#include <iostream>
using namespace std;

/* ===========================================================
   RECURSION EXAMPLE: FACTORIAL
   -----------------------------------------------------------
   Definition:
   Recursion is a process where a function calls itself until
   a base condition is met.

   Factorial Formula:
   n! = n * (n-1)!
   Base Case: 0! = 1 , 1! = 1
=========================================================== */

// Recursive function for factorial
int factorial(int n) {
    // Base Case
    if (n == 0 || n == 1) {
        return 1;  // stop recursion
    }

    // Recursive Case
    return n * factorial(n - 1);
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    return 0;
}

/* ===========================================================
   OUTPUT:
   Factorial of 5 is: 120

   CALL FLOW (when num = 5):
   factorial(5)
   = 5 * factorial(4)
   = 5 * 4 * factorial(3)
   = 5 * 4 * 3 * factorial(2)
   = 5 * 4 * 3 * 2 * factorial(1)
   = 5 * 4 * 3 * 2 * 1
   = 120
=========================================================== */


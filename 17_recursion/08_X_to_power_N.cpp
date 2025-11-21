#include <iostream>
using namespace std;

/* ===========================================================
   RECURSION EXAMPLE: FAST EXPONENTIATION
   -----------------------------------------------------------
   Problem:
   Compute x^n using recursion in O(log n) time.

   Logic:
   - Base Case: n == 0 → return 1
   - Recursive Case:
       If n is even: x^n = (x^(n/2))^2
       If n is odd : x^n = x * (x^(n/2))^2
=========================================================== */

long long fastPower(int x, int n) {
    // Base Case
    if (n == 0) return 1;

    // Recursive Case
    long long half = fastPower(x, n / 2);

    if (n % 2 == 0) {
        return half * half;           // n is even
    } else {
        return x * half * half;       // n is odd
    }
}

int main() {
    int x = 3, n = 5;
    cout << x << " raised to the power " << n << " is: " 
         << fastPower(x, n) << endl;  // Expected: 243
    return 0;
}

/* ===========================================================
   OUTPUT:
   3 raised to the power 5 is: 243

   CALL FLOW (fastPower(3,5)):
   fastPower(3,5)
   → half = fastPower(3,2)
       → half = fastPower(3,1)
           → half = fastPower(3,0) = 1
           → return 3*1*1 = 3
       → return 3*3 = 9
   → return 3*9*9 = 243
=========================================================== */
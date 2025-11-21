#include <iostream>
using namespace std;

/* ===========================================================
   RECURSION EXAMPLE: FIBONACCI SERIES
   -----------------------------------------------------------
   Problem:
   Print the first N Fibonacci numbers using recursion.

   Fibonacci Formula:
   F(0) = 0
   F(1) = 1
   F(n) = F(n-1) + F(n-2) for n >= 2
=========================================================== */

// Recursive function to find nth Fibonacci number
int fibonacci(int n) {
    // Base Cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive Case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Number of terms
    cout << "First " << n << " Fibonacci numbers: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}

/* ===========================================================
   OUTPUT:
   First 10 Fibonacci numbers: 0 1 1 2 3 5 8 13 21 34

   CALL FLOW (for fibonacci(5)):
   fibonacci(5)
   = fibonacci(4) + fibonacci(3)
   = (fibonacci(3) + fibonacci(2)) + (fibonacci(2) + fibonacci(1))
   = ((fibonacci(2)+fibonacci(1))+ (fibonacci(1)+fibonacci(0))) + ...
   ... continues recursively until base cases
=========================================================== */
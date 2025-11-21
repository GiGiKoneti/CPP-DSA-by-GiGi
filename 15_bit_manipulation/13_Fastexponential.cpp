#include <iostream>
using namespace std;

/*
    Function: fastExponential
    -------------------------
    Calculates x^n (x raised to the power n) using the 
    binary exponentiation method (also called fast exponentiation).
    This method reduces the time complexity from O(n) to O(log n).

    How it works:
    1. Binary representation of n determines which powers of x to multiply.
    2. For each bit of n (starting from LSB):
        - If the current bit is 1 → multiply 'ans' by the current 'x'.
        - Square 'x' in every step because each shift moves to the next power of 2.
        - Right shift n (n >> 1) to process the next bit.
    3. Continue until n becomes 0.

    Example:
        x = 3, n = 5 (binary: 101)
        Iteration 1: last bit = 1 → ans = 1*3 = 3, x = 9, n = 2
        Iteration 2: last bit = 0 → ans = 3,   x = 81, n = 1
        Iteration 3: last bit = 1 → ans = 3*81 = 243, n = 0
        Output: 243
*/
int fastExponential(int x, int n) {
    int ans = 1;
    while (n > 0) {
        int lastBit = n & 1;   // Check if the current bit is set
        if (lastBit) {
            ans *= x;          // Multiply by current x if bit is 1
        }
        x *= x;                // Square x for the next bit position
        n = n >> 1;            // Move to the next bit
    }
    cout << ans << endl;
    return ans;
}

int main() {
    fastExponential(3, 5); // Expected output: 243
    return 0;
}
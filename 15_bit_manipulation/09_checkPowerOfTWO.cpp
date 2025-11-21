#include <iostream>
using namespace std;

/*
    Function: PowerOfTwo
    --------------------
    Checks if a given number is a power of two using bit manipulation.

    Concept:
    --------
    - A number that is a power of two has only ONE bit set in its binary representation.
        Examples:
        1  -> 0001  (2^0)
        2  -> 0010  (2^1)
        4  -> 0100  (2^2)
        8  -> 1000  (2^3)

    - If 'n' is a power of two:
        n       = 1000  (binary for 8)
        n - 1   = 0111  (binary for 7)

        Performing 'n & (n - 1)':
        1000
      & 0111
      --------
        0000   -> Result is 0.

    - If 'n' is NOT a power of two:
        n       = 1010  (binary for 10)
        n - 1   = 1001  (binary for 9)

        1010
      & 1001
      --------
        1000   -> Result is NOT 0.

    - Special case:
        The number 0 is NOT a power of two, but 0 & (0 - 1) also gives 0.
        So we must ensure num > 0 before applying the check.

    Time Complexity: O(1) (Single bitwise operation)
    Space Complexity: O(1)
*/
bool PowerOfTwo(int num) {
    // First check if num is greater than 0 to avoid false positives for 0.
    if (num > 0 && !(num & (num - 1))) {
        return true; // num is a power of two
    }
    else {
        return false; // num is NOT a power of two
    }
}

int main() {
    int num = 8;

    if (PowerOfTwo(num)) {
        cout << "It's a power of TWO" << endl;
    }
    else {
        cout << "It's not a power of TWO" << endl;
    }

    return 0;
}
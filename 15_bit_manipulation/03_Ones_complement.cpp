#include <iostream>
using namespace std;

int main() {

    /*
    ==============================
    Bitwise NOT (~) in C++
    ==============================
    - The '~' operator flips every bit in the binary representation of a number.
    - It works on the "bit level" (0 becomes 1, and 1 becomes 0).

    ------------------------------------------
    SIGNED INTEGER REPRESENTATION IN C++:
    ------------------------------------------
    - C++ stores signed integers in **2's complement** form.
    - In 2's complement:
        - The Most Significant Bit (MSB) is the sign bit.
            - MSB = 0 → positive number
            - MSB = 1 → negative number
        - Negative numbers are stored in 2's complement form.

    ------------------------------------------
    HOW 2's COMPLEMENT WORKS:
    ------------------------------------------
    1. **Positive to Negative:**
        - Take the binary form of the positive number.
        - Invert all bits → this is the **1's complement**.
        - Add 1 to the result → this is the **2's complement** (final stored value).

    2. **Negative to Positive (decoding):**
        - Take the binary form of the negative number.
        - Invert all bits (1's complement).
        - Add 1 to get the magnitude, and keep the negative sign.

    ------------------------------------------
    EXAMPLE: Why ~6 = -7
    ------------------------------------------
    Step 1:  Represent +6 in binary (assuming 32-bit int):
             00000000 00000000 00000000 00000110

    Step 2:  Apply bitwise NOT (~):
             11111111 11111111 11111111 11111001  <-- 1's complement

    Step 3:  Interpret as signed integer:
             Since MSB = 1, it's a negative number.

    Step 4:  Convert to magnitude:
             Invert bits (1's complement): 00000000 00000000 00000000 00000110
             Add 1:                        00000000 00000000 00000000 00000111 → decimal 7

    Step 5:  Add negative sign:
             → -7

    ------------------------------------------
    Why ~0 = -1:
    ------------------------------------------
    Step 1:  0 in binary:
             00000000 00000000 00000000 00000000

    Step 2:  Apply ~:
             11111111 11111111 11111111 11111111

    Step 3:  MSB = 1 → negative number.
             Invert bits: 00000000 00000000 00000000 00000000
             Add 1:       00000000 00000000 00000000 00000001 → decimal 1
             Apply negative sign → -1
    */

    // Bitwise NOT examples
    cout << (~6) << endl; // Output: -7
    cout << (~0) << endl; // Output: -1

    return 0;
}
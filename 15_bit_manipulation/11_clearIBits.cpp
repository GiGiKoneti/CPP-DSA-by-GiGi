#include <iostream>
using namespace std;

/*
    Function: clearIBits
    --------------------
    Clears (sets to 0) all bits from the least significant bit (LSB) up to the (i-1)-th bit in the integer 'num'.
    Bits from position i and above remain unchanged.

    How it works:
    1. (~0)       → Bitwise NOT of 0 gives a value with all bits set to 1 (infinite 1s conceptually).
    2. (~0 << i)  → Left shift moves the block of 1s to the left by i positions, 
                    resulting in the last i bits becoming 0, and higher bits remaining 1.
                    Example (i = 2, 8-bit view): ~0 << 2 = 11111100
    3. num & mask → Performing AND with this mask keeps bits from position i upwards, 
                    and clears bits below i.

    Example:
        num = 15 (00001111 in binary), i = 2
        Step 1: (~0 << 2) = 11111100
        Step 2: 00001111 & 11111100 = 00001100 (decimal 12)
*/
void clearIBits(int num, int i) {
    num = num & (~0 << i); // Create mask and clear bits below i
    cout << num << endl;
}

int main() {
    clearIBits(15, 2); // Expected output: 12
    return 0;
}
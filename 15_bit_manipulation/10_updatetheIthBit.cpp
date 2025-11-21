#include <iostream>
using namespace std;

/*
    Function: updateTheIthBit
    -------------------------
    Updates the i-th bit of an integer 'num' to a specified 'value' (either 0 or 1).

    How it works:
    1. Clearing the i-th bit:
       - (1 << i)   → Creates a mask where only the i-th bit is set (e.g., if i=2 → 00000100 in binary).
       - ~(1 << i)  → Inverts the mask so that all bits are 1 except the i-th bit, which becomes 0.
       - num & ~(1 << i) → Clears the i-th bit of num (sets it to 0), leaving other bits unchanged.

    2. Setting the i-th bit to 'value':
       - (value << i) → Shifts the 'value' (0 or 1) to the i-th bit position.
       - num | (value << i) → Sets the i-th bit to 'value' without affecting other bits.

    Example:
        num = 7 (binary 00000111), i = 2, value = 0
        Step 1: Clear bit 2 → 00000111 & 11111011 = 00000011 (3)
        Step 2: Set bit 2 to 0 → 00000011 | 00000000 = 00000011 (3)
        Output = 3
*/
void updateTheIthBit(int num, int i, int value) {
    num = num & ~(1 << i);      // Step 1: Clear the i-th bit
    num = num | (value << i);   // Step 2: Set the i-th bit to 'value'
    cout << num << endl;
}

int main() {
    updateTheIthBit(7, 2, 0); // Expected output: 3
    return 0;
}
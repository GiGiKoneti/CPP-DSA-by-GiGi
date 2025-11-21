#include <iostream>
using namespace std;

/*
    Function: setIthBit
    -------------------
    Sets the ith bit of an integer to 1.

    num: The original number.
    i:   The bit position to set (0-based index from the right).

    Steps:
    1. Create a bitmask by left-shifting 1 by i positions.
       Example: If i = 3 → bitmask = 00001000 (binary).
    2. Use the bitwise OR (|) operation between num and bitmask.
       This ensures the ith bit becomes 1, and other bits remain unchanged.
    3. Print the new number after setting the bit.
*/
void setIthBit(int num, int i) {
    int bitmask = 1 << i;         // Step 1: Create bitmask
    cout << (bitmask | num) << endl; // Step 2 & 3: Set ith bit and print result
}

int main() {
    int num = 6; // binary: 0110
    int i = 3;   // We want to set the 3rd bit (0-based)
    setIthBit(num, i); 
    // Expected output: 14 (binary: 1110)
    return 0;
}
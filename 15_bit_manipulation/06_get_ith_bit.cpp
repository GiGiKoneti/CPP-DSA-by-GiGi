#include <iostream>
using namespace std;

/*
======================
   FINDING i-th BIT
======================

🧠 Concept:
We want to find whether the i-th bit (0-indexed from right to left) in a number's binary representation is 0 or 1.

Example:
Let num = 7
Binary of 7:  0 1 1 1   (assuming 4 bits for simplicity)
Bit index:   3 2 1 0

If i = 1, we want the 2nd bit from the right (index 1), which here is 1.

---------------------------
Step-by-Step Process:
---------------------------

1️⃣ Create a BITMASK:
   - We start with 1 (binary `0001`).
   - Left shift this by `i` positions → `(1 << i)`
   - Example: (1 << 1) = binary `0010` (which represents bit position 1).

2️⃣ Perform Bitwise AND:
   - We do: num & bitmask
   - This will keep only the i-th bit of `num` and set all other bits to 0.
   - Example:
       num      = 0111 (7 in binary)
       bitmask  = 0010
       -----------------
       result   = 0010  (non-zero → i-th bit is 1)

3️⃣ Check if result is 0 or not:
   - If result == 0 → i-th bit is 0.
   - If result != 0 → i-th bit is 1.

💡 Why `(1 << i)`?
   - This ensures we create a mask with ONLY the i-th bit set to 1, and others set to 0.

💡 Bit Indexing:
   - Bit 0 → LSB (Least Significant Bit, far right)
   - Bit n → MSB (Most Significant Bit, far left for n-bit number)
*/

int getIthBit(int num, int i) {
    int bitmask = (1 << i);  // Create a mask with only i-th bit set

    // Isolate the i-th bit
    if (num & bitmask) {
        return 1; // Non-zero means the bit is 1
    }
    else {
        return 0; // Zero means the bit is 0
    }
}

int main() {
    int num = 7;
    int i = 1;
    cout << "The " << i << "-th bit of " << num << " is: " << getIthBit(num, i) << endl;
    return 0;
}
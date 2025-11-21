#include <iostream>
using namespace std;

/*
    Function: countSetBits
    ----------------------
    Counts the number of 1's (set bits) in the binary representation of an integer 'num'.

    How it works:
    1. num & 1 → Checks the least significant bit (LSB):
         - If LSB is 1 → lastDig = 1
         - If LSB is 0 → lastDig = 0
    2. count += lastDig → Increments count if the current bit is set.
    3. num >> 1 → Right shift by 1 moves the next bit into LSB position.
    4. Loop continues until num becomes 0.

    Example:
        num = 15 (binary 1111)
        Iteration 1: lastDig = 1 → count = 1 → num = 111 (7)
        Iteration 2: lastDig = 1 → count = 2 → num = 11  (3)
        Iteration 3: lastDig = 1 → count = 3 → num = 1   (1)
        Iteration 4: lastDig = 1 → count = 4 → num = 0
        Output: 4
*/
int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        int lastDig = num & 1; // Extract LSB
        count += lastDig;      // Add to count if LSB is 1
        num = num >> 1;        // Shift bits to process the next one
    }
    cout << count << endl;
    return count;
}

int main() {
    countSetBits(15); // Expected output: 4
    return 0;
}
/*
Question 1:
Write a Function to clear the range of bits from i to j in a given number 
(i & j are counted backwards from the right end of the number).

Examples:

Input: num = 15, i = 1, j = 3
Output: 1
Explanation:
15 in binary form is => 00001111 
[i=1st & j=3rd bit underlined] 
After bits are cleared, number will become 00000001

Input: num = 31, i = 1, j = 3
Output: 17

Note: Think about what type of bit mask is needed. 
It can also be a combination of 2 numbers.
*/

#include <iostream>
using namespace std;

void clearBitsInRange(int num, int i, int j) {
    int a = (~0) << (j + 1);      // 1s before position j
    int b = (1 << i) - 1;         // 1s after position i-1
    int mask = a | b;             // Combine to create mask
    num = num & mask;
    cout << num << endl;
}

int main() {
    clearBitsInRange(15, 1, 3);   // Expected output: 1
    clearBitsInRange(31, 1, 3);   // Expected output: 17
    return 0;
}
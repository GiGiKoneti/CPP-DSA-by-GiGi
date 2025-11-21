#include <iostream>
using namespace std;

// Function to clear the i-th bit of a number
int clearIthBit(int num, int i) {
    // Step 1: Create a bitmask with only the i-th bit set (1 << i)
    int bitmask = 1 << i; // e.g., i = 1 → bitmask = 0000 0010

    // Step 2: Invert the bitmask so the i-th bit becomes 0, others become 1
    // Example: 0000 0010 → ~0000 0010 = 1111 1101
    bitmask = ~bitmask;

    // Step 3: AND the number with the new mask to clear the i-th bit
    // This keeps all other bits same and forces the i-th bit to 0
    return (num & bitmask);
}

int main() {
    int num = 6; // binary: 0000 0110
    int i = 1;   // clearing bit at position 1 (counting from right, starting at 0)

    cout << clearIthBit(num, i) << endl; // Expected output: 4
    return 0;
}
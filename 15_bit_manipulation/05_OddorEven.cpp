#include <iostream>
using namespace std;

/*
  Bit-level explanation (why `num & 1` checks even/odd)

  - Integers are stored in binary. The Least Significant Bit (LSB, bit 0)
    represents 2^0 = 1. All higher bits represent higher powers of two.

  - Any integer can be written as:
      num = ( ... b3 b2 b1 b0 )_2
    where b0 is the LSB.

  - If b0 == 0 → num = multiple of 2 → EVEN
    If b0 == 1 → num = multiple of 2 + 1 → ODD

  - Bitwise AND with 1:
      1 in binary = ... 0001
      num & 1 keeps only the LSB of num and zeroes all other bits.
      => (num & 1) is either 0 (LSB 0 → even) or 1 (LSB 1 → odd).

  Example (8-bit shown for clarity):
    6  = 0000 0110
    1  = 0000 0001
    6 & 1 = 0000 0000 => 0 -> even

    7  = 0000 0111
    1  = 0000 0001
    7 & 1 = 0000 0001 => 1 -> odd

  - Negative numbers (two's complement):
    Two's complement representation preserves the parity in the LSB:
    e.g., -3:
      +3 in binary = 0000...0011
      invert bits    = 1111...1100   (1's complement)
      add 1          = 1111...1101   (2's complement) -> LSB = 1 (odd)
    So (num & 1) == 1 for odd negative numbers and == 0 for even negative numbers.

  - Complexity: O(1) time, O(1) space.
    Equivalent to `num % 2` for parity testing, but uses a single bit operation.
    Modern compilers often optimize `% 2` similarly, but `& 1` is explicit bit-level check.

  - Important: Works for integer types only (not floats/doubles).
*/

void OddOrEven(int num) {
    // (num & 1) isolates the LSB; compare to 0 to determine evenness
    if ((num & 1) == 0) {
        cout << num << " is Even\n";
    } else {
        cout << num << " is Odd\n";
    }
}

int main() {
    int num;
    cout << "Enter any integer: ";
    if (!(cin >> num)) {
        cout << "Invalid input.\n";
        return 1;
    }

    OddOrEven(num);

    return 0;
}
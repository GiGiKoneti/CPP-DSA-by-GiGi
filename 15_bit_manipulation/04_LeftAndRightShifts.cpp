#include <iostream>
using namespace std;

int main() {
    /*
    ===========================
    🔹 Bitwise LEFT SHIFT (<<)
    ===========================
    Syntax: a << b
    Meaning: Shift all bits of 'a' to the LEFT by 'b' positions.
    
    ❓ What happens when we left shift?
       - All bits move to the left.
       - Empty positions on the RIGHT are filled with 0.
       - Each left shift by 1 position multiplies the number by 2.

    💡 Shortcut formula:
       a << b = a * (2^b)

    Example: 7 << 2
       Step 1: Write 7 in binary (assuming 8-bit representation for simplicity)
               00000111  (7 in binary)
       Step 2: Shift LEFT by 2 positions
               00011100  (Now the binary value is 28)
       Step 3: Convert back to decimal → 28

       Using shortcut:
         7 << 2 = 7 * (2^2)
                 = 7 * 4
                 = 28
    */
    cout << (7 << 2) << endl;  // Output: 28


    /*
    ===========================
    🔹 Bitwise RIGHT SHIFT (>>)
    ===========================
    Syntax: a >> b
    Meaning: Shift all bits of 'a' to the RIGHT by 'b' positions.
    
    ❓ What happens when we right shift?
       - All bits move to the right.
       - Empty positions on the LEFT depend on the type:
           For unsigned numbers → filled with 0.
           For signed numbers → sign bit (MSB) is filled for arithmetic shift.
       - Each right shift by 1 position divides the number by 2 (floor division).

    💡 Shortcut formula:
       a >> b = a / (2^b)

    Example: 7 >> 2
       Step 1: Write 7 in binary
               00000111  (7 in binary)
       Step 2: Shift RIGHT by 2 positions
               00000001  (Now the binary value is 1)
       Step 3: Convert back to decimal → 1

       Using shortcut:
         7 >> 2 = 7 / (2^2)
                 = 7 / 4
                 = 1 (floor division)
    */
    cout << (7 >> 2) << endl;  // Output: 1

    return 0;
}

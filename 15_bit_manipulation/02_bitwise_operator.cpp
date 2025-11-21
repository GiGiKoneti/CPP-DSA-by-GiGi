#include <iostream>
using namespace std;

int main() {
    // Binary of 3 = 011
    // Binary of 5 = 101

    // Bitwise AND: 011 & 101 = 001 => 1
    cout << (3 & 5) << endl;  // Output: 1 ✅

    // Bitwise OR: 011 | 101 = 111 => 7
    cout << (3 | 5) << endl;  // Output: 7 ✅

    // Bitwise XOR: 011 ^ 101 = 110 => 6
    cout << (3 ^ 5) << endl;  // Output: 6 ✅

    return 0;
}
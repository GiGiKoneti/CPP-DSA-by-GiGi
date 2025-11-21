#include <iostream>
#include <string>
using namespace std;

/* =======================================================
   BINARY STRINGS PROBLEM
   -------------------------------------------------------
   Generate all binary strings of size n
   such that there are NO consecutive 1s.

   Idea:
   - Keep track of 'lastPlace' (0 or 1)
   - Always allowed to place '0'
   - Place '1' only if lastPlace != 1
======================================================= */

void generateBinaryStrings(int n, int lastPlace, string result) {
    // Base case: if string size == n, print it
    if (n == 0) {
        cout << result << endl;
        return;
    }

    // Always allowed to put '0'
    generateBinaryStrings(n - 1, 0, result + "0");

    // Put '1' only if lastPlace was not 1
    if (lastPlace == 0) {
        generateBinaryStrings(n - 1, 1, result + "1");
    }
}

int main() {
    int n;
    cout << "Enter size of binary string: ";
    cin >> n;

    cout << "Binary strings of size " << n << " without consecutive 1s:\n";
    generateBinaryStrings(n, 0, "");  // start with lastPlace=0

    return 0;
}

/* =======================================================
   Example:
   Input: n = 3
   Output:
   000
   001
   010
   100
   101
======================================================= */
#include <iostream>
using namespace std;

/* ===========================================================
   STACK OVERFLOW & INFINITE RECURSION
   -----------------------------------------------------------
   1. Stack Overflow occurs when function calls use up 
      all stack memory (usually due to infinite recursion).
   2. Missing Base Case → recursion never stops.
   3. Large local variables → each recursive call consumes 
      stack space faster.
   4. Result → Segmentation Fault / Crash
=========================================================== */

// Infinite recursion example
void infiniteRecursion(int n) {
    int localArray[1000];  // Each call consumes stack memory
    cout << "Recursion level: " << n << endl;

    // Missing base case → recursion never stops
    infiniteRecursion(n + 1);
}

int main() {
    cout << "Demonstrating Stack Overflow via infinite recursion:" << endl;
    // WARNING: This will crash the program
    // Comment out to prevent actual crash
    // infiniteRecursion(1);

    cout << "If uncommented, the program would eventually crash with SEGMENTATION FAULT." << endl;
    return 0;
}

/* ===========================================================
   EXPLANATION:
   1. Each function call is stored on stack with local variables.
   2. No base case → recursion never ends.
   3. Stack memory fills up → stack overflow → segmentation fault.
   4. If large local arrays/objects exist, stack fills faster.
=========================================================== */
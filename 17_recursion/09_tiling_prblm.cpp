#include <iostream>
using namespace std;

/* ===========================================================
   TILING PROBLEM (2 x n floor using 2 x 1 tiles)
   -----------------------------------------------------------
   Problem:
   Count number of ways to tile a 2 x n board using 2 x 1 tiles.

   Logic:
   - Base Case:
        n == 0 → 1 way (fill empty floor with no tiles)
        n == 1 → 1 way (only vertical placement possible)
   - Recursive Case:
        ways(n) = ways(n-1) + ways(n-2)
        (Vertical tile + Horizontal tile cases)
=========================================================== */

int tilingWays(int n) {
    if (n == 0) return 1;  // 1 way to fill 0 area
    if (n == 1) return 1;  // 1 way (vertical tile)
    if (n == 2) return 2;  // 2 ways (VV or HH)

    return tilingWays(n-1) + tilingWays(n-2);
}

int main() {
    int n = 5; // 2 x 5 floor
    cout << "Number of ways to tile a 2x" << n << " floor: " 
         << tilingWays(n) << endl;
    return 0;
}

/* ===========================================================
   OUTPUT:
   Number of ways to tile a 2x5 floor: 8

   SEQUENCE:
   n=0 → 1
   n=1 → 1
   n=2 → 2
   n=3 → 3
   n=4 → 5
   n=5 → 8
   (This is Fibonacci starting with F(0)=1, F(1)=1)
=========================================================== */
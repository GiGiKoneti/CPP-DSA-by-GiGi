#include <iostream>
using namespace std;

/* =======================================================
   FRIENDS PAIRING PROBLEM
   -------------------------------------------------------
   f(n) = f(n-1) + (n-1) * f(n-2)

   Explanation:
   - Case 1: nth friend stays single → f(n-1)
   - Case 2: nth friend pairs with (n-1) others → (n-1)*f(n-2)
======================================================= */

int friendsPairing(int n) {
    // Base cases
    if (n == 1) return 1;
    if (n == 2) return 2;

    // Recursive relation
    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main() {
    int n;
    cout << "Enter number of friends: ";
    cin >> n;

    cout << "Total ways " << n << " friends can be paired: "
         << friendsPairing(n) << endl;

    return 0;
}

/* =======================================================
   Example:
   Input : 3
   Output: 4

   Ways:
   - {A,B,C}
   - {(A,B),C}
   - {(A,C),B}
   - {(B,C),A}
======================================================= */
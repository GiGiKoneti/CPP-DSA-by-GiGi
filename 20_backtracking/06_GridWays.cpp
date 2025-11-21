#include <iostream>
using namespace std;

/*
    🧭 Grid Ways Problem — Backtracking + Recursion
    ------------------------------------------------
    You are at the top-left corner (0,0) of an n×m grid.
    You can only move:
        ➡️ Right  (increase column)
        ⬇️ Down   (increase row)

    Goal: Find the total number of ways to reach the
          bottom-right corner (n-1, m-1).

    Example: For a 3x3 grid
              Start (0,0)
                ⬇️     ➡️
              (1,0) → (1,1) → ... → (2,2)
              Total ways = 6


    🧩 Explanation
    ---------------
    - The grid is treated as a decision tree.
    - At each step (i, j), you have two choices:
        - Move Down → (i+1, j)
        - Move Right → (i, j+1)
    - The recursion explores all paths until it reaches 
      the destination (n-1, m-1).

    ✅ Base Cases:
        1. Reached destination → Return 1 (one valid path)
        2. Out of bounds → Return 0 (invalid path)

    🔁 Recursive Case:
        Each cell’s total paths = paths from below + paths from right

    ⏱️ Time and Space Complexity
    -----------------------------
    - Time Complexity: O(2^(n+m))
        Each cell calls recursion twice → exponential due to overlapping subproblems.
        ⚡ Can be optimized to O(n×m) using Dynamic Programming or Combinatorics.
    - Space Complexity: O(n+m)
        Recursive call stack depth = (n+m)
*/


// Recursive function to count paths from (i, j) to (n-1, m-1)
int gridWays(int i, int j, int n, int m) {
    // ✅ Base Case 1: Reached destination
    if (i == n - 1 && j == m - 1) {
        return 1;
    }

    // 🚫 Base Case 2: Out of bounds
    if (i >= n || j >= m) {
        return 0;
    }

    // Move Down + Move Right
    int downWays = gridWays(i + 1, j, n, m);
    int rightWays = gridWays(i, j + 1, n, m);

    // Total ways = sum of both
    return downWays + rightWays;
}

int main() {
    int n = 3, m = 3; // 3x3 grid
    cout << "Total ways to reach (" << n-1 << "," << m-1 << ") = "
         << gridWays(0, 0, n, m) << endl;

    return 0;
}
#include <iostream>
using namespace std;

/*
    🎯 Sudoku Solver using Recursion + Backtracking
    ------------------------------------------------
    Sudoku is a 9×9 puzzle grid where:
        - Each row, column, and 3×3 subgrid must contain digits 1–9 without repetition.

    🧩 Approach:
    -------------
    1. **Find an empty cell (0)** → this represents an unfilled spot.
    2. **Try digits 1–9**:
        - For each number, check if it’s *safe* to place in that cell:
            ✅ Not already present in the current row.
            ✅ Not already present in the current column.
            ✅ Not already present in the 3×3 subgrid.
    3. **Recursion**:
        - Place the number and recursively attempt to fill the rest of the board.
    4. **Backtracking**:
        - If a conflict occurs later, remove the number (reset to 0) and try the next number.
    5. **Success**:
        - When all cells are filled validly, print the solved Sudoku.

    ⚙️ Base Case:
        - If no empty cell remains → Puzzle solved → Return true.

    🔁 Recursive Case:
        - For each empty cell, try placing 1–9.
        - Recurse deeper until solved or backtrack if invalid.

    🧮 Time and Space Complexity
    -----------------------------
    - Time Complexity: O(9^(n*n)) in worst case → exponential.
      But practical backtracking prunes a lot of invalid branches.
    - Space Complexity: O(n*n) recursion depth (stack + board state).
*/


// ✅ Function to check if placing 'num' at board[row][col] is valid
bool isSafe(int board[9][9], int row, int col, int num) {
    // Check row
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num)
            return false;
    }

    // Check column
    for (int x = 0; x < 9; x++) {
        if (board[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// 🧠 Recursive function to solve Sudoku using backtracking
bool solveSudoku(int board[9][9], int n) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // Find next empty cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }

    // ✅ Base Case: no empty cell left → solved
    if (!isEmpty) return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;   // Choose
            if (solveSudoku(board, n))
                return true;          // Success path found
            board[row][col] = 0;      // Backtrack
        }
    }

    return false; // Trigger backtracking
}

// 📜 Function to print Sudoku board
void printBoard(int board[9][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 9;
    int board[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "🧩 Original Sudoku:\n";
    printBoard(board, n);

    if (solveSudoku(board, n)) {
        cout << "\n✅ Solved Sudoku:\n";
        printBoard(board, n);
    } else {
        cout << "\n❌ No solution exists.";
    }

    return 0;
}
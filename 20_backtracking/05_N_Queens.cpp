#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    🧩 N-Queens Problem — Backtracking Approach
    --------------------------------------------------
    Goal: Place N queens on an N×N chessboard so that
          no two queens attack each other.

    We explore every row, placing one queen per row.
    For each cell, we check if it’s safe:
        - No queen in same column
        - No queen in upper-left diagonal
        - No queen in upper-right diagonal

    If safe → place queen → move to next row
    If not safe → try next column
    If all rows filled → print the board
    If not possible → backtrack
*/

// 🧱 Helper function to print the current board
void printboard(const vector<vector<char>>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

// ✅ Checks if placing a queen at (row, col) is safe
bool isSafe(const vector<vector<char>>& board, int row, int col) {
    int n = board.size();

    // Check same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// 🔁 Recursive function to solve N-Queens
void nQueens(vector<vector<char>>& board, int row) {
    int n = board.size();

    // Base case: all queens placed
    if (row == n) {
        printboard(board);
        return;
    }

    // Try placing a queen in every column of this row
    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';     // Place queen
            nQueens(board, row + 1); // Recur for next row
            board[row][j] = '.';     // Backtrack
        }
    }
}

// 🚀 Main function
int main() {
    int n = 4; // Try 4-Queens
    vector<vector<char>> board(n, vector<char>(n, '.'));

    nQueens(board, 0);
    return 0;
}

/*
### ⏱️ Time & Space Complexity

- **Time Complexity:** O(N!)  
  Each row tries N positions, but valid configurations decrease as queens are placed.

- **Space Complexity:** O(N²) (for the board)  
  + O(N) recursion stack → effectively **O(N²)**.
  
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For formatted printing (setw)
using namespace std;


/***************************************************************************************************
 * 🧭 QUESTION 1: RAT IN A MAZE (Backtracking)
 *
 * Problem:
 *  - A rat starts at (0,0) in an N×N maze.
 *  - 1 represents open cells, 0 represents blocked paths.
 *  - The goal is to reach (N-1, N-1) by moving in 4 directions: Up(U), Down(D), Left(L), Right(R).
 *
 * Approach:
 *  - Use recursion and backtracking.
 *  - From the current cell, try all 4 possible moves.
 *  - Only proceed if the next cell is within bounds, open (1), and not visited.
 *  - When (N-1, N-1) is reached → store the current path.
 *  - Backtrack by marking the cell as unvisited before returning.
 *
 * Base Case:
 *  - When (x, y) == (n-1, n-1), add the path to result.
 *
 * Time Complexity:  O(4^(n*n))  (each cell can have 4 directions)
 * Space Complexity: O(n*n)       (visited matrix + recursion stack)
 ***************************************************************************************************/

// ✅ Check if a move is valid (inside bounds, not visited, and open)
bool isMazeMoveSafe(int x, int y, const vector<vector<int>>& maze, int n, const vector<vector<bool>>& visited) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

// 🔁 Recursive function to explore paths
void solveRatInAMazeHelper(int x, int y, vector<vector<int>>& maze, int n,
                           vector<string>& result, string path, vector<vector<bool>>& visited) {

    // ✅ Base Case: Destination reached
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }

    visited[x][y] = true;

    // Explore all directions (Down, Left, Right, Up)
    if (isMazeMoveSafe(x + 1, y, maze, n, visited))
        solveRatInAMazeHelper(x + 1, y, maze, n, result, path + 'D', visited);

    if (isMazeMoveSafe(x, y - 1, maze, n, visited))
        solveRatInAMazeHelper(x, y - 1, maze, n, result, path + 'L', visited);

    if (isMazeMoveSafe(x, y + 1, maze, n, visited))
        solveRatInAMazeHelper(x, y + 1, maze, n, result, path + 'R', visited);

    if (isMazeMoveSafe(x - 1, y, maze, n, visited))
        solveRatInAMazeHelper(x - 1, y, maze, n, result, path + 'U', visited);

    // 🔙 Backtrack
    visited[x][y] = false;
}

// 🎯 Setup and execution
void solveRatInAMaze() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = maze.size();
    vector<string> result;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        cout << "No valid path exists.\n";
        return;
    }

    solveRatInAMazeHelper(0, 0, maze, n, result, "", visited);

    if (result.empty()) cout << "No paths found.\n";
    else {
        cout << "✅ Found " << result.size() << " paths:\n";
        for (auto& path : result) cout << path << endl;
    }
}


/***************************************************************************************************
 * ☎️ QUESTION 2: KEYPAD COMBINATIONS (Backtracking)
 *
 * Problem:
 *  - Given digits 2–9, print all possible letter combinations based on a phone keypad.
 *
 * Approach:
 *  - Use recursion to generate all combinations.
 *  - Each digit maps to several letters (e.g., 2 → "abc").
 *  - At each level, append one letter from the current digit and recurse for the next.
 *
 * Base Case:
 *  - When index == digits.length(), store the combination.
 *
 * Time Complexity:  O(4^n)  (each digit can map to at most 4 letters)
 * Space Complexity: O(n)    (recursion depth)
 ***************************************************************************************************/

void solveKeypadCombinationsHelper(const string& digits, int index, const vector<string>& mapping,
                                   string current, vector<string>& result) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];
    for (char c : letters)
        solveKeypadCombinationsHelper(digits, index + 1, mapping, current + c, result);
}

void solveKeypadCombinations() {
    string digits = "23";
    if (digits.empty()) {
        cout << "Empty input.\n";
        return;
    }

    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> result;
    solveKeypadCombinationsHelper(digits, 0, mapping, "", result);

    cout << "✅ Combinations for \"" << digits << "\":\n";
    for (auto& s : result) cout << s << " ";
    cout << endl;
}


/***************************************************************************************************
 * ♞ QUESTION 3: KNIGHT'S TOUR (Backtracking)
 *
 * Problem:
 *  - Place a knight on a chessboard such that it visits every cell exactly once.
 *
 * Approach:
 *  - Use recursion and backtracking.
 *  - Try all 8 possible knight moves from the current cell.
 *  - Mark the cell as visited with move count.
 *  - If all cells are filled → print the board.
 *  - Backtrack if stuck.
 *
 * Base Case:
 *  - moveCount == n*n → all cells visited.
 *
 * Time Complexity:  O(8^(n*n))  (each cell has 8 possible moves)
 * Space Complexity: O(n*n)      (board + recursion)
 ***************************************************************************************************/

bool isKnightMoveSafe(int x, int y, int n, const vector<vector<int>>& board) {
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

bool solveKnightsTourHelper(int x, int y, int moveCount, int n, vector<vector<int>>& board,
                            const int moveX[], const int moveY[]) {
    if (moveCount == n * n) return true;

    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];
        if (isKnightMoveSafe(nextX, nextY, n, board)) {
            board[nextX][nextY] = moveCount;
            if (solveKnightsTourHelper(nextX, nextY, moveCount + 1, n, board, moveX, moveY))
                return true;
            board[nextX][nextY] = -1; // Backtrack
        }
    }
    return false;
}

void solveKnightsTour() {
    int n = 8;
    vector<vector<int>> board(n, vector<int>(n, -1));

    int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};

    board[0][0] = 0;

    if (solveKnightsTourHelper(0, 0, 1, n, board, moveX, moveY)) {
        cout << "✅ Knight's Tour Solution:\n";
        for (auto& row : board) {
            for (int cell : row) cout << setw(3) << cell << " ";
            cout << endl;
        }
    } else cout << "No solution found.\n";
}


/***************************************************************************************************
 * 🚀 MAIN DRIVER FUNCTION
 ***************************************************************************************************/
int main() {
    cout << "========================================\n";
    cout << "     🧩 BACKTRACKING PROBLEMS IN C++     \n";
    cout << "========================================\n";

    cout << "\n--- [1] Rat in a Maze ---\n";
    solveRatInAMaze();

    cout << "\n--- [2] Keypad Combinations ---\n";
    solveKeypadCombinations();

    cout << "\n--- [3] Knight's Tour ---\n";
    solveKnightsTour();

    cout << "\n========================================\n";
    cout << "        ✅ All Tasks Completed          \n";
    cout << "========================================\n";

    return 0;
}
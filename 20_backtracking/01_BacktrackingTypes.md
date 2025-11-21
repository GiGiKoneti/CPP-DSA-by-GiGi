# Backtracking in Algorithms

## 🔹 What is Backtracking?
Backtracking is a **problem-solving technique** used to build a solution **step by step** while abandoning ("backtracking") a path as soon as it is determined that it cannot lead to a valid solution.

- It is a form of **recursion** where we try different possibilities.  
- If one choice does not work, we **undo (backtrack)** and try another.  
- Often used in solving problems like **N-Queens, Sudoku, Maze-solving, Hamiltonian cycles, and Combinatorial generation**.

---

## 🔹 Types of Backtracking

### 1. **Decision Problems**
- These problems focus on answering **YES / NO**.  
- Example:  
  - Does there exist a solution for placing `N` queens on an `N x N` chessboard such that no two queens attack each other?  
  - Maze Path: Is there a path from start to destination?

---

### 2. **Optimization Problems**
- In these problems, the goal is to find the **best possible solution** among all feasible solutions.  
- Example:  
  - The **Knapsack Problem**: Fill a bag with items to maximize profit without exceeding weight capacity.  
  - The **Shortest Path Problem**: Find the path with minimum distance/cost.

---

### 3. **Enumeration Problems**
- These problems require **listing all possible solutions**, not just one.  
- Example:  
  - Generate all **permutations of a string**.  
  - Print all valid parenthesis combinations for `n` pairs.  
  - Generate all subsets of a set.

---

## 🔑 Summary
- **Decision** → Does a solution exist? (YES/NO)  
- **Optimization** → Find the *best* solution.  
- **Enumeration** → List *all* possible solutions.  

Backtracking is powerful but can be **exponential in complexity**, making pruning and constraints crucial for efficiency.
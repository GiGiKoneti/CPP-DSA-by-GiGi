#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Utility function to print the array
void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
 Backtracking Example:
 ----------------------
 - We try to fill the array step by step.
 - At each index `i`, we assign arr[i] = i+1.
 - Then, we recursively call for the next index.
 - After returning (backtracking), we UNDO our choice by modifying arr[i] -= 2.
 - This ensures we explore both the "forward" choice and the "backtracked" choice.

 Key Point:
 Backtracking means: 
    1. Make a choice
    2. Recurse
    3. Undo the choice (backtrack) and explore other possibilities
*/
void changeArr(int arr[], int n, int i) {
    // Base case → when we have filled all elements
    if (i == n) {
        printarr(arr, n); // Print one configuration of array
        return;
    }

    // Step 1: Make a choice
    arr[i] = i + 1;

    // Step 2: Recursive call to fill next element
    changeArr(arr, n, i + 1);

    // Step 3: Backtrack (Undo the previous choice)
    arr[i] -= 2;
}

int main() {
    int arr[5] = {0};
    int n = 5;

    // Start filling array from index 0
    changeArr(arr, n, 0);

    // Final state of the array after all recursion and backtracking
    cout << "Final state of array after recursion & backtracking:" << endl;
    printarr(arr, n);

    return 0;
}


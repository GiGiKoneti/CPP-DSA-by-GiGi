#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 Backtracking Example: Generate All Permutations of a String
 ------------------------------------------------------------
 Problem:
    Given a string, print all possible permutations of it.

 Concept:
    - A permutation is a rearrangement of characters.
    - For a string of length n, there are n! (factorial) possible permutations.
    - Backtracking is used here by swapping/choosing characters step by step.

 Logic:
    1. Base Case:
        If the input string becomes empty, print the current answer (ans).
    2. Recursive Case:
        For every character in the string:
            a. Pick that character (ch).
            b. Create a smaller string excluding that character.
            c. Recursively call the function for the smaller string with ans + ch.

 Example (str = "abc"):
        Step 1 → Pick 'a', permute "bc"
        Step 2 → Pick 'b', permute "c"
        Step 3 → Pick 'c', permute ""
        => one permutation = "abc"
        (and similarly for others)

 Time Complexity: O(n × n!) 
    → Because there are n! permutations and creating substrings takes O(n).
*/

void permutations(string str, string ans) {
    int n = str.size();

    // Base case → if the string becomes empty, print the permutation
    if (n == 0) {
        cout << ans << endl;
        return;
    }

    // Recursive case → explore all characters as potential starting points
    for (int i = 0; i < n; i++) {
        char ch = str[i];  // choose the current character

        // form the remaining string excluding the chosen character
        string nextStr = str.substr(0, i) + str.substr(i + 1, n - i - 1);

        // recursive call → build permutations with current choice added to ans
        permutations(nextStr, ans + ch);
    }
}

int main() {
    string str = "abc";
    string ans = "";

    cout << "All permutations of \"" << str << "\" are:\n";
    permutations(str, ans);

    return 0;
}

/*

⏱️ Time & Space Complexity

- **Total permutations:** n!  
- **Work per call:** O(n) (due to substring creation)

✅ **Time Complexity:** O(n × n!)  
✅ **Space Complexity:** O(n)

*/
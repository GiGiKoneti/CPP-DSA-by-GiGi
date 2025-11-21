#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 Backtracking Example: Generate all subsets of a string
 ------------------------------------------------------
 Problem:
    Given a string, print all possible subsets of it.

 Logic:
    - At each step, we decide whether to:
        1. INCLUDE the current character in the subset.
        2. EXCLUDE the current character from the subset.
    - This gives us 2^n subsets for a string of length n.
    - Base case: when the string becomes empty, print the subset.

 Steps:
    1. Pick the first character of the string.
    2. Explore the "Yes choice" → include it in the subset.
    3. Explore the "No choice"  → exclude it from the subset.
    4. Backtracking ensures we explore all possible combinations.
*/

void printSubsets(string str, string subset) {
    // Base Case → when the input string is empty
    if (str.size() == 0) {
        cout << subset << endl; // print one subset
        return;
    }

    char ch = str[0]; // take the first character

    // Choice 1 → YES: include the current character
    printSubsets(str.substr(1, str.size() - 1), subset + ch);

    // Choice 2 → NO: exclude the current character
    printSubsets(str.substr(1, str.size() - 1), subset);
}

int main() {
    string str = "abc";     // input string
    string subset = "";     // initially empty subset
    cout << "All subsets of \"" << str << "\" are:" << endl;
    printSubsets(str, subset);
    return 0;
}
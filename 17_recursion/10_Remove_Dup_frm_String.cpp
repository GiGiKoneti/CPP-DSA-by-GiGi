#include <iostream>
#include <string>
using namespace std;

/* ===========================================================
   REMOVE DUPLICATES FROM STRING USING RECURSION
   -----------------------------------------------------------
   Problem:
   Input  : "appnnacolleg"
   Output : "apncoleg"

   Logic:
   - Keep a boolean array visited[26] to track seen characters.
   - Traverse string recursively:
        - If char not visited → add to result, mark visited.
        - If visited → skip char.
=========================================================== */

void removeDuplicates(string input, int index, string &result, bool visited[26]) {
    // Base case: reached end of string
    if (index == input.length()) {
        cout << result << endl;  // print final answer
        return;
    }

    char currChar = input[index];

    // If char already visited → skip
    if (visited[currChar - 'a']) {
        removeDuplicates(input, index + 1, result, visited);
    }
    else {
        // Mark as visited and add to result
        visited[currChar - 'a'] = true;
        result.push_back(currChar);
        removeDuplicates(input, index + 1, result, visited);
    }
}

int main() {
    string input = "appnnacollege";
    string result = "";
    bool visited[26] = {false}; // track lowercase letters

    cout << "Input : " << input << endl;
    cout << "Output: ";
    removeDuplicates(input, 0, result, visited);

    return 0;
}

/* ===========================================================
   OUTPUT:
   Input : appnnacolleg
   Output: apncoleg
=========================================================== */


// METHOD TWO (without i)

/*
#include <iostream>
#include <string>
using namespace std;

=============================================================
   REMOVE DUPLICATES FROM STRING (BACKWARDS RECURSION)
   -----------------------------------------------------------
   Problem:
   Input  : "appnnacolleg"
   Output : "apncoleg"

   Logic:
   - Base case: empty string → return "".
   - Process substring (excluding last char).
   - Check if last char already exists in processed result:
        - If yes → skip it.
        - If no  → append it.
=========================================================== 

string removeDuplicates(string input) {
    // Base case
    if (input.empty()) {
        return "";
    }

    // Take last character
    char lastChar = input.back();

    // Recursive call on substring (exclude last char)
    string reduced = removeDuplicates(input.substr(0, input.size() - 1));

    // If lastChar already exists in reduced → skip
    if (reduced.find(lastChar) != string::npos) {
        return reduced;
    }
    else {
        return reduced + lastChar;
    }
}

int main() {
    string input = "appnnacolleg";

    cout << "Input : " << input << endl;
    cout << "Output: " << removeDuplicates(input) << endl;

    return 0;
}

=============================================================
   OUTPUT:
   Input : appnnacolleg
   Output: apncoleg
=============================================================

*/
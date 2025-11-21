#include <iostream>
#include <string>
using namespace std;

bool canBeEqualWithOneSwap(string s1, string s2) {
    // If strings are already equal
    if (s1 == s2) return true;

    int n = s1.length();

    // To store the indices where characters differ
    int first = -1, second = -1;

    // Find mismatched characters
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            if (first == -1) {
                first = i;
            } else if (second == -1) {
                second = i;
            } else {
                // More than two mismatches, cannot fix with one swap
                return false;
            }
        }
    }

    // If exactly two mismatches, check if swapping makes them equal
    if (second != -1) {
        return (s1[first] == s2[second] && s1[second] == s2[first]);
    }

    // If only one mismatch or none — cannot fix with a single swap
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;

    if (s1.length() != s2.length()) {
        cout << "false (Strings are of unequal length)" << endl;
        return 0;
    }

    bool result = canBeEqualWithOneSwap(s1, s2);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// Function to check whether two strings are anagrams
bool isAnagram(string str1, string str2) {
    // If the lengths differ, they can't be anagrams
    if (str1.length() != str2.length()) {
        cout << "Not an Anagram" << endl;
        return false;
    }

    // Initialize a count array for 26 lowercase English letters
    int count[26] = {0};

    // Increment count for each character in str1
    for (int i = 0; i < str1.length(); i++) {
        int idx = str1[i] - 'a';  // Calculate index (0 for 'a', 1 for 'b', etc.)
        count[idx]++;
    }

    // Decrement count for each character in str2
    for (int i = 0; i < str2.length(); i++) {
        int idx = str2[i] - 'a';

        // If count is already 0, str2 has an extra character not in str1
        if (count[idx] == 0) {
            cout << "Not an Anagram" << endl;
            return false;
        }
        count[idx]--;
    }

    // If all counts are balanced, it's a valid anagram
    cout << "Valid Anagram" << endl;
    return true;
}

int main() {
    string str1 = "anagram";
    string str2 = "nagaram";

    // Call the function with two input strings
    isAnagram(str1, str2);

    return 0;
}
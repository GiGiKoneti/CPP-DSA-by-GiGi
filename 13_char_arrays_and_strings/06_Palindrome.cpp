#include <iostream>
#include <cstring>  // Required for strlen()
using namespace std;

// Function to check if a given character array (C-string) is a palindrome
bool isPalindrome(char word[], int n) {
    int start = 0;
    int end = n - 1;

    // Compare characters from both ends moving toward the center
    while (start < end) {
        if (word[start] != word[end]) {
            return false;  // Mismatch found → not a palindrome
        }
        start++;
        end--;
    }

    return true;  // All characters matched → it’s a palindrome
}

int main() {
    char word[] = "racecar";  // You can change this to test other words

    // Check if the word is a palindrome
    if (isPalindrome(word, strlen(word))) {
        cout << word << " is a palindrome." << endl;
    } else {
        cout << word << " is not a palindrome." << endl;
    }

    return 0;
}
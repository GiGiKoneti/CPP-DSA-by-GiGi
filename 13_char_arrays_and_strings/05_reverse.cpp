#include <iostream>
#include <cstring>  // Required for strlen() function
using namespace std;

// Function to reverse a character array (C-style string)
void reverse(char word[], int n) {
    int start = 0;
    int end = n - 1;  // Exclude the null terminator '\0'

    // Swap characters from start and end moving towards the center
    while (start < end) {
        swap(word[start], word[end]);  // Swap characters
        start++;  // Move start pointer forward
        end--;    // Move end pointer backward
    }
}

int main() {
    // Define a character array (C-string)
    char word[] = "Majd";

    // Get the length of the string (excluding '\0') using strlen
    int length = strlen(word);

    // Reverse the string in-place
    reverse(word, length);

    // Print the reversed string
    cout << "Reversed word: " << word << endl;

    return 0;
}
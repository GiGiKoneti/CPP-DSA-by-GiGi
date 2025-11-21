#include <iostream>
#include <cstring>  // For strlen
using namespace std;

// Convert all lowercase letters in the word to uppercase
void toUpper(char word[], int n) {
    for (int i = 0; i < n; i++) {
        char ch = word[i];
        if (ch >= 'a' && ch <= 'z') {
            word[i] = ch - 'a' + 'A';
        }
    }
}

int main() {
    char word[] = "GiGiMajd";

    toUpper(word, strlen(word));

    cout << "Uppercase: " << word << endl;

    return 0;
}
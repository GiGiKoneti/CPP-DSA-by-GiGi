#include <iostream>
using namespace std;

int main() {
    char ch1 = 'a';
    char ch2 = 'f';
    char ch3 = '\n';  // Newline character

    // ASCII value of a character
    cout << "ASCII value of '" << ch1 << "' is: " << (int)ch1 << endl;

    // Position of ch2 relative to 'a' (0-based index)
    int position = ch2 - 'a';
    cout << "Position of '" << ch2 << "' relative to 'a': " << position << endl;

    return 0;
}
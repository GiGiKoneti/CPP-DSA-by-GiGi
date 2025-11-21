#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "GiGi Molki";

    // -------------------------------
    // str.length() → returns number of characters
    // -------------------------------
    cout << "Length of string: " << str.length() << endl;

    // -------------------------------
    // str.at(index) → returns character at specified index with bounds checking
    // -------------------------------
    cout << "Character at index 0: " << str.at(0) << endl;

    // -------------------------------
    // str.substr(startIndex, length) → returns substring starting from index
    // -------------------------------
    cout << "Substring from index 0 of length 4: " << str.substr(0, 4) << endl;

    // -------------------------------
    // str.find("substring") → returns starting index of the substring (or npos if not found)
    // -------------------------------
    cout << "Position of 'Molki' in the string: " << str.find("Molki") << endl;

    return 0;
}
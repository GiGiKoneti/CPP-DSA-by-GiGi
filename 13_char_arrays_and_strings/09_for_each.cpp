#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "GiGi Molki";

    // -------------------------------
    // Method 1: Index-based iteration
    // -------------------------------
    cout << "Characters using index-based for loop: ";
    for (int i = 0; i < str.length(); i++) {
        cout << str[i];  // Accessing characters via index
        if (i != str.length() - 1) cout << ", ";  // Add commas between characters
    }
    cout << endl;

    // --------------------------------
    // Method 2: Range-based for loop
    // --------------------------------
    cout << "Characters using range-based for loop: ";
    for (char ch : str) {
        cout << ch << " ";  // Directly accessing each character
    }

    cout << endl;
    return 0;
}
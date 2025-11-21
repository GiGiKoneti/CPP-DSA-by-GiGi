/*
===============================================================================
🆚 Difference Between char[] (C-style) and string (C++ STL)
===============================================================================

| Feature         | char[] (C-style)                            | string (C++ STL)                                   |
|----------------|---------------------------------------------|----------------------------------------------------|
| Header file     | <cstring>                                  | <string>                                           |
| Mutability      | Fixed size at declaration                  | Dynamic size (auto-managed)                        |
| Assignment      | Cannot assign directly after declaration   | Direct assignment using = supported                |
| Operators       | Not supported directly (e.g., +, ==)       | Supports operators like +, ==, <, > etc.           |
| Functions       | Uses functions like strcpy, strlen         | Has built-in member functions like .length(), .substr() |
| Memory          | Array of characters, manual management     | Object stored contiguously, auto-managed           |
| Input handling  | cin, gets, fgets (unsafe or limited)       | cin, getline (safe, preferred)                     |

===============================================================================
*/



#include <iostream>
#include <string>  // Required for using std::string
using namespace std;

int main() {
    // Creating a string object
    string str = "GiGi";

    // Direct assignment is allowed in C++ strings (not in char arrays)
    str = "Majd";
    cout << "String after reassignment: " << str << endl;

    // ----------------------------------------
    // Input using cin (only reads until first space)
    // ----------------------------------------
    // string str1;
    // cout << "Enter a word: ";
    // cin >> str1;
    // cout << "You entered: " << str1 << endl;

    // ----------------------------------------
    // Input using getline() — reads the entire line including spaces
    // ----------------------------------------
    string str2;
    cout << "Enter a full sentence: ";
    getline(cin, str2);  // Safer and preferred for full-line input
    cout << "You entered: " << str2 << endl;

    return 0;
}
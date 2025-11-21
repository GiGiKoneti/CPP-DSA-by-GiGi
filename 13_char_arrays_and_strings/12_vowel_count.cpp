#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);  // Read the entire line including spaces

    // Initialize counters for each vowel
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;

    // Loop through each character in the string
    for (char ch : str) {
        // Check for lowercase vowels
        if (ch == 'a') countA++;
        else if (ch == 'e') countE++;
        else if (ch == 'i') countI++;
        else if (ch == 'o') countO++;
        else if (ch == 'u') countU++;
    }

    // Display the count of each vowel
    cout << "Vowel Counts (lowercase only):" << endl;
    cout << "a: " << countA << endl;
    cout << "e: " << countE << endl;
    cout << "i: " << countI << endl;
    cout << "o: " << countO << endl;
    cout << "u: " << countU << endl;

    // Total vowel count
    int total = countA + countE + countI + countO + countU;
    cout << "Total lowercase vowels: " << total << endl;

    return 0;
}
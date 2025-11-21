#include <iostream>
#include <cstring>  // For strlen
using namespace std;

int main() {
    // Character array without null-terminator — treated as garbage if printed as string
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << "arr (random characters, no null-terminator): " << arr << endl;

    // Character array with null-terminator — treated as valid C-style string
    char arr1[6] = {'c', 'o', 'd', 'e', '\0'};
    cout << "arr1 (null-terminated): " << arr1 << endl;

    // Integer array — prints memory address when passed to cout
    int arr3[3] = {1, 2, 3};
    cout << "arr3 (integer array address): " << arr3 << endl;

    // Proper null-terminated character array
    char arr4[4] = {'a', 'b', 'c', '\0'};
    cout << "arr4: " << arr4 << endl;

    // String literals and C-style strings
    char work[] = "GiGi";           // Auto size, null-terminated
    char work1[5] = "Majd";         // Fixed size, null-terminated
    char work2[] = {'a', 'b', 'c', '\0'}; // Manual initialization
    char work3[50] = {'a', 'b', 'c', '\0'}; // Manual with extra capacity

    cout << "Length of work: " << strlen(work) << endl;
    cout << "Length of work1: " << strlen(work1) << endl;

    // Word input using cin — stops at whitespace
    char word[30];
    cout << "\nEnter a single word: ";
    cin >> word;
    cout << "You entered: " << word << endl;
    cout << "Length: " << strlen(word) << endl;

    cin.ignore(); // Flush newline left in input buffer

    // Sentence input using cin.getline — accepts whitespace
    char sentence[30];
    cout << "\nEnter a sentence: ";
    cin.getline(sentence, 30);
    cout << "You entered: " << sentence << endl;
    cout << "First character: " << sentence[0] << endl;

    // Optional: using custom delimiter
    // cin.getline(sentence, 30, '*');

    return 0;
}
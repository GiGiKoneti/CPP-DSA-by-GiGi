// Find the largest word in a string.
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string str = "I love programming in C++";
    string word, largestWord = "";
    
    stringstream ss(str);

    while (ss >> word) {
        if (word.length() > largestWord.length()) {
            largestWord = word;
        }
    }

    cout << "Largest word: " << largestWord;
    
    return 0;
}
// Write a function to check if a string is a Palindrome.

# include <iostream>
using namespace std;

bool CheckPalindrome(string word) {
    int i = 0, j = word.length() - 1;

    while (i < j) {
        if (word[i] != word[j]) {
            return false;   // mismatch found
        }
        i++;
        j--;
    }
    return true; // all matched
}

int main(){
    string word = "hello";
    (CheckPalindrome(word))? cout<<"Palindrome" : cout<<"Not a Palindrome";
    cout<<endl;
    return 0;
}
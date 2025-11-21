// Check if two strings are anagrams.
# include <iostream>
# include<list>
using namespace std;

int main() {
    string word1="Hello",word2="olleH";
    std::list<char> charList1,charList2;
    for(char &c : word1){
        c = tolower(c);
        charList1.push_back(c);

    }
    for(char &c : word2){
        c = tolower(c);
        charList2.push_back(c);
    }
    charList1.sort();
    charList2.sort();
    (charList1==charList2)? cout<<"Anagrams" : cout<<"Not anagrams";
    cout<<endl;
    return 0;
    
}
// Check if string is palindrome.
# include<iostream>
# include <algorithm>
using namespace std;

int main(){
    string word="Gig";
    for(char &c : word)
        c = tolower(c);
    string s=word;
    reverse(word.begin(),word.end());
    cout<<word<<endl;
    (s==word)?cout<<true:cout<<false;
    cout<<endl;
    return 0;
}
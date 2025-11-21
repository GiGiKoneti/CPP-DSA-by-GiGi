// Reverse a string
# include<iostream>
# include <algorithm>
using namespace std;

int main(){
    string word="Hello";
    reverse(word.begin(),word.end());
    cout<<word<<endl;
    return 0;
}
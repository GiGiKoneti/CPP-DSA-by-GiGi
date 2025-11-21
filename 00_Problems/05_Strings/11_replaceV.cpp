// Replace all verbs with *
# include <iostream>
using namespace std;

int main () {
    string word = "Hello";
    for(char &c : word){
        c = tolower(c);
        c= (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')? '*':c;
        
    }
    cout<<word<<endl;
    return 0;
}
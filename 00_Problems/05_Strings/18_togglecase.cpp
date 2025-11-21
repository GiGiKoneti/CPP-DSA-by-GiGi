// Toggle case of each character.
# include<iostream>
using namespace std;

int main() {
    string word="HellO";
    for(char &c : word){
        if(c>='a'&&c<='z')
            c=toupper(c);
        else if(c>='A'&&c<='Z')
            c=tolower(c);
    }
    cout<<word<<endl;
    return 0;
}
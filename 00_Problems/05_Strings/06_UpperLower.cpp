// Convert to upper case and lower case.
# include <iostream>
using namespace std;

int main() {
    string word = "Hello";
    for(char &c : word){
        c = tolower(c);
        cout<<c;
    }
    cout<<endl;
    for(char &c : word){
        c = toupper(c);
        cout<<c;
    }
    cout<<endl;
    return 0;

}
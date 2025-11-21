// Input and display a string.
# include <iostream>
# include <string>
using namespace std;

int main() {
    string name = "Hello";
    string name2 = {'H','e','l','l','o','\0'};
    char name3[5];
    cout<<"Enter a word :";
    for(int i = 0;i<5;i++){
        cin>>name3[i];
        cout<<name[i];
    }
    cout<<endl;
    cout<<name<<" "<<name2<<endl;
    return 0;
}
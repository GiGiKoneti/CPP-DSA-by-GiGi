// Count vowels and consonants.

# include  <iostream>
# include <string>
using namespace std;

int main() {
    string word ;
    cout<<"Enter your string :";
    getline(cin,word);
    int Vcount=0,Ccount=0;
    for (char &c : word){
        c = tolower(c);
        if(c=='a'|| c=='e' || c=='i'  || c=='o'  || c=='u')
            Vcount++;
        else
            Ccount++;
    }
    cout<<"Number of Vowels :"<<Vcount<<endl<<"Number of Consonants :"<<Ccount<<endl;
    return 0;
}

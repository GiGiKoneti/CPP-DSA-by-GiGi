// Find out string length manually.

# include<iostream>
using namespace std;

int main(){
    string word="Hello there ";
    int i=0,count=0;
    while(word[i]!='\0'){
        count++;
        i++;

    }
    cout<<"Length:"<<count<<endl;
    return 0;
}
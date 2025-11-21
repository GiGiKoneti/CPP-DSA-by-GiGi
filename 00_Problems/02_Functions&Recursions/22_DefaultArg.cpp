// Create a function with default arguments to print patterns.
# include<iostream>
using namespace std;

void PrintPattern(char ch='*',int n = 5){
    for(int i = 0 ; i<n;i++){
        for(int i = 0 ; i<n;i++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    PrintPattern('#');
    PrintPattern('@',10);
    return 0;
}
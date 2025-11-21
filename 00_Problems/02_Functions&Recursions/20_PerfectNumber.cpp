// Implement a function to  check perfect Number.

# include <iostream>
using namespace std;

void Perfect(int n){
    if(n<=0){
        cout<<"Enter a Positive Integer : ";
    }
    else {
        int divisorsum=0;
        for (int i = 1;i<n;i++){
            if(n%i==0){
                divisorsum+=i;
            }
        }
        (n==divisorsum)? cout<<"Perfect Number" : cout<<"Not a Perfect Number";
        cout<<endl;
    }
}

int main() {
    int n = 6;
    Perfect(n);
}
//  Write a function to find factorial using the recursion.

# include <iostream>
using namespace std;

int factorial(int n){
    int fact;
    if(n<=1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    int n=4;
    int fact = factorial(n);
    cout<<fact<<endl;
    return 0;
}
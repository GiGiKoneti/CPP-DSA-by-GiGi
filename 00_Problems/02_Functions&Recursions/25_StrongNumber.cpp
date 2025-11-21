// Make a function that returns true if number is Strong.

# include <iostream>
using namespace std;

int factorial(int n){
    if(n){
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
}


bool Strong(int n){
    int temp = n;
    int sum =0;
    while(n){
        int b = n%10;
        sum += factorial(b);
        n=n/10;
    }
    if (sum==temp)
        return true;
    else 
        return false;
}

int main() {
    int n = 145;
    cout<<Strong(n)<<endl;
    return 0;
}

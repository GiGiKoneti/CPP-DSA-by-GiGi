// Reverse a Number — Reverse the digits of a given integer.

# include <iostream>
using namespace std;

int main () {
    int n = 1234567,remainder=1,rev=0;
    while(n){
        remainder = n%10;
        rev = rev*10 + remainder ;
        n = n/10;

    }
    cout<<"Reverse Number : "<<rev<<endl;
    return 0;
}
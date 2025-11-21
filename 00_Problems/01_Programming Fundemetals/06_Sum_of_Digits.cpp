// Sum of Digits — Given n, find sum of its digits without using string conversion.

# include <iostream>
using namespace std ;

int main() {
    int n=123;
    int remainder=1,sum=0;
    while(remainder){
        remainder = n%10;
        sum += remainder;
        n=n/10;

    }
    cout<<"Sum : "<<sum<<endl;
    return 0;
}
// Write a function to check if two numbers are Co - Prime.

# include <iostream>
# include<numeric>
using namespace std;

int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool CheckCoPrime(int a , int b){
    return calculateGCD(a,b)==1;
}

int main(){
    int a = 4,b = 9;
    cout<<CheckCoPrime(a,b)<<endl;
    return 0;
}
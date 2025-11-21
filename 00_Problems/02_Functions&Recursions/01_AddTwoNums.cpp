// Create a function to add two integers and return the sum.

#include <iostream>
using namespace std;

int Sum(int a,int b){
    return a+b;
}

int main() {
    int a = 1,b = 2;
    int sum = Sum(a,b);
    cout<<sum<<endl;
    return 0;
}
// Implement function to compute GCD using Euclid's Algorithm.

# include <iostream>
using namespace std;

int ComputeGCD(int a, int b){
    while(b!=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int a = 6 , b = 3;
    int GCD = ComputeGCD(a,b);
    cout<<GCD<<endl;
    return 0;
}
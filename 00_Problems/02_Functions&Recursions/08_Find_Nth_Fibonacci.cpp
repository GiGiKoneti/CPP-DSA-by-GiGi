// Implement a recursive function to finf the nth Fibonacci term.
# include <iostream>
using namespace std;

int FindNthFibonacci(int n){
    int term = 0;
    term = (n==1)? 0 : (n==2)? 1 : FindNthFibonacci(n-1)+FindNthFibonacci(n-2);
    return term;
    
}

int main(){
    int n = 4;
    int term = FindNthFibonacci(n);
    cout<<term<<endl;
    return 0;

}
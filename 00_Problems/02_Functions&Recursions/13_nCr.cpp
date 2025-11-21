// Write a function to find nCr.
# include <iostream>
using namespace std;

/*
int factorial(int n){
    int fact;
    if(n<=1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

float nCr(int n, int r){
    return (factorial(n))/(factorial(r)*factorial(n-r));
}
*/

long long NCR(int n , int r){
    long long res =1;
    for(int i=0;i<r;i++){
        res = res * (n-i);
        res = res / (i+1);    
    }
    return res;
}

int main(){
    int n = 6 , r = 2;
    cout<<NCR(n,r)<<endl;
    return 0;
}

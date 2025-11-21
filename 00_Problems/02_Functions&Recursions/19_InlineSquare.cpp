// Create a inline function for a sqaure of  a function.
# include<iostream>
using namespace std;

inline int Square(int n){
    return n*n;
}

int main(){
    int n = 2;
    int sqr = Square(n);
    cout<<sqr<<endl;
    return 0;
}
// Write a function that swaps two  numbers using pass by reference.

# include <iostream>
using namespace std;

void SwapTwoNums(int &a,int &b){ // if its just a,b ...function makes own copies of a,b but originals will remain the same ;
    int temp = a;
    a = b;
    b=temp;

}

int main() {
    int a = 1 , b = 2;
    SwapTwoNums(a,b);
    cout<<a<<","<<b<<endl;
    return 0;
}

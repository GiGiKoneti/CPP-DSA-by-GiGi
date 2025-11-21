// Factorial Calculator — Compute factorial using a loop.

# include <iostream>
using namespace std;

int main() {
    int num = 5,factorial=1;
    for(int i = 1;i<=num;i++){factorial*=i;}cout<<factorial<<endl;
    return 0;
}
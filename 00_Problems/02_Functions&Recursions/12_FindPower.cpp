// Write  a function to calculate power (a^b) using recursion.
# include <iostream>
using namespace std;

int Power(int a, int b) {
    if (b == 0) 
        return 1;          // base case

    return a * Power(a, b - 1);
}

int main(){
    int a = 3 , b = 3;
    int power = Power(a,b);
    cout<<power<<endl;
    return 0;

}
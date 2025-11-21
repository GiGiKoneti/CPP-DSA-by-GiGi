// Implement a function to calculate sum of digits recursively.
# include <iostream>
using namespace std;

int DigitSum(int n) {
    if (n == 0)
        return 0;

    int remainder = n % 10;
    return remainder + DigitSum(n / 10);
}

int main() {
    int n = 123;
    int sum = DigitSum(n);
    cout<<sum<<endl;
    return 0;
}
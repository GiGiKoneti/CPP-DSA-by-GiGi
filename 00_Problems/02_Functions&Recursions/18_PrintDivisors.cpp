// Write a function to print all divisors of a Number.
#include <iostream>
using namespace std;

void PrintDivisors(int n) {
    // First print divisors from 1 to sqrt(n)
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout<<endl;
    // Then print the larger divisors
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0 && i != n / i) {
            cout << n / i << " ";
        }
    }

    cout << endl;
}

int main() {
    PrintDivisors(36);
    return 0;
}
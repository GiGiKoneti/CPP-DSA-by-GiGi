// Implement a func to check if a number is prime .

#include <iostream>
using namespace std;

bool Prime(int n) {
    if (n <= 1)
        return false; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= n; i++) { // Because if n is divisible by any number greater than √n, then it must also be divisible by a smaller number less than √n.
        if (n % i == 0)
            return false; // found a divisor, not prime
    }
    return true; // no divisors found, number is prime
}

int main() {
    int num = 5;
    if (Prime(num))
        cout << "Prime" << endl;
    else
        cout << "Non-Prime" << endl;
}
// Create a function to check Armstrong Number .

#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int original = n;
    int digits = 0;

    // count digits
    int temp = n;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // compute sum of each digit^digits
    int sum = 0;
    temp = n;
    while (temp > 0) {
        int remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }

    return (sum == original);
}

int main() {
    int n = 153;
    if (isArmstrong(n))
        cout << "Armstrong Number";
    else
        cout << "Not an Armstrong Number";
}
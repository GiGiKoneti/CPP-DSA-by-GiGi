#include <iostream>
#include <climits> // For INT_MAX and INT_MIN

int divide(int dividend, int divisor) {
    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the sign of the result
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Work with positive values (use long to avoid overflow)
    long long a = std::llabs((long long)dividend);
    long long b = std::llabs((long long)divisor);

    long long quotient = 0;

    // Start from the highest bit and go down to 0
    for (int i = 31; i >= 0; i--) {
        // Check if divisor shifted by i fits into dividend
        if ((b << i) <= a) {
            a -= (b << i);        // Subtract the shifted divisor
            quotient += (1LL << i); // Add the power of two to quotient
        }
    }

    // Apply sign
    if (negative) quotient = -quotient;

    // Clamp result within 32-bit integer range
    if (quotient > INT_MAX) return INT_MAX;
    if (quotient < INT_MIN) return INT_MIN;

    return (int)quotient;
}

int main() {
    int dividend, divisor;
    std::cout << "Enter dividend: ";
    std::cin >> dividend;
    std::cout << "Enter divisor: ";
    std::cin >> divisor;

    int result = divide(dividend, divisor);
    std::cout << "Quotient: " << result << std::endl;

    return 0;
}
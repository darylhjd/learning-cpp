#include <iostream>

// Write a recursive function that returns
// the factorial of the input.
int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}

// Write a recursive function that takes an integer as input
// and returns the sum of each individual digit in the integer.
// Assume all input values are positive.
int digit_sum(int n) {
    if (n == 0) {
        return 0;
    }

    return (n % 10) + digit_sum(n / 10);
}

// Write a recursive function that prints out the binary
// representation for that number.
void binary_rep(int n) {
    if (n == 0) {
        return;
    }
    // Print out the rest of the digits
    binary_rep(n >> 1);
    std::cout << (n % 2);
}

void binary_neg_pos(unsigned int n) {
    // The termination case will be if n > 1.
    if (n > 1) {
        binary_neg_pos(n >> 1);
    }
    std::cout << n % 2;
}

int main() {
    std::cout << factorial(9) << '\n';
    std::cout << digit_sum(93427) << '\n';
    binary_rep(9); std::cout << '\n';
    binary_neg_pos(-15); std::cout << '\n';
}
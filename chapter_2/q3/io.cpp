#include "io.h"
#include <iostream>

int readNumber() {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

void writeAnswer(int ans) {
    std::cout << "The answer is " << ans << '\n';
}
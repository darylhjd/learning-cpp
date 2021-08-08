#include <iostream>

void print_binary(int x) {
    for (int i{128}; i > 0; i /= 2) {
        if (x >= i) {
            std::cout << '1';
            x -= i;
        } else {
            std::cout << '0';
        }

        if (i == 16) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    std::cout << "Enter a number between 0 and 255: ";
    int x{};
    std::cin >> x;

    print_binary(x);
}
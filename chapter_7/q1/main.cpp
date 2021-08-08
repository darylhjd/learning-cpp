#include "constants.h"
#include <iostream>

double calculate_height(double initial_height, int seconds) {
    double new_height{initial_height - constants::GRAVITY * seconds * seconds / 2};
    return new_height;
}

int main() {
    std::cout << "Enter the initial height of the tower: ";
    double height{};
    std::cin >> height;

    double new_height{};
    for (int s{0}; (new_height = calculate_height(height, s)) >= 0.0; ++s) {
        std::cout << new_height << " at " << s << " seconds.\n";
    }
    return 0;
}

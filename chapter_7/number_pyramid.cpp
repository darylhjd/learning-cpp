#include <iostream>

int main() {
    int count{1};
    while (count < 6) {
        // Print the spaces
        int spaces{5-count};
        while (spaces) {
            std::cout << "  ";
            --spaces;
        }
        // Print the numbers
        int inner{count};
        while (inner > 0) {
            std::cout << inner << ' ';
            --inner;
        }
        std::cout << '\n';
        ++count;
    }
    return 0;
}
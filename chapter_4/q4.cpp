#include <iostream>

constexpr double GRAVITY{9.8};

double calculateHeight(double start, int second) {
    return start - GRAVITY * second * second / 2;
}

int main() {
    std::cout << "Etner the height of the tower in meters: ";
    double height{};
    std::cin >> height;

    double curr_height{};
    for (int i{0}; i < 6; i++) {
        curr_height = calculateHeight(height, i);
        if (curr_height > 0) {
            std::cout << "At " << i << " seconds, the ball is at height: " 
            << curr_height << " meters\n";
        } else {
            std::cout << "At " << i << " seconds, the ball is on the ground.\n";
            break;
        }
    }
    return 0;
}

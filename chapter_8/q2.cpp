#include <iostream>

namespace constants {
    inline constexpr double pi {3.14159};
}

using degrees_t = double;
using radians_t = double;

radians_t convert_to_radians(degrees_t degrees) {
    return degrees * constants::pi / 180;
}

int main() {
    std::cout << "Enter a number of degrees: ";
    degrees_t degrees{};
    std::cin >> degrees;

    radians_t radians{convert_to_radians(degrees)};
    std::cout << degrees << " degree is " << radians << " radians.\n";
    return 0;
}
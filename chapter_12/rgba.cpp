#include <cstdint>
#include <iostream>

class RGBA {
    using c_int = std::uint_fast8_t;
    c_int red{}, green{}, blue{}, alpha{};

public:
    RGBA(c_int red=0, c_int green=0, c_int blue=0, c_int alpha=255)
        : red{red}, green{green}, blue{blue}, alpha{alpha} 
    {}

    void print() {
        std::cout << "r=" << static_cast<int>(red) << ' ';
        std::cout << "g=" << static_cast<int>(green) << ' ';
        std::cout << "b=" << static_cast<int>(blue) << ' ';
        std::cout << "a=" << static_cast<int>(alpha) << ' ';
        std::cout << '\n';
    }
};

int main() {
    RGBA teal{ 0, 127, 127 };
	teal.print();
 
	return 0;
}
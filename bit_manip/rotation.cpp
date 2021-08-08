#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits) {
    // Test the last bit
    bool msb_set{bits.test(3)};

    // Rotate the bits left.
    bits <<= 1;

    if (msb_set) {
        bits.set(0);
    }
    return bits;
}

std::bitset<4> rotl(std::bitset<4> bits) {
    // Without using any test/set functions.
    return (bits << 1) | (bits >> 3);
}

int main() {
    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << '\n';
    return 0;
}
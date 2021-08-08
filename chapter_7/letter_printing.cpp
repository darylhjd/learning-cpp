#include <iostream>


int main() {
    for (char a = 'a'; a <= 'z'; ++a) {
        std::cout << a << ": " << static_cast<int>(a) << '\n';
    }
    return 0;
}
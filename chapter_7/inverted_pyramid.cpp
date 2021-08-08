#include <iostream>

int main() {
    int count{5};
    while (count > 0) {
        int i{count};
        while (i > 0) {
            std::cout << i << ' ';
            --i;
        }
        std::cout << '\n';
        --count;
    }
    return 0;
}
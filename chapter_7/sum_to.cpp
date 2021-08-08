#include <iostream>

int sum_to(int x) {
    int sum{0};
    for (; x > 0; --x) {
        sum += x;
    }
    return sum;
}

int main() {
    std::cout << sum_to(5) << '\n';
}
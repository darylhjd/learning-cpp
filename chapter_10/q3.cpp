#include <iostream>

void swap(int& one, int& two) {
    int temp{one};
    one = two;
    two = temp;
}

int main() {
    int a{1};
    int b{2};
    std::cout << a << b << '\n';
    swap(a, b);
    std::cout << a << b << '\n';
}
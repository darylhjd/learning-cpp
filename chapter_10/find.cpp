#include <iostream>
#include <iterator>

int* find(int* begin, int* end, int target) {
    for (; begin != end; ++begin) {
        if (*begin == target) {
            return begin;
        }
    }
    return end;
}

int main() {
    int arr[]{2, 5, 4, 10, 8, 20, 16, 40};

    // Search for the fist element with value 20.
    int* found{find(std::begin(arr), std::end(arr), 20)};

    // Print the element if it is found
    if (found != std::end(arr)) {
        std::cout << *found << '\n';
    }
    return 0;
}
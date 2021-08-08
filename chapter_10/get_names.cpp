#include <iostream>
#include <string>
#include <algorithm>

void getNames(std::string* names, int size) {
    for (int i{0}; i < size; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }
    std::cout << '\n';
}

int main() {
    std::cout << "How many names would you like to enter? ";
    int len{};
    std::cin >> len;

    // Create dynamic array to store the names.
    std::string* names{new std::string[len]};
    getNames(names, len);

    std::sort(names, names + len);

    std::cout << "Here is your sorted list:\n";
    for (int i{0}; i < len; ++i) {
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
    }

    // Remember to de-allocate memory for the name list.
    delete[] names;
    return 0;
}
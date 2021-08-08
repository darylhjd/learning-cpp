#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // Cast one operand to double so result is a double.
    std::cout << "You've lived " << static_cast<double>(age) / name.length() 
    << " years for each letter in your name.";
    return 0;
}
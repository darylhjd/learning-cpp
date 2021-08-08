#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string_view names[]{"Alex", "Betty", "Caroline", "Dave",
                        "Emily", "Fred", "Greg", "Holly"};
    
    std::cout << "Enter a name: ";
    std::string f_name{};
    std::getline(std::cin >> std::ws, f_name);

    for (auto& name: names) {
        if (name == f_name) {
            std::cout << f_name << " was found.\n";
            return 0;
        }
    }
    std::cout << f_name << " was not found.\n";
}
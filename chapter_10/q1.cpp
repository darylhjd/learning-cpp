#include <array>
#include <cstddef>
#include <numeric>
#include <iostream>

enum Items {
    health_potion,
    torches,
    arrows,
    max_items,
};

using inventory_t = std::array<int, Items::max_items>;

int count_total_items(const inventory_t& inventory) {
    return std::accumulate(inventory.begin(), inventory.end(), 0);
}

int main() {
    inventory_t inventory{2, 5, 10};
    std::cout << "There are " << count_total_items(inventory) 
    << " total items, with " << inventory[Items::torches] << " torches.\n";
}
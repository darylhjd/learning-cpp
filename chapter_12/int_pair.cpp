#include <iostream>

class IntPair {
public:
    int x{};
    int y{};

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void print() {
        std::cout << "Pair(" << this->x << ", " << this->y << ")\n";
    }
};

int main() {
    IntPair p1;
    p1.set(1, 1);

    IntPair p2{2, 2};

    p1.print();
    p2.print();
    
    return 0;
}
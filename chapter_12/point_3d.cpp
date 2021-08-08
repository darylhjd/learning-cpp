#include <iostream>

class Point3D {
    int x{};
    int y{};
    int z{};

public:
    void set_values(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print() {
        std::cout << '<' << this->x << ", " << this->y << ", " << this->z << ">\n";
    }

    bool is_equal(const Point3D& other) {
        return this->x == other.x && this->y == other.y && this->z == other.z;
    }
};

int main() {
    Point3D point;
    point.set_values(1, 2, 3);

    point.print();
    std::cout << '\n';

    Point3D point1;
    point1.set_values(1, 2, 3);
 
    Point3D point2;
    point2.set_values(1, 2, 3);
 
    if (point1.is_equal(point2)) {
        std::cout << "point1 and point2 are equal\n";
    } else {
        std::cout << "point1 and point2 are not equal\n";
    }
 
    Point3D point3;
    point3.set_values(3, 4, 5);
 
    if (point1.is_equal(point3)) {
        std::cout << "point1 and point3 are equal\n";
    } else {
        std::cout << "point1 and point3 are not equal\n";
    }
 
    return 0;
}
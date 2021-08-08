#include <string>
#include <iostream>

class Ball {
    double radius{};
    std::string color{};

public:
    Ball() {
        radius = 10.0;
        color = "black";
    }

    Ball(const std::string& color) {
        radius = 10.0;
        this->color = color;
    }

    Ball(double radius) {
        this->radius = radius;
        color = "black";
    }

    Ball(const std::string& color, double radius) {
        this->color = color;
        this->radius = radius;
    }

    // Default arguments
    Ball(const std::string& color="black", double radius=10.0) {
        this->color = color;
        this->radius = radius;
    }

    void print() {
        std::cout << "color: " << color << ", radius: " << radius << '\n';
    }
};

int main() {
	Ball def{};
	def.print();
 
	Ball blue{ "blue" };
	blue.print();
	
	Ball twenty{ 20.0 };
	twenty.print();
	
	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();
 
	return 0;
}
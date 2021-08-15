#include <iostream>
#include <string>

class Fruit {
    std::string name{};
    std::string color{};

public:
    Fruit(const std::string& name, const std::string& color)
        : name{name}, color{color}
    {}

    const std::string& get_name() const {
        return name;
    }

    const std::string& get_color() const {
        return color;
    }
};

class Apple : public Fruit {
    double fiber{};

public:
    Apple(const std::string& name, const std::string& color, double fiber)
        : Fruit{name, color}, fiber{fiber}
    {}

    friend std::ostream& operator<<(std::ostream& out, const Apple& a) {
        out << "Apple(" << a.get_name() << ", " << a.get_color()
        << ", " << a.fiber << ')';
    }
};

class Banana : public Fruit {
public:
    Banana(const std::string& name, const std::string& color) 
        : Fruit{name, color}
    {}

    friend std::ostream& operator<<(std::ostream& out, const Banana& b) {
        out << "Banana(" << b.get_name() << ", " << b.get_color() << ')';
    }
};

int main() {
    const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';
 
	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';
 
	return 0;
}
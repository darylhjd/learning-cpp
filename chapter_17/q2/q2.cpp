#include <iostream>
#include <string>

class Fruit {
    std::string name{};
    std::string color{};

public:
    Fruit(const std::string& name, const std::string& color)
        : name{name}, color{color}
    {}

    const std::string& getName() {
        return name;
    }

    const std::string& getColor() {
        return color;
    }
};

class Apple : public Fruit {
protected:
    Apple(const std::string& name, const std::string& color)
        : Fruit{name, color}
    {}

public:
    Apple(const std::string& color="red")
        : Fruit{"apple", color}
    {}
};

class GrannySmith : public Apple {
public:
    GrannySmith(const std::string& color="green")
        : Apple{"granny smith", color}
    {}
};

class Banana : public Fruit {
public:
    Banana(const std::string& color="yellow")
        : Fruit{"banana", color}
    {}
};

int main() {
	Apple a{ "red" };
	Banana b;
	GrannySmith c;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
 
	return 0;
}
#include <iostream>

double getDouble() {
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    return x;
}

void doOperation(double x, double y) {
    std::cout << "Enter one of the following: "
    "+, -, * or /: ";
    char op{};
    std::cin >> op;

    double res{};
    switch (op) {
    case '+':
        res = x + y;
        break;
    case '-':
        res = x - y;
        break;
    case '*':
        res = x * y;
        break;
    case '/':
        res = x / y;
        break;
    default:
        return;
    }
    std::cout << x << ' ' << op << ' ' << y << " is " << res << '\n';
}

int main() {
    // Get two floating point numbers (use doubles)
    double x{getDouble()};
    double y(getDouble());

    doOperation(x, y);
    return 0;
}
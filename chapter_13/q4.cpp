#include <iostream>
#include <cstddef>
#include <cmath>

class FixedPoint2 {
    using i = std::int_least16_t;
    using f = std::int_least8_t;
    // Create variables to hold the integer and floating parts.
    i integer{0};
    f floating{0};

public:
    // Normal constructor
    FixedPoint2(i integer=0, f floating=0)
        : integer{integer}, floating{floating}
    {
        if (integer < 0 || floating < 0) {
            if (integer > 0) {
                this->integer = -integer;
            }
            if (floating > 0) {
                this->floating = -floating;
            }
        }
    }
    // Constructor with double
    FixedPoint2(double d=0.0) 
        : integer{static_cast<i>(std::round(d))}, 
          floating{static_cast<f>(std::round(d*100) - integer * 100)}
    {}

    // Overload casting
    operator double() const {
        return integer + floating / 100.0;
    }

    // Overload equality
    friend bool operator==(const FixedPoint2& p1, const FixedPoint2& p2) {
        return p1.integer == p2.integer && p1.floating == p2.floating;
    }

    // Overload unary -
    FixedPoint2 operator-() const {
        return {static_cast<i>(-integer), static_cast<f>(-floating)};
    }

    // Overload binary + 
    friend FixedPoint2 operator+(const FixedPoint2& p1, const FixedPoint2& p2) {
        return {static_cast<double>(p1) + static_cast<double>(p2)};
    }

    // Overload printing
    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& p) {
        out << static_cast<double>(p);
    }

    // Overload input
    friend std::istream& operator>>(std::istream& in, FixedPoint2& p) {
        double d{};
        in >> d;
        p = d;
        return in;
    }
};

void testAddition() {
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}
 
int main() {
	testAddition();
 
	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';
 
	std::cout << -a << '\n';
 
	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	
	std::cout << "You entered: " << a << '\n';
 
	return 0;
}
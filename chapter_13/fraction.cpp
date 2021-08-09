#include <iostream>
#include <numeric>

class Fraction {
    int numerator{0};
    int denominator{1};

public:
    Fraction(int num, int denom=1)
        : numerator{num}, denominator{denom}
    {
        reduce();
    }

    void print() const {
        std::cout << numerator << '/' << denominator << '\n';
    }

    Fraction reduce() {
        // Find the GCD of numerator and denominator
        int gcd{std::gcd(numerator, denominator)};
        // Divide num and denom with gcd.
        numerator /= gcd;
        denominator /= gcd;
    }

    friend Fraction operator*(const Fraction& one, const Fraction& two);
    friend Fraction operator*(const Fraction& one, int two);
    friend Fraction operator*(int one, const Fraction& two);
};

Fraction operator*(const Fraction& one, const Fraction& two) {
    return {
        one.numerator * two.numerator, one.denominator * two.denominator
    };
}

Fraction operator*(const Fraction& one, int two) {
    return {
        one.numerator * two, one.denominator
    };
}

Fraction operator*(int one, const Fraction& two) {
    return two * one;
}

int main() {
	Fraction f1{ 2, 5 };
	f1.print();
 
	Fraction f2{ 3, 8 };
	f2.print();
 
	Fraction f3{ f1 * f2 };
	f3.print();
 
	Fraction f4{ f1 * 2 };
	f4.print();
 
	Fraction f5{ 2 * f2 };
	f5.print();
 
	Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
	f6.print();
 
	Fraction f7{ 0, 6 };
	f7.print();
 
	return 0;
}
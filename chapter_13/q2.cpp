#include <iostream>
#include <cstddef>

class Average {
    using sum_type = std::int_least32_t;
    using num_type = std::int_least8_t;

    sum_type sum{0};
    num_type num{0};

public:
    // Normal constructor
    Average(sum_type s=0, num_type n=0)
        : sum{s}, num{n}
    {}
    // Copy constructor.
    // No need for any special construction
    // since the values are all primitive.
    Average(const Average& avg)
        : sum{avg.sum}, num{avg.num}
    {}

    // Overloaded operator.
    Average& operator+=(int n) {
        sum += n;
        ++num;
        return *this;
    };

    // Overloaded operator.
    friend std::ostream& operator<<(std::ostream& cout, const Average& avg);
};

std::ostream& operator<<(std::ostream& cout, const Average& avg) {
    cout << static_cast<double>(avg.sum) / avg.num;
    return cout;
}

int main() {
    Average avg{};
	
	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4
	
	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6
 
	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12
 
	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5
 
	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7
 
	Average copy{ avg };
	std::cout << copy << '\n';
 
	return 0;
}
#include <iostream>
#include <string>
#include <cassert>

class StringClass {
    std::string string{};

public:
    StringClass(const std::string& string={})
        : string{string}
    {}

    std::string operator()(int start, int length) {
        // Make sure that the start is not less than 0.
        assert(start >= 0);
        // Make sure that start and length is in range.
        assert(start + length <= static_cast<int>(string.length()));

        std::string res{};
        for (int count{0}; count < length; ++count) {
            res += string[static_cast<std::string::size_type>(start+count)];
        }
        return res;
    }
};


int main() {
    StringClass string{"Hello, world!"};
    std::cout << string(7, 5) << '\n';
    return 0;
}
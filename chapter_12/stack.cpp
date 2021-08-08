#include <iostream>
#include <array>
#include <cassert>

class Stack {
    using stack_t = std::array<int, 10>;
    using size_type = stack_t::size_type;
    stack_t stack{};
    size_type size{0};

public:
    void reset() {
        this->size = 0;
    }

    bool push(int n) {
        if (size == this->stack.size()) {
            return false;
        }
        this->stack[size] = n;
        ++size;
        return true;
    }

    int pop() {
        assert(this->size != 0 && "cannot pop from empty stack");
        --(this->size);
        return this->stack[this->size];
    }

    void print() {
        std::cout << "( ";
        for (int i{0}; i < this->size; ++i) {
            std::cout << this->stack[i] << ' ';
        }
        std::cout << ")\n";
    }
};

int main() {
    Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
 
	stack.print();
 
	return 0;
}

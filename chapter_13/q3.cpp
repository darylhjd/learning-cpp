#include <iostream>
#include <cassert>

class IntArray {
    int* array{nullptr};
    int size{0};

public:
    // Normal Constructor
    IntArray(int size)
        : size{size} {
        assert(size > 0 && "length of array cannot be less than 0.");
        array = new int[size];
    }

    // Copy constructor 
    IntArray(const IntArray& a) {
        // Allocate the required new array
        array = new int[a.size];
        // Copy elements of the array also.
        for (int i{0}; i < a.size; ++i) {
            array[i] = a.array[i];
        }
    }

    // Destructor
    ~IntArray() {
        delete[] array;
    }

    // Overloaded operators

    // Overload printing
    friend std::ostream& operator<<(std::ostream& out, const IntArray& a);

    // Overload subscripting
    int& operator[](int index) {
        // Check that the index is less than the length 
        assert(index < size && index >= 0 && "index out of bounds");

        return array[index];
    }

    // Overload assignment operator
    IntArray& operator=(const IntArray& a) {
        if (this == &a) {
            return *this;
        }

        // De-allocate if the array was allocated
        delete[] array;

        // Then create a new array and copy elements over.
        array = new int[a.size];
        size = a.size;
        for (int i{0}; i < size; ++i) {
            array[i] = a.array[i];
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const IntArray& a) {
    // Print all the elements in the array.
    for (int i{0}; i < a.size; ++i) {
        out << a.array[i] << ' ';
    }
    return out;
}

IntArray fillArray() {
	IntArray a(5);
 
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
 
	return a;
}
 
int main() {
	IntArray a{ fillArray() };
	std::cout << a << '\n';
 
	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;
 
	IntArray b(1);
	b = a;
 
	std::cout << b << '\n';
 
	return 0;
}
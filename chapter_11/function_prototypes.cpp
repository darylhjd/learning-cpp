#include <utility>
#include <vector>
#include <cstddef>
#include <string>

// A function that takes an integer parameter and 
// returns the sum of all the numbers between 1 and the input number.
int sumTo(int x);

// A function that takes an Employee struct as input.
struct Employee{};
void printEmployeeName(const Employee& emp);

// A function  that takes two integers as input and returns back to the caller 
// the smaller and larger number in a std::pair.
std::pair<int ,int> minmax(int a, int b);

// A function that takes an integer array (as a std::vector), 
// and returns the index of the largest element in the array.
std::size_t getIndexOfLargestValue(const std::vector<int>& vector);

// A function named getElement() that takes an array of std::string (as a std::vector) 
// and an index and returns the array element at that index (not a copy). 
// Assume the index is valid, and the return value is const.
const std::string& getElement(const std::vector<std::string>& strings, std::size_t index);
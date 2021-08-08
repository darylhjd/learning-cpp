#include <vector>

// A function that takes two doubles and
// returns the larger of the two.
double max(double a, double b);

// A function that takes a dynamically allocated array
// of integeres and returns the largest number
// in such as way that the caller can change the value
// of the element returned.
int& get_largest_element(int* array, int size);
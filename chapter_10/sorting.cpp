#include <iostream>
#include <iterator>

void selection_sort(int array[], int size, bool asc=true) {
    // We use a selection sort here.
    for (int i{0}; i < size-1; ++i){
        int swap{i};
        // Inner for loop to find the smallest element.
        for (int j{swap}; j < size; ++j) {
            if (asc && (array[j] < array[swap])) {
                swap = j;
            } else if (!asc && (array[j] > array[swap])) {
                swap = j;
            }
        }
        // Swap the elements
        int temp{array[i]};
        array[i] = array[swap];
        array[swap] = temp;
    }
}

void bubble_sort(int array[], int size) {
    for (int max_offset{1}; max_offset < size; ++max_offset) {
        bool swapped{false};
        for (int i{0}; i < size-max_offset; ++i) {
            if (array[i] > array[i+1]) {
                swapped = true;
                int temp(array[i]);
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        if (!swapped) {
            std::cout << "Early termination on iteration " << max_offset << '\n';
            break;
        }
    }
}

void print_array(int array[], int size) {
    for (int i{0}; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    int array[]{5, 3, 2, 9, 7, 1, 5, 4};
    int size{std::size(array)};
    std::cout << "Before sorting:\n";
    print_array(array, size);

    bubble_sort(array, size);

    std::cout << "After sorting:\n";
    print_array(array, size);
}
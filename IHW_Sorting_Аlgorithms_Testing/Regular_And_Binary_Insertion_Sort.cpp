#include <vector>
#include "Regular_And_Binary_Insertion_Sort.h"

// Function to sort an array using
// insertion sort
void regularInsertionSort(std::vector<int> &arr) {
    auto begin = arr.begin();
    auto end = arr.end();
    for (auto i = begin + 1; i != end; ++i) {
        for (auto j = i; (j != begin) && (*j < *(j - 1)); --j) {
            std::iter_swap(j - 1, j);
        }
    }
}

// Function to sort an array a[] of size 'n'
void binaryInsertionSort(std::vector<int>& arr) {
    auto begin = arr.begin();
    auto end = arr.end();
    for (auto it = begin; it != end; ++it) {
        auto begin_rotate = std::upper_bound(begin, it, *it);
        std::rotate(begin_rotate, it, std::next(it));
    }
}
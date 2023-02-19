#include "Bubble_Sort.h"
#include "iostream"
#include <vector>

// A function to implement bubble sort
void bubbleSort(std::vector<int>& arr) {
    int i, j;
    int n = static_cast<int>(arr.size());
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void IversonOneBubbleSort(std::vector<int>& arr) {
    int i = 0;
    int n = static_cast<int>(arr.size());
    bool t = true;
    while (t) {
        t = false;
        for (int k = 0; k < n - i - 1; ++k) {
            if (arr[k] > arr[k + 1]) {
                std::swap(arr[k], arr[k + 1]);
                t = true;
            }
        }
        i++;
    }
}

void IversonTwoBubbleSort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int help_bound = 0;
    int upper_bound = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < upper_bound; j++)
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                help_bound = j;
            }
        if (help_bound != 0) {
            upper_bound = help_bound;
        }
    }
}
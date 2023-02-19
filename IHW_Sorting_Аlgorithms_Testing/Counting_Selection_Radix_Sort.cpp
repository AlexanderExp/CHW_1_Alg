// C++ implementation of Radix Sort

#include <iostream>
#include "vector"
#include "Counting_Selection_Radix_Sort.h"

// A utility function to get maximum value in arr[]
int getMax(std::vector<int>& arr, int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSortRadix(std::vector<int>& arr, int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
}

// The main function that sort
// the given string arr[] in
// alphabetical order
void countSortStable(std::vector<int>& numbers_to_sort) {
    std::vector<int> sorted_numbers;
    sorted_numbers = numbers_to_sort;
    int n = static_cast<int>(numbers_to_sort.size());

    int min = numbers_to_sort[0], max = numbers_to_sort[0];
    for (int i = 0; i < n; ++i) {
        if (numbers_to_sort[i] < min) {
            min = numbers_to_sort[i];
        }
        if (numbers_to_sort[i] > max) {
            max = numbers_to_sort[i];
        }
    }
    int size_count = max - min + 1;
    int count[size_count];
    for (int i = 0; i < size_count; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        count[numbers_to_sort[i] - min]++;
    }

    for (int i = 1; i < size_count; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        sorted_numbers[count[numbers_to_sort[i] - min] - 1] = numbers_to_sort[i];
        count[numbers_to_sort[i] - min]--;
    }
    numbers_to_sort = sorted_numbers;
    sorted_numbers.clear();
    sorted_numbers.shrink_to_fit();
}

void selectionSort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            std::swap(arr[min_idx], arr[i]);
    }
}
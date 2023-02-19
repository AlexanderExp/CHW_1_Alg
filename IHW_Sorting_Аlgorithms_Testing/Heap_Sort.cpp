#include "Heap_Sort.h"

void heapify(std::vector<int> &numbers, size_t n, size_t i) {
    size_t left_child = 2 * i + 1;
    size_t right_child = 2 * i + 2;
    size_t largest_child = i;
    int temp;
    if (left_child < n && numbers[left_child] > numbers[largest_child]) {
        largest_child = left_child;
    }
    if (right_child < n && numbers[right_child] > numbers[largest_child]) {
        largest_child = right_child;
    }
    if (largest_child != i) {
        temp = numbers[i];
        numbers[i] = numbers[largest_child];
        numbers[largest_child] = temp;

        heapify(numbers, n, largest_child);
    }
}

void heapSort(std::vector<int> &numbers) {
    int n = static_cast<int>(numbers.size());
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(numbers, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(numbers[0], numbers[i]);
        heapify(numbers, i, 0);
    }
}
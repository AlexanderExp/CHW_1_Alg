#include "Quick_Sort.h"

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return (i + 1);
}

void actualQuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        actualQuickSort(arr, low, pi - 1);
        actualQuickSort(arr, pi + 1, high);
    }
}

void quickSort(std::vector<int>& arr) {
    actualQuickSort(arr, 0, static_cast<int>(arr.size() - 1));
}
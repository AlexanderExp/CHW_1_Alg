#include "Merge_Sort.h"

void merge(int begin, int middle, int end, std::vector<int> &array, std::vector<int> &help_array) {
    int b1 = begin;
    int b2 = 0;
    int m = middle + 1;

    while (b1 <= middle && m <= end) {
        if (array[b1] < array[m]) {
            help_array[b2++] = array[b1++];
        } else {
            help_array[b2++] = array[m++];
        }
    }

    for (; b1 <= middle; ++b1) {
        help_array[b2++] = array[b1];
    }

    for (; m <= end; ++m) {
        help_array[b2++] = array[m];
    }

    for (auto i = begin; i <= end; ++i) {
        array[i] = help_array[i - begin];
    }
}

void mergeSort(int begin, int end, std::vector<int> &array, std::vector<int> &help_array) {
    if (begin >= end) {
        return;
    } else {
        int middle = begin + (end - begin) / 2;
        mergeSort(begin, middle, array, help_array);
        mergeSort(middle + 1, end, array, help_array);
        merge(begin, middle, end, array, help_array);
    }
}

void mergeSort(std::vector<int> &array) {
    std::vector<int> help_array(array.size());
    mergeSort(0, static_cast<int>(array.size() - 1), array, help_array);
}
#include "Shell_Sort_Shell_Ciura.h"

void shellSortShellSequence(std::vector<int> &array) {
    int n = static_cast<int>(array.size());
    for (int step = n / 2; step > 0; step /= 2) {
        for (int i = step; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= step && array[j - step] > temp; j -= step) {
                array[j] = array[j - step];
            }
            array[j] = temp;
        }
    }
}

void shellSortCiuraSequence(std::vector<int> &array) {
    int n = static_cast<int>(array.size());
    std::vector<int> ciura_sequence = {-1, 1, 4, 10, 23, 57, 132, 301, 701, 1750};
    auto bound = std::lower_bound(ciura_sequence.begin(), ciura_sequence.end(), n - 1);
    for (auto step = bound; step != ciura_sequence.begin(); --step) {
        for (int i = *step; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= *step && array[j - *step] > temp; j -= *step) {
                array[j] = array[j - *step];
            }
            array[j] = temp;
        }
    }
}

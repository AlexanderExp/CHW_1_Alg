#include "Tester.h"

void chooseCorrectSortingAlgorithmAndRunIt(std::vector<int> &arr, std::vector<long long>& results, const std::string& sort_type) {
    if (sort_type == "Bubble Sort") {
        auto begin = std::chrono::steady_clock::now();
        bubbleSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Bubble Sort with 1 Iverson condition") {
        auto begin = std::chrono::steady_clock::now();
        IversonOneBubbleSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Bubble Sort with 2 Iverson condition") {
        auto begin = std::chrono::steady_clock::now();
        IversonTwoBubbleSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Counting Sort") {
        auto begin = std::chrono::steady_clock::now();
        countSortStable(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Selection Sort") {
        auto begin = std::chrono::steady_clock::now();
        selectionSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Radix Sort") {
        auto begin = std::chrono::steady_clock::now();
        radixSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Heap Sort") {
        auto begin = std::chrono::steady_clock::now();
        heapSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Merge Sort") {
        auto begin = std::chrono::steady_clock::now();
        mergeSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Quick Sort") {
        auto begin = std::chrono::steady_clock::now();
        quickSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Regular Insertion Sort") {
        auto begin = std::chrono::steady_clock::now();
        regularInsertionSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Binary Insertion Sort") {
        auto begin = std::chrono::steady_clock::now();
        binaryInsertionSort(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Shell Sort on Shell Sequence") {
        auto begin = std::chrono::steady_clock::now();
        shellSortShellSequence(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    } else if (sort_type == "Shell Sort Ciura Sequence") {
        auto begin = std::chrono::steady_clock::now();
        shellSortCiuraSequence(arr);
        auto end = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        results.push_back(res);
    }
}

void ultimateTester(std::vector<int> const &arr, std::ofstream &file_output, const std::string& sort_type) {
    std::vector<int> inner_arr;
    std::vector<long long> results;
    for (int j = 0; j < 30; ++j) {
        std::copy(arr.begin(), arr.end(), back_inserter(inner_arr));
        chooseCorrectSortingAlgorithmAndRunIt(inner_arr, results, sort_type);
        inner_arr.clear();
        inner_arr.shrink_to_fit();
    }
    file_output << std::fixed << static_cast<int>(getAverage(results));
    file_output << ",";
    results.clear();
    results.shrink_to_fit();
}
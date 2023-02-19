#ifndef IHW_SORTING_LGORITHMS_TESTING_ARRAY_WORKER_H
#define IHW_SORTING_LGORITHMS_TESTING_ARRAY_WORKER_H
#include "vector"
#include "iostream"
#include <numeric>

void printArray(std::vector<int> &array);

void randomVectorGeneratorEasy(std::vector<int> &arr, int n);

void randomVectorGeneratorHardcore(std::vector<int> &arr, int n);

void descendingOrderVectorGenerator(std::vector<int> &arr, int n);

void nearlySortedVectorGenerator(std::vector<int> &arr, int n);

double getAverage(std::vector<long long> const& v);

#endif  // IHW_SORTING_LGORITHMS_TESTING_ARRAY_WORKER_H

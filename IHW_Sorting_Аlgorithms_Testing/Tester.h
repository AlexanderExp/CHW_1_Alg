#ifndef IHW_SORTING_LGORITHMS_TESTING_TESTER_H
#define IHW_SORTING_LGORITHMS_TESTING_TESTER_H
#include <iostream>
#include "Heap_Sort.h"
#include "Counting_Selection_Radix_Sort.h"
#include "Shell_Sort_Shell_Ciura.h"
#include "Bubble_Sort.h"
#include "Quick_Sort.h"
#include "Regular_And_Binary_Insertion_Sort.h"
#include "Merge_Sort.h"
#include "Array_Worker.h"
#include <ctime>
#include <chrono>
#include <fstream>

void ultimateTester(std::vector<int> const &arr, std::ofstream &file_output, const std::string& sort_type);
void testBubbleSortIversonOne(std::vector<int> const &arr, std::ofstream &file_output);
void testBubbleSortIversonTwo(std::vector<int> const &arr, std::ofstream &file_output);
void testCountingSort(std::vector<int> const &arr, std::ofstream &file_output);
void testSelectionSort(std::vector<int> const &arr, std::ofstream &file_output);
void testRadixSort(std::vector<int> const &arr, std::ofstream &file_output);
void testHeapSort(std::vector<int> const &arr, std::ofstream &file_output);
void testMergeSort(std::vector<int> const &arr, std::ofstream &file_output);
void testQuickSort(std::vector<int> const &arr, std::ofstream &file_output);
void testRegularInsertionSort(std::vector<int> const &arr, std::ofstream &file_output);
void testBinaryInsertionSort(std::vector<int> const &arr, std::ofstream &file_output);
void testShellSortShellSequence(std::vector<int> const &arr, std::ofstream &file_output);
void testShellSortCiuraSequence(std::vector<int> const &arr, std::ofstream &file_output);
void testBubbleSort(std::vector<int> const &arr, std::ofstream &file_output);

#endif  // IHW_SORTING_LGORITHMS_TESTING_TESTER_H

#ifndef IHW_SORTING_LGORITHMS_TESTING_TESTUNITER_H
#define IHW_SORTING_LGORITHMS_TESTING_TESTUNITER_H
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

void generalTestUnite(std::ofstream &results_file_csv, int i, int step,
                      std::vector<int> &array_copy, std::vector<int> &array_rnd_0_to_5,
                      std::vector<int> &array_rnd_0_to_4000, std::vector<int> &array_nearly_sorted,
                      std::vector<int> &array_descending, std::string &sort_type);

#endif  // IHW_SORTING_LGORITHMS_TESTING_TESTUNITER_H

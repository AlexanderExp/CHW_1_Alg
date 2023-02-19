cmake_minimum_required(VERSION 3.21)
project(IHW_Sorting_lgorithms_Testing)

set(CMAKE_CXX_STANDARD 17)

include_directories(${IHW_Sorting_lgorithms_Testing})
add_executable(IHW_Sorting_lgorithms_Testing main.cpp Array_Worker.cpp Bubble_Sort.cpp Counting_Selection_Radix_Sort.cpp Heap_Sort.cpp Merge_Sort.cpp Quick_Sort.cpp Regular_And_Binary_Insertion_Sort.cpp Shell_Sort_Shell_Ciura.cpp TestUniter.cpp TestUniter.h Tester.cpp Tester.h)

// АИСД-2, 2023, задание 5
// Фролов Александр Сергеевич БПИ217
// C++ Clion
// Сделано: Реализованы все требуемые сортировки.
// Проверена работа всех реализованных сортировок.
// Программа замеряет время работы сортировок на требуемых массивах необходимых размеров.
// ...
// Подробнее в отчёте на GitHub по ссылке: https://github.com/AlexanderExp/CHW_1_Alg


#include <iostream>
#include "Heap_Sort.h"
#include "Array_Worker.h"
#include "TestUniter.h"

std::string getNameOfCurrentSort(int n) {
    switch (n) {
        case 1:
            return "Bubble Sort";
        case 2:
            return "Bubble Sort with 1 Iverson condition";
        case 3:
            return "Bubble Sort with 2 Iverson condition";
        case 4:
            return "Counting Sort";
        case 5:
            return "Selection Sort";
        case 6:
            return "Radix Sort";
        case 7:
            return "Heap Sort";
        case 8:
            return "Merge Sort";
        case 9:
            return "Quick Sort";
        case 10:
            return "Regular Insertion Sort";
        case 11:
            return "Binary Insertion Sort";
        case 12:
            return "Shell Sort on Shell Sequence";
        case 13:
            return "Shell Sort Ciura Sequence";
        default:
            return "";
    }
}

void testSortingAlgorithmsOnSmallArray(std::ofstream &resulting_file) {
    std::vector<int> array_300_rnd_0_to_5(300, 0);
    std::vector<int> array_300_rnd_0_to_4000(300, 0);
    std::vector<int> array_300_nearly_sorted(300, 0);
    std::vector<int> array_300_descending(300, 0);
    std::vector<int> array_copy;

    randomVectorGeneratorEasy(array_300_rnd_0_to_5, 300);
    randomVectorGeneratorHardcore(array_300_rnd_0_to_4000, 300);
    nearlySortedVectorGenerator(array_300_nearly_sorted, 300);
    descendingOrderVectorGenerator(array_300_descending, 300);

    resulting_file
        << "Sort_Type,Array_size,Array_0_5,Array_0_4000,Array_Nearly_Sorted,Array_Descending"
        << "\n";
    std::string sort_type;
    for (int i = 1; i < 14; ++i) {
        sort_type = getNameOfCurrentSort(i);
        for (int j = 1; j < 7; ++j) {
            resulting_file << sort_type << "," << 50 * j << ",";
            std::cout << j << " ";
            generalTestUnite(resulting_file, j, 50, array_copy, array_300_rnd_0_to_5,
                             array_300_rnd_0_to_4000, array_300_nearly_sorted, array_300_descending,
                             sort_type);
        }
        resulting_file << "\n";
    }
    resulting_file << "\n\n\n";
}

void testSortingAlgorithmsOnBiggerArray(std::ofstream &resulting_file) {
    std::vector<int> array_4100_rnd_0_to_5(4100, 0);
    std::vector<int> array_4100_rnd_0_to_4000(4100, 0);
    std::vector<int> array_4100_nearly_sorted(4100, 0);
    std::vector<int> array_4100_descending(4100, 0);
    std::vector<int> array_copy;

    randomVectorGeneratorEasy(array_4100_rnd_0_to_5, 4100);
    randomVectorGeneratorHardcore(array_4100_rnd_0_to_4000, 4100);
    nearlySortedVectorGenerator(array_4100_nearly_sorted, 4100);
    descendingOrderVectorGenerator(array_4100_descending, 4100);
    resulting_file
        << "Sort_Type,Array_size,Array_0_5,Array_0_4000,Array_Nearly_Sorted,Array_Descending"
        << "\n";
    std::string sort_type;
    for (int i = 1; i < 14; ++i) {
        sort_type = getNameOfCurrentSort(i);
        for (int j = 1; j < 42; ++j) {
            resulting_file << sort_type << "," << 100 * j << ",";
            std::cout << j << "\n";
            generalTestUnite(resulting_file, j, 100, array_copy, array_4100_rnd_0_to_5,
                             array_4100_rnd_0_to_4000, array_4100_nearly_sorted,
                             array_4100_descending, sort_type);
        }
        resulting_file << "\n";
    }
}

int main() {
    std::ofstream results_file_csv;
    results_file_csv.open("CHW.csv");

    testSortingAlgorithmsOnSmallArray(results_file_csv);
    std::cout << "done 1"
              << "\n";
    testSortingAlgorithmsOnBiggerArray(results_file_csv);

    results_file_csv.close();
    return 0;
}

#include "TestUniter.h"
#include "Tester.h"

void chooseAppropriateTestAndActivateIt(std::vector<int> &arr, std::ofstream &results_file_csv,
                                        const std::string &sort_type) {
    ultimateTester(arr, results_file_csv, sort_type);
}

void testWrapper(std::ofstream &results_file_csv, int i, int step, std::vector<int> &array_copy_1,
                 std::vector<int> &array_rnd_0_to_5, std::vector<int> &array_rnd_0_to_4000,
                 std::vector<int> &array_nearly_sorted, std::vector<int> &array_descending,
                 const std::string &sort_type) {
    std::vector<int> array_copy;
    std::copy(array_rnd_0_to_5.begin(), array_rnd_0_to_5.begin() + step * i,
              std::back_inserter(array_copy));
    chooseAppropriateTestAndActivateIt(array_copy, results_file_csv, sort_type);
    array_copy.clear();
    array_copy.shrink_to_fit();

    std::copy(array_rnd_0_to_4000.begin(), array_rnd_0_to_4000.begin() + step * i,
              std::back_inserter(array_copy));
    chooseAppropriateTestAndActivateIt(array_copy, results_file_csv, sort_type);
    array_copy.clear();
    array_copy.shrink_to_fit();

    std::copy(array_nearly_sorted.begin(), array_nearly_sorted.begin() + step * i,
              std::back_inserter(array_copy));
    chooseAppropriateTestAndActivateIt(array_copy, results_file_csv, sort_type);
    array_copy.clear();
    array_copy.shrink_to_fit();

    std::copy(array_descending.begin(), array_descending.begin() + step * i,
              std::back_inserter(array_copy));
    chooseAppropriateTestAndActivateIt(array_copy, results_file_csv, sort_type);
    results_file_csv << "\n";
    array_copy.clear();
    array_copy.shrink_to_fit();
}

void generalTestUnite(std::ofstream &results_file_csv, int i, int step,
                      std::vector<int> &array_copy, std::vector<int> &array_rnd_0_to_5,
                      std::vector<int> &array_rnd_0_to_4000, std::vector<int> &array_nearly_sorted,
                      std::vector<int> &array_descending, std::string &sort_type) {
    testWrapper(results_file_csv, i, step, array_copy, array_rnd_0_to_5, array_rnd_0_to_4000,
                array_nearly_sorted, array_descending, sort_type);
}
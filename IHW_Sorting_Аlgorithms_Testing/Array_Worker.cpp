#include "Array_Worker.h"

void printArray(std::vector<int> &array) {
    for (int &i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n"
              << "\n";
}

void randomVectorGeneratorEasy(std::vector<int> &arr, int n) {
    srand(std::time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 6;
    }
}
void randomVectorGeneratorHardcore(std::vector<int> &arr, int n) {
    srand(std::time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 4001;
    }
}
void descendingOrderVectorGenerator(std::vector<int> &arr, int n) {
    int current = n;
    for (int i = 0; i < n; ++i) {
        arr[i] = current--;
    }
}

void nearlySortedVectorGenerator(std::vector<int> &arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < arr.size(); i += 49) {
        std::swap(arr[i + 5], arr[i + 25]);
    }
}

double getAverage(std::vector<long long> const& v) {
    if (v.empty()) {
        return 0;
    }
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}
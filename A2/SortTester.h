#ifndef SORTTESTER_H
#define SORTTESTER_H

#include "ArrayGenerator.h"
#include "SortFuncs.h"
#include <ctime>
#include <chrono>

class SortTester {
public:
  double CalculateMergeSortTime(std::vector<int>& arr) {
    const int attempts = 5;
    long long allTime = 0;

    for (int t = 0; t < attempts; ++t) {
      std::vector<int> tmpArr = arr;

      auto start = std::chrono::high_resolution_clock::now();
      MergeSort(tmpArr, 0, tmpArr.size());
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long microsec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

      allTime += microsec;
    }

    return static_cast<double>(allTime) / attempts;
  }

  double CalculateHybridMergeSortTime(std::vector<int>& arr, int threshold) {
    const int attempts = 5;
    long long allTime = 0;

    for (int t = 0; t < attempts; ++t) {
      std::vector<int> tmpArr = arr;

      auto start = std::chrono::high_resolution_clock::now();
      HybridMergeSort(tmpArr, 0, tmpArr.size(), threshold);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long microsec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

      allTime += microsec;
    }

    return static_cast<double>(allTime) / attempts;
  }
};

#endif


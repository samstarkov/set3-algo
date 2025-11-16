#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ArrayGenerator.h"
#include "SortFuncs.h"
#include "SortTester.h"

int main() {
  std::ofstream outMS1("MergeSortRandom.txt");
  std::ofstream outMS2("MergeSortReversed.txt");
  std::ofstream outMS3("MergeSortAlmostSorted.txt");
  std::ofstream outHMS1("HybridMergeSortRandom.txt");
  std::ofstream outHMS2("HybridMergeSortReversed.txt");
  std::ofstream outHMS3("HybridMergeSortAlmostSorted.txt");

  ArrayGenerator arrayGenerator;
  SortTester sortTester;
  std::vector<int> thresholds = { 5, 10, 20, 30, 50 };

  for (size_t size = 500; size <= 100000; size += 100) {
    std::vector<int> randomArray = arrayGenerator.GetRandomArray(size);
    std::vector<int> reversedArray = arrayGenerator.GetReversedArray(size);
    std::vector<int> almostSortedArray = arrayGenerator.GetAlmostSortedArray(size);

    double randomTime = sortTester.CalculateMergeSortTime(randomArray);
    double reversedTime = sortTester.CalculateMergeSortTime(reversedArray);
    double almostSortedTime = sortTester.CalculateMergeSortTime(almostSortedArray);

    outMS1 << size << ' ' << randomTime << '\n';
    outMS2 << size << ' ' << reversedTime << '\n';
    outMS3 << size << ' ' << almostSortedTime << '\n';

    outHMS1 << size << ' ';
    outHMS2 << size << ' ';
    outHMS3 << size << ' ';
    for (size_t i = 0; i < thresholds.size(); ++i) {
      randomTime = sortTester.CalculateHybridMergeSortTime(randomArray, thresholds[i]);
      reversedTime = sortTester.CalculateHybridMergeSortTime(reversedArray, thresholds[i]);
      almostSortedTime = sortTester.CalculateHybridMergeSortTime(almostSortedArray, thresholds[i]);

      outHMS1 << randomTime;
      outHMS2 << reversedTime;
      outHMS3 << almostSortedTime;
      if (i + 1 < thresholds.size()) {
        outHMS1 << ' ';
        outHMS2 << ' ';
        outHMS3 << ' ';
      }
      else {
        outHMS1 << '\n';
        outHMS2 << '\n';
        outHMS3 << '\n';
      }
    }
  }
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ArrayGenerator.h"
#include "SortFuncs.h"
#include "SortTester.h"

int main() {
  std::ofstream outQS1("QuickSortRandom.txt");
  std::ofstream outQS2("QuickSortReversed.txt");
  std::ofstream outQS3("QuickSortAlmostSorted.txt");
  std::ofstream outIS1("IntroSortRandom.txt");
  std::ofstream outIS2("IntroSortReversed.txt");
  std::ofstream outIS3("IntroSortAlmostSorted.txt");

  ArrayGenerator arrayGenerator;
  SortTester sortTester;

  for (size_t size = 500; size <= 100000; size += 100) {
    std::vector<int> randomArray = arrayGenerator.GetRandomArray(size);
    std::vector<int> reversedArray = arrayGenerator.GetReversedArray(size);
    std::vector<int> almostSortedArray = arrayGenerator.GetAlmostSortedArray(size);

    double randomTime = sortTester.CalculateQuickSortTime(randomArray);
    double reversedTime = sortTester.CalculateQuickSortTime(reversedArray);
    double almostSortedTime = sortTester.CalculateQuickSortTime(almostSortedArray);

    outQS1 << size << ' ' << randomTime << '\n';
    outQS2 << size << ' ' << reversedTime << '\n';
    outQS3 << size << ' ' << almostSortedTime << '\n';

    randomTime = sortTester.CalculateIntroSortTime(randomArray);
    reversedTime = sortTester.CalculateIntroSortTime(reversedArray);
    almostSortedTime = sortTester.CalculateIntroSortTime(almostSortedArray);

    outIS1 << size << ' ' << randomTime << '\n';
    outIS2 << size << ' ' << reversedTime << '\n';
    outIS3 << size << ' ' << almostSortedTime << '\n';
    if (size % 10000 == 0) {
      std::cout << size << '\n';
    }
  }
}

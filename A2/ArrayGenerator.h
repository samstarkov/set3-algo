#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

#include <vector>
#include <random>

std::random_device random_dev;
std::mt19937 generator(random_dev());

class ArrayGenerator {
private:
  const size_t maxSize = 100 * 1000;
  const int minVal = 0;
  const int maxVal = 6000;

  std::vector<int> randArray;
  std::vector<int> reversedArray;
  std::vector<int> almostSortedArray;

  void buildMainArrays() {
    std::uniform_int_distribution<> distr(minVal, maxVal);
    for (size_t i = 0; i < maxSize; ++i) {
      randArray.push_back(distr(generator));
      reversedArray.push_back(distr(generator));
      almostSortedArray.push_back(distr(generator));
    }
    std::sort(reversedArray.begin(), reversedArray.end(), std::greater<int>());
    std::sort(almostSortedArray.begin(), almostSortedArray.end());

    std::uniform_int_distribution<> distr_ind(0, maxSize - 1);

    for (size_t i = 0; i < 5000; ++i) {
      std::swap(almostSortedArray[distr_ind(generator)], almostSortedArray[distr_ind(generator)]);
    }
  }

public:
  ArrayGenerator() {
    buildMainArrays();
  }

  std::vector<int> GetRandomArray(size_t size) {
    return std::vector<int>(randArray.begin(), randArray.begin() + size);
  }

  std::vector<int> GetReversedArray(size_t size) {
    return std::vector<int>(reversedArray.begin(), reversedArray.begin() + size);
  }

  std::vector<int> GetAlmostSortedArray(size_t size) {
    return std::vector<int>(almostSortedArray.begin(), almostSortedArray.begin() + size);
  }
};

#endif


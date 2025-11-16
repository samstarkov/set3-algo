#ifndef SORTFUNCS_H
#define SORTFUNCS_H

#include <vector>

void InsertionSort(std::vector<int>& v, size_t begin, size_t end) {
  int beg = begin;
  for (size_t i = begin + 1; i < end; ++i) {
    int key = v[i];
    int j = i - 1;

    while (j >= beg && v[j] > key) {
      v[j + 1] = v[j];
      --j;
    }
    v[j + 1] = key;
  }
}

void Merge(std::vector<int>& v, size_t begin, size_t end) {
  size_t mid = (begin + end) / 2;
  size_t nf = mid - begin;
  size_t ns = end - mid;

  std::vector <int> a(nf);
  std::vector <int> b(ns);

  for (size_t i = 0; i < nf; ++i) {
    a[i] = v[i + begin];
  }
  for (size_t i = 0; i < ns; ++i) {
    b[i] = v[i + mid];
  }

  size_t i = 0;
  size_t j = 0;

  for (size_t ind = begin; ind < end; ++ind) {
    if (i == nf) {
      v[ind] = b[j];
      ++j;
    }
    else if (j == ns) {
      v[ind] = a[i];
      ++i;
    }
    else {
      if (a[i] <= b[j]) {
        v[ind] = a[i];
        ++i;
      }
      else {
        v[ind] = b[j];
        ++j;
      }
    }
  }
}

void HybridMergeSort(std::vector<int>& v, size_t begin, size_t end, int threshold) {
  if (end - begin <= threshold) {
    InsertionSort(v, begin, end);
    return;
  }
  size_t mid = (begin + end) / 2;
  HybridMergeSort(v, begin, mid, threshold);
  HybridMergeSort(v, mid, end, threshold);
  Merge(v, begin, end);
}

void MergeSort(std::vector<int>& v, size_t begin, size_t end) {
  if (begin + 1 == end) {
    return;
  }
  size_t mid = (begin + end) / 2;
  MergeSort(v, begin, mid);
  MergeSort(v, mid, end);
  Merge(v, begin, end);
}

#endif


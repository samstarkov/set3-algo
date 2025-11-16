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

void Heapify(std::vector<int>& v, size_t i, size_t begin, size_t end) {
  int n = end - begin;
  size_t left = 2 * i + 1;
  size_t right = 2 * i + 2;
  size_t c_ind = i + begin;
  size_t l_ind = left + begin;
  size_t r_ind = right + begin;

  size_t flag = 0;
  if (left < n && v[l_ind] > v[c_ind]) {
    flag = 1;
  }
  if (right < n && v[r_ind] > v[c_ind]) {
    if (v[r_ind] > v[l_ind]) {
      flag = 2;
    }
  }

  if (flag == 1) {
    std::swap(v[c_ind], v[l_ind]);
    Heapify(v, left, begin, end);
  }
  if (flag == 2) {
    std::swap(v[c_ind], v[r_ind]);
    Heapify(v, right, begin, end);
  }
}

void BuildMaxHeap(std::vector<int>& v, size_t begin, size_t end) {
  int n = end - begin;
  for (int i = n / 2; i >= 0; --i) {
    Heapify(v, i, begin, end);
  }
}

void HeapSort(std::vector<int>& v, size_t begin, size_t end) {
  int n = end - begin;
  BuildMaxHeap(v, begin, end);
  for (int i = 0; i < n - 1; ++i) {
    size_t lst = begin + n - 1 - i;
    std::swap(v[begin], v[lst]);
    Heapify(v, 0, begin, lst);
  }
}


int Partition(std::vector<int>& v, size_t begin, size_t end) {
  int pi = v[(begin + end) / 2];
  int i = begin;
  int j = end - 1;
  while (i <= j) {
    while (v[i] < pi) {
      ++i;
    }
    while (v[j] > pi) {
      --j;
    }
    if (i >= j) {
      break;
    }
    std::swap(v[i++], v[j--]);
  }
  return j;
}


void QuickSort(std::vector<int>& v, size_t begin, size_t end, int curHeight, int maxHeight) {
  const int threshold = 16;
  if (curHeight == maxHeight) {
    HeapSort(v, begin, end);
    return;
  }
  if (end - begin < threshold) {
    InsertionSort(v, begin, end);
    return;
  }
  if (begin < end) {
    int pivot = Partition(v, begin, end);
    QuickSort(v, begin, pivot + 1, curHeight + 1, maxHeight);
    QuickSort(v, pivot + 1, end, curHeight + 1, maxHeight);
  }
}

void IntroSort(std::vector<int>& arr) {
  QuickSort(arr, 0, arr.size(), 0, 2 * log2(arr.size()));
}

size_t ClPartition(std::vector<int>& a, size_t left, size_t right) {
  int pivot = a[(left + right) / 2];

  int i = left - 1;
  int j = right + 1;

  while (true) {
    ++i;
    while (a[i] < pivot) {
      ++i;
    }

    --j;
    while (a[j] > pivot) {
      --j;
    }

    if (i >= j) {
      return j;
    }

    std::swap(a[i], a[j]);
  }
}

void ClQuickSort(std::vector<int>& a, size_t left, size_t right) {
  if (left < right) {
    size_t p = ClPartition(a, left, right);
    ClQuickSort(a, left, p);
    ClQuickSort(a, p + 1, right);
  }
}

#endif


// SortingAlgorithms.h
#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>
#include <algorithm>

class SortingAlgorithms {
public:
    template<typename T>
    static void swapSort(std::vector<T>& list) {
        bool swapped;
        do {
            swapped = false;
            for (size_t i = 1; i < list.size(); ++i) {
                if (list[i - 1] > list[i]) {
                    std::swap(list[i - 1], list[i]);
                    swapped = true;
                }
            }
        } while (swapped);
    }
    template<typename T>
    static void bubbleSort(std::vector<T>& list) {
        bool swapped;
        size_t n = list.size();
        do {
            swapped = false;
            for (size_t i = 0; i < n-1; ++i) {
                if (list[i] > list[i + 1]) {
                    std::swap(list[i], list[i + 1]);
                    swapped = true;
                }
            }
            --n;
        } while (swapped);
    }
    template<typename T>
    static void selectionSort(std::vector<T>& list) {
        size_t n = list.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (list[j] < list[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(list[i], list[minIndex]);
        }
    }
    template<typename T>
    static void insertionSort(std::vector<T>& list) {
        size_t n = list.size();
        for (size_t i = 1; i < n; ++i) {
            T key = list[i];
            ssize_t j = i - 1;
            while (j >= 0 && list[j] > key) {
                list[j + 1] = list[j];
                --j;
            }
            list[j + 1] = key;
        }
    }
    template<typename T>
    static void merge(std::vector<T>& left, std::vector<T>& right, std::vector<T>& list) {
        size_t leftIndex = 0, rightIndex = 0, mergeIndex = 0;
        while (leftIndex < left.size() && rightIndex < right.size()) {
            if (left[leftIndex] < right[rightIndex]) {
                list[mergeIndex++] = left[leftIndex++];
            } else {
                list[mergeIndex++] = right[rightIndex++];
            }
        }
        while (leftIndex < left.size()) {
            list[mergeIndex++] = left[leftIndex++];
        }
        while (rightIndex < right.size()) {
            list[mergeIndex++] = right[rightIndex++];
        }
    }
    template<typename T>
    static void mergeSort(std::vector<T>& list) {
        if (list.size() <= 1) return;
        size_t mid = list.size() / 2;
        std::vector<T> left(list.begin(), list.begin() + mid);
        std::vector<T> right(list.begin() + mid, list.end());
        mergeSort(left);
        mergeSort(right);
        merge(left, right, list);
    }
    template<typename T>
    static size_t partition(std::vector<T>& list, size_t low, size_t high) {
        T pivot = list[high];
        size_t i = (low - 1); 

        for (size_t j = low; j <= high - 1; j++) {
            if (list[j] <= pivot) {
                i++; 
                std::swap(list[i], list[j]);
            }
        }
        std::swap(list[i + 1], list[high]);
        return (i + 1);
    }

    template<typename T>
    static void quickSort(std::vector<T>& list, size_t low, size_t high) {
        if (low < high) {
            size_t pi = partition(list, low, high);

            if (pi > 0) quickSort(list, low, pi - 1); 
            quickSort(list, pi + 1, high);
        }
    }
};

#endif

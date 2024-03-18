#include <iostream>
#include <chrono>
#include <vector>
#include "include/RandomListGenerator.h" 
#include "include/SortingAlgorithms.h"

int main() {
    srand(static_cast<unsigned>(time(0))); 
    std::vector<int> integerList;
    int option, n;

    do {
        std::cout << "Options Menu:\n";
        std::cout << "1. Create list of data\n";
        std::cout << "2. Sort list (Swap Sort)\n";
        std::cout << "3. Sort list (Bubble Sort)\n";
        std::cout << "4. Sort list (Selection Sort)\n";
        std::cout << "5. Sort list (Insertion Sort)\n";
        std::cout << "6. Sort list (Merge Sort)\n";
        std::cout << "7. Sort list (Quick Sort)\n";
        std::cout << "0. Exit\n";
        std::cin >> option;

        switch(option) {
            case 1:
                std::cout << "Enter the number of elements: ";
                std::cin >> n;
                integerList = generateRandomList<int>(n);
                break;
            case 2:
                if (!integerList.empty()) {
                    auto start = std::chrono::high_resolution_clock::now();
                    SortingAlgorithms::swapSort(integerList);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    std::cout << "List sorted with Swap Sort in " << duration.count() << " ms\n";
                } else {
                    std::cout << "List is empty. Generate a list first.\n";
                }
                break;
            case 3:
                if (!integerList.empty()) {
                    auto start = std::chrono::high_resolution_clock::now();
                    SortingAlgorithms::bubbleSort(integerList);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    std::cout << "List sorted with Bubble Sort in " << duration.count() << " ms\n";
                } else {
                    std::cout << "List is empty. Generate a list first.\n";
                }
                break;
            case 4:
                if (!integerList.empty()) {
                    auto start = std::chrono::high_resolution_clock::now();
                    SortingAlgorithms::selectionSort(integerList);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    std::cout << "List sorted with Selection Sort in " << duration.count() << " ms\n";
                } else {
                    std::cout << "List is empty. Generate a list first.\n";
                }
                break;
            case 5:
                if (!integerList.empty()) {
                    auto start = std::chrono::high_resolution_clock::now();
                    SortingAlgorithms::insertionSort(integerList);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    std::cout << "List sorted with Insertion Sort in " << duration.count() << " ms\n";
                } else {
                    std::cout << "List is empty. Generate a list first.\n";
                }
                break;
            case 6:
                if (!integerList.empty()) {
                    auto start = std::chrono::high_resolution_clock::now();
                    SortingAlgorithms::mergeSort(integerList);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    std::cout << "List sorted with Merge Sort in " << duration.count() << " ms\n";
                } else {
                    std::cout << "List is empty. Generate a list first.\n";
                }
                break;
            case 7:
                if (!integerList.empty()) {
                    auto start = std::chrono::high_resolution_clock::now();
                    SortingAlgorithms::quickSort(integerList, 0, integerList.size() - 1);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    std::cout << "List sorted with Quick Sort in " << duration.count() << " ms\n";
                } else {
                    std::cout << "List is empty. Generate a list first.\n";
                }
                break;
            default:
                break;
        }
    } while(option != 0);

    return 0;
}

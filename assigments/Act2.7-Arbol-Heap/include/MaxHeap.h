#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapify_up(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapify_up(parent);
        }
    }

    void heapify_down(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify_down(largest);
        }
    }

public:
    void push(int n) {
        heap.push_back(n);
        heapify_up(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) {
            throw out_of_range("pop from empty heap");
        }
        int max_value = heap.front();
        heap.front() = heap.back();
        heap.pop_back();
        heapify_down(0);
        return max_value;
    }

    int top() {
        if (heap.empty()) {
            throw out_of_range("top from empty heap");
        }
        return heap.front();
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

#endif
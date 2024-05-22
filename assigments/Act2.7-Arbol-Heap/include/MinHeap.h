#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;


class MinHeap {
private:
    vector<int> heap;

    void heapify_up(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapify_up(parent);
        }
    }

    void heapify_down(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapify_down(smallest);
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
        int min_value = heap.front();
        heap.front() = heap.back();
        heap.pop_back();
        heapify_down(0);
        return min_value;
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
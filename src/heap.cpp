#ifndef HEAP_CPP
#define HEAP_CPP

#include "../include/heap.hpp"
#include <iostream>

template <typename T, typename Compare>
void Heap<T, Compare>::push(const T& value) {
    std::cout << "Pushing value: " << value << std::endl;
    if (data.size() >= 1000) throw std::runtime_error("Heap is full");
    data.push_back(value);
    heapify_up(data.size() - 1);
}

template <typename T, typename Compare>
void Heap<T, Compare>::pop() {
    if (empty()) throw std::runtime_error("Heap is empty");
    std::swap(data[0], data.back());
    data.pop_back();
    if (!empty()) heapify_down(0);
}

template <typename T, typename Compare>
T Heap<T, Compare>::top() const {
    if (empty()) throw std::runtime_error("Heap is empty");
    return data[0];
}

template <typename T, typename Compare>
bool Heap<T, Compare>::empty() const {
    return data.empty();
}

template <typename T, typename Compare>
size_t Heap<T, Compare>::size() const {
    return data.size();
}

template <typename T, typename Compare>
void Heap<T, Compare>::heapify_up(size_t index) {
    while (index > 0) {
        size_t parent = (index - 1) / 2;
        if (cmp(data[parent], data[index])) {
            std::swap(data[parent], data[index]);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename T, typename Compare>
void Heap<T, Compare>::heapify_down(size_t index) {
    size_t min_index = index;
    while (true) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        if (left < data.size() && cmp(data[min_index], data[left])) {
            min_index = left;
        }
        if (right < data.size() && cmp(data[min_index], data[right])) {
            min_index = right;
        }
        if (min_index == index) break;
        std::swap(data[index], data[min_index]);
        index = min_index;
    }
}

#endif
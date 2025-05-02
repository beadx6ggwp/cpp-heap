#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <functional>

template <typename T, typename Compare = std::less<T>>
class Heap {
public:
    Heap() = default;
    void push(const T& value);
    void pop();
    T top() const;
    bool empty() const;
    size_t size() const;

private:
    std::vector<T> data;
    Compare cmp;
    void heapify_up(size_t index);
    void heapify_down(size_t index);
};

#include "../src/heap.cpp"
#endif
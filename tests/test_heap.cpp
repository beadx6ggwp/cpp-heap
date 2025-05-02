#include <gtest/gtest.h>
#include "heap.hpp"

TEST(HeapTest, PushAndTop) {
    Heap<int> max_heap;
    max_heap.push(3);
    max_heap.push(1);
    max_heap.push(4);
    EXPECT_EQ(max_heap.top(), 4);
}

TEST(HeapTest, Pop) {
    Heap<int> max_heap;
    max_heap.push(3);
    max_heap.push(1);
    max_heap.push(4);
    max_heap.pop();
    EXPECT_EQ(max_heap.top(), 3);
}

TEST(HeapTest, MinHeap) {
    Heap<int, std::greater<int>> min_heap;
    min_heap.push(3);
    min_heap.push(1);
    min_heap.push(4);
    EXPECT_EQ(min_heap.top(), 1);
}

TEST(HeapTest, PopEmpty) {
    Heap<int> max_heap;
    EXPECT_THROW(max_heap.pop(), std::runtime_error);
}
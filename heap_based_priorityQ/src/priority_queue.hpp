#pragma once

#include <string>
#include <vector>
#include <functional>

#include "heap.hpp"


class PriorityQueue
{
    public:
        PriorityQueue() = default;
        PriorityQueue(const std::vector<size_t>& elements);

        size_t peek() const;
        void pop();

        void insert(const size_t& element);
        void insert(const std::vector<size_t>& elements);

        std::string toString() const;

    private:
        std::function<bool(int,int)> m_priority_function;
        Heap m_heap;
};

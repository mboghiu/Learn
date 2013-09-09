#pragma once

#include <string>
#include <vector>

class Heap
{
    public:
        Heap() = default;
        Heap(const std::vector<size_t>& elements);

        size_t view_root() const;

        void delete_root();

        void insert(size_t element);

        void merge(const Heap& other_heap);

        const std::vector<size_t>& get() const;

        std::string toString() const;

    private:
        std::vector<size_t> m_heap;

        void upheap(int node);
        void downheap(int node);
        void heapify(std::vector<size_t>& array, size_t array_size);

        bool SatisfiesHeapProperty(int node) const;

        bool HasLeftChild(int indexOfNode) const;
        bool HasRightChild(int indexOfNode) const;

        int GetParentIndex(int indexOfNode) const;
        int GetLeftChildIndex(int indexOfNode) const;
        int GetRightChildIndex(int indexOfNode) const;

        int GetIndexOfMinValueChild(int node) const;
};

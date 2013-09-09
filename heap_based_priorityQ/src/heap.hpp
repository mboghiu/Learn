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

        void upheap(size_t element);
        void merge(const Heap& other_heap);

        const std::vector<size_t>& get() const;

        std::string toString() const;

    private:
        std::vector<size_t> m_heap;

        bool SatisfiesHeapProperty(int indexOfNode) const;
        bool HasLeftChild(int indexOfNode) const;
        bool HasRightChild(int indexOfNode) const;

        int GetParentIndex(int indexOfNode) const;
        int GetLeftChildIndex(int indexOfNode) const;
        int GetRightChildIndex(int indexOfNode) const;
};

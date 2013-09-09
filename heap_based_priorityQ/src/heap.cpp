#include <sstream>
#include <iostream>

#include "heap.hpp"

Heap::Heap(const std::vector<size_t>& elements) :
    m_heap(elements)
{
    heapify(m_heap, m_heap.size());
}

size_t Heap::view_root() const
{
    if (m_heap.size() == 0)
        throw "You are trying to peek at an empty set.";

    return m_heap.at(0);
}

void Heap::delete_root()
{
    std::swap(m_heap.at(0), m_heap.at(m_heap.size() - 1));

    m_heap.pop_back();

    if (m_heap.size() >= 1)
        downheap(0);
}

void Heap::insert(size_t element)
{
    m_heap.push_back(element);

    upheap(static_cast<int>(m_heap.size()) - 1);
}

void Heap::merge(const Heap& other_heap)
{
    m_heap.reserve(m_heap.size() + other_heap.get().size());

    m_heap.insert(m_heap.end(), other_heap.get().begin(), other_heap.get().end());

    heapify(m_heap, m_heap.size());
}

const std::vector<size_t>& Heap::get() const
{
    return m_heap;
}

std::string Heap::toString() const
{
    std::ostringstream iss;

    if ( m_heap.empty() )
        iss << "<empty>";

    for ( size_t element : m_heap )
        iss << element << " ";

    return std::move(iss.str());
}

////////////// Algorithms - actual work happens here /////////////////

void Heap::upheap(int node)
{
    if (GetParentIndex(node) < 0)
        return;

    if (SatisfiesHeapProperty(GetParentIndex(node)))
        return;

    std::swap(m_heap.at(node), m_heap.at(GetParentIndex(node)));

    upheap(GetParentIndex(node));
}

void Heap::downheap(int node)
{
    if (SatisfiesHeapProperty(node))
        return;

    int indexOfMinValueChild = GetIndexOfMinValueChild(node);

    std::swap(m_heap.at(node), m_heap.at(indexOfMinValueChild));

    downheap(indexOfMinValueChild);
}

void Heap::heapify(std::vector<size_t>& array, size_t array_size)
{
    if (array_size == 0)
        return;

    for (size_t i = array_size / 2; i < array_size; i++)
        downheap(static_cast<int>(i)); 

    heapify(array, array_size / 2);
}


////////////// Helpers /////////////////

bool Heap::SatisfiesHeapProperty(int node) const
{
    /* If parent is <= then both children, if they exits. */

    if (HasLeftChild(node) and m_heap.at(node) > m_heap.at(GetLeftChildIndex(node)))
        return false;

    if (HasRightChild(node) and m_heap.at(node) > m_heap.at(GetRightChildIndex(node)))
        return false;

    return true;
}

bool Heap::HasLeftChild(int indexOfNode) const
{
    return (indexOfNode * 2 + 1 < static_cast<int>(m_heap.size()));
}

bool Heap::HasRightChild(int indexOfNode) const
{
    return (indexOfNode * 2 + 2 < static_cast<int>(m_heap.size()));
}

int Heap::GetParentIndex(int indexOfNode) const
{
    if (indexOfNode == 0)
        return -1;

    return (indexOfNode - 1) / 2;
}

int Heap::GetLeftChildIndex(int indexOfNode) const
{
    return indexOfNode * 2 + 1;
}

int Heap::GetRightChildIndex(int indexOfNode) const
{
    return indexOfNode * 2 + 2;
}

int Heap::GetIndexOfMinValueChild(int node) const
{
    if (!HasLeftChild(node))
        return GetRightChildIndex(node);

    if (!HasRightChild(node))
        return GetLeftChildIndex(node);

    if (m_heap.at(GetLeftChildIndex(node)) <= m_heap.at(GetRightChildIndex(node)))
        return GetLeftChildIndex(node);
    else
        return GetRightChildIndex(node);
}

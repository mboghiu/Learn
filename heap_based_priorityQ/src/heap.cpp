#include <sstream>
#include <iostream>

#include "heap.hpp"

Heap::Heap(const std::vector<size_t>& elements) :
    m_heap(elements)
{
    // TODO ALG heapify function
}

size_t Heap::view_root() const
{
    if (m_heap.size() == 0)
        throw "You are trying to peek at an empty set.";

    return m_heap.at(0);
}

void Heap::delete_root()
{
    // TODO ALG delete root
}

void Heap::upheap(size_t element)
{
    m_heap.push_back(element);

    int indexOfNewNode = static_cast<int>(m_heap.size()) - 1;

    while (GetParentIndex(indexOfNewNode) >= 0)
    {
        if (SatisfiesHeapProperty(GetParentIndex(indexOfNewNode)))
        {
            break;
        }
        else
        {
            std::swap(m_heap.at(indexOfNewNode), m_heap.at(GetParentIndex(indexOfNewNode)));
            indexOfNewNode = GetParentIndex(indexOfNewNode);
        }
    }
}

void Heap::merge(const Heap& /*other_heap*/)
{
    // TODO ALG merge
    std::cout << "\033[1;31mMERGE NOT YET IMPLEMENTED\033[0m" << std::endl;
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

////////////// Helpers /////////////////

bool Heap::SatisfiesHeapProperty(int indexOfNode) const
{
    if (HasLeftChild(indexOfNode) and m_heap.at(indexOfNode) > m_heap.at(GetLeftChildIndex(indexOfNode)))
        return false;

    if (HasRightChild(indexOfNode) and m_heap.at(indexOfNode) > m_heap.at(GetRightChildIndex(indexOfNode)))
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

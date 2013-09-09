#include "priority_queue.hpp"

PriorityQueue::PriorityQueue(const std::vector<size_t>& elements) :
    m_heap(elements)
{

}

size_t PriorityQueue::peek() const
{
    return m_heap.view_root();
}

void PriorityQueue::pop()
{
    m_heap.delete_root();
}

void PriorityQueue::insert(const size_t& element)
{
    m_heap.insert(element);
}

void PriorityQueue::insert(const std::vector<size_t>& elements)
{
    m_heap.merge(Heap(elements));
}

std::string PriorityQueue::toString() const
{
    return (std::move(m_heap.toString()));
}

#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "node.hpp"

template<typename T>
class Queue
{
    public:
        void Push(const T& value);
        void Pop();

        void Print();
        std::string ToString();

    private:
        Node<T>* m_front = nullptr;
        Node<T>* m_end = nullptr;
};

template<typename T>
void Queue<T>::Push(const T& value)
{
    if (m_front == nullptr)
    {
        m_end = new Node<T>(value);
        m_front = m_end;
    }
    else
    {
        m_end->m_next = new Node<T>(value);
        m_end = m_end->m_next;
    }
}

template<typename T>
void Queue<T>::Pop()
{
    if (m_front == nullptr)
        return;

    Node<T>* del = m_front;
    m_front = m_front->m_next;
    delete del;
}

template<typename T>
void Queue<T>::Print()
{
    std::cout << ToString() << std::endl;
}

template<typename T>
std::string Queue<T>::ToString()
{
    std::stringstream ss;
    for (Node<T>* i = m_front; i != nullptr; i = i->m_next)
        ss << i->m_data << " | ";
    return std::move(ss.str());
}

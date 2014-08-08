#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "qnode.hpp"

template<typename T>
class Queue
{
    public:
        void Push(const T& value);
        qnode<T>* Pop();
        qnode<T>* Peek() const;

        void Print();
        std::string ToString();

    private:
        qnode<T>* m_front = nullptr;
        qnode<T>* m_end = nullptr;
};

template<typename T>
void Queue<T>::Push(const T& value)
{
    if (m_front == nullptr)
    {
        m_end = new qnode<T>(value);
        m_front = m_end;
    }
    else
    {
        m_end->m_next = new qnode<T>(value);
        m_end = m_end->m_next;
    }
}

template<typename T>
qnode<T>* Queue<T>::Pop()
{
    if (m_front == nullptr)
        return nullptr;

    auto front = m_front;
    m_front = m_front->m_next;
    return front;
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
    for (qnode<T>* i = m_front; i != nullptr; i = i->m_next)
        ss << i->m_data << "|";
    return std::move(ss.str());
}

template<typename T>
qnode<T>* Queue<T>::Peek() const
{
    return m_front;
}

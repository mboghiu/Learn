#pragma once

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
struct Node
{
    Node() :
        m_have(false),
        m_next(nullptr)
    { }

    Node(const T& data) :
        m_data(data),
        m_have(true),
        m_next(nullptr)
    { }

    Node(const T& data, Node* next) :
        Node(data)
    {
        m_next = next;
    }

    T m_data;
    bool m_have;
    Node* m_next;
};

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
}

template<typename T>
void Queue<T>::Pop()
{
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

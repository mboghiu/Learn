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
class Stack
{
    public:
        void Push(const T& value);
        void Pop();

        void Print();
        std::string ToString();

    private:
        Node<T>* m_top = nullptr;
};

template<typename T>
void Stack<T>::Push(const T& value)
{
    if (m_top == nullptr)
        m_top = new Node<T>(value);
    else
        m_top = new Node<T>(value, m_top);
}

template<typename T>
void Stack<T>::Pop()
{
    if (m_top == nullptr)
        return;

    Node<T>* del = m_top;
    m_top = m_top->m_next;
    delete del;
}

template<typename T>
void Stack<T>::Print()
{
    std::cout << ToString() << std::endl;
}

template<typename T>
std::string Stack<T>::ToString()
{
    std::stringstream ss;
    for (Node<T>* i = m_top; i != nullptr; i = i->m_next)
        ss << i->m_data << " | ";
    return std::move(ss.str());
}

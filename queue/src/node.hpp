#pragma once

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

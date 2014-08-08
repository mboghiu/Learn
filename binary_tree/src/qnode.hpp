#pragma once

template<typename T>
struct qnode
{
    qnode() :
        m_have(false),
        m_next(nullptr)
    { }

    qnode(const T& data) :
        m_data(data),
        m_have(true),
        m_next(nullptr)
    { }

    qnode(const T& data, qnode* next) :
        qnode(data)
    {
        m_next = next;
    }

    T m_data;
    bool m_have;
    qnode* m_next;
};

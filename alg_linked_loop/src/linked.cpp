#include <iostream>
#include <cstddef>
#include <sstream>

#include "linked.hpp"


//////////// operators

bool operator==(const Node& lhs, const Node& rhs)
{
    if (lhs.Size() != rhs.Size())
        return false;

    if (lhs.m_data != rhs.m_data)
        return false;

    Node* itl = lhs.m_next;
    Node* itr = rhs.m_next;
    for (; itl != nullptr && itr != nullptr; itl = itl->m_next, itr = itr->m_next) 
         if (itl->m_data != itr->m_data)
            return false;

    return true;
}

Node operator+(const Node& rhs, const Node& lhs)
{
    Node res((rhs.m_data + lhs.m_data) % 10);
    int carryOver = (rhs.m_data + lhs.m_data) / 10;

    Node* itl = lhs.m_next;
    Node* itr = rhs.m_next;
    while (itl != nullptr && itr != nullptr)
    {
        res.Add((itl->m_data + itr->m_data + carryOver) % 10);
        carryOver = (itl->m_data + itr->m_data + carryOver) / 10; 
        itl = itl->m_next;
        itr = itr->m_next;
    }

    if (itl == nullptr)
        while (itr != nullptr)
        {
            res.Add((itr->m_data + carryOver) % 10);
            carryOver = (itr->m_data + carryOver) / 10;
            itr = itr->m_next;
        }
    
    if (itr == nullptr)
        while (itl != nullptr)
        {
            res.Add((itl->m_data + carryOver) % 10);
            carryOver = (itl->m_data + carryOver) / 10;
            itl = itl->m_next;
        }
    
    if (carryOver != 0)
        res.Add(carryOver);

    return std::move(res);
}



//////////// Linked List

Node* Node::Add(Node* n)
{
    Node* end = this;
    while (end->m_next != nullptr)
        end = end->m_next;
    end->m_next = n;

    return this;
}

Node* Node::Add(int data)
{
    Node* end = this;
    while (end->m_next != nullptr)
        end = end->m_next;
    end->m_next = new Node(data);

    return this;
}

Node* Node::Delete(int data)
{
    if (data == m_data)
    {
        Node* ret = m_next;
        delete this;
        return ret;
    }

    for (Node* it = this; it->m_next != nullptr; it = it->m_next)
        if (it->m_next->m_data == data)
        {
            it->m_next = it->m_next->m_next;
            return this;
        }

    return nullptr;
}

bool Node::Has(int data) const
{
    if (m_data == data)
        return true;
    for (Node* it = m_next; it != nullptr; it = it->m_next)
        if (it->m_data == data)
            return true;
    return false;
}

int Node::GetData() const
{
    return m_data;
}

size_t Node::Size() const
{
    if (m_next == nullptr)
        return 1;

    size_t c = 1;
    for (Node* it = m_next; it != nullptr; it = it->m_next)
        c++;
    return c;
}

std::string Node::PrintToString() const
{
    std::stringstream ss;
    ss << m_data << " -> ";

    for (Node* it = m_next; it != nullptr; it = it->m_next)
        ss << it->m_data << " -> ";

    return std::move(ss.str());
}

void Node::Print() const
{
    std::cout << PrintToString() << std::endl;
}



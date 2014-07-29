#pragma once

struct Node
{
    Node(int data) :
        m_next(nullptr),
        m_data(data)
    { }

    Node* Add(int data);
    Node* Delete(int data);

    bool Has(int data) const;
    int GetData() const;

    size_t Size() const;
    void Print() const;
    std::string PrintToString() const;

    Node* m_next;
    int m_data;
};


bool operator==(const Node& lhs, const Node& rhs);
Node operator+(const Node& rhs, const Node& lhs);

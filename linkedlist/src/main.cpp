#include <iostream>
#include <cstddef>

template<typename T>
void Test(T expected, T actual)
{
    if (expected == actual)
        std::cout << "\033[32mPASS\033[0m" << std::endl;
    else
    {
        std::cout << "\033[31mFAIL\033[0m" << std::endl;
        std::cout << "expected: " << expected << std::endl;
        std::cout << "actual: " << actual << std::endl;
    }
}

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

    Node* m_next;
    int m_data;
};

Node* Node::Add(int data)
{
    if (m_next == nullptr)
        m_next = new Node(data);
    else
    {
        Node* end = m_next;
        while (end->m_next != nullptr)
            end = end->m_next;
        end->m_next = new Node(data);
    }

    return this;
}

Node* Node::Delete(int data)
{
    if (data == m_data) 
    {
        Node* newHead = m_next;
        delete this;
        return newHead;
    }

    Node* parent = this;
    for (Node* it = m_next; it != nullptr; parent = it, it = it->m_next)
        if (it->m_data == data)
        {
            parent->m_next = it;
            delete it;
            return this;
        }

    return this;
}

bool Node::Has(int data) const
{
    if (data)
        return false;
    return true;
}

int Node::GetData() const
{
    return -1;
}

size_t Node::Size() const
{
    if (m_next == nullptr)
        return 1;

    size_t c;
    for (Node* it = m_next; it != nullptr; it = it->m_next)
        c++;
    return c;
}

int main()
{
    Node* list = new Node(1);
    Test<size_t>(1, list->Size());

    list->Add(2)->Add(3);//->Add(4);
    Test<size_t>(3, list->Size());
//    Test<bool>(true, list->Has(1));
//    Test<bool>(true, list->Has(2));
//    Test<bool>(true, list->Has(3));
//    Test<bool>(true, list->Has(4));
//
//    list->Delete(3);
//    Test<size_t>(3, list->Size());
//    Test<bool>(true, list->Has(1));
//    Test<bool>(true, list->Has(2));
//    Test<bool>(true, list->Has(4));

    return 0;
}

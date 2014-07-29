#include <iostream>
#include <cstddef>
#include <sstream>

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
    void Print() const;

    Node* m_next;
    int m_data;
};

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

void Node::Print() const
{
    std::stringstream ss;
    ss << m_data << " -> ";

    for (Node* it = m_next; it != nullptr; it = it->m_next)
        ss << it->m_data << " -> ";

    std::cout << ss.str() << std::endl;
}

int main()
{
    Node* list = new Node(1);
    Test<size_t>(1, list->Size());

    list->Add(2)->Add(3)->Add(4)->Print();
    Test<size_t>(4, list->Size());
    Test<bool>(true, list->Has(1));
    Test<bool>(true, list->Has(2));
    Test<bool>(true, list->Has(3));
    Test<bool>(true, list->Has(4));

    list = list->Delete(1);
    Test<size_t>(3, list->Size());
    Test<bool>(true, list->Has(2));
    Test<bool>(true, list->Has(3));
    Test<bool>(true, list->Has(4));

    list->Add(5);
    Test<size_t>(4, list->Size());
    Test<bool>(true, list->Has(5));

    list = list->Delete(4);
    Test<size_t>(3, list->Size());
    Test<bool>(true, list->Has(2));
    Test<bool>(true, list->Has(3));
    Test<bool>(true, list->Has(5));

    list = list->Delete(2);
    Test<size_t>(2, list->Size());
    Test<bool>(true, list->Has(3));
    Test<bool>(true, list->Has(5));
    list = list->Delete(3);
    Test<size_t>(1, list->Size());
    Test<bool>(true, list->Has(5));

    Test<Node*>(nullptr, (list->Delete(5)));

    return 0;
}

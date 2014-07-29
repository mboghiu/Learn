#include <iostream>
#include <cstddef>
#include <sstream>

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

//////////// Tester

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

template<typename T>
void Test(const T& expected, const T& actual)
{
    if (expected == actual)
        std::cout << "\033[32mPASS\033[0m" << std::endl;
    else
        std::cout << "\033[31mFAIL\033[0m" << std::endl;
}

int main()
{
    Node* c1 = (new Node(3))->Add(1); // 13
    Node* c2 = (new Node(3))->Add(1)->Add(5); // 513
    Test<bool>(false, *c1 == *c2);

    Node* d1 = (new Node(3))->Add(1)->Add(5); // 513
    Node* d2 = (new Node(3))->Add(1)->Add(5); // 513
    Test<bool>(true, *d1 == *d2);

    Node* e1 = (new Node(3)); // 3
    Node* e2 = (new Node(3)); // 3
    Test<bool>(true, *e1 == *e2);

    // 513 + 295 = 808
    Node* x1 = (new Node(3))->Add(1)->Add(5); // 513
    Node* y1 = (new Node(5))->Add(9)->Add(2); // 295
    Node* r1 = (new Node(8))->Add(0)->Add(8); // 808
    x1->Print(); y1->Print(); r1->Print();
    Test<bool>(true, *r1 == (*x1 + *y1));

    // 999 + 111 = 1110
    Node* x2 = (new Node(9))->Add(9)->Add(9);
    Node* y2 = (new Node(1))->Add(1)->Add(1);
    Node* r2 = (new Node(0))->Add(1)->Add(1)->Add(1);
    x2->Print(); y2->Print(); r2->Print();
    Test<bool>(true, *r2 == (*x2 + *y2));

    // 13 + (-1) = 12
    Node* x3 = (new Node(3))->Add(1);
    Node* y3 = (new Node(-1));
    Node* r3 = (new Node(2))->Add(1);
    x3->Print(); y3->Print(); r3->Print();
    Test<bool>(true, *r3 == (*x3 + *y3));

    return 0;
}

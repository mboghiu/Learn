#include <set>
#include <algorithm>

#include "tester.hpp"
#include "linked.hpp"

int nth(Node* X, size_t index)
{
    Node* p1 = X;
    Node* p2 = X;

    for (size_t x = 0; x < index; x++)
        if (p2->m_next == nullptr)
            return p1->m_data;
        else
            p2 = p2->m_next;

    while (p2 != nullptr)
    {
        p1 = p1->m_next;
        p2 = p2->m_next;
    }

    return p1->m_data;
}

int nth_naive(Node* X, size_t index)
{
    if (X->Size() < index)
        return -1;

    Node* it = X;
    int c = 0;
    while (it != nullptr)
    {
        if (X->Size() - c == index)
            return it->m_data;
        
        c++;
        it = it->m_next;
    }

    return -1;
}

int main()
{
    Node* X = (new Node(1))->Add(2)->Add(3)->Add(4)->Add(5);
    Test(true, nth(X, 5) == 1);
    Test(true, nth(X, 3) == 3);
    Test(true, nth(X, 4) == 2);
    Test(true, nth(X, 1) == 5);

    Node* Y = (new Node(3));
    Test(true, nth(Y, 1) == 3);
    return 0;
}

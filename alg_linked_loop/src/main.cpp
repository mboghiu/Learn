#include <set>
#include <algorithm>

#include "tester.hpp"
#include "linked.hpp"

int FindLoop(Node* list)
{
    
}

int FindLoop_Naive(Node* list)
{
    std::set<Node*> have;

    Node* it = list;
    while (have.find(it) == have.end())
    {
        have.insert(it);
        it = it->m_next;
    }

    return it->m_data;
}

int main()
{
    Node* X = new Node(1);
    Node* a = (new Node(2));
    a->m_next = X;
    X->Add(a);
    Test(true, FindLoop(X) == 1);

    Node* Y = (new Node(1))->Add(2)->Add(3);
    Node* loop = new Node(4);
    Node* b = new Node(5);
    b->m_next = loop;
    Y->Add(loop)->Add(4)->Add(b);
    Test(true, FindLoop(Y) == loop->m_data);

    return 0;
}

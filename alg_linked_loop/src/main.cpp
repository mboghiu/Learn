#include <set>
#include <algorithm>

#include "tester.hpp"
#include "linked.hpp"

int FindLoop(Node* list)
{
    Node* fastRunner = list;
    Node* slowRunner = list;

    while (fastRunner->m_next != nullptr &&
           fastRunner->m_next->m_next != nullptr &&
           fastRunner != slowRunner)
    {
        fastRunner = fastRunner->m_next->m_next;
        slowRunner = slowRunner->m_next;
    }

    if (fastRunner != slowRunner)
        return -1;

    slowRunner = list;

    while (slowRunner != fastRunner)
    {
        slowRunner = slowRunner->m_next;
        fastRunner = fastRunner->m_next;
    }

    return slowRunner->m_data;
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
    std::cout<< "r: " << FindLoop(Y) << std::endl;

    return 0;
}

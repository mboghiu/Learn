#include "test.hpp"

#include <stack>

void hanoi(std::stack<int>& start, size_t size,
           std::stack<int>& end,
           std::stack<int>& pivot)
{
    if (size == 0)
        return;

    if (size == 1)
    {
        end.push(start.top());
        start.pop();
        return;
    }

    if (size == 2)
    {
        pivot.push(start.top());
        start.pop();

        end.push(start.top());
        start.pop();

        end.push(pivot.top());
        pivot.pop();

        return;
    }
    
    hanoi(start, size-1, pivot, end);

    end.push(start.top());
    start.pop();

    hanoi(pivot, pivot.size(), end, start);
}

int main()
{
    std::stack<int> s, e, p;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    test<size_t>(4, s.size());
    test<size_t>(0, p.size());
    test<size_t>(0, e.size());
    hanoi(s, s.size(), e, p);
    test<size_t>(0, s.size());
    test<size_t>(0, p.size());
    test<size_t>(4, e.size());

    test<size_t>(1, e.top()); e.pop();
    test<size_t>(2, e.top()); e.pop();
    test<size_t>(3, e.top()); e.pop();
    test<size_t>(4, e.top()); e.pop();
    test<size_t>(0, e.size());

    return 0;
}

#include "test.hpp"

#include <string>
#include <sstream>
#include <stack>

void hanoi(std::stack<int>& start, size_t size,
           std::stack<int>& end,
           std::stack<int>& pivot, std::stringstream& ss)
{
    if (size == 0)
        return;

    if (size == 1)
    {
        ss << "S->E";
        return;
    }

    if (size == 2)
    {
        ss << "S->P;";
        pivot.push(start.top());
        start.pop();

        ss << "S->E;";
        end.push(start.top());
        start.pop();

        ss << "P->E;";
        end.push(pivot.top());
        pivot.pop();

        return;
    }
    
    hanoi(start, size-1, pivot, end, ss);

    ss << "S->E;";
    end.push(start.top());
    start.pop();

    hanoi(pivot, pivot.size(), end, start, ss);
}

int main()
{
    std::stringstream ss;
    std::stack<int> s, e, p;
    s.push(3);
    s.push(2);
    s.push(1);
    hanoi(s, s.size(), e, p, ss);
    //test<std::string>("S->P;S->E;P->E;", ss.str());
    test<size_t>(0, s.size());
    test<size_t>(0, p.size());
    test<size_t>(3, e.size());
    test<size_t>(1, e.top());
    e.pop();
    test<size_t>(2, e.top());
    e.pop();
    test<size_t>(3, e.top());
    e.pop();
    test<size_t>(0, e.size());

    return 0;
}

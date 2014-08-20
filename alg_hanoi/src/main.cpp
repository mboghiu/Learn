#include "test.hpp"

#include <string>
#include <sstream>
#include <stack>

void hanoi(std::stack<int>& start,
           std::stack<int>& end,
           std::stack<int>& pivot, std::stringstream& ss)
{
    if (start.size() == 0)
        return;

    if (start.size() == 1)
    {
        ss << "S->E";
        return;
    }

    if (start.size() == 2)
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

    
}

int main()
{
    std::stringstream ss;
    std::stack<int> s, e, p;
    s.push(2);
    s.push(1);
    hanoi(s, e, p, ss);
    test<std::string>("S->P;S->E;P->E;", ss.str());
    test<size_t>(0, s.size());
    test<size_t>(0, p.size());
    test<size_t>(2, e.size());
    test<size_t>(1, e.top());
    e.pop();
    test<size_t>(2, e.top());
    e.pop();
    test<size_t>(0, e.size());

    return 0;
}

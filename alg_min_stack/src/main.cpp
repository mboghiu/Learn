#include "test.hpp"
#include "stack.hpp"

int main()
{
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(0);
    s.push(7);
    s.print();

    test(7, s.peek());
    s.pop();
    s.print();
    test(0, s.peek());
    test(0, s.min());
    s.pop();
    s.print();
    test(1, s.min());

    return 0;
}

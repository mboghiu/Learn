#include "test.hpp"
#include "stack.hpp"

int main()
{
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(0);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    test(11, s.peek());
    s.pop();
    test(10, s.peek());
    s.pop();
    test(9, s.peek());
    s.pop();
    s.pop();
    test(7, s.peek());

    return 0;
}

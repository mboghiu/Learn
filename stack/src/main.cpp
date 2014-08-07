#include "test.hpp"
#include "stack.hpp"

int main()
{
    Stack<int>* s = new Stack<int>();
    s->Print();

    s = s->Push(4);
    s->Print();

    s = s->Push(5);
    s->Print();


    return 0;
}

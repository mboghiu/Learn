#include <string>

#include "test.hpp"
#include "stack.hpp"

int main()
{
    Stack<int>* s = new Stack<int>();
    Test<std::string>("", s->ToString());

    s->Push(4);
    Test<std::string>("4 | ", s->ToString());

    s->Push(5);
    Test<std::string>("5 | 4 | ", s->ToString());

    s->Push(7);
    s->Push(6);
    Test<std::string>("6 | 7 | 5 | 4 | ", s->ToString());

    s->Pop();
    Test<std::string>("7 | 5 | 4 | ", s->ToString());
    s->Pop();
    s->Pop();
    Test<std::string>("4 | ", s->ToString());
    s->Pop();
    Test<std::string>("", s->ToString());


    return 0;
}
